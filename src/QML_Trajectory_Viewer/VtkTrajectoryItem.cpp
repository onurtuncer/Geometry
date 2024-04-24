
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

#include "VtkTrajectoryItem.h"


 void VtkTrajectoryItem::AddCamera(){

  m_Camera = vtkSmartPointer<vtkCamera>::New();
  std::lock_guard<std::mutex> lock(mutex); // Lock mutex before modifying m_Renderer
  m_Renderer->SetActiveCamera(m_Camera);  
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
 
    // Set the custom type to use for interaction.
    // vtkNew<MouseInteractorHighLightActor> style;
    // style->SetDefaultRenderer(m_Renderer);

    // renderWindow->GetInteractor()->SetInteractorStyle(style); // This causes QSocket to crash... I do not know why.
   
    AddCamera();
    AddAxesActor();
    AddToolTip();       
    UpdateCamera();
    SetBackGround();

    // Loop through m_Primitives and add them to m_Renderer
    for (const auto& primitive : m_Primitives) {
        qDebug() << "Adding actor";
        m_Renderer->AddActor(primitive);
    }

    return vtk;
}