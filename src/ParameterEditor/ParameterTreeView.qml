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

    anchors.fill: parent
    anchors.margins: 1

    // ContentItem
    contentItem: Item {
        id: contentItem
        width: parameterTreeView.width
        height: childrenRect.height

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
                        case 7:
                            return stringDelegate;
                        case 1:
                            return intDelegate;
                        case 2:
                            return unsignedIntDelegate;
                        case 8:
                            return signedCharDelegate;
                        case 9:
                            return doubleDoublePairDelegate;
                        case 10:
                            return boolDoublePairDelegate;  
                        case 11:
                            return stringStringPairDelegate;
                        case 19:
                            return doubleVectorDelegate;
                        case 17:
                            return intDelegate; // int32T
                        case 18:
                            return intDelegate; // int8T
                        case 20:
                            return stringVectorDelegate; 
                        case 21:
                            return intDelegate; // uint8T
                        case 3:
                            return doubleDelegate;
                        // Add cases for other types as needed
                    }
                }

                // Bind delegateData property to currentRow.currentData
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
     id: stringDelegate
     StringDelegate {
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

  Component {
     id: stringVectorDelegate
     StringVectorDelegate {
       displayData: delegateData
       height: delegateHeight
       width:  delegateWidth
    }
  }

  Component {
     id: stringStringPairDelegate
     StringStringPairDelegate {
       displayData: delegateData
       height: delegateHeight
       width:  delegateWidth
    }
  }

Component {
     id: doubleDoublePairDelegate
     DoubleDoublePairDelegate {
       displayData: delegateData
       height: delegateHeight
       width:  delegateWidth
    }
  }

  Component {
     id: boolDoublePairDelegate
     BoolDoublePairDelegate {
       displayData: delegateData
       height: delegateHeight
       width:  delegateWidth
    }
  }

}