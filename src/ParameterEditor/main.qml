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

    contentItem: Item {
           id: contentItem
           width: parameterView.width
           height: childrenRect.height
           RowLayout {
               anchors.fill: parent

               Loader {
                   sourceComponent: {
                       switch (currentRow.currentData.type) {
                           case 0:
                               return headerDelegate;
                           case 5:
                               return boolDelegate;
                           case 6:
                               return charDelegate;
                           case 1:
                               return intDelegate;
                            case 2:
                               return unsignedIntDelegate; 
                            case 8:
                               return signedCharDelegate; 
                            case 17:
                               return intDelegate; // int32T
                            case 18: 
                               return intDelegate; // int8T
                            case 21:
                               return intDelegate; // uint8T
                            case 3:
                               return doubleDelegate;
                        //    case 7:
                        //        return stringDelegate;
                           // Add cases for other types as needed
                       }
                   }
             
                    // Bind currentData property to currentRow.currentData
                    property var delegateData: currentRow.currentData
                    property var delegateHeight: contentItem.height
                    property var delegateWidth: parameterView.width
               
               }
           }
       }
   }

   Component {
       id: headerDelegate
       Text {
           verticalAlignment: Text.AlignVCenter
           horizontalAlignment: Text.AlignLeft
           text: delegateData.key
       }
   }

   Component {
     id: boolDelegate
     BoolDelegate {
       displayData: delegateData
       height: delegateHeight
       width:  delegateWidth
     }
   }

   Component {
     id: intDelegate
     IntDelegate {
       displayData: delegateData
       height: delegateHeight
       width:  delegateWidth
    }
   }

   Component {
     id: unsignedIntDelegate
     IntDelegate {
       displayData: delegateData
       height: delegateHeight
       width:  delegateWidth
    }
   }

    Component {
     id: signedCharDelegate
     IntDelegate {
       displayData: delegateData
       height: delegateHeight
       width:  delegateWidth
    }
   }

    Component {
     id: doubleDelegate
     DoubleDelegate {
       displayData: delegateData
       height: delegateHeight
       width:  delegateWidth
    }
  }

  Component {
     id: charDelegate
     CharDelegate {
       displayData: delegateData
       height: delegateHeight
       width:  delegateWidth
    }
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