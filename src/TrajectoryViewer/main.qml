import QtQuick 2.15
import QtQuick.Window 2.15

import Vtk 1.0 as Vtk

Window {
    width: 640
    height: 480
    visible: true
    title: "Trajectory Viewer"

    Rectangle {
      anchors.fill: parent
      color: "yellow"
      opacity: 0.5

    }

    Vtk.Viewer {
        anchors.fill: parent
        objectName: "viewer"
        anchors.margins: 10
        opacity: 1.0
    }

}