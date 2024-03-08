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

    CheckBox {
        id: checkBox
        checked: displayData.value[0] // Display the boolean value
        onCheckedChanged: {
            var updatedPair = [ checked , doubleTextInput.text ];
            console.log("Parameter path:", displayData.path, ", updated pair:", updatedPair);
            parameterManager.UpdateParameter(displayData.path, updatedPair, displayData.type);
        }
    }

    TextInput {
    id: doubleTextInput
    text: displayData.value[1] // Display the double value
    validator: DoubleValidator { bottom: -9999999.0; top: 9999999.0; decimals: 2 }
    width: parent.width / 3
    onTextChanged: {
        var updatedPair = [checkBox.checked, text ];
        console.log("Parameter path:", displayData.path, ", updated pair:", updatedPair);
        parameterManager.UpdateParameter(displayData.path, updatedPair, displayData.type);
    }
}

}