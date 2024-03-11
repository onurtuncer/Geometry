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

    Repeater {
        model: displayData.value 
        delegate: TextInput {
            text: modelData.toString() 
            validator: DoubleValidator { bottom: -9999999.0; top: 9999999.0; decimals: 2 }
            width: parent.width / 3
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            onTextChanged: {
                var updatedList = displayData.value.slice(); // Create a copy of the original list
                updatedList[index] = parseFloat(text); // Update the value at the current index
            //    console.log("Parameter path:", displayData.path, ", updated values:", updatedList);
                parameterManager.UpdateParameter(displayData.path, updatedList, displayData.type);
            }
        }
    } 
}