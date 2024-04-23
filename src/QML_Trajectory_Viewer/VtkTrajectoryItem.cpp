
#include "VtkTrajectoryItem.h"

#include <vtkActor.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkMinimalStandardRandomSequence.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkObjectFactory.h>
#include <vtkPolyDataMapper.h>
#include <vtkPropPicker.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkSphereSource.h>

#include <vtkSmartPointer.h>
#include <vtkPoints.h>
#include <vtkCellArray.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>

#include <vtkRenderWindowInteractor.h>
#include <vtkLineSource.h>
#include <vtkArcSource.h>
#include <vtkRegularPolygonSource.h>
#include <vtkCylinderSource.h>
#include <vtkMath.h>
#include <vtkProperty.h>
#include <vtkTransform.h>
#include <vtkTransformPolyDataFilter.h>
#include <cmath>

#include <vtkPointData.h> // Include for vtkPointData
#include <vtkFloatArray.h> // Include for vtkFloatArray
#include <vtkPolyDataNormals.h>

#include <vtkPolyLine.h>
#include <vtkPoints.h>
#include <vtkCellArray.h>
#include <vtkPolyData.h>

#include <vtkBoundingBox.h>

 void VtkTrajectoryItem::AddCamera(){

  m_Camera = vtkSmartPointer<vtkCamera>::New();
  std::lock_guard<std::mutex> lock(mutex); // Lock mutex before modifying m_Renderer
  m_Renderer->SetActiveCamera(m_Camera);  
}

void VtkTrajectoryItem::AddLine(double startPoint[3], double endPoint[3], bool green) {

    vtkSmartPointer<vtkLineSource> lineSource = vtkSmartPointer<vtkLineSource>::New();
    lineSource->SetPoint1(startPoint);
    lineSource->SetPoint2(endPoint);
    vtkSmartPointer<vtkPolyDataMapper> lineMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    lineMapper->SetInputConnection(lineSource->GetOutputPort());
    vtkSmartPointer<vtkActor> lineActor = vtkSmartPointer<vtkActor>::New();
    lineActor->SetMapper(lineMapper);
    if (green) {
        lineActor->GetProperty()->SetColor(0, 1, 0); // Set color to green
    } else {
        lineActor->GetProperty()->SetColor(m_ToolPathColor); 
    }
    std::lock_guard<std::mutex> lock(mutex); // Lock mutex before modifying m_Renderer
    m_Renderer->AddActor(lineActor);
    UpdateCamera();
    m_Primitives.push_back({lineActor});
}

void VtkTrajectoryItem::AddCircle(double center[3], double radius, double normal[3]) {

    auto circleSource = vtkSmartPointer<vtkRegularPolygonSource>::New();
    circleSource->SetNumberOfSides(50); // Adjust the number of sides for smoothness

    circleSource->GeneratePolygonOff();
    circleSource->SetRadius(radius);
    circleSource->SetCenter(center[0], center[1], center[2]);
    circleSource->SetNormal(normal[0], normal[1], normal[2]);

    auto circleMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    circleMapper->SetInputConnection(circleSource->GetOutputPort());

    auto circleActor = vtkSmartPointer<vtkActor>::New();
    circleActor->SetMapper(circleMapper);
    circleActor->GetProperty()->SetRepresentationToWireframe(); // Render only the wireframe
    circleActor->GetProperty()->SetColor(m_ToolPathColor[0], m_ToolPathColor[1], m_ToolPathColor[2]); 

    m_Renderer->AddActor(circleActor);
    UpdateCamera();
    m_Primitives.push_back({circleActor});
}


void VtkTrajectoryItem::AddArc(double center[3], double start[3], double end[3], double normal[3]) {
   
    auto arcSource = vtkSmartPointer<vtkArcSource>::New();

    arcSource->SetPoint1(start);
    arcSource->SetPoint2(end);
    arcSource->SetCenter(center);
    arcSource->SetNormal(normal);
    arcSource->SetResolution(100);

    // Create a mapper
    auto mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(arcSource->GetOutputPort());

    // Create an actor
    auto actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);

    // Set the color of the actor
    actor->GetProperty()->SetColor(m_ToolPathColor[0], m_ToolPathColor[1], m_ToolPathColor[2]);

    // Add the actor to the renderer
    m_Renderer->AddActor(actor);
}

