/* ----------------------------------------------------------------------------*
  Copyright 2024 MILTEKSAN

  Written by Melina Aero, Istanbul, Turkey
  Contact onur.tuncer@melina-aero.com
-------------------------------------------------------------------------------*/

#include <vtkSmartPointer.h>
#include <vtkActor.h>
#include <vtkAlgorithmOutput.h> 
#include <vtkLineSource.h>
#include <vtkRegularPolygonSource.h>
#include <vtkArcSource.h>
#include <vtkCylinderSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkMath.h>
#include <vtkProperty.h>
#include <vtkTransform.h> 

#include "TrajectoryViewer.h"
#include "VtkViewer.h"

TrajectoryViewer::TrajectoryViewer(QObject* parent) : QObject(parent), m_Viewer(nullptr) {
   
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

void TrajectoryViewer::SetToolPosition(const double (&position)[3]) {

    std::copy(position, position + 3, m_ToolPosition);
}

void TrajectoryViewer::SetToolOrientation(const double i, const double j, const double k) {

    m_ToolOrientation[0] = i;
    m_ToolOrientation[1] = j;
    m_ToolOrientation[2] = k;
}

void TrajectoryViewer::SetToolOrientation(const double (&orientation)[3]) {

    std::copy(orientation, orientation + 3, m_ToolOrientation);
}

void TrajectoryViewer::SetToolColor(const double r, const double g, const double b) {

    m_ToolColor[0] = r;
    m_ToolColor[1] = g;
    m_ToolColor[2] = b;
}

void TrajectoryViewer::SetToolPathColor(const double r, const double g, const double b) {

    m_ToolPathColor[0] = r;
    m_ToolPathColor[1] = g;
    m_ToolPathColor[2] = b;
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

void TrajectoryViewer::SetBackGround(const double r, const double g, const double b){
    
    if(m_Viewer){
       m_Viewer->SetBackGround(r, g, b);
    } else{
        qWarning("Viewer is not initialized");
    }
}

void TrajectoryViewer::SetBackGround2(const double r, const double g, const double b){
    
    if(m_Viewer){
       m_Viewer->SetBackGround2(r, g, b);
    } else{
        qWarning("Viewer is not initialized");
    }
}

 void TrajectoryViewer::SetGradientBackground(bool value){

    if(m_Viewer){
       m_Viewer->SetGradientBackground(value);
    } else{
        qWarning("Viewer is not initialized");
    }
 }

void TrajectoryViewer::ShowAxes(){

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

void TrajectoryViewer::HideAxes(){

    if(m_Viewer  && m_AxesActor){
       m_Viewer->Renderer()->RemoveActor(m_AxesActor);
    //    m_AxesActor = nullptr;
    } else{
        qWarning("Viewer is not initialized");
    }
}

void TrajectoryViewer::ShowTool(){

    if(m_Viewer){

        if (!m_ToolActor) {

          CreateToolActor();
        }
    } else{

        qWarning("Viewer is not initialized");
    }
}

void TrajectoryViewer::HideTool(){

    if(m_Viewer){

        if (m_ToolActor) {

          m_Viewer->Renderer()->RemoveActor(m_ToolActor);
        }
    } else{

        qWarning("Viewer is not initialized");
    }
}

void TrajectoryViewer::UpdateToolTip() {

    if (m_ToolActor) {

      UpdateToolPose();
      UpdateCamera();
   } 

}

void TrajectoryViewer::AddLine(double startPoint[3], double endPoint[3], bool green) {

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
    m_Viewer->Renderer()->AddActor(lineActor);
    UpdateCamera();
}

void TrajectoryViewer::AddCircle(double center[3], double radius, double normal[3]) {

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

    m_Viewer->Renderer()->AddActor(circleActor);
    UpdateCamera();
}


void TrajectoryViewer::AddArc(double center[3], double start[3], double end[3], double normal[3]) {
   
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
    m_Viewer->Renderer()->AddActor(actor);
}

void TrajectoryViewer::UpdateCamera() {
    
    double bounds[6];
    double center[3];

    m_Viewer->Renderer()->ComputeVisiblePropBounds(bounds);

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
    m_Viewer->Renderer()->GetActiveCamera()->SetPosition(cameraPosition);
    m_Viewer->Renderer()->GetActiveCamera()->SetFocalPoint(focalPoint);   
    m_Viewer->Renderer()->ResetCameraClippingRange(); // Adjusts the clipping range of the camera  
} 