#include <vector>
#include <vtkSmartPointer.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkAxesActor.h>
#include <vtkActor.h>
#include <vtkCamera.h>
#include <vtkPoints.h>
  
class ToolPathRenderer {

  struct Primitive {
    vtkSmartPointer<vtkActor> actor;
  };

  public:
    explicit ToolPathRenderer();
    virtual ~ToolPathRenderer();

    void AddLine(double startPoint[3], double endPoint[3], bool green = false);
    void AddCircle(double center[3], double radius, double normal[3]);
    void AddArc(double center[3], double start[3], double end[3], double normal[3]);
    void AddPolyline(vtkSmartPointer<vtkPoints> points);
    void AddPointsToPolyline(const std::vector<std::array<double, 3>>& additionalPoints);
    // void RemovePointsFromFrontOfPolyLine(vtkSmartPointer<vtkActor> polylineActor, int numPointsToRemove);

    void SetToolDiameter(double diameter) {m_ToolDiameter = diameter;}
    void SetToolHeight(double height) {m_ToolHeight = height;}

   void SetToolPosition(double position[3]){ 
    
    for (int i = 0; i < 3; ++i) {
      m_ToolPosition[i] = position[i];
    }
   }

   void SetToolOrientation(double orientation[3]){ 
   
    for (int i = 0; i < 3; ++i) {
      m_ToolOrientation[i] = orientation[i];
    }
   }

   void SetToolColor(double color[3]){

    for (int i = 0; i < 3; ++i) {
      m_ToolColor[i] = color[i];
    }
   }

    void UpdateToolTip();
   
    void RemoveFirstPrimitive();
    void RemoveLastPrimitive();

    void SetBackGround() {m_Renderer->SetBackground(m_BackGroundColor);} // white
    void Render() {m_RenderWindow->Render();}
    void StartInteractor() { m_Interactor->Start();}
    void Terminate() {m_Interactor->TerminateApp();}

    void TurnOffAxisLabels() {m_AxesActor->AxisLabelsOff();}
    void TurnOnAxisLabels() {m_AxesActor->AxisLabelsOn();}

  private:
    void AddAxesActor();
    void AddCamera();
    void AddToolTip();
    void UpdateCamera();

  private:
    vtkSmartPointer<vtkRenderer> m_Renderer;
    vtkSmartPointer<vtkRenderWindow> m_RenderWindow;
    vtkSmartPointer<vtkRenderWindowInteractor> m_Interactor;

    std::vector<Primitive> m_Primitives;

    vtkSmartPointer<vtkAxesActor> m_AxesActor; 
    
    vtkSmartPointer<vtkCamera> m_Camera;
  
    vtkSmartPointer<vtkActor> m_ToolActor;
    double                    m_ToolDiameter{0.15};
    double                    m_ToolHeight{1.5};
    double                    m_ToolPosition[3] = {0, 0, 0};
    double                    m_ToolOrientation[3] = {0, 0, 1.0};
    double                    m_ToolColor[3] = {1.0, 0.0, 0.0};              
    double                    m_ToolPathColor[3] = {1, 1, 1};
    double                    m_BackGroundColor[3] = {0, 0, 0};
};