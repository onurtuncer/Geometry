#include <vector>
#include <vtkSmartPointer.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkAxesActor.h>
  
class ToolPathRenderer {

  struct Primitive {
    int lineNumber;
    vtkSmartPointer<vtkActor> actor;
  };

  public:
    explicit ToolPathRenderer();
    virtual ~ToolPathRenderer() = default;

    void AddLine(double startPoint[3], double endPoint[3], int lineNumber, bool green = false);
    void AddCircle(double center[3], double radius, double normal[3], int lineNumber);
    void AddArc(double center[3], double radius, double startAngle, double endAngle, double normal[3], int lineNumber);
    void AddToolTip(double diameter, double height, double tipX, double tipY, double tipZ, double tipOrientation[3]);
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
};