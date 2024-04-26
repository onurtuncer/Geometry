#include "pointcloud.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickVTKRenderItem.h>
#include <QQuickVTKRenderWindow.h>
#include <QDebug>

#include "vtkConeSource.h"
#include "vtkGenericOpenGLRenderWindow.h"
#include "vtkNew.h"
#include "vtkPolyDataMapper.h"
#include "vtkRenderer.h"
#include "vtkWindowToImageFilter.h"

int main(int argc, char *argv[]) {
  QQuickVTKRenderWindow::setupGraphicsBackend();
  QGuiApplication app(argc, argv);
  PointCloud cloud;
  // qmlRegisterType<QQuickVTKRenderWindow>("VTKPLUS", 9, 3, "VTKRenderWindow");
  // qmlRegisterType<QQuickVTKRenderItem>("VTKPLUS", 9, 3, "VTKRenderItem");
  qmlRegisterSingletonInstance<PointCloud>("PointCloud", 1, 0, "PointCloud",
                                           &cloud);
  QQmlApplicationEngine engine;
  const QUrl url(u"qrc:/VTKTest/main.qml"_qs);
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreated, &app,
      [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
          QCoreApplication::exit(-1);
      },
      Qt::QueuedConnection);
  engine.load(url);
  QObject *rootObject = engine.rootObjects()[0];
  auto *container = rootObject->findChild<QObject *>("container");
  QQuickVTKRenderItem* vtkRenderItem = container->findChild<QQuickVTKRenderItem*>("renderItem");

  // QQuickVTKRenderItem* vtkRenderItem = dynamic_cast<QQuickVTKRenderItem*>(renderItem);
  if (vtkRenderItem) {
    qDebug() << "Dynamic cast successful. Setting background and updating.";
    // vtkRenderItem->renderer()->SetBackground(0, 0, 0);
    // // Disable lighting in the renderer
    // vtkRenderItem->renderer()->SetLightFollowCamera(0);
    // vtkRenderItem->renderer()->RemoveAllLights();
    // vtkRenderItem->update();

    // Create a cone pipeline and add it to the view
    vtkNew<vtkActor> actor;
    vtkNew<vtkPolyDataMapper> mapper;
    vtkNew<vtkConeSource> cone;
    mapper->SetInputConnection(cone->GetOutputPort());
    actor->SetMapper(mapper);
    vtkRenderItem->renderer()->AddActor(actor);
    vtkRenderItem->renderer()->ResetCamera();
    vtkRenderItem->renderer()->SetBackground(0.5, 0.5, 0.7);
    vtkRenderItem->renderer()->SetBackground2(0.7, 0.7, 0.7);
    vtkRenderItem->renderer()->SetGradientBackground(true);
    vtkRenderItem->update();


    //cloud.setVtkItem(vtkRenderItem);
   } else {
    qWarning() << "Dynamic cast failed. The pointer is not of type QQuickVTKRenderItem.";
  }

  return app.exec();
}