void VtkTrajectoryItem::AddToolTip() {
      
  if (!m_ToolActor) {
    // Create a cylinder
    auto cylinder = vtkSmartPointer<vtkCylinderSource>::New();
    cylinder->SetRadius(m_ToolDiameter / 2.0);
    cylinder->SetHeight(m_ToolHeight);
    cylinder->SetResolution(50); 
    // Create mapper
    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(cylinder->GetOutputPort());
    // Create actor
    m_ToolActor = vtkSmartPointer<vtkActor>::New();
    m_ToolActor->SetMapper(mapper);
    // Set the color of the actor to red
     m_ToolActor->GetProperty()->SetColor(m_ToolColor[0], m_ToolColor[1], m_ToolColor[2]); 
     m_Renderer->AddActor(m_ToolActor); // Add the actor to the renderer
  }

    UpdateToolPose();
}

void VtkTrajectoryItem::UpdateToolTip() {

   if (m_ToolActor) {

      UpdateToolPose();
      UpdateCamera();
   } 
}

void VtkTrajectoryItem::UpdateToolPose(){

    vtkMath::Normalize(m_ToolOrientation);
    // Define unit vector along y-axis
    double yAxis[3] = {0.0, 1.0, 0.0};

    // Calculate the rotation angle and axis to align the cylinder along the arbitrary vector
    double rotationAxis[3];
    vtkMath::Cross(m_ToolOrientation, yAxis, rotationAxis);
    double rotationAngle = vtkMath::DegreesFromRadians(acos(vtkMath::Dot(m_ToolOrientation, yAxis)));

    auto transform = vtkSmartPointer<vtkTransform>::New();
    transform->Translate(m_ToolPosition[0] + 0.5 * m_ToolHeight * m_ToolOrientation[0],
                         m_ToolPosition[1] + 0.5 * m_ToolHeight * m_ToolOrientation[1],
                         m_ToolPosition[2] + 0.5 * m_ToolHeight * m_ToolOrientation[2]);  

    transform->RotateWXYZ(rotationAngle, rotationAxis);

    // Apply the transformation to the actor
    m_ToolActor->SetUserTransform(transform);
}

void VtkTrajectoryItem::AddPolyline(vtkSmartPointer<vtkPoints> points) {
    // Create the polyline
    vtkSmartPointer<vtkPolyLine> polyline = vtkSmartPointer<vtkPolyLine>::New();
    polyline->GetPointIds()->SetNumberOfIds(points->GetNumberOfPoints());
    for (vtkIdType i = 0; i < points->GetNumberOfPoints(); i++) {
        polyline->GetPointIds()->SetId(i, i);
    }

    // Create cell array and add the polyline to it
    vtkSmartPointer<vtkCellArray> lines = vtkSmartPointer<vtkCellArray>::New();
    lines->InsertNextCell(polyline);

    // Create polydata and add the points and lines to it
    vtkSmartPointer<vtkPolyData> polyData = vtkSmartPointer<vtkPolyData>::New();
    polyData->SetPoints(points);
    polyData->SetLines(lines);

    // Create mapper and actor for the polyline
    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputData(polyData);

    vtkSmartPointer<vtkActor> polyLineActor = vtkSmartPointer<vtkActor>::New();
    polyLineActor->SetMapper(mapper);

    // Set color for the polyline
    polyLineActor->GetProperty()->SetColor(m_ToolPathColor[0], m_ToolPathColor[1], m_ToolPathColor[2]);

    m_Renderer->AddActor(polyLineActor);
    UpdateCamera();
    m_Primitives.push_back({polyLineActor}); 
}

void VtkTrajectoryItem::AddPointsToPolyline(const std::vector<std::array<double, 3>>& additionalPoints) {

    if (!m_Primitives.empty()) {
        // Get the last primitive, assuming it's a polyline
        Primitive& lastPrimitive = m_Primitives.back();

        // Get the existing points from the last primitive
        vtkPoints* polylinePoints = vtkPolyData::SafeDownCast(lastPrimitive.actor->GetMapper()->GetInput())->GetPoints();

        // Add the additional points
        for (const auto& point : additionalPoints) {
            polylinePoints->InsertNextPoint(point.data());
        }

        // Update the renderer
        m_Renderer->Modified();
    } else {
        std::cerr << "Error: No primitives found to add points to." << std::endl;
    }
}

