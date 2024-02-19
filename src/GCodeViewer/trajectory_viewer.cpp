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
    double normal[3] = {0.0, 0.0, 1.0}; // Example normal vector pointing in the z-direction
    vtkSmartPointer<vtkActor> circle = createCircle(center, radius, normal);
    
    // Create arc
    double normal2[3] = {0.0, 1.0, 0.0}; // Example normal vector pointing in the y-direction
    vtkSmartPointer<vtkActor> arc = createArc(center, radius, startAngle, endAngle, normal2);

    // Create renderer and add geometric primitives
    vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor(lineSegment);
    renderer->AddActor(circle);
    renderer->AddActor(arc);

    // Create cylinder
    double tipOrientation[3] = {0.707, 0.707, 0.0}; // Example: pointing in the X direction
    renderCylinderWithPoseAndColor(renderer, 0.2, 3.0, 1.0, 1.0, 1.0, tipOrientation, 1.0, 0.0, 0.0);  // Red cylinder at origin

    // Create render window and interactor
    vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
    renderWindow->AddRenderer(renderer);

    vtkSmartPointer<vtkRenderWindowInteractor> interactor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    interactor->SetRenderWindow(renderWindow);

    // Set background color and start rendering
    renderer->SetBackground(1.0, 1.0, 1.0);  // Set background color to white
    renderWindow->Render();
    interactor->Start();
    
    return 0;
}