import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

RowLayout {

    property var displayData

    Text {
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        text: displayData.key
    }

    // ColumnLayout {
    //     Layout.alignment: Qt.AlignVCenter

    //     Item {
    //         Layout.fillWidth: true
    //     }

    CheckBox {
            id: checkBox
            checked: displayData.value
            onCheckedChanged: {
                console.log("Parameter path:", displayData.path, ", checked:", checked);
                parameterManager.UpdateParameter(displayData.path, checked, displayData.type);
            }
        }
    // }
}

