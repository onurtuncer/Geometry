#include <vtkSmartPointer.h>
#include <vtkActor.h>
#include <vtkAlgorithmOutput.h> 
#include <vtkCylinderSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkMath.h>
#include <vtkProperty.h>
#include <vtkTransform.h> 

#include "TrajectoryViewer.h"
#include "VtkViewer.h"

TrajectoryViewer::TrajectoryViewer(QObject* parent) : QObject(parent), m_Viewer(nullptr)/* , m_ToolDiameter(0.15), m_ToolHeight(0.1) */ {
   
    // m_ToolPosition[0] = 0;
    // m_ToolPosition[1] = 0;
    // m_ToolPosition[2] = 0;

    // m_ToolOrientation[0] = 0;
    // m_ToolOrientation[1] = 0;
    // m_ToolOrientation[2] = 1.0;

    // m_ToolColor[0] = 1.0;
    // m_ToolColor[1] = 0.0;
    // m_ToolColor[2] = 0.0;
}

void TrajectoryViewer::SetViewer(VtkViewer* viewer) {
    m_Viewer = viewer;
}

void TrajectoryViewer::SetToolDiameter(const double diameter) {
    m_ToolDiameter = diameter;
}

double TrajectoryViewer::GetToolDiameter() const {
    return m_ToolDiameter;
}

void TrajectoryViewer::SetToolHeight(const double height) {
    m_ToolHeight = height;
}

double TrajectoryViewer::GetToolHeight() const {
    return m_ToolHeight;
}

void TrajectoryViewer::SetToolPosition(const double x, const double y, const double z) {
    m_ToolPosition[0] = x;
    m_ToolPosition[1] = y;
    m_ToolPosition[2] = z;
}

void TrajectoryViewer::SetToolOrientation(const double i, const double j, const double k) {
    m_ToolOrientation[0] = i;
    m_ToolOrientation[1] = j;
    m_ToolOrientation[2] = k;
}

void TrajectoryViewer::SetToolColor(const double r, const double g, const double b) {
    m_ToolColor[0] = r;
    m_ToolColor[1] = g;
    m_ToolColor[2] = b;
}

const double* TrajectoryViewer::GetToolPosition() const {
    return m_ToolPosition;
}

const double* TrajectoryViewer::GetToolOrientation() const {
    return m_ToolOrientation;
}

const double* TrajectoryViewer::GetToolColor() const {
    return m_ToolColor;
}

void TrajectoryViewer::Clear() {
    // Clearing logic goes here
}

// void TrajectoryViewer::CreateToolActor() {
//     if (!m_ToolActor) {
//         auto cylinder = vtkSmartPointer<vtkCylinderSource>::New();
//         cylinder->SetRadius(m_ToolDiameter / 2.0);
//         cylinder->SetHeight(m_ToolHeight);
//         cylinder->SetResolution(50); 

//         vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
//         mapper->SetInputConnection(cylinder->GetOutputPort());

//         m_ToolActor = vtkSmartPointer<vtkActor>::New();
//         m_ToolActor->SetMapper(mapper);
//         m_ToolActor->GetProperty()->SetColor(m_ToolColor[0], m_ToolColor[1], m_ToolColor[2]); 

//         m_Viewer->Renderer()->AddActor(m_ToolActor);
//     } else {
//         vtkSmartPointer<vtkCylinderSource> cylinderSource = vtkSmartPointer<vtkCylinderSource>::New();
//         cylinderSource = vtkCylinderSource::SafeDownCast(m_ToolActor->GetMapper()->GetInputConnection(0)->GetProducer());
//         cylinderSource->SetRadius(m_ToolDiameter / 2.0);
//         cylinderSource->SetHeight(m_ToolHeight);

//         m_ToolActor->GetProperty()->SetColor(m_ToolColor[0], m_ToolColor[1], m_ToolColor[2]);
//         m_ToolActor->GetMapper()->Modified();
//     }

//     UpdateToolPose();
// }

void TrajectoryViewer::CreateToolActor() {

    if (!m_ToolActor) {
        auto cylinder = vtkSmartPointer<vtkCylinderSource>::New();
        cylinder->SetRadius(m_ToolDiameter / 2.0);
        cylinder->SetHeight(m_ToolHeight);
        cylinder->SetResolution(50); 

        vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
        mapper->SetInputConnection(cylinder->GetOutputPort());

        m_ToolActor = vtkSmartPointer<vtkActor>::New();
        m_ToolActor->SetMapper(mapper);
        m_ToolActor->GetProperty()->SetColor(m_ToolColor[0], m_ToolColor[1], m_ToolColor[2]); 

        m_Viewer->Renderer()->AddActor(m_ToolActor);
    } else {
        vtkSmartPointer<vtkCylinderSource> cylinderSource = vtkSmartPointer<vtkCylinderSource>::New();
        vtkAlgorithmOutput* output = m_ToolActor->GetMapper()->GetInputConnection(0, 0);
        cylinderSource = vtkCylinderSource::SafeDownCast(output->GetProducer());
        cylinderSource->SetRadius(m_ToolDiameter / 2.0);
        cylinderSource->SetHeight(m_ToolHeight);

        m_ToolActor->GetProperty()->SetColor(m_ToolColor[0], m_ToolColor[1], m_ToolColor[2]);
        m_ToolActor->GetMapper()->Modified();
    }

    UpdateToolPose();
}

void TrajectoryViewer::UpdateToolPose() {

    vtkMath::Normalize(m_ToolOrientation);
    double yAxis[3] = {0.0, 1.0, 0.0};

    double rotationAxis[3];
    vtkMath::Cross(m_ToolOrientation, yAxis, rotationAxis);
    double rotationAngle = vtkMath::DegreesFromRadians(acos(vtkMath::Dot(m_ToolOrientation, yAxis)));

    auto transform = vtkSmartPointer<vtkTransform>::New();
    transform->Translate(m_ToolPosition[0] + 0.5 * m_ToolHeight * m_ToolOrientation[0],
                         m_ToolPosition[1] + 0.5 * m_ToolHeight * m_ToolOrientation[1],
                         m_ToolPosition[2] + 0.5 * m_ToolHeight * m_ToolOrientation[2]);  

    transform->RotateWXYZ(rotationAngle, rotationAxis);

    m_ToolActor->SetUserTransform(transform);
}

void TrajectoryViewer::ChangeBackGroundColor(const double r, const double g, const double b){
    
    if(m_Viewer){
       m_Viewer->ChangeBackGroundColor(r, g, b);
    } else{
        qWarning("Viewer is not initialized");
    }
}

void TrajectoryViewer::AddAxisActor(){

    if(m_Viewer){

       m_AxesActor = vtkSmartPointer<vtkAxesActor>::New();
       m_AxesActor->SetTotalLength(1.0, 1.0, 1.0); // Set total length of the axes
       m_AxesActor->SetCylinderRadius(0.02); // Set cylinder radius
       m_AxesActor->SetConeRadius(0.05); // Set cone radius
       m_AxesActor->SetAxisLabels(true); // Enable axis labels
   
       m_Viewer->Renderer()->AddActor(m_AxesActor);
    } else{
        qWarning("Viewer is not initialized");
    }
}

void TrajectoryViewer::RemoveAxisActor(){

    if(m_Viewer  && m_AxesActor){
       m_Viewer->Renderer()->RemoveActor(m_AxesActor);
    //    m_AxesActor = nullptr;
    } else{
        qWarning("Viewer is not initialized");
    }
}