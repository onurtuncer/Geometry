import QtQuick.Window 2.15
import QtQuick.Layouts 1.15
import QMLTreeView 1.0

Window {
   id: root

   visible: true
   width: 400
   height: 400
   title: qsTr("Main Window")

//    RowLayout{

    // ParameterTreeView {
    //     id: parameterTreeView

    //     model: parameterModel
    //     rowPadding: 20
    //     selectionEnabled: true
    // }

    ParameterTableView {
        id: parameterTableView

        model: toolTable
        rowPadding: 20
        selectionEnabled: true
    }
//    }
}
