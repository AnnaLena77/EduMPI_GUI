import QtQuick
import QtQuick.Layouts 6.3
import QtQuick.Controls 6.3

Item {
    id: menu_bar_item
    width: parent.width
    height: 30

    MenuBar{
        id: menu
        anchors.fill: parent

        background: Rectangle{
            color: "#383936"
        }

        Menu {
            id: menu1
            title: qsTr("Settings")

            background: Rectangle {
                implicitWidth: 200
                //implicitHeight: 20
                color: "#383936"
                border.color: "black"
            }

            Action {

                text: "<font color=\"white\">Generate Skript (HS Fulda)</font>"
                onTriggered: {
                    var component = Qt.createComponent("Cluster_Connection_Formular.qml");
                    var window = component.createObject(root);
                    window.show();
                }
            }
            Action {
                text: "<font color=\"white\">Timescale_DB</font>"
                onTriggered: {
                        var component = Qt.createComponent("DB_Connection_Formular.qml");
                        var window = component.createObject(root);
                        window.show();
                }
            }
            Action {
                text: "<font color=\"white\">Manual Bash Skript</font>"
                onTriggered: {
                    var component = Qt.createComponent("Bash_Skript_Manual.qml");
                    var window = component.createObject(root);
                    window.show();
                }
            }
            Action { text: "<font color=\"white\">Save As...</font>"}
            MenuSeparator { }
            //Action { text: qsTr("&Quit") }

        }
        Menu {
            title: qsTr("Options")

            background: Rectangle {
                implicitWidth: 200
                //implicitHeight: 20
                color: "#383936"
                border.color: "black"
            }

            Action {
                text: qsTr("Cu&t")
            }
            Action { text: qsTr("&Copy") }
            Action { text: qsTr("&Paste") }
        }
        Menu {
            title: qsTr("Windows")

            background: Rectangle {
                implicitWidth: 200
                //implicitHeight: 20
                color: "#383936"
                border.color: "black"
            }

            Action {
                text: qsTr("&2D-View")
                onTriggered: actualScreen.source = "Cores2D.qml"
            }
            Action {
                text: qsTr("&3D-View")
                onTriggered: actualScreen.source = "Cores3D.qml"


            }
        }

        Menu {
            title: qsTr("Help")

            background: Rectangle {
                    implicitWidth: 200
                    color: "#383936"
                    border.color: "black"
                }

            Action {
                text: qsTr("SSH-Key-Gen Guide")
                onTriggered: {
                    var component = Qt.createComponent("Key_Gen_Guide.qml");
                    var window = component.createObject(root);
                    window.show();
                }
            }
            Action { text: qsTr("About") }
        }

        delegate: MenuBarItem {
            id: menuBarItem
            contentItem: Text {
                text: menuBarItem.text
                font: menuBarItem.font
                color: "white"
            }

        }

    }
}
