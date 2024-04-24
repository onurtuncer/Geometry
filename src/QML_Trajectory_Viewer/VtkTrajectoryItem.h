#ifndef VTKTRAJECTORYITEM_H
#define VTKTRAJECTORYITEM_H

#include <vector>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkAxesActor.h>
#include <vtkCamera.h>
#include <vtkActor.h>
#include <vtkSmartPointer.h>
#include <vtkPoints.h>
#include <vtkMatrix4x4.h>
#include <vtkLinearTransform.h>

#include "QQuickVtkItem.h"
// #include "MouseInteractorHighlightActor.h"

struct Primitive {
    vtkSmartPointer<vtkActor> actor;
  };


class VtkTrajectoryItem : public QQuickVtkItem{

    public:
     VtkTrajectoryItem(std::vector<vtkSharePointer<vtkActor>>& actors,
                       double toolDiameter,
                       double toolHeight,
                       double toolPosition,
                       double toolOrientation,
                       double toolColor,
                       double backGroundColor) : m_RenderWindow(nullptr), 
                                                 m_Renderer(nullptr),
                                                 m_ToolPathActors(actors),
                                                 m_ToolDiameter(toolDiameter),
                                                 m_ToolHeight(toolHeight),
                                                 m_ToolPosition(toolPosition),
                                                 m_ToolOrientation(toolOrientation),
                                                 m_ToolColor(toolColor),          
                                                 m_BackGroundColor(backGroundColor){/*empty*/} 
    
    vtkUserData initializeVTK(vtkRenderWindow* renderWindow) override;

    void UpdateToolTip();
   
    void SetBackGround() {

        if (!m_Renderer) {
          std::cerr << "Error: Renderer is not initialized." << std::endl;
          return;
        }
        m_Renderer->SetBackground(m_BackGroundColor);
    }
    void Render() {m_RenderWindow->Render();}
    // void StartInteractor() { m_Interactor->Start();}
    // void Terminate() {m_Interactor->TerminateApp();}

    void TurnOffAxisLabels() {m_AxesActor->AxisLabelsOff();}
    void TurnOnAxisLabels() {m_AxesActor->AxisLabelsOn();}

  private:
    void AddAxesActor();
    void AddCamera();
    void AddToolTip();
    void UpdateCamera();
    void UpdateToolPose();

  private:
    vtkSmartPointer<vtkRenderWindow> m_RenderWindow; 
    vtkSmartPointer<vtkRenderer>     m_Renderer; 
    int                              m_WindowWidth{320};
    int                              m_WindowHeight{240};   

    vtkSmartPointer<vtkRenderWindowInteractor> m_Interactor;

    std::vector<vtkSmartPointer<vtkActor>> m_Primitives;

    vtkSmartPointer<vtkAxesActor> m_AxesActor; 
    
    vtkSmartPointer<vtkCamera> m_Camera;
  
    vtkSmartPointer<vtkActor> m_ToolActor;
    double                    m_ToolDiameter;
    double                    m_ToolHeight;
    double                    m_ToolPosition;
    double                    m_ToolOrientation[3];
    double                    m_ToolColor[3];              
    double                    m_ToolPathColor[3];
    double                    m_BackGroundColor[3];
};

#endif // VTKTRAJECTORYITEM_H