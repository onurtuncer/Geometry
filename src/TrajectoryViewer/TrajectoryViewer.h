/* ----------------------------------------------------------------------------*
  Copyright 2024 MILTEKSAN

  Written by Melina Aero, Istanbul, Turkey
  Contact onur.tuncer@melina-aero.com
-------------------------------------------------------------------------------*/

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
    virtual ~TrajectoryViewer() = default;

    void SetViewer(VtkViewer* viewer);

    void    SetToolDiameter(const double diameter);
    double  GetToolDiameter() const;
    void    SetToolHeight(const double height);
    double  GetToolHeight() const;
    void    SetToolPosition(const double x, const double y, const double z);
    void    SetToolPosition(const double (&position)[3]);
    void    SetToolOrientation(const double i, const double j, const double k);
    void    SetToolOrientation(const double (&orientation)[3]);
    void    SetToolColor(const double r, const double g, const double b);
    void    SetToolPathColor(const double r, const double g, const double b);
    const double* GetToolPosition() const;
    const double* GetToolOrientation() const;
    const double* GetToolColor() const;
    void    Clear();

    void SetBackGround(const double r, const double g, const double b);
    void SetBackGround2(const double r, const double g, const double b);

    void SetGradientBackground(bool value);

    Q_INVOKABLE void ShowAxes();
    Q_INVOKABLE void HideAxes();

    Q_INVOKABLE void ShowTool();
    Q_INVOKABLE void HideTool();

    void UpdateToolTip();

    void AddLine(double startPoint[3], double endPoint[3], bool green = false);
    void AddCircle(double center[3], double radius, double normal[3]);
    void AddArc(double center[3], double start[3], double end[3], double normal[3]);

  private:
    void CreateToolActor();
    void UpdateToolPose();
    void UpdateCamera();

  private:
    VtkViewer* m_Viewer;
    vtkSmartPointer<vtkAxesActor> m_AxesActor; 

  private:
    double     m_ToolDiameter{0.15};
    double     m_ToolHeight{0.1};
    double     m_ToolPosition[3] = {0, 0, 0};
    double     m_ToolOrientation[3] = {0, 0, 1.0};
    double     m_ToolColor[3] = {1.0, 0.0, 0.0};  
    double     m_ToolPathColor[3] = {1, 1, 1};            

    vtkSmartPointer<vtkActor> m_ToolActor;   
};

#endif // TRAJECTORY_VIEWER_H