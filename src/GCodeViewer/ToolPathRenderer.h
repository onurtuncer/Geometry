#include <vector>
#include <vtkSmartPointer.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkAxesActor.h>
#include <vtkActor.h>
  
class ToolPathRenderer {

  struct Primitive {
    int lineNumber;
    vtkSmartPointer<vtkActor> actor;
  };

  public:
    explicit ToolPathRenderer();
    virtual ~ToolPathRenderer();

    void AddLine(double startPoint[3], double endPoint[3], int lineNumber, bool green = false);
    void AddCircle(double center[3], double radius, double normal[3], int lineNumber);
    void AddArc(double center[3], double radius, double startAngle, double endAngle, double normal[3], int lineNumber);
    void AddPolyline(const std::vector<std::array<double, 3>>& points, int lineNumber);
    void AddPointsToPolyline(const std::vector<std::array<double, 3>>& additionalPoints, int lineNumber);
    void AddToolTip(double diameter, double height, double tipPosition[3], double tipOrientation[3]);
    void UpdateToolTip(double tipPosition[3], double tipOrientation[3]);
    void AddAxesActor();

    void RemoveFirstPrimitive();
    void RemoveLastPrimitive();

    void SetBackGround() {m_Renderer->SetBackground(1, 1, 1);} // white
    void Render() {m_RenderWindow->Render();}
    void StartInteractor() { m_Interactor->Start();}
    void Terminate() {m_Interactor->TerminateApp();}

  private:
    vtkSmartPointer<vtkRenderer> m_Renderer;
    vtkSmartPointer<vtkRenderWindow> m_RenderWindow;
    vtkSmartPointer<vtkRenderWindowInteractor> m_Interactor;
    std::vector<Primitive> m_Primitives;
    vtkSmartPointer<vtkAxesActor> m_AxesActor;
    vtkSmartPointer<vtkActor> m_ToolTipActor;
};