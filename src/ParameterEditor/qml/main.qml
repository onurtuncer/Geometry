import QtQuick.Window 2.15
import QMLTreeView 1.0

Window {
   id: root

   visible: true
   width: 400
   height: 400
   title: qsTr("Parameter TreeView")

    ParameterTreeView {
        id: parameterTreeView

        model: parameterModel
        rowPadding: 20
        selectionEnabled: true
    }
}