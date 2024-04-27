#ifndef TRAJECTORY_VIEWER_H
#define TRAJECTORY_VIEWER_H

#include <QObject>
#include <vtkSmartPointer.h>
#include <vtkActor.h>
#include "VtkViewer.h"

class TrajectoryViewer : public QObject{
  Q_OBJECT

  public:
    explicit TrajectoryViewer(QObject* parent = nullptr);
    ~TrajectoryViewer() = default;

    void   SetToolDiameter(const double diameter) {m_ToolDiameter = diameter;}
    double GetToolDiameter() const {return m_ToolDiameter;}
    void   SetToolHeight(const double height) {m_ToolHeight = height;}
    double GetToolHeight() const {return m_ToolHeight;}
    void   SetToolPosition(const double x, const double y, const double z) {m_ToolPosition[0] = x; m_ToolPosition[1] = y; m_ToolPosition[2] = z;}
    void   SetToolOrientation(const double i, const double j, const double k) {m_ToolOrientation[0] = i; m_ToolOrientation[1] = j; m_ToolOrientation[2] = k;}
    void   SetToolColor(const double r, const double g, const double b) {m_ToolColor[0] = r; m_ToolColor[1] = g; m_ToolColor[2] = b;}
    double[3] GetToolPosition() const {return m_ToolPosition;}
    double[3] GetToolOrientation() const {return m_ToolOrientation;}
    double[3] GetToolColor() const {return m_ToolColor;}
    void   Clear();

  private:
    void CreateToolActor(){
      if (!m_ToolActor) {
        auto cylinder = vtkSmartPointer<vtkCylinderSource>::New();
        cylinder->SetRadius(m_ToolDiameter / 2.0);
        cylinder->SetHeight(m_ToolHeight);
        cylinder->SetResolution(50); 
        // Create mapper
        vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
        mapper->SetInputConnection(cylinder->GetOutputPort());
        // Create actor
        m_ToolActor = vtkSmartPointer<vtkActor>::New();
        m_ToolActor->SetMapper(mapper);
        // Set the color of the actor to red
         m_ToolActor->GetProperty()->SetColor(m_ToolColor[0], m_ToolColor[1], m_ToolColor[2]); 
      } else {
        // Update existing tool actor properties
        vtkSmartPointer<vtkCylinderSource> cylinderSource = vtkSmartPointer<vtkCylinderSource>::New();
        cylinderSource = vtkCylinderSource::SafeDownCast(m_ToolActor->GetMapper()->GetInputConnection(0)->GetProducer());
        cylinderSource->SetRadius(m_ToolDiameter / 2.0);
        cylinderSource->SetHeight(m_ToolHeight);

        m_ToolActor->GetProperty()->SetColor(m_ToolColor[0], m_ToolColor[1], m_ToolColor[2]);
        m_ToolActor->GetMapper()->Modified(); // Notify the mapper that the geometry has changed
      }

     // UpdateToolPose();
    }

  private:
    VtkViewer* m_VtkViewer;
    double     m_ToolDiameter{0.15};
    double     m_ToolHeight{0.1};
    double     m_ToolPosition[3] = {0, 0, 0};
    double     m_ToolOrientation[3] = {0, 0, 1.0};
    double     m_ToolColor[3] = {1.0, 0.0, 0.0};              

    vtkSmartPointer<vtkActor> m_ToolActor;
    
}

#endif // TRAJECTORY_VIEWER_H