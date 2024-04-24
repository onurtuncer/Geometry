import QtQuick 2.15
import QtQuick.Window 2.15

import Vtk 1.0 

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Milteksan Trajectory Viewer")

    Rectangle {
      anchors.fill: parent
      color: "yellow"
      opacity: 0.2

    }

    Item{
        anchors.fill: parent
        // Instantiate VtkTrajectoryItem from C++ side
        VtkTrajectoryItem {
            id: vtkItem
            anchors.fill: parent
            // You can set properties or bindings here if needed
        }
    }

    // VtkTrajectoryItem {
    //     id: vtkItem
    //     anchors.fill: parent
    //     anchors.margins: 10
    //     opacity: 1.0
    // }

}
