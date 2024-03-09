import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQml 2.15

Flickable {
    id: root

    implicitWidth: 400
    implicitHeight: 400
    clip: true

    property var model
    readonly property alias currentIndex: table.selectedIndex
    readonly property alias currentItem: table.currentItem
    property var currentData

    property alias contentItem: table.contentItem
    property Component highlight: Rectangle {
        color: root.selectedColor
    }

    property alias selectionEnabled: table.selectionEnabled
    property alias hoverEnabled: table.hoverEnabled

    property alias color: table.color
    property alias hoverColor: table.hoverColor
    property alias selectedColor: table.selectedColor
    property alias selectedItemColor: table.selectedItemColor

    property alias rowHeight: table.rowHeight
    property alias rowPadding: table.rowPadding
    property alias rowSpacing: table.rowSpacing

    property alias fontMetrics: table.fontMetrics
    property alias font: table.font

    contentHeight: table.height
    contentWidth: width
    boundsBehavior: Flickable.StopAtBounds
    ScrollBar.vertical: ScrollBar {}

    Connections { function onCurrentIndexChanged() { if(currentIndex) currentData = model.data(currentIndex) }  }

    tableViewItem {
        id: table

        model: root.model
        parentIndex: model.rootIndex()
        childCount: model.rowCount(parentIndex)

        itemLeftPadding: 0
        color: root.color
        hoverColor: root.hoverColor
        selectedColor: root.selectedColor
        selectedItemColor: root.selectedItemColor
        z: 1

        Connections {
           target: root.model
           ignoreUnknownSignals: true
           function onLayoutChanged() {
               table.childCount = root.model ? root.model.rowCount(table.parentIndex) : 0
           }
        }
    }

    Loader {
        id: highlightLoader
        sourceComponent: highlight

        width: root.width
        height: root.rowHeight
        z: 0
        visible: root.selectionEnabled && table.currentItem !== null

        Binding {
            target: highlightLoader.item
            property: "y"
            value: table.currentItem ? table.currentItem.mapToItem(table, 0, 0).y + table.anchors.topMargin : 0
            when: highlightLoader.status === Loader.Ready
        }
    }
}
