import QtQuick
// import VTKPLUS
// import VTKTest 
import PointCloud
import QtQuick.Controls
import QtQuick.Controls.Material
import QtQuick.Layouts

import VTK 9.3

ApplicationWindow {
    visibility: "Maximized"
    visible: true
    title: "VTK Test"
    menuBar: MenuBar {
        Menu {
            id: fileMenu
            title: 'Files'
            Action {
                text: "Add Point"
                onTriggered: {
                    PointCloud.startRandom()
                }
            }
            Action {
                text: "Clear"
                onTriggered: {
                    PointCloud.clear()
                }
            }
        }
    }
    Item {
        anchors.fill: parent
        objectName: "container"
        VTKRenderWindow {
            objectName: "vtkRenderWindow"
            id: vtkwindow
            anchors.fill: parent
        }
        VTKRenderItem {
            objectName: "renderItem"
            anchors.fill: parent
            renderWindow: vtkwindow
        }
    }
}