#include "pointcloud.h"
#include "vtkProperty.h"
#include "vtkSmartPointer.h"

#include <QThread> // Include Qt's thread-related header

PointCloud::PointCloud(QObject *parent)
    : QObject{parent}{
  polyData = vtkSmartPointer<vtkPolyData>::New();
  mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
  vertices = vtkSmartPointer<vtkCellArray>::New();
  depth = vtkSmartPointer<vtkDoubleArray>::New();
  depth->SetName("depth");
  m_points = vtkSmartPointer<vtkPoints>::New();
  polyData->SetPoints(m_points);
  polyData->SetVerts(vertices);
  polyData->GetPointData()->SetScalars(depth);
  polyData->GetPointData()->SetActiveScalars("depth");
  mapper->SetInputData(polyData);
  mapper->SetColorModeToDefault();
  mapper->SetScalarVisibility(1);
  actor = vtkSmartPointer<vtkActor>::New();
  actor->SetMapper(mapper);
  actor->GetProperty()->SetPointSize(2);

}
void PointCloud::setVtkItem(QQuickVTKRenderItem *item) {
  m_renderItem = item;
  if (m_renderItem) {
    m_renderItem->renderer()->AddActor(actor);
  }
}
void PointCloud::addPoint(const double point[3]) {
  auto pid = m_points->InsertNextPoint(point);
  depth->InsertNextTuple1(point[2]);
  vertices->InsertNextCell(1);
  vertices->InsertCellPoint(pid);
  m_points->Modified();
  depth->Modified();
  vertices->Modified();
}

void PointCloud::clear() {
  vertices->Initialize();
  vertices->Modified();
  depth->Initialize();
  depth->Modified();
  m_points->Initialize();
  m_points->Modified();
}
void PointCloud::startRandom(){
  auto future=QtConcurrent::run([&](){
    while(polyData->GetPoints()->GetNumberOfPoints()<1000000){
      auto theta=2*vtkMath::Pi() *vtkMath::Random();
      double phi=acos(2*vtkMath::Random()-1);
      double p[3]={sin(phi)*cos(theta),sin(phi)*sin(theta),cos(phi)};
      addPoint(p);
      QThread::msleep(5);
    }
  });
}