import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

RowLayout {

    property var displayData

   // width: parent.width
    spacing: 10

    Text {
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        text: displayData.key // Display the key
    }

    Repeater {
        model: displayData.value // Iterate over the list of double values
        TextInput {
            text: modelData.toString() // Convert double to text
            validator: DoubleValidator { bottom: -9999999.0; top: 9999999.0; decimals: 2 }
            width: parent.width / 3
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            onTextChanged: {
                var updatedList = displayData.value.slice(); // Create a copy of the original list
                updatedList[index] = parseFloat(textInput.text); // Update the value at the current index
                console.log("Parameter path:", displayData.path, ", updated values:", updatedList);
                parameterManager.UpdateParameter(displayData.path, updatedList, displayData.type);
            }
        }
    }
}
