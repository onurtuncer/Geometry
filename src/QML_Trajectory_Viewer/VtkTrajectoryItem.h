#ifndef VTKTRAJECTORYITEM_H
#define VTKTRAJECTORYITEM_H

#include <vtkRenderer.h>
#include <vtkRenderWindow.h>

#include "QQuickVtkItem.h"

class VtkTrajectoryItem : public QQuickVtkItem{
  public:
    public:
    VtkTrajectoryItem() : m_RenderWindow(nullptr), 
                          m_Renderer(nullptr) {/*empty*/} // Constructor to initialize the member variable
    vtkUserData initializeVTK(vtkRenderWindow* renderWindow) override;

  private:
    vtkSmartPointer<vtkRenderWindow> m_RenderWindow; 
    vtkSmartPointer<vtkRenderer>     m_Renderer; // Member variable to store the renderer pointer

};

#endif // VTKTRAJECTORYITEM_H
