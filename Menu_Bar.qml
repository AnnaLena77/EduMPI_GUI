import QtQuick
import QtQuick.Layouts 6.3
import QtQuick.Controls 6.3

Item {
    id: menu_bar_item
    width: parent.width
    height: 30

    Rectangle{
        anchors.fill: parent
        color: "#808080"
    }
    MenuBar{
        id: menu
        anchors.fill: parent
        Menu {
            title: qsTr("&Settings")

            Action {
                text: qsTr("&Generate Skript (HS Fulda)")
                onTriggered: {
                        var component = Qt.createComponent("Cluster_Connection_Formular.qml");
                        var window = component.createObject(root);
                        window.show();
                }
            }
            Action {
                text: qsTr("&Timescale_DB")
                onTriggered: {
                        var component = Qt.createComponent("DB_Connection_Formular.qml");
                        var window = component.createObject(root);
                        window.show();
                }
            }
            Action {
                text: qsTr("&Manual Bash Skript")
                onTriggered: {
                    var component = Qt.createComponent("Bash_Skript_Manual.qml");
                    var window = component.createObject(root);
                    window.show();
                }
            }
            Action { text: qsTr("Save &As...") }
            MenuSeparator { }
            Action { text: qsTr("&Quit") }
        }
        Menu {
            title: qsTr("&Options")
            Action {
                text: qsTr("Cu&t")
            }
            Action { text: qsTr("&Copy") }
            Action { text: qsTr("&Paste") }
        }
        Menu {
            title: qsTr("&Windows")
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
            title: qsTr("&Help")
            Action {
                text: qsTr("&SSH-Key-Gen Guide")
                onTriggered: {
                    var component = Qt.createComponent("Key_Gen_Guide.qml");
                    var window = component.createObject(root);
                    window.show();
                }
            }
            Action { text: qsTr("&About") }
        }
    }
}