void VtkTrajectoryItem::AddAxesActor() {

    m_AxesActor = vtkSmartPointer<vtkAxesActor>::New();
    // Customize appearance
    m_AxesActor->SetTotalLength(1.0, 1.0, 1.0); // Set total length of the axes
    m_AxesActor->SetCylinderRadius(0.02); // Set cylinder radius
    m_AxesActor->SetConeRadius(0.05); // Set cone radius
    m_AxesActor->SetAxisLabels(true); // Enable axis labels

    // Add axes actor to the renderer
    m_Renderer->AddActor(m_AxesActor);
}

void VtkTrajectoryItem::RemoveFirstPrimitive() {

  if (!m_Primitives.empty()) {
    m_Renderer->RemoveActor(m_Primitives.front().actor);
    m_Primitives.erase(m_Primitives.begin());
  }
}

void VtkTrajectoryItem::RemoveLastPrimitive() {

  if (!m_Primitives.empty()) {
    m_Renderer->RemoveActor(m_Primitives.back().actor);
    m_Primitives.pop_back();
  }
}

void VtkTrajectoryItem::UpdateCamera() {
    
    double bounds[6];
    double center[3];

    m_Renderer->ComputeVisiblePropBounds(bounds);

    // Calculate the length of each axis based on the bounding box dimensions
    double xAxisLength = bounds[1] - bounds[0];
    double yAxisLength = bounds[3] - bounds[2];
    double zAxisLength = bounds[5] - bounds[4];

    // Set the length of the axes actor accordingly
    m_AxesActor->SetTotalLength(0.1* xAxisLength, 0.1*yAxisLength, 0.1*zAxisLength); 

    for (int i = 0; i < 3; ++i) {
        center[i] = (bounds[2 * i] + bounds[2 * i + 1]) / 2.0;
    }
    
    // Determine camera position and focal point
    double cameraPosition[3];
    double focalPoint[3];
    // Calculate camera position based on bounding box
    for (int i = 0; i < 3; ++i) {
      cameraPosition[i] = center[i] + 2.0 * (bounds[2 * i + 1] - bounds[2 * i]);
    }

    // Calculate focal point based on bounding box center
    for (int i = 0; i < 3; ++i) {
      focalPoint[i] = center[i];
    }

    // Set camera position and focal point
    m_Renderer->GetActiveCamera()->SetPosition(cameraPosition);
    m_Renderer->GetActiveCamera()->SetFocalPoint(focalPoint);
    
    m_Renderer->ResetCameraClippingRange(); // Adjusts the clipping range of the camera  
}  


//***************************************************************************************************************

// vtkSmartPointer<vtkActor> createLineSegment(double startPoint[3], double endPoint[3]) {
//     vtkSmartPointer<vtkLineSource> lineSource = vtkSmartPointer<vtkLineSource>::New();
//     lineSource->SetPoint1(startPoint);
//     lineSource->SetPoint2(endPoint);
    
//     vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
//     mapper->SetInputConnection(lineSource->GetOutputPort());
    
//     vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
//     actor->SetMapper(mapper);
//     actor->GetProperty()->SetColor(0, 0, 0); // Set color to black
    
//     return actor;
// }

// vtkSmartPointer<vtkActor> createCircle(double center[3], double radius, double normal[3]) {
//     // Normalize the normal vector
//     vtkMath::Normalize(normal);

//     vtkSmartPointer<vtkRegularPolygonSource> circleSource = vtkSmartPointer<vtkRegularPolygonSource>::New();
//     circleSource->SetNumberOfSides(50); // Adjust the number of sides for smoothness
//     circleSource->SetRadius(radius);
//     circleSource->SetCenter(center);
    
//     // Set the normal
//     circleSource->SetNormal(normal);
    
//     vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
//     mapper->SetInputConnection(circleSource->GetOutputPort());
    
//     vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
//     actor->SetMapper(mapper);
//     actor->GetProperty()->SetRepresentationToWireframe(); // Render only the wireframe
//     actor->GetProperty()->SetColor(0, 0, 0); // Set outline color (black)
    
//     return actor;
// }

// vtkSmartPointer<vtkActor> createArc(double center[3], double radius, double startAngle, double endAngle, double normal[3]) {
//     // Normalize the normal vector
//     vtkMath::Normalize(normal);

