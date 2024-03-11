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
        id: modeComboBox
        width: parent.width / 3
        model: [
            { value: 0,  display: "N/A" },
            { value: 1,  display: "Profiled Position" },
            { value: 3,  display: "Profiled Velocity" },
            { value: 4,  display: "Profiled Torque" },
            { value: 6,  display: "Homing" },
            { value: 8,  display: "Cyclic Synchronous Position" },
            { value: 9,  display: "Cyclic Synchronous Velocity" },
            { value: 10, display: "Cyclic Synchronous Torque" }
        ]
        textRole: "display"
        editable: false 

        // When an item is selected, update the parameter manager
        onActivated: {
            var selectedValue = model[currentIndex].value;
           // console.log("Parameter path:", displayData.path, ", value:", selectedValue);
            parameterManager.UpdateParameter(displayData.path, selectedValue, displayData.type);
        }

        // Set the initial selection based on displayData.value
        Component.onCompleted: {
            currentIndex = displayData.value;
        }
    }
}