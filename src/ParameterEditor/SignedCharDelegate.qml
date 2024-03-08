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

    SpinBox {
        id: spinBox
        value: Math.min(127, Math.max(-128, displayData.value)) // Clamp value to range of signed char
        from: -128
        to: 127
        stepSize: 1
        width: parent.width / 3
        validator: IntValidator { bottom: -128; top: 127 }
        onValueChanged: {
            console.log("Parameter path:", displayData.path, ", value:", value);
            parameterManager.UpdateParameter(displayData.path, value, displayData.type);
        }
    } 
}
