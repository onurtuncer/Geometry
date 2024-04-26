#ifndef POINTCLOUD_H
#define POINTCLOUD_H

#include "QQuickVTKRenderItem.h"
#include "qtconcurrentrun.h"
#include "qtmetamacros.h"
#include "vtkActor.h"
#include "vtkMath.h"
#include "vtkPolyData.h"
#include "vtkPolyDataMapper.h"
#include "vtkSmartPointer.h"
#include <QObject>
#include "vtkDoubleArray.h"
#include "vtkPointData.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkSmartPointerBase.h"
#include <math.h>
#include <QTimer>
#include <QtConcurrent>
class PointCloud : public QObject {
  Q_OBJECT
public:
  explicit PointCloud(QObject *parent = nullptr);
  void setVtkItem(QQuickVTKRenderItem *item);
  Q_INVOKABLE void addPoint(const double point[3]);
  Q_INVOKABLE void clear();
  Q_INVOKABLE void startRandom();


private:
  vtkSmartPointer<vtkPolyData> polyData;
  vtkSmartPointer<vtkActor> actor;
  vtkSmartPointer<vtkPoints> m_points;
  vtkSmartPointer<vtkDoubleArray> depth;
  vtkSmartPointer<vtkCellArray> vertices;
  vtkSmartPointer<vtkPolyDataMapper> mapper;
  QQuickVTKRenderItem *m_renderItem;


signals:
};

#endif // POINTCLOUD_H
