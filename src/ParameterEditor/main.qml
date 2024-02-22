import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ApplicationWindow {
    visible: true
    width: 400
    height: 400
    title: "Tree View Example"

    TreeView {
        anchors.fill: parent
        model: treeModel.rootItem
        headerVisible: false

        TableViewColumn {
            role: "name"
            title: "Name"
            width: 200
        }

        TableViewColumn {
            title: "Value"
            width: 200
            delegate: Item {
                Loader {
                    property string settingType: modelData.children[0].name
                    sourceComponent: {
                        if (settingType === "bool") {
                            return boolDelegate
                        } else if (settingType === "vector") {
                            return vectorDelegate
                        } else if (settingType === "string") {
                            return stringDelegate
                        } else {
                            return defaultDelegate
                        }
                    }
                }
            }
        }

        itemDelegate: Item {
            height: 20
            width: treeView.width

            Rectangle {
                anchors.fill: parent
                color: Style.isCurrentItem ? "lightblue" : "transparent"
            }
        }
    }

    Component {
        id: boolDelegate
        CheckBox {
            checked: modelData.children[1].children[1].value
            onClicked: {
                // Update the value in the model when the checkbox is clicked
                modelData.children[1].children[1].value = checked
            }
        }
    }

    Component {
        id: vectorDelegate
        Repeater {
            model: modelData.children[1].children[1].value
            delegate: TextInput {
                text: modelData.children[1].children[1].value[index]
                onTextChanged: {
                    // Update the value in the model when the text is changed
                    modelData.children[1].children[1].value[index] = text
                }
            }
        }
    }

    Component {
        id: stringDelegate
        TextInput {
            text: modelData.children[1].children[1].value
            onTextChanged: {
                // Update the value in the model when the text is changed
                modelData.children[1].children[1].value = text
            }
        }
    }

    Component {
        id: defaultDelegate
        Text {
            text: modelData.children[1].children[1].value
        }
    }
}
