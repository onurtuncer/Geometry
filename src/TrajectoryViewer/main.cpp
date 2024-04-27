#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QSGRendererInterface>

#include <QVTKRenderWindowAdapter.h>

#include "VtkViewer.h"
#include "TrajectoryViewer.h"


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QQuickWindow::setSceneGraphBackend(QSGRendererInterface::OpenGLRhi);
#else
    QQuickWindow::setGraphicsApi(QSGRendererInterface::OpenGLRhi);
#endif
    QSurfaceFormat::setDefaultFormat(QVTKRenderWindowAdapter::defaultFormat());

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    qmlRegisterType<VtkViewer>("Vtk", 1, 0, "Viewer");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

  auto* rootObject = engine.rootObjects()[0];
  VtkViewer* vtkViewer = rootObject->findChild<VtkViewer*>("viewer");

  TrajectoryViewer trajectoryViewer;

  qmlRegisterSingletonInstance<TrajectoryViewer>("Vtk", 1, 0, "TrajectoryViewer",
                                                 &trajectoryViewer);

  trajectoryViewer.SetToolPosition(0.0, 0.0, 0.0);
  trajectoryViewer.SetToolOrientation(0.0, 0.0, 1.0);
  trajectoryViewer.SetToolDiameter(0.15);
  trajectoryViewer.SetToolHeight(0.1);
  trajectoryViewer.SetToolColor(1.0, 0.0, 0.0);

  if (vtkViewer) {
    trajectoryViewer.SetViewer(vtkViewer);

    trajectoryViewer.ChangeBackGroundColor(1.0, 0.0, 0.0);
    trajectoryViewer.AddAxisActor();
  } else {
        // Handle case when vtkViewer is not found
  }

  return app.exec();
}