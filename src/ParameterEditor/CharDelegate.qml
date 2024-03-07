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

    ComboBox {
        id: charComboBox
        width: parent.width / 3
        model: ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
                 "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"]
        editable: false 

        // When an item is selected, update the parameter manager
        onActivated: {
            var asciiValue = currentText.charCodeAt(0); // Convert currentText to ASCII
            console.log("Parameter path:", displayData.path, ", value:", asciiValue);
            parameterManager.UpdateParameter(displayData.path, asciiValue, displayData.type);
        }

        // Set the initial selection based on displayData.value
        Component.onCompleted: {
            var asciiA = "A".charCodeAt(0);
            var value = displayData.value;
            var index = value - asciiA;
            console.log("Value:", displayData.value);
            console.log("Index:", index);
            currentIndex = index;
        }
    }
}