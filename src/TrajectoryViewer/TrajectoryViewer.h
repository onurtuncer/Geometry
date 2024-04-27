#ifndef TRAJECTORY_VIEWER_H
#define TRAJECTORY_VIEWER_H

#include <QObject>
#include <vtkSmartPointer.h>
#include <vtkActor.h>
#include <vtkAxesActor.h>

class VtkViewer;
class TrajectoryViewer : public QObject{
  Q_OBJECT

  public:
    explicit TrajectoryViewer(QObject* parent = nullptr);
    ~TrajectoryViewer() = default;

    void SetViewer(VtkViewer* viewer);

    void    SetToolDiameter(const double diameter);
    double  GetToolDiameter() const;
    void    SetToolHeight(const double height);
    double  GetToolHeight() const;
    void    SetToolPosition(const double x, const double y, const double z);
    void    SetToolOrientation(const double i, const double j, const double k);
    void    SetToolColor(const double r, const double g, const double b);
    const double* GetToolPosition() const;
    const double* GetToolOrientation() const;
    const double* GetToolColor() const;
    void    Clear();

    void ChangeBackGroundColor(const double r, const double g, const double b);
    Q_INVOKABLE void AddAxisActor();
    Q_INVOKABLE void RemoveAxisActor();

  private:
    void CreateToolActor();
    void UpdateToolPose();

  private:
    VtkViewer* m_Viewer;
    vtkSmartPointer<vtkAxesActor> m_AxesActor; 

  private:
    double     m_ToolDiameter{0.15};
    double     m_ToolHeight{0.1};
    double     m_ToolPosition[3] = {0, 0, 0};
    double     m_ToolOrientation[3] = {0, 0, 1.0};
    double     m_ToolColor[3] = {1.0, 0.0, 0.0};              

    vtkSmartPointer<vtkActor> m_ToolActor;   
};

#endif // TRAJECTORY_VIEWER_H