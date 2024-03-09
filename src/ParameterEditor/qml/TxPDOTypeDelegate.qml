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
        id: txPdoTypeComboBox
        width: parent.width / 3
        model: [
            { value: -128, display: "NA" },
            { value: -127, display: "TxPdoStandard" },
            { value: -126, display: "TxPdoCSP" },
            { value: -125, display: "TxPdoCSV" },
            { value: -124, display: "TxPdoCSTCSPCSV" }
        ]
        textRole: "display"
        editable: false 

        // When an item is selected, update the parameter manager
        onActivated: {
            var selectedValue = model[currentIndex].value;
            console.log("Parameter path:", displayData.path, ", value:", selectedValue);
            parameterManager.UpdateParameter(displayData.path, selectedValue, displayData.type);
        }

        // Set the initial selection based on displayData.value
        Component.onCompleted: {
            currentIndex = displayData.value + 128; // Convert to index
        }
    }
}
