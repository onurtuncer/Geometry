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

        TextInput {
            id: textInput
            text: displayData.value.toString() // Convert QVariant double to text
            validator: DoubleValidator { bottom: -9999999.0; top: 9999999.0; decimals: 2 }
            width: parent.width / 3
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            onTextChanged: {
                    console.log("Parameter path:", displayData.path, ", value:", textInput.text);
                    parameterManager.UpdateParameter(displayData.path, parseFloat(textInput.text), displayData.type);
        }
    }
}

}
