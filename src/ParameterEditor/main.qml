import QtQuick.Window 2.15
import QMLTreeView 1.0

Window {
   id: root

   visible: true
   width: 400
   height: 400
   title: qsTr("Parameter TreeView")

    ParameterTreeView {
        id: parameterTreeView

        model: parameterModel
        rowPadding: 20
        selectionEnabled: true
    }
}

  // TreeView {
  //     id: parameterView

  //     anchors.fill: parent
  //     anchors.margins: 1

  //     model: parameterModel
  //     rowPadding: 20
  //     selectionEnabled: true

  //     contentItem: RowLayout {
  //        Text {
  //           verticalAlignment: Text.AlignVCenter
  //           horizontalAlignment: Text.AlignLeft
  //           text: currentRow.currentData.key
  //        }

  //    // Display each value in separate columns if it's a QVariantList
  //       Repeater {
  //           model: Array.isArray(currentRow.currentData.value) ? currentRow.currentData.value.length : 1
  //           delegate: TextInput {
  //               Layout.fillWidth: true
  //               verticalAlignment: Text.AlignVCenter
  //               horizontalAlignment: Text.AlignRight
  //               text: {
  //                   if (currentRow.currentData.value && Array.isArray(currentRow.currentData.value)) {
  //                       // If it's a QVariantList, display each item in a separate column
  //                       return currentRow.currentData.value[index].toString();
  //                   } else if (currentRow.currentData.value !== undefined) {
  //                       // If it's a single QVariant, display it in a single column
  //                       return currentRow.currentData.value.toString();
  //                   } else {
  //                       // Handle case where value is undefined or null
  //                       return "";
  //                   }
  //               }
  //               onEditingFinished: {
  //                   if (currentRow.currentData.value && Array.isArray(currentRow.currentData.value)) {
  //                       // Update the value in the QVariantList
  //                       currentRow.currentData.value[index] = text;
  //                   } else {
  //                       // Preserve the original QVariant type when setting the edited value
  //                       switch (typeof currentRow.currentData.value) {
  //                           case "boolean":
  //                               currentRow.currentData.value = (text.toLowerCase() === "true");
  //                               break;
  //                           case "number":
  //                               currentRow.currentData.value = parseFloat(text);
  //                               break;
  //                           case "string":
  //                               currentRow.currentData.value = text;
  //                               break;
  //                           // Handle other QVariant types as needed
  //                           default:
  //                               console.error("Unsupported QVariant type");
  //                       }
  //                   }
  //               }
  //           }
  //       }
         
  //     }
  // }  // treeView