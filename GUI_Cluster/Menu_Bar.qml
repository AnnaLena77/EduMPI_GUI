import QtQuick
import QtQuick.Layouts 6.3
import QtQuick.Controls 6.3

Item {
    id: menu_bar_item
    width: parent ? parent.width : 0
    height: Qt.platform.os === "osx" ? 0 : 30

    MenuBar {
        id: menu
        anchors.fill: parent

        // macOS: use global system menubar (native)
        // Win/Linux: draw menubar inside the window (non-native) so styling works
        nativeMenuBar: (Qt.platform.os === "osx")

        // Only relevant for non-native (Win/Linux). On macOS this won't be drawn in-window.
        background: Rectangle {
            color: "#383936"
        }

        Menu {
            id: settingsMenu
            title: qsTr("Settings")

            // Primarily affects non-native popup menus (Win/Linux). Native menus on macOS are OS-styled.
            background: Rectangle {
                implicitWidth: 220
                color: "#383936"
                border.color: "black"
            }

            Action {
                text: qsTr("Cluster Connection")
                onTriggered: {
                    var component = Qt.createComponent("Cluster_Connection_Formular.qml")
                    var window = component.createObject(root)
                    window.show()
                }
            }

            Action {
                text: qsTr("Database Connection")
                onTriggered: {
                    var component = Qt.createComponent("DB_Connection_Formular.qml")
                    var window = component.createObject(root)
                    window.show()
                }
            }

            Action {
                text: qsTr("Load EduMPI-Run from DB")
                onTriggered: {
                    var component, window
                    if (controller.db_connection && controller.cluster_connection) {
                        var fd_id = controller.getClusterIdent()
                        // controller.getJobTable().loadJobs(fd_id);

                        component = Qt.createComponent("Table_Userid_Selection.qml")
                        window = component.createObject(root)
                        window.show()
                    } else {
                        component = Qt.createComponent("Error.qml")
                        window = component.createObject(root, {
                            "message": "First, please establish a connection to the cluster and the database!"
                        })
                        window.x = (root.width - window.width) / 2
                        window.y = (root.height - window.height) / 2
                        window.show()
                    }
                }
            }

            MenuSeparator { }
        }

        Menu {
            id: helpMenu
            title: qsTr("Help")

            background: Rectangle {
                implicitWidth: 220
                color: "#383936"
                border.color: "black"
            }

            Action {
                text: qsTr("SSH-Key-Gen Guide")
                onTriggered: {
                    var component = Qt.createComponent("Key_Gen_Guide.qml")
                    var window = component.createObject(root)
                    window.show()
                }
            }
        }

        Menu {
            id: nonVisMenu
            title: qsTr("Non-Visualization")

            background: Rectangle {
                implicitWidth: 260
                color: "#383936"
                border.color: "black"
            }

            Action {
                text: qsTr("MPI Program")
                onTriggered: {
                    var component = Qt.createComponent("Application_Start_without.qml")
                    var window = component.createObject(root)
                    window.show()
                }
            }

            Action {
                text: qsTr("MPI Program with Score-P")
                onTriggered: {
                    var component = Qt.createComponent("Application_Start_Scorep.qml")
                    var window = component.createObject(root)
                    window.show()
                }
            }

            Action {
                text: qsTr("OpenMP Program")
                onTriggered: {
                    var component = Qt.createComponent("Application_Start_OpenMP.qml")
                    var window = component.createObject(root)
                    window.show()
                }
            }
        }

        // Menubar item styling for Win/Linux (non-native). On macOS nativeMenuBar is true.
        delegate: MenuBarItem {
            id: menuBarItem

            contentItem: Text {
                text: menuBarItem.text
                font: menuBarItem.font
                color: "white"
                verticalAlignment: Text.AlignVCenter
                elide: Text.ElideRight
            }
        }
    }
}
