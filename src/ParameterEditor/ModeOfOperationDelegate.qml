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
            { value: 0,  display: "NA" },
            { value: 1,  display: "ProfiledPositionMode" },
            { value: 3,  display: "ProfiledVelocityMode" },
            { value: 4,  display: "ProfiledTorqueMode" },
            { value: 6,  display: "HomingMode" },
            { value: 8,  display: "CyclicSynchronousPositionMode" },
            { value: 9,  display: "CyclicSynchronousVelocityMode" },
            { value: 10, display: "CyclicSynchronousTorqueMode" }
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
            currentIndex = displayData.value;
        }
    }
}