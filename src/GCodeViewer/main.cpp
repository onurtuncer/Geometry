#include <thread>
#include <chrono>
#include "ToolPathRenderer.h"

int main(int argc, char* argv[]) {

    ToolPathRenderer toolPathRenderer;

    // Example line
    double startPointLine[3] = {0, 0, 0};
    double endPointLine[3] = {1, 1, 1};
    int lineNumberLine = 1; // Example line number
    toolPathRenderer.AddLine(startPointLine, endPointLine, lineNumberLine);

    toolPathRenderer.SetBackGround();
    toolPathRenderer.AddAxesActor();
    toolPathRenderer.Render();
   
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Wait for 2 seconds

    // Example green line
    double startPointGreenLine[3] = {0, 1, 0};
    double endPointGreenLine[3] = {1, 1, 0};
    int lineNumberGreenLine = 2; // Example line number
    toolPathRenderer.AddLine(startPointGreenLine, endPointGreenLine, lineNumberGreenLine, true);
    toolPathRenderer.Render();
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Wait for 2 seconds

    // Example circle
    double centerCircle[3] = {0, 0, 0};
    double normalCircle[3] = {0, 0, 1};
    double radiusCircle = 1.0;
    int lineNumberCircle = 3; // Example line number
    toolPathRenderer.AddCircle(centerCircle, radiusCircle, normalCircle, lineNumberCircle);
    toolPathRenderer.Render();
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Wait for 2 seconds

    // Example arc
    double centerArc[3] = {0, 0, 0};
    double normalArc[3] = {0, 0, 1};
    double radiusArc = 1.0;
    double startAngleArc = 0.0;
    double endAngleArc = 90.0;
    int lineNumberArc = 4; // Example line number
    toolPathRenderer.AddArc(centerArc, radiusArc, startAngleArc, endAngleArc, normalArc, lineNumberArc);

     // Create cylinder
    double tipOrientation[3] = {0.707, 0.707, 0.0}; // Example: pointing in the X direction
    toolPathRenderer.AddToolTip(0.2, 3.0, 1.0, 1.0, 1.0, tipOrientation);  // Red cylinder at origin

    toolPathRenderer.Render();

    std::this_thread::sleep_for(std::chrono::seconds(2)); // Wait for 2 seconds

    toolPathRenderer.StartInteractor();

    return 0;
}
