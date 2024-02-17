#include <vtkSmartPointer.h>
#include <vtkPoints.h>
#include <vtkCellArray.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkLineSource.h>
#include <vtkArcSource.h>
#include <vtkRegularPolygonSource.h>
#include <vtkMath.h>
#include <vtkProperty.h>


vtkSmartPointer<vtkActor> createLineSegment(double startPoint[3], double endPoint[3]) {
    vtkSmartPointer<vtkLineSource> lineSource = vtkSmartPointer<vtkLineSource>::New();
    lineSource->SetPoint1(startPoint);
    lineSource->SetPoint2(endPoint);
    
    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(lineSource->GetOutputPort());
    
    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);
    
    // Set actor properties
    actor->GetProperty()->SetColor(0, 0, 0); // Set color to black
    
    return actor;
}

// Function to create a circle given center and radius
vtkSmartPointer<vtkActor> createCircle(double center[3], double radius) {
    vtkSmartPointer<vtkRegularPolygonSource> circleSource = vtkSmartPointer<vtkRegularPolygonSource>::New();
    circleSource->SetNumberOfSides(50); // Adjust the number of sides for smoothness
    circleSource->SetRadius(radius);
    circleSource->SetCenter(center);
    
    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(circleSource->GetOutputPort());
    
    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);
    
    // Set actor properties
    actor->GetProperty()->SetRepresentationToWireframe(); // Render only the wireframe
    actor->GetProperty()->SetColor(0, 0, 0); // Set outline color (black)
    
    return actor;
}

// Function to create an arc given center, radius, start angle, and end angle
vtkSmartPointer<vtkActor> createArc(double center[3], double radius, double startAngle, double endAngle) {
    vtkSmartPointer<vtkArcSource> arcSource = vtkSmartPointer<vtkArcSource>::New();
    arcSource->SetCenter(center);
    arcSource->SetResolution(100); // Adjust resolution as needed
    
    // Convert angles from degrees to radians
    startAngle = vtkMath::RadiansFromDegrees(startAngle);
    endAngle = vtkMath::RadiansFromDegrees(endAngle);
    
    // Set polar vectors for start and end angles
    arcSource->SetPolarVector(std::cos(startAngle), std::sin(startAngle), 0); // Set start angle
    arcSource->SetPolarVector(std::cos(endAngle), std::sin(endAngle), 0); // Set end angle
    
    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(arcSource->GetOutputPort());
    
    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);
    
    // Set actor properties
    actor->GetProperty()->SetColor(0, 0, 0); // Set color to black
    
    return actor;
}

// Function to display geometric primitives
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

int main(int argc, char* argv[]) {
    // Example geometric primitives
    double startPoint[3] = {0, 0, 0};
    double endPoint[3] = {1, 1, 1};
    double center[3] = {0, 0, 0};
    double radius = 1.0;
    double startAngle = 0.0;
    double endAngle = 90.0;
    
    // Create line segment
    vtkSmartPointer<vtkActor> lineSegment = createLineSegment(startPoint, endPoint);
    
    // Create circle
    vtkSmartPointer<vtkActor> circle = createCircle(center, radius);
    
    // Create arc
    vtkSmartPointer<vtkActor> arc = createArc(center, radius, startAngle, endAngle);
    
    // Display geometric primitives
    std::vector<vtkSmartPointer<vtkActor>> primitives;
    primitives.push_back(lineSegment);
    primitives.push_back(circle);
    primitives.push_back(arc);
    
    displayGeometricPrimitives(primitives);
    
    return 0;
}
