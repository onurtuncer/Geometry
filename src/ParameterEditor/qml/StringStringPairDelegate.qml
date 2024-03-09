import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

RowLayout {

    property var displayData

    Text {
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        text: displayData.key // Display the key
    }

    RowLayout {
        spacing: 10

        Repeater {
        model: displayData.value 
        delegate: TextInput {
            text: modelData 
            width: parent.width / 3
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            onTextChanged: {
                var updatedList = [];
                for (var i = 0; i < displayData.value.length; i++) {
                    updatedList.push(displayData.value[i]);
                }
                updatedList[index] = text; 
                console.log("Parameter path:", displayData.path, ", updated values:", updatedList);
                parameterManager.UpdateParameter(displayData.path, updatedList, displayData.type);
            }
        }
    }
    }

    //     TextInput {
    //         id: firstTextInput
    //         text: displayData.value.length > 0 ? displayData.value[0].toString() : ""
    //         width: parent.width / 3
    //         horizontalAlignment: Text.AlignHCenter
    //         verticalAlignment: Text.AlignVCenter
    //         onTextChanged: {
    //             var updatedPair = { first: text, second: secondTextInput.text };
    //             console.log("Parameter path:", displayData.path, ", updated pair:", updatedPair);
    //             parameterManager.UpdateParameter(displayData.path, updatedPair, displayData.type);
    //         }
    //     }

    //     TextInput {
    //         id: secondTextInput
    //         text: displayData.value.length > 1 ? displayData.value[0].toString() : ""
    //         width: parent.width / 3
    //         horizontalAlignment: Text.AlignHCenter
    //         verticalAlignment: Text.AlignVCenter
    //         onTextChanged: {
    //             var updatedPair = { first: firstTextInput.text, second: text };
    //             console.log("Parameter path:", displayData.path, ", updated pair:", updatedPair);
    //             parameterManager.UpdateParameter(displayData.path, updatedPair, displayData.type);
    //         }
    //     }
    // }
}