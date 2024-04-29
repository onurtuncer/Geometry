#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QSGRendererInterface>
#include <QVTKRenderWindowAdapter.h>
#include "VtkViewer.h"
#include "TrajectoryViewer.h"

void PrepareMockData(TrajectoryViewer& tv, VtkViewer* vtkviewer) {

  tv.SetToolPosition(0.0, 0.0, 0.0);
  tv.SetToolOrientation(0.0, 0.0, 1.0);
  tv.SetToolDiameter(0.2);
  tv.SetToolHeight(5);
  tv.SetToolColor(1.0, 0.0, 0.0);

  tv.SetViewer(vtkviewer);

  tv.SetBackGround(0.0, 0.0, 0.7);
  tv.SetBackGround2(0.7, 0.7, 0.7);
  tv.SetGradientBackground(true);
  tv.ShowAxes();
  tv.ShowTool();

  double p1[3] = {0,0,0};
  double p2[3] = {10,0,0};
  double p3[3] = {12,2,0};
  double p4[3] = {12,4,0};
  double p5[3] = {10,6,0};
  double p6[3] = {0,6,0};
  double p7[3] = {-2, 4, 0};
  double p8[3] = {-2, 2, 0};  
  double c1[3] = {10, 2, 0};
  double c2[3] = {10, 4, 0};
  double c3[3] = {0, 4, 0};
  double c4[3] = {0, 2, 0};  
  double p9[3] = {0,0,-3};
  double p10[3] = {10,0,-3};
  double p11[3] = {12,2,-3};
  double p12[3] = {12,4,-3};
  double p13[3] = {10,6,-3};
  double p14[3] = {0,6,-3};
  double p15[3] = {-2, 4, -3};
  double p16[3] = {-2, 2, -3};  
  double p17[3] = {4, 1, 0};
  double p18[3] = {4, 5, 0};
  double p19[3] = {5, 5, 0};
  double p20[3] = {5, 1, 0};
  double p21[3] = {5, 1, -1};
  double p22[3] = {5, 5, -1};  
  double c5[3] = {10, 2, -3};
  double c6[3] = {10, 4, -3};
  double c7[3] = {0, 4, -3};
  double c8[3] = {0, 2, -3};  
  double n1[3] = {0, 0, 1};
  double r     = 0.5;   

  tv.AddLine(p1, p2);
  tv.AddLine(p3, p4);
  tv.AddLine(p5, p6);
  tv.AddLine(p7, p8);  
  tv.AddArc(c1, p2, p3, n1);
  tv.AddArc(c2, p4, p5, n1);
  tv.AddArc(c3, p6, p7, n1);
  tv.AddArc(c4, p8, p1, n1);  
  tv.AddLine(p9, p10);
  tv.AddLine(p11, p12);
  tv.AddLine(p13, p14);
  tv.AddLine(p15, p16);  
  tv.AddArc(c5, p10, p11, n1);
  tv.AddArc(c6, p12, p13, n1);
  tv.AddArc(c7, p14, p15, n1);
  tv.AddArc(c8, p16, p9, n1);  
  tv.AddCircle(c1, r, n1);
  tv.AddCircle(c2, r, n1);
  tv.AddCircle(c3, r, n1);
  tv.AddCircle(c4, r, n1);  
  tv.AddCircle(c5, r, n1);
  tv.AddCircle(c6, r, n1);
  tv.AddCircle(c7, r, n1);
  tv.AddCircle(c8, r, n1); 

  tv.SetToolOrientation(n1);
  tv.SetToolPosition(p22);
  tv.UpdateToolTip();
    
}


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

  if (vtkViewer) {
   PrepareMockData(trajectoryViewer, vtkViewer);
  } else {
        // Handle case when vtkViewer is not found
  }

  return app.exec();
}