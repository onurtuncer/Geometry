#pragma once

#include <vector>
#include <vtkSmartPointer.h>
#include <vtkAxesActor.h>
#include <vtkActor.h>
// #include <vtkCamera.h>
#include <vtkPoints.h>
// #include <vtkMatrix4x4.h>
// #include <vtkLinearTransform.h>
  
class VtkToolPath{

  public:
    explicit VtkToolPath();
    virtual ~VtkToolPath();

    void AddLine(double startPoint[3], double endPoint[3], bool green = false);
    void AddCircle(double center[3], double radius, double normal[3]);
    void AddArc(double center[3], double start[3], double end[3], double normal[3]);
    void AddPolyline(vtkSmartPointer<vtkPoints> points);
    void AddPointsToPolyline(const std::vector<std::array<double, 3>>& additionalPoints);
    // void RemovePointsFromFrontOfPolyLine(vtkSmartPointer<vtkActor> polylineActor, int numPointsToRemove);

    void SetToolDiameter(double diameter) {m_ToolDiameter = diameter;}
    void SetToolHeight(double height) {m_ToolHeight = height;}

   void SetToolPosition(double position[3]){ 
    
    for (int i = 0; i < 3; ++i) {
      m_ToolPosition[i] = position[i];
    }
   }

   void SetToolOrientation(double orientation[3]){ 
   
    for (int i = 0; i < 3; ++i) {
      m_ToolOrientation[i] = orientation[i];
    }
   }

   void SetToolColor(double color[3]){

    for (int i = 0; i < 3; ++i) {
      m_ToolColor[i] = color[i];
    }
   }

    // void UpdateToolTip();

    void RemoveFirstPrimitive();
    void RemoveLastPrimitive();

    // void SetBackGround() {m_Renderer->SetBackground(m_BackGroundColor);} // white
   
//   private:
//     void AddAxesActor();
//     void AddCamera();
//     void AddToolTip();
//     void UpdateCamera();

//     void UpdateToolPose();


  private:
    
  
//  std::vector<Primitive> m_ToolPathActors;
//  vtkSmartPointer<vtkAxesActor> m_AxesActor; 
    
    vtkSmartPointer<vtkSmartPointer<vtkActor> m_ToolPathActors;
    double                    m_ToolDiameter{0.15};
    double                    m_ToolHeight{1.5};
    double                    m_ToolPosition[3] = {0, 0, 0};
    double                    m_ToolOrientation[3] = {0, 0, 1.0};
    double                    m_ToolColor[3] = {1.0, 0.0, 0.0};              
    double                    m_ToolPathColor[3] = {1, 1, 1};
    double                    m_BackGroundColor[3] = {0, 0, 0};
};