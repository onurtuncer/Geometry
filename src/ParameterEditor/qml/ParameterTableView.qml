// ParameterTableView.qml

import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import QMLTableView 1.0

TreeView {
    id: parameterTableView

    // Define properties to receive data from the main QML file
    property alias model: parameterTableView.model
    property alias rowPadding: parameterTableView.rowPadding
    property alias selectionEnabled: parameterTableView.selectionEnabled

    anchors.fill: parent
    anchors.margins: 1

    // ContentItem
    contentItem: Item {
        id: contentItem
        width: parameterTableView.width
        height: childrenRect.height

        RowLayout {
            anchors.fill: parent

            Loader {
                sourceComponent: {
                    // Use currentRow.currentData here to determine which delegate to load
                    switch (currentRow.currentData.type) {
                        case 0:
                            return headerDelegate; 
                        case 1:
                            return intDelegate;
                        case 2:
                            return unsignedIntDelegate;
                        case 3:
                            return doubleDelegate;
                        case 4:
                            return doubleDelegate;
                        case 5:
                            return boolDelegate;
                        case 6:
                            return charDelegate;
                        case 7:
                            return stringDelegate;
                        case 8:
                            return signedCharDelegate;
                        case 9:
                            return doubleDoublePairDelegate;
                        case 10:
                            return boolDoublePairDelegate;  
                        case 11:
                            return stringStringPairDelegate;
                        case 12:
                            return rxPDOTypeDelegate;
                        case 13:
                            return txPDOTypeDelegate;
                        case 14:
                            return modeOfOperationDelegate;
                        case 15:
                            return modeOfOperationVectorDelegate;
                        case 16:
                             return deviceTypeDelegate;
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
                      
                        // Add cases for other types as needed
                    }
                }

                // Bind delegateData property to currentRow.currentData
                property var delegateData: currentRow.currentData
                property var delegateHeight: contentItem.height
                property var delegateWidth: parameterTableView.width
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

  Component {
     id: rxPDOTypeDelegate
     RxPDOTypeDelegate {
       displayData: delegateData
       height: delegateHeight
       width:  delegateWidth
    }
  }

   Component {
     id: txPDOTypeDelegate
     TxPDOTypeDelegate {
       displayData: delegateData
       height: delegateHeight
       width:  delegateWidth
    }
  }

   Component {
     id: modeOfOperationDelegate
     ModeOfOperationDelegate {
       displayData: delegateData
       height: delegateHeight
       width:  delegateWidth
    }
  }

  Component {
     id: modeOfOperationVectorDelegate
     ModeOfOperationVectorDelegate {
       displayData: delegateData
       height: delegateHeight
       width:  delegateWidth
    }
  }

  Component {
     id: deviceTypeDelegate
     DeviceTypeDelegate {
       displayData: delegateData
       height: delegateHeight
       width:  delegateWidth
    }
  }

}