import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import QMLTreeView 1.0

Window {
   id: root

   visible: true
   width: 400
   height: 400
   title: qsTr("Parameter TreeView")

  
  TreeView {
      id: parameterView

      anchors.fill: parent
      anchors.margins: 1

      model: parameterModel
      rowPadding: 20
      selectionEnabled: true

      contentItem: RowLayout {
         Text {
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            text: currentRow.currentData.key
         }

     // Display each value in separate columns if it's a QVariantList
        Repeater {
            model: Array.isArray(currentRow.currentData.value) ? currentRow.currentData.value.length : 1
            delegate: TextInput {
                Layout.fillWidth: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignRight
                text: {
                    if (currentRow.currentData.value && Array.isArray(currentRow.currentData.value)) {
                        // If it's a QVariantList, display each item in a separate column
                        return currentRow.currentData.value[index].toString();
                    } else if (currentRow.currentData.value !== undefined) {
                        // If it's a single QVariant, display it in a single column
                        return currentRow.currentData.value.toString();
                    } else {
                        // Handle case where value is undefined or null
                        return "";
                    }
                }
                onEditingFinished: {
                    if (currentRow.currentData.value && Array.isArray(currentRow.currentData.value)) {
                        // Update the value in the QVariantList
                        currentRow.currentData.value[index] = text;
                    } else {
                        // Preserve the original QVariant type when setting the edited value
                        switch (typeof currentRow.currentData.value) {
                            case "boolean":
                                currentRow.currentData.value = (text.toLowerCase() === "true");
                                break;
                            case "number":
                                currentRow.currentData.value = parseFloat(text);
                                break;
                            case "string":
                                currentRow.currentData.value = text;
                                break;
                            // Handle other QVariant types as needed
                            default:
                                console.error("Unsupported QVariant type");
                        }
                    }
                }
            }
        }



        //  // Display each value in a separate column
        // Repeater {
        //     model: currentRow.currentData.value.length // Assuming value is a QVariantList
        //     delegate: Text {
        //         Layout.fillWidth: true
        //         verticalAlignment: Text.AlignVCenter
        //         horizontalAlignment: Text.AlignRight
        //         text: currentRow.currentData.value[index].toString()
        //     }
        // }

        // Text {
        //   Layout.fillWidth: true
        //   Layout.rightMargin: 10
  
        //   verticalAlignment: Text.AlignVCenter
        //   horizontalAlignment: Text.AlignRight
        //   text: {
        //       if (currentRow.currentData.value) {
        //           // Check if the value is a QVariantList
        //           if (Array.isArray(currentRow.currentData.value)) {
        //               // Convert QVariantList to string representation
        //               return currentRow.currentData.value.join(", ");
        //           } else {
        //               // If it's not an array, convert to string directly
        //               return currentRow.currentData.value.toString();
        //           }
        //           } else {
        //         return "";
        //       }
        //   }
        // }

         
      }
  }  // treeView

}
