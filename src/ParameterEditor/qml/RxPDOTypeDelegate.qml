import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

RowLayout {
    property var displayData

    Text {
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        text: displayData.key // Display the parameter name
    }

    ComboBox {
        id: comboBox
        width: parent.width / 3
        model: [
            { value: 0, display: "NA" },
            { value: 1, display: "RxPdoStandard" },
            { value: 2, display: "RxPdoCSP" },
            { value: 3, display: "RxPdoCSV" },
            { value: 4, display: "RxPdoCSTCSPCSV" }
        ]
        textRole: "display"
        editable: false 

        onActivated: {
            var selectedValue = model[currentIndex].value;
          //  console.log("Parameter path:", displayData.path, ", value:", selectedValue);
            parameterManager.UpdateParameter(displayData.path, selectedValue, displayData.type);
        }

        Component.onCompleted: {
            currentIndex = displayData.value;
        }
    }
}