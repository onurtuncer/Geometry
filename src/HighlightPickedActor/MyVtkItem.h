#ifndef MYVTKITEM_H
#define MYVTKITEM_H

#include <QObject>
#include <vtkSmartPointer.h>
#include <vtkConeSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkProperty.h>
#include <vtkRenderer.h>

#include <vtkGenericOpenGLRenderWindow.h>

#include "QQuickVtkItem.h"

class MyVtkItem : public QQuickVtkItem
{
     Q_OBJECT
public:
    
    explicit MyVtkItem(QObject* parent = nullptr): QQuickVtkItem() {

        qDebug() << "MyVtkItem constructor called";

        // Create the cone source and mapper
        m_coneSource = vtkSmartPointer<vtkConeSource>::New();
        m_coneMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
        m_coneMapper->SetInputConnection(m_coneSource->GetOutputPort());

        // Create the cone actor and set its properties
        m_coneActor = vtkSmartPointer<vtkActor>::New();
        m_coneActor->SetMapper(m_coneMapper);
        m_coneActor->GetProperty()->SetColor(1.0, 0.0, 0.0); // Red color

        // Add the cone actor to the renderer
        m_renderer = vtkSmartPointer<vtkRenderer>::New();
        m_renderer->AddActor(m_coneActor);

        setVTKRenderInstance(vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New());

        auto instance = getVTKRenderInstance();

        qDebug() << "Render instance =" << instance;

    // Set up the rendering context
        vtkRenderWindow* renderWindow = vtkGenericOpenGLRenderWindow::SafeDownCast(instance);
        qDebug() << "Window ptr =" << renderWindow;
        auto renderers = renderWindow->GetRenderers();

        renderWindow->AddRenderer(m_renderer); // Check if this needs to be replaced with a raw pointer

        m_renderer->SetBackground(0.0, 0.0, 0.0);
        m_renderer->SetBackground2(0.7, 0.7, 0.7);
        m_renderer->SetGradientBackground(true);
    }

    vtkUserData initializeVTK(vtkRenderWindow *renderWindow) override;
private:
   vtkSmartPointer<vtkConeSource>     m_coneSource;
   vtkSmartPointer<vtkPolyDataMapper> m_coneMapper;
   vtkSmartPointer<vtkActor>          m_coneActor;
   vtkSmartPointer<vtkRenderer>       m_renderer;
};

#endif // MYVTKITEM_H
