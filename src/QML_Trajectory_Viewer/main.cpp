#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QSGRendererInterface>
#include <QVTKRenderWindowAdapter.h>

#include "VtkTrajectoryItem.h"

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

    qmlRegisterType<VtkTrajectoryItem>("Vtk", 1, 0, "VtkTrajectoryItem");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    // Get the root object from the QML engine
    QObject *rootObject = engine.rootObjects().value(0);
    if (rootObject) {
        // Access the VtkTrajectoryItem instance from QML
        VtkTrajectoryItem *vtkItem = rootObject->findChild<VtkTrajectoryItem*>("vtkItem");
        if (vtkItem) {

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
            double p22[4] = {5, 5 , -1};

       // Create vtkPoints
    auto points = vtkSmartPointer<vtkPoints>::New();

    // Add points to vtkPoints
    points->InsertNextPoint(p17);
    points->InsertNextPoint(p18);
    points->InsertNextPoint(p19);
    points->InsertNextPoint(p20);
    points->InsertNextPoint(p21);
    points->InsertNextPoint(p22);


    double c5[3] = {10, 2, -3};
    double c6[3] = {10, 4, -3};
    double c7[3] = {0, 4, -3};
    double c8[3] = {0, 2, -3};

    double n1[3] = {0, 0, 1};
    double r     = 0.5;    

            std::cout << "Found vtk item in QML" << std::endl;
            // // Call methods from VtkTrajectoryItem
            // vtkItem->methodName(); // Replace methodName with the actual method you want to call
        }
    }

   

 

    // vtkItem->AddLine(p1, p2);
    // vtkItem->AddLine(p3, p4);
    // vtkItem->AddLine(p5, p6);
    
    // vtkItem->AddArc(c1, p2, p3, n1);
    // vtkItem->AddArc(c2, p4, p5, n1);
    // vtkItem->AddArc(c3, p6, p7, n1);
    // toolPathRenderer.AddArc(c4, p8, p1, n1);

    // toolPathRenderer.AddLine(p9, p10);
    // toolPathRenderer.AddLine(p11, p12);
    // toolPathRenderer.AddLine(p13, p14);
    // toolPathRenderer.AddLine(p15, p16);

    // toolPathRenderer.AddArc(c5, p10, p11, n1);
    // toolPathRenderer.AddArc(c6, p12, p13, n1);
    // toolPathRenderer.AddArc(c7, p14, p15, n1);
    // toolPathRenderer.AddArc(c8, p16, p9, n1);

    // toolPathRenderer.AddCircle(c1, r, n1);
    // toolPathRenderer.AddCircle(c2, r, n1);
    // toolPathRenderer.AddCircle(c3, r, n1);
    // toolPathRenderer.AddCircle(c4, r, n1);

    // toolPathRenderer.AddCircle(c5, r, n1);
    // toolPathRenderer.AddCircle(c6, r, n1);
    // toolPathRenderer.AddCircle(c7, r, n1);
    // toolPathRenderer.AddCircle(c8, r, n1);

    // toolPathRenderer.AddPolyline(points);

    // toolPathRenderer.SetToolOrientation(n1);
    // toolPathRenderer.SetToolPosition(p22);
   
    // toolPathRenderer.UpdateToolTip(); 
    // toolPathRenderer.TurnOffAxisLabels();

    return app.exec();
}
