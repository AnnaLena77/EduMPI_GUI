import QtQuick
import QtQuick.Layouts 6.3
import QtQuick.Controls 6.3

Item {
    id: menu_bar_item
    width: parent.width
    height: Qt.platform.os === "osx" ? 0 : 30

    MenuBar{
        id: menu
        visible: Qt.platform.os !== "osx"
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

                text: Qt.platform.os === "osx" ? "Cluster Connection" : "<font color=\"white\">Cluster Connection</font>"
                onTriggered: {
                    var component = Qt.createComponent("Cluster_Connection_Formular.qml");
                    var window = component.createObject(root);
                    window.show();
                }
            }
            Action {
                text: Qt.platform.os === "osx" ? "Database Connection" : "<font color=\"white\">Database Connection</font>"
                onTriggered: {
                        var component = Qt.createComponent("DB_Connection_Formular.qml");
                        var window = component.createObject(root);
                        window.show();
                }
            }
            Action {
                text: Qt.platform.os === "osx" ? "Load EduMPI-Run from DB" : "<font color=\"white\">Load EduMPI-Run from DB</font>"
                onTriggered: {
                    var component, window;
                    if(controller.db_connection && controller.cluster_connection){
                        var fd_id = controller.getClusterIdent();
                        //controller.getJobTable().loadJobs(fd_id);

                        component = Qt.createComponent("Table_Userid_Selection.qml");
                        window = component.createObject(root);
                        window.show();
                    } else {
                        component = Qt.createComponent("Error.qml");
                        window = component.createObject(root, {"message": "First, please establish a connection to the cluster and the database!"});
                        window.x = (root.width - window.width) / 2;
                        window.y = (root.height - window.height) / 2;
                        window.show();
                    }
                }
            }
            //Action { text: "<font color=\"white\">Save As...</font>"}
            MenuSeparator { }
            //Action { text: qsTr("&Quit") }

        }
        /*Menu {
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
        }*/
        /*Menu {
            title: qsTr("Windows")

            background: Rectangle {
                implicitWidth: 200
                //implicitHeight: 20
                color: "#383936"
                border.color: "black"
            }

            Action {
                text: qsTr("&2D-View")
                onTriggered: {
                    //actualScreen.source = "Cores2D.qml"
                    actualScreen.replace("Cores2D.qml", {listNodes : nodesList})
                }
            }
            Action {
                text: qsTr("&3D-View")
                onTriggered: {
                    //actualScreen.source = "Cores3D.qml";  // Lade die neue Quelle
                    actualScreen.replace("Cores3D.qml", {listNodes : nodesList})
                }
            }
        }*/

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
            //Action { text: qsTr("About") }
        }

        Menu {
            title: qsTr("Non-Visualization")

            Action {
                text: qsTr("MPI Program")
                onTriggered: {
                    var component = Qt.createComponent("Application_Start_without.qml");
                    var window = component.createObject(root);
                    window.show();
                }
            }
            Action {
                text: qsTr("MPI Program with Score-P")
                onTriggered: {
                    var component = Qt.createComponent("Application_Start_Scorep.qml");
                    var window = component.createObject(root);
                    window.show();
                }
            }
            Action {
                text: qsTr("OpenMP Program")
                onTriggered: {
                    var component = Qt.createComponent("Application_Start_OpenMP.qml");
                    var window = component.createObject(root);
                    window.show();
                }
            }
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
