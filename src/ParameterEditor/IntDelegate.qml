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

    RowLayout {
            SpinBox {
                id: spinBox
                value: displayData.value // Assuming displayData.value is an integer
                stepSize: 1
                width: parent.width / 3
                onValueChanged: {
                    console.log("Parameter path:", displayData.path, ", value:", value);
                    parameterManager.UpdateParameter(displayData.path, value, displayData.type);
                }
            }
        }
    // }
}