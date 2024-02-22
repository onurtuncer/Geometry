#include <vtkSmartPointer.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkLineSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkTextActor.h>
#include <vtkTextProperty.h>
#include <vtkProperty.h>
#include <vtkMath.h>

void drawWitnessLinesAndDimensions(vtkSmartPointer<vtkRenderer> renderer, double bounds[6]) {
    double minX = bounds[0], maxX = bounds[1];
    double minY = bounds[2], maxY = bounds[3];
    double minZ = bounds[4], maxZ = bounds[5];

    // Create line sources for witness lines
    vtkSmartPointer<vtkLineSource> lineSourceX = vtkSmartPointer<vtkLineSource>::New();
    lineSourceX->SetPoint1(minX, minY, minZ);
    lineSourceX->SetPoint2(maxX, minY, minZ);

    vtkSmartPointer<vtkLineSource> lineSourceY = vtkSmartPointer<vtkLineSource>::New();
    lineSourceY->SetPoint1(minX, minY, minZ);
    lineSourceY->SetPoint2(minX, maxY, minZ);

    vtkSmartPointer<vtkLineSource> lineSourceZ = vtkSmartPointer<vtkLineSource>::New();
    lineSourceZ->SetPoint1(minX, minY, minZ);
    lineSourceZ->SetPoint2(minX, minY, maxZ);

    // Create mappers and actors for witness lines
    vtkSmartPointer<vtkPolyDataMapper> mapperX = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapperX->SetInputConnection(lineSourceX->GetOutputPort());

    vtkSmartPointer<vtkActor> actorX = vtkSmartPointer<vtkActor>::New();
    actorX->SetMapper(mapperX);
    actorX->GetProperty()->SetColor(1, 0, 0); // Red color

    vtkSmartPointer<vtkPolyDataMapper> mapperY = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapperY->SetInputConnection(lineSourceY->GetOutputPort());

    vtkSmartPointer<vtkActor> actorY = vtkSmartPointer<vtkActor>::New();
    actorY->SetMapper(mapperY);
    actorY->GetProperty()->SetColor(0, 1, 0); // Green color

    vtkSmartPointer<vtkPolyDataMapper> mapperZ = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapperZ->SetInputConnection(lineSourceZ->GetOutputPort());

    vtkSmartPointer<vtkActor> actorZ = vtkSmartPointer<vtkActor>::New();
    actorZ->SetMapper(mapperZ);
    actorZ->GetProperty()->SetColor(0, 0, 1); // Blue color

    // Add witness line actors to the renderer
    renderer->AddActor(actorX);
    renderer->AddActor(actorY);
    renderer->AddActor(actorZ);

   // Add dimension labels
vtkSmartPointer<vtkTextActor> textActorX = vtkSmartPointer<vtkTextActor>::New();
textActorX->SetInput("X");
textActorX->GetTextProperty()->SetColor(1, 0, 0); // Red color
// textActorX->GetTextProperty()->SetTextScaleModeToNone(); // Disable text scaling
textActorX->GetTextProperty()->SetFontSize(24); // Set the font size
textActorX->SetPosition((maxX + minX) / 2.0, minY);

vtkSmartPointer<vtkTextActor> textActorY = vtkSmartPointer<vtkTextActor>::New();
textActorY->SetInput("Y");
textActorY->GetTextProperty()->SetColor(0, 1, 0); // Green color
// textActorY->GetTextProperty()->SetTextScaleModeToNone(); // Disable text scaling
textActorY->GetTextProperty()->SetFontSize(40); // Set the font size
textActorY->SetPosition(minX + 10, (maxY + minY) / 2.0);

vtkSmartPointer<vtkTextActor> textActorZ = vtkSmartPointer<vtkTextActor>::New();
textActorZ->SetInput("Z");
textActorZ->GetTextProperty()->SetColor(0, 0, 1); // Blue color
// textActorZ->GetTextProperty()->SetTextScaleModeToNone(); // Disable text scaling
textActorZ->GetTextProperty()->SetFontSize(24); // Set the font size
textActorZ->SetPosition(minX, minY);

    // Add dimension label actors to the renderer
    renderer->AddActor2D(textActorX);
    renderer->AddActor2D(textActorY);
    renderer->AddActor2D(textActorZ);
}

int main(int argc, char* argv[]) {
    // Create renderer, render window, and interactor
    vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
    vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
    renderWindow->AddRenderer(renderer);
    vtkSmartPointer<vtkRenderWindowInteractor> interactor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    interactor->SetRenderWindow(renderWindow);

    // Set renderer background color
    renderer->SetBackground(1, 1, 1); // White

    // Set bounding box dimensions
    double bounds[6] = {-10, 10, -20, 20, -30, 30};

    // Draw witness lines and dimensions
    drawWitnessLinesAndDimensions(renderer, bounds);

    // Start interaction
    renderWindow->Render();
    interactor->Start();

    return 0;
}


