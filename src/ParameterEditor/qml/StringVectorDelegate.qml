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
            //    console.log("Parameter path:", displayData.path, ", updated values:", updatedList);
                parameterManager.UpdateParameter(displayData.path, updatedList, displayData.type);
            }
        }
    }
}