
#include <vtkMath.h>
#include <vtkProperty.h>
#include <vtkTransform.h>
#include <vtkTransformPolyDataFilter.h>
#include <vtkLineSource.h>
#include <vtkRegularPolygonSource.h>
#include <vtkArcSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkCylinderSource.h>

#include <vtkPolyLine.h>
#include <vtkPoints.h>
#include <vtkCellArray.h>
#include <vtkPolyData.h>

#include <vtkBoundingBox.h>


#include "ToolPathRenderer.h"

ToolPathRenderer::ToolPathRenderer() {

        m_Renderer = vtkSmartPointer<vtkRenderer>::New();
        m_RenderWindow = vtkSmartPointer<vtkRenderWindow>::New();
        m_RenderWindow->AddRenderer(m_Renderer);
        m_Interactor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
        m_Interactor->SetRenderWindow(m_RenderWindow);

        AddCamera();
        AddAxesActor();
        AddToolTip();       
        UpdateCamera();      
        SetBackGround();
}

ToolPathRenderer::~ToolPathRenderer() {
    // Remove all actors from the renderer
    m_Renderer->RemoveAllViewProps();

    // Reset the smart pointers to release the memory
    m_Renderer = nullptr;
    m_RenderWindow = nullptr;
    m_Interactor = nullptr;
    m_Primitives.clear(); // Clear the vector of primitives
    m_AxesActor = nullptr;
    m_ToolActor = nullptr;
    m_Camera = nullptr;
}

void ToolPathRenderer::AddCamera(){

  m_Camera = vtkSmartPointer<vtkCamera>::New();
  m_Renderer->SetActiveCamera(m_Camera);  
}

void ToolPathRenderer::AddLine(double startPoint[3], double endPoint[3], bool green) {

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
    m_Renderer->AddActor(lineActor);
    UpdateCamera();
    m_Primitives.push_back({lineActor});
}

void ToolPathRenderer::AddCircle(double center[3], double radius, double normal[3]) {

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


void ToolPathRenderer::AddArc(double center[3], double start[3], double end[3], double normal[3]) {
   
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

void ToolPathRenderer::AddToolTip() {
      
  if (!m_ToolActor) {
    // Create a cylinder
    vtkSmartPointer<vtkCylinderSource> cylinder = vtkSmartPointer<vtkCylinderSource>::New();
    cylinder->SetRadius(m_ToolDiameter / 2.0);
    cylinder->SetHeight(m_ToolHeight);
    cylinder->SetResolution(50); // Set a higher resolution for smoother appearance
    // Create mapper
    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(cylinder->GetOutputPort());
    // Create actor
    m_ToolActor = vtkSmartPointer<vtkActor>::New();
    m_ToolActor->SetMapper(mapper);
    // Set the color of the actor to red
    m_ToolActor->GetProperty()->SetColor(1.0, 0.0, 0.0); // Red
    // m_ToolActor->GetProperty()->SetColor(m_ToolColor[0], m_ToolColor[1], m_ToolColor[2]); 
    m_Renderer->AddActor(m_ToolActor); // Add the actor to the renderer
  }
    // Update tooltip position and orientation
    vtkSmartPointer<vtkTransform> transform = vtkSmartPointer<vtkTransform>::New();
    transform->Translate(m_ToolPosition);
    // Calculate the rotation angles from the tip orientation vector
    double angleX = atan2(m_ToolOrientation[1], m_ToolOrientation[2]) * 180.0 / vtkMath::Pi();
    double angleY = atan2(-m_ToolOrientation[0], sqrt(m_ToolOrientation[1] * m_ToolOrientation[1] + m_ToolOrientation[2] * m_ToolOrientation[2])) * 180.0 / vtkMath::Pi();
    transform->RotateWXYZ(angleX, 1.0, 0.0, 0.0);
    transform->RotateWXYZ(angleY, 0.0, 1.0, 0.0);
    m_ToolActor->SetUserTransform(transform);
}

void ToolPathRenderer::UpdateToolTip() {

  if (m_ToolActor) {
        vtkSmartPointer<vtkTransform> transform = vtkSmartPointer<vtkTransform>::New();
        transform->Translate(m_ToolPosition);


        // Calculate the rotation angles to align the tool orientation with the Z-axis
        double angleX = atan2(m_ToolOrientation[1], m_ToolOrientation[2]) * 180.0 / vtkMath::Pi();
        double angleY = atan2(-1.0* m_ToolOrientation[0], sqrt(m_ToolOrientation[1] * m_ToolOrientation[1] + m_ToolOrientation[2] * m_ToolOrientation[2])) * 180.0 / vtkMath::Pi();

        // Apply the rotations
        transform->RotateWXYZ(angleX, 1.0, 0.0, 0.0);
        transform->RotateWXYZ(angleY, 0.0, 1.0, 0.0);

        // Set the user transform to the tool actor
        m_ToolActor->SetUserTransform(transform);

        // Update camera (optional, depending on your requirements)
        UpdateCamera();
    }
    
}

void ToolPathRenderer::AddPolyline(vtkSmartPointer<vtkPoints> points) {
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


void ToolPathRenderer::AddPointsToPolyline(const std::vector<std::array<double, 3>>& additionalPoints) {

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

/* void ToolPathRenderer::RemovePointsFromFrontOfPolyLine(vtkSmartPointer<vtkActor> polylineActor, int numPointsToRemove) {

    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkPolyDataMapper::SafeDownCast(polylineActor->GetMapper());
    if (!mapper) {
        std::cerr << "Failed to get mapper from the polyline actor." << std::endl;
        return;
    }

    vtkSmartPointer<vtkPolyData> polydata = vtkPolyData::SafeDownCast(mapper->GetInput());
    if (!polydata) {
        std::cerr << "Failed to get input polydata from the mapper." << std::endl;
        return;
    }

    vtkSmartPointer<vtkPoints> points = polydata->GetPoints();
    if (!points) {
        std::cerr << "Failed to get points from the polydata." << std::endl;
        return;
    }

    if (numPointsToRemove >= points->GetNumberOfPoints()) {
        // Remove all points if the number of points to remove is greater than or equal to the current size
        points->Reset();
    } else {
        // Remove the specified number of points from the front of the polyline
        for (int i = 0; i < numPointsToRemove; ++i) {
            points->DeletePoint(i);
        }
        points->Squeeze(); // Remove deleted points from memory
    }

    // Update the actor
    mapper->Update();
    polylineActor->Modified();
} */


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

// void UpdateBoundingBox(double* sceneBoundingBox, vtkSmartPointer<vtkActor> actor) {

//     vtkSmartPointer<vtkBoundingBox> sceneBBox = vtkSmartPointer<vtkBoundingBox>::New();
//     actor->GetBounds(sceneBBox);

//     double actorBounds[6];
//     sceneBBox->GetBounds(actorBounds);

//     bool needUpdate = false;
//     for (int i = 0; i < 3; ++i) {
//         if (actorBounds[i] < sceneBoundingBox[i]) {
//             sceneBoundingBox[i] = actorBounds[i];
//             needUpdate = true;
//         }
//         if (actorBounds[i+3] > sceneBoundingBox[i+3]) {
//             sceneBoundingBox[i+3] = actorBounds[i+3];
//             needUpdate = true;
//         }
//     }

//     if (needUpdate) {
//         // Adjust scene bounding box if necessary
//         for (int i = 0; i < 6; ++i) {
//             sceneBBox[i] = sceneBoundingBox[i];
//         }
//     }
// }

void ToolPathRenderer::UpdateCamera() {
    
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