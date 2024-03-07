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

    ColumnLayout {
        Layout.alignment: Qt.AlignVCenter

        Item {
            Layout.fillWidth: true
        }

        SpinBox {
            id: spinBox
            value: displayData.value 
            from: 0
            to: 4294967295 // Maximum value of an unsigned 32-bit integer
            stepSize: 1
            width: parent.width / 3
            validator: IntValidator { bottom: 0; top: 4294967295 }
            onValueChanged: {
                console.log("Parameter path:", displayData.path, ", value:", value);
                parameterManager.UpdateParameter(displayData.path, value, displayData.type);
            }
        }
    }
}