//     // Convert angles from degrees to radians
//     startAngle = vtkMath::RadiansFromDegrees(startAngle);
//     endAngle = vtkMath::RadiansFromDegrees(endAngle);

//     // Calculate start and end points based on the center and radius
//     double startPoint[3];
//     startPoint[0] = center[0] + radius * cos(startAngle);
//     startPoint[1] = center[1] + radius * sin(startAngle);
//     startPoint[2] = center[2];

//     double endPoint[3];
//     endPoint[0] = center[0] + radius * cos(endAngle);
//     endPoint[1] = center[1] + radius * sin(endAngle);
//     endPoint[2] = center[2];

//     // Create an arc source using the start and end points
//     vtkSmartPointer<vtkArcSource> arcSource = vtkSmartPointer<vtkArcSource>::New();
//     arcSource->SetCenter(center);
//     arcSource->SetPoint1(startPoint);
//     arcSource->SetPoint2(endPoint);
//     arcSource->SetNormal(normal);
//     arcSource->SetResolution(100); // Adjust resolution as needed

//     // Create mapper and actor for the arc source
//     vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
//     mapper->SetInputConnection(arcSource->GetOutputPort());

//     vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
//     actor->SetMapper(mapper);
//     actor->GetProperty()->SetColor(0, 0, 0); // Set color to black

//     return actor;
// }


// void displayGeometricPrimitives(std::vector<vtkSmartPointer<vtkActor>> primitives) {

//     vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
//     vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
//     renderWindow->AddRenderer(renderer);
    
//     vtkSmartPointer<vtkRenderWindowInteractor> interactor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
//     interactor->SetRenderWindow(renderWindow);
    
//     // Add primitives to the renderer
//     for (auto primitive : primitives) {
//         renderer->AddActor(primitive);
//     }
    
//     renderer->SetBackground(1, 1, 1); // white background
//     renderWindow->Render();
//     interactor->Start();
// }

// void renderCylinderWithPoseAndColor(vtkSmartPointer<vtkRenderer> renderer, double diameter, double height, double tipX, double tipY, double tipZ,
//                                     double tipOrientation[3], double r = 1.0, double g=0.0, double b=0.0) {
//     // Create a cylinder
//     vtkSmartPointer<vtkCylinderSource> cylinder = vtkSmartPointer<vtkCylinderSource>::New();
//     cylinder->SetRadius(diameter / 2.0);
//     cylinder->SetHeight(height);
//     cylinder->SetResolution(100); // Set a higher resolution for smoother appearance

//     // Create a transform to position and orient the cylinder
//     vtkSmartPointer<vtkTransform> transform = vtkSmartPointer<vtkTransform>::New();
//     transform->Translate(tipX, tipY, tipZ);

//     // Calculate the rotation angles from the tip orientation vector
//     double angleX = atan2(tipOrientation[1], tipOrientation[2]) * 180.0 / vtkMath::Pi();
//     double angleY = atan2(-tipOrientation[0], sqrt(tipOrientation[1] * tipOrientation[1] + tipOrientation[2] * tipOrientation[2])) * 180.0 / vtkMath::Pi();
//     transform->RotateWXYZ(angleX, 1.0, 0.0, 0.0);
//     transform->RotateWXYZ(angleY, 0.0, 1.0, 0.0);

//     // Apply the transform to the cylinder
//     vtkSmartPointer<vtkTransformPolyDataFilter> transformFilter = vtkSmartPointer<vtkTransformPolyDataFilter>::New();
//     transformFilter->SetInputConnection(cylinder->GetOutputPort());
//     transformFilter->SetTransform(transform);
//     transformFilter->Update();

//     // Create a mapper
//     vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
//     mapper->SetInputConnection(transformFilter->GetOutputPort());

//     // Create an actor
//     vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
//     actor->SetMapper(mapper);

//     // Set the color of the actor
//     actor->GetProperty()->SetColor(r, g, b);

//     // Add the actor to the renderer
//     renderer->AddActor(actor);
// }

namespace {
// Handle mouse events
class MouseInteractorHighLightActor : public vtkInteractorStyleTrackballCamera
{
public:
    static MouseInteractorHighLightActor* New();
    vtkTypeMacro(MouseInteractorHighLightActor,
                 vtkInteractorStyleTrackballCamera);

