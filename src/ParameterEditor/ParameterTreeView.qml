// ParameterTreeView.qml

import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import QMLTreeView 1.0

TreeView {
    id: parameterTreeView

    // Define properties to receive data from the main QML file
    property alias model: parameterTreeView.model
    property alias rowPadding: parameterTreeView.rowPadding
    property alias selectionEnabled: parameterTreeView.selectionEnabled

    // Bind data model and other properties
    anchors.fill: parent
    anchors.margins: 1

    // ContentItem
    contentItem: Item {
        id: contentItem
        width: parameterTreeView.width
        height: childrenRect.height

        // RowLayout with Loader
        RowLayout {
            anchors.fill: parent

            Loader {
                sourceComponent: {
                    // Use currentRow.currentData here to determine which delegate to load
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
                        // Add cases for other types as needed
                    }
                }

                // Bind currentData property to currentRow.currentData
                property var delegateData: currentRow.currentData
                property var delegateHeight: contentItem.height
                property var delegateWidth: parameterTreeView.width
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

   Component {
     id: doubleVectorDelegate
     DoubleVectorDelegate {
       displayData: delegateData
       height: delegateHeight
       width:  delegateWidth
    }
  }

}