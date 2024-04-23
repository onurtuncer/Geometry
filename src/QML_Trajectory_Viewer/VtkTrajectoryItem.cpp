
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


vtkSmartPointer<vtkActor> createLineSegment(double startPoint[3], double endPoint[3]) {
    vtkSmartPointer<vtkLineSource> lineSource = vtkSmartPointer<vtkLineSource>::New();
    lineSource->SetPoint1(startPoint);
    lineSource->SetPoint2(endPoint);
    
    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(lineSource->GetOutputPort());
    
    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);
    actor->GetProperty()->SetColor(0, 0, 0); // Set color to black
    
    return actor;
}

vtkSmartPointer<vtkActor> createCircle(double center[3], double radius, double normal[3]) {
    // Normalize the normal vector
    vtkMath::Normalize(normal);

    vtkSmartPointer<vtkRegularPolygonSource> circleSource = vtkSmartPointer<vtkRegularPolygonSource>::New();
    circleSource->SetNumberOfSides(50); // Adjust the number of sides for smoothness
    circleSource->SetRadius(radius);
    circleSource->SetCenter(center);
    
    // Set the normal
    circleSource->SetNormal(normal);
    
    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(circleSource->GetOutputPort());
    
    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);
    actor->GetProperty()->SetRepresentationToWireframe(); // Render only the wireframe
    actor->GetProperty()->SetColor(0, 0, 0); // Set outline color (black)
    
    return actor;
}

vtkSmartPointer<vtkActor> createArc(double center[3], double radius, double startAngle, double endAngle, double normal[3]) {
    // Normalize the normal vector
    vtkMath::Normalize(normal);

    // Convert angles from degrees to radians
    startAngle = vtkMath::RadiansFromDegrees(startAngle);
    endAngle = vtkMath::RadiansFromDegrees(endAngle);

    // Calculate start and end points based on the center and radius
    double startPoint[3];
    startPoint[0] = center[0] + radius * cos(startAngle);
    startPoint[1] = center[1] + radius * sin(startAngle);
    startPoint[2] = center[2];

    double endPoint[3];
    endPoint[0] = center[0] + radius * cos(endAngle);
    endPoint[1] = center[1] + radius * sin(endAngle);
    endPoint[2] = center[2];

    // Create an arc source using the start and end points
    vtkSmartPointer<vtkArcSource> arcSource = vtkSmartPointer<vtkArcSource>::New();
    arcSource->SetCenter(center);
    arcSource->SetPoint1(startPoint);
    arcSource->SetPoint2(endPoint);
    arcSource->SetNormal(normal);
    arcSource->SetResolution(100); // Adjust resolution as needed

    // Create mapper and actor for the arc source
    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(arcSource->GetOutputPort());

    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);
    actor->GetProperty()->SetColor(0, 0, 0); // Set color to black

    return actor;
}


void displayGeometricPrimitives(std::vector<vtkSmartPointer<vtkActor>> primitives) {

    vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
    vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
    renderWindow->AddRenderer(renderer);
    
    vtkSmartPointer<vtkRenderWindowInteractor> interactor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    interactor->SetRenderWindow(renderWindow);
    
    // Add primitives to the renderer
    for (auto primitive : primitives) {
        renderer->AddActor(primitive);
    }
    
    renderer->SetBackground(1, 1, 1); // white background
    renderWindow->Render();
    interactor->Start();
}

void renderCylinderWithPoseAndColor(vtkSmartPointer<vtkRenderer> renderer, double diameter, double height, double tipX, double tipY, double tipZ,
                                    double tipOrientation[3], double r = 1.0, double g=0.0, double b=0.0) {
    // Create a cylinder
    vtkSmartPointer<vtkCylinderSource> cylinder = vtkSmartPointer<vtkCylinderSource>::New();
    cylinder->SetRadius(diameter / 2.0);
    cylinder->SetHeight(height);
    cylinder->SetResolution(100); // Set a higher resolution for smoother appearance

    // Create a transform to position and orient the cylinder
    vtkSmartPointer<vtkTransform> transform = vtkSmartPointer<vtkTransform>::New();
    transform->Translate(tipX, tipY, tipZ);

    // Calculate the rotation angles from the tip orientation vector
    double angleX = atan2(tipOrientation[1], tipOrientation[2]) * 180.0 / vtkMath::Pi();
    double angleY = atan2(-tipOrientation[0], sqrt(tipOrientation[1] * tipOrientation[1] + tipOrientation[2] * tipOrientation[2])) * 180.0 / vtkMath::Pi();
    transform->RotateWXYZ(angleX, 1.0, 0.0, 0.0);
    transform->RotateWXYZ(angleY, 0.0, 1.0, 0.0);

    // Apply the transform to the cylinder
    vtkSmartPointer<vtkTransformPolyDataFilter> transformFilter = vtkSmartPointer<vtkTransformPolyDataFilter>::New();
    transformFilter->SetInputConnection(cylinder->GetOutputPort());
    transformFilter->SetTransform(transform);
    transformFilter->Update();

    // Create a mapper
    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(transformFilter->GetOutputPort());

    // Create an actor
    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);

    // Set the color of the actor
    actor->GetProperty()->SetColor(r, g, b);

    // Add the actor to the renderer
    renderer->AddActor(actor);
}

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

           if(m_Renderer){
          // Create a renderer and add it to the render window
            m_Renderer = vtkSmartPointer<vtkRenderer>::New();
            m_RenderWindow->AddRenderer(m_Renderer);
          }
    }   

    auto vtk = vtkNew<MyVtkData>();

    vtkNew<vtkNamedColors> colors;
/* 
    // A renderer and render window
    vtkNew<vtkRenderer> renderer; */

    renderWindow->SetSize(320, 240);
    renderWindow->AddRenderer(m_Renderer);
    renderWindow->SetWindowName("HighlightPickedActor");

    // Set the custom type to use for interaction.
    vtkNew<MouseInteractorHighLightActor> style;
    style->SetDefaultRenderer(m_Renderer);

    renderWindow->GetInteractor()->SetInteractorStyle(style);

    double startPoint[3] = {0, 0, 0};
    double endPoint[3] = {1, 1, 1};
    double center[3] = {0, 0, 0};
    double radius = 1.0;
    double startAngle = 0.0;
    double endAngle = 90.0;
    
    // Create line segment
    vtkSmartPointer<vtkActor> lineSegment = createLineSegment(startPoint, endPoint);
    
    // Create circle
    double normal[3] = {0.0, 0.0, 1.0}; // Example normal vector pointing in the z-direction
    vtkSmartPointer<vtkActor> circle = createCircle(center, radius, normal);
    
    // Create arc
    double normal2[3] = {0.0, 1.0, 0.0}; // Example normal vector pointing in the y-direction
    vtkSmartPointer<vtkActor> arc = createArc(center, radius, startAngle, endAngle, normal2);

    // // Create renderer and add geometric primitives
    // vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
    m_Renderer->AddActor(lineSegment);
    m_Renderer->AddActor(circle);
    m_Renderer->AddActor(arc);

    // // Create cylinder
    // double tipOrientation[3] = {0.707, 0.707, 0.0}; // Example: pointing in the X direction
    // renderCylinderWithPoseAndColor(renderer, 0.2, 3.0, 1.0, 1.0, 1.0, tipOrientation, 1.0, 0.0, 0.0);  // Red cylinder at origin

    m_Renderer->SetBackground(colors->GetColor3d("SteelBlue").GetData());
    return vtk;
}