    MouseInteractorHighLightActor()
    {
        LastPickedActor = NULL;
        LastPickedProperty = vtkProperty::New();
    }
    virtual ~MouseInteractorHighLightActor()
    {
        LastPickedProperty->Delete();
    }
    virtual void OnLeftButtonDown() override
    {
        vtkNew<vtkNamedColors> colors;

        int* clickPos = this->GetInteractor()->GetEventPosition();

        // Pick from this location.
        vtkNew<vtkPropPicker> picker;
        picker->Pick(clickPos[0], clickPos[1], 0, this->GetDefaultRenderer());

        // If we picked something before, reset its property
        if (this->LastPickedActor)
        {
            this->LastPickedActor->GetProperty()->DeepCopy(this->LastPickedProperty);
        }
        this->LastPickedActor = picker->GetActor();
        if (this->LastPickedActor)
        {
            // Save the property of the picked actor so that we can
            // restore it next time
            this->LastPickedProperty->DeepCopy(this->LastPickedActor->GetProperty());
            // Highlight the picked actor by changing its properties
            this->LastPickedActor->GetProperty()->SetColor(
                colors->GetColor3d("Red").GetData());
            this->LastPickedActor->GetProperty()->SetDiffuse(1.0);
            this->LastPickedActor->GetProperty()->SetSpecular(0.0);
            this->LastPickedActor->GetProperty()->EdgeVisibilityOn();
        }

        // Forward events
        vtkInteractorStyleTrackballCamera::OnLeftButtonDown();
    }

private:
    vtkActor* LastPickedActor;
    vtkProperty* LastPickedProperty;
};

vtkStandardNewMacro(MouseInteractorHighLightActor);
} // namespace

namespace {
struct MyVtkData : vtkObject
{
    static MyVtkData* New();
    vtkTypeMacro(MyVtkData, vtkObject);

    // Place all your persistant VTK objects here
};

vtkStandardNewMacro(MyVtkData);
}

QQuickVtkItem::vtkUserData VtkTrajectoryItem::initializeVTK(vtkRenderWindow* renderWindow)
{
    if (renderWindow) {
        m_RenderWindow = renderWindow; // Assign the render window pointer to the member variable

           if(!m_Renderer){
          // Create a renderer and add it to the render window
            m_Renderer = vtkSmartPointer<vtkRenderer>::New();
            m_RenderWindow->AddRenderer(m_Renderer);
          }
    }   

    auto vtk = vtkNew<MyVtkData>();

    // vtkNew<vtkNamedColors> colors;

    renderWindow->SetSize(m_WindowWidth, m_WindowHeight);
 
    renderWindow->SetWindowName("HighlightPickedActor");

    // Set the custom type to use for interaction.
    // vtkNew<MouseInteractorHighLightActor> style;
    // style->SetDefaultRenderer(m_Renderer);

    // renderWindow->GetInteractor()->SetInteractorStyle(style); // This causes QSocket to crash... I do not know why.
    // double startPoint[3] = {0, 0, 0};
    // double endPoint[3] = {1, 1, 1};
    // double center[3] = {0, 0, 0};
    // double radius = 1.0;
    // double startAngle = 0.0;
    // double endAngle = 90.0;
    
    // // Create line segment
    // vtkSmartPointer<vtkActor> lineSegment = createLineSegment(startPoint, endPoint);
    
    // // Create circle
    // double normal[3] = {0.0, 0.0, 1.0}; // Example normal vector pointing in the z-direction
    // vtkSmartPointer<vtkActor> circle = createCircle(center, radius, normal);
    
    // // Create arc
    // double normal2[3] = {0.0, 1.0, 0.0}; // Example normal vector pointing in the y-direction
    // vtkSmartPointer<vtkActor> arc = createArc(center, radius, startAngle, endAngle, normal2);

    // // Create renderer and add geometric primitives
    // vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
    // m_Renderer->AddActor(lineSegment);
    // m_Renderer->AddActor(circle);
    // m_Renderer->AddActor(arc);

    // // Create cylinder
    // double tipOrientation[3] = {0.707, 0.707, 0.0}; // Example: pointing in the X direction
    // renderCylinderWithPoseAndColor(renderer, 0.2, 3.0, 1.0, 1.0, 1.0, tipOrientation, 1.0, 0.0, 0.0);  // Red cylinder at origin

    // m_Renderer->SetBackground(colors->GetColor3d("SteelBlue").GetData());

    SetBackGround();
    return vtk;
}