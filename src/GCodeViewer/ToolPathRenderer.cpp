#include "ToolPathRenderer.h"

#include <vtkMath.h>
#include <vtkProperty.h>
#include <vtkTransform.h>
#include <vtkTransformPolyDataFilter.h>
#include <vtkLineSource.h>
#include <vtkRegularPolygonSource.h>
#include <vtkArcSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkCylinderSource.h>

ToolPathRenderer::ToolPathRenderer() {
        m_Renderer = vtkSmartPointer<vtkRenderer>::New();
        m_RenderWindow = vtkSmartPointer<vtkRenderWindow>::New();
        m_RenderWindow->AddRenderer(m_Renderer);
        m_Interactor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
        m_Interactor->SetRenderWindow(m_RenderWindow);
}

void ToolPathRenderer::AddLine(double startPoint[3], double endPoint[3], int lineNumber, bool green) {
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
            lineActor->GetProperty()->SetColor(0, 0, 0); // Set color to black
        }
        m_Renderer->AddActor(lineActor);
        m_Primitives.push_back({lineNumber, lineActor});
}

void ToolPathRenderer::AddCircle(double center[3], double radius, double normal[3], int lineNumber) {
        vtkSmartPointer<vtkRegularPolygonSource> circleSource = vtkSmartPointer<vtkRegularPolygonSource>::New();
        circleSource->SetNumberOfSides(50); // Adjust the number of sides for smoothness
        circleSource->SetRadius(radius);
        circleSource->SetCenter(center);
        vtkSmartPointer<vtkPolyDataMapper> circleMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
        circleMapper->SetInputConnection(circleSource->GetOutputPort());
        vtkSmartPointer<vtkActor> circleActor = vtkSmartPointer<vtkActor>::New();
        circleActor->SetMapper(circleMapper);
        circleActor->GetProperty()->SetRepresentationToWireframe(); // Render only the wireframe
        circleActor->GetProperty()->SetColor(0, 0, 0); // Set outline color (black)
        m_Renderer->AddActor(circleActor);
        m_Primitives.push_back({lineNumber, circleActor});
}

void ToolPathRenderer::AddArc(double center[3], double radius, double startAngle, double endAngle, double normal[3], int lineNumber) {
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

    AddLine(startPoint, endPoint, lineNumber);
}

void ToolPathRenderer::AddToolTip(double diameter, double height, double tipX, double tipY, double tipZ, double tipOrientation[3]) {
    // Create a cylinder
    vtkSmartPointer<vtkCylinderSource> cylinder = vtkSmartPointer<vtkCylinderSource>::New();
    cylinder->SetRadius(diameter / 2.0);
    cylinder->SetHeight(height);
    cylinder->SetResolution(50); // Set a higher resolution for smoother appearance

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
        actor->GetProperty()->SetColor(1.0, 0.0, 0.0); // red

        // Add the actor to the renderer
        m_Renderer->AddActor(actor);
}

void ToolPathRenderer::AddAxesActor() {

    m_AxesActor = vtkSmartPointer<vtkAxesActor>::New();
    // Customize appearance
    m_AxesActor->SetTotalLength(1.0, 1.0, 1.0); // Set total length of the axes
    m_AxesActor->SetCylinderRadius(0.02); // Set cylinder radius
    m_AxesActor->SetConeRadius(0.05); // Set cone radius
    m_AxesActor->SetAxisLabels(true); // Enable axis labels

    // Add axes actor to the renderer
    m_Renderer->AddActor(m_AxesActor);
}

void ToolPathRenderer::RemoveFirstPrimitive() {

  if (!m_Primitives.empty()) {
    m_Renderer->RemoveActor(m_Primitives.front().actor);
    m_Primitives.erase(m_Primitives.begin());
  }
}

void ToolPathRenderer::RemoveLastPrimitive() {

  if (!m_Primitives.empty()) {
    m_Renderer->RemoveActor(m_Primitives.back().actor);
    m_Primitives.pop_back();
  }
}