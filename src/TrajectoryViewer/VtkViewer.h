#ifndef VTK_VIEWER_H
#define VTK_VIEWER_H

#include <QObject>
#include <vtkSmartPointer.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkCamera.h>
#include "QQuickVtkItem.h"

class VtkViewer : public QQuickVtkItem{

  Q_OBJECT

  public:
    
    explicit VtkViewer(QObject* parent = nullptr): QQuickVtkItem() {

      qDebug() << "VtkViewer constructor called";
      // Create the renderer
      m_Renderer = vtkSmartPointer<vtkRenderer>::New();
      // Create renderer window and set it inside the parent class
      setVTKRenderInstance(vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New());
      // Get the render window 
      auto instance = getVTKRenderInstance();  
      qDebug() << "Render instance =" << instance;  
      // Set up the rendering context
      vtkRenderWindow* renderWindow = vtkGenericOpenGLRenderWindow::SafeDownCast(instance);
      qDebug() << "Window ptr =" << renderWindow;
      
      renderWindow->AddRenderer(m_Renderer); 

      AddCamera();
    }

    auto Renderer() -> vtkSmartPointer<vtkRenderer> {return m_Renderer;}
    void Refresh() {this->scheduleRender();}
    void ChangeBackGroundColor(double r, double g, double b) {

        m_Renderer->SetBackground(r, g, b);
        Refresh();
    }

  private:
    void AddCamera(){

      m_Camera = vtkSmartPointer<vtkCamera>::New();
      m_Renderer->SetActiveCamera(m_Camera);  
    }
    
    vtkUserData initializeVTK(vtkRenderWindow* renderWindow) override;

  private:
   vtkSmartPointer<vtkRenderer>   m_Renderer;
   vtkSmartPointer<vtkCamera>     m_Camera;
};

#endif // VTK_VIEWER_H