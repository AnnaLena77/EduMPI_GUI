import QtQuick
import QtQuick.Controls 6.3
import QtQuick.Layouts 6.3

ApplicationWindow {
    id: root
    width: 1200
    height: 800
    visible: true
    title: "My App"

    //
    // macOS: MenuBar muss hierhin, damit sie oben in der System-Menüleiste auftaucht
    //
    menuBar: MenuBar {
        id: macMenuBar
        visible: Qt.platform.os === "osx"
        nativeMenuBar: true

        Menu {
            title: qsTr("Settings")

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
            title: qsTr("Help")
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
            title: qsTr("Non-Visualization")
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
    }

    //
    // Win/Linux: MenuBar im Fenster (z.B. als header), damit du sie stylen kannst
    //
    header: Item {
        height: (Qt.platform.os === "osx") ? 0 : 30
        visible: Qt.platform.os !== "osx"

        MenuBar {
            id: inWindowMenuBar
            anchors.fill: parent
            nativeMenuBar: false

            background: Rectangle { color: "#383936" }

            Menu {
                title: qsTr("Settings")
                background: Rectangle {
                    implicitWidth: 220
                    color: "#383936"
                    border.color: "black"
                }

                // Hier kannst du gern wieder deine RichText-Strings verwenden,
                // aber sauberer ist Styling über delegate.
                Action {
                    text: qsTr("Cluster Connection")
                    onTriggered: macMenuBar.menus[0].actions[0].trigger() // optional: gleiche Logik nutzen
                }
                Action {
                    text: qsTr("Database Connection")
                    onTriggered: macMenuBar.menus[0].actions[1].trigger()
                }
                Action {
                    text: qsTr("Load EduMPI-Run from DB")
                    onTriggered: macMenuBar.menus[0].actions[2].trigger()
                }
                MenuSeparator { }
            }

            Menu {
                title: qsTr("Help")
                background: Rectangle {
                    implicitWidth: 220
                    color: "#383936"
                    border.color: "black"
                }
                Action {
                    text: qsTr("SSH-Key-Gen Guide")
                    onTriggered: macMenuBar.menus[1].actions[0].trigger()
                }
            }

            Menu {
                title: qsTr("Non-Visualization")
                background: Rectangle {
                    implicitWidth: 260
                    color: "#383936"
                    border.color: "black"
                }
                Action { text: qsTr("MPI Program"); onTriggered: macMenuBar.menus[2].actions[0].trigger() }
                Action { text: qsTr("MPI Program with Score-P"); onTriggered: macMenuBar.menus[2].actions[1].trigger() }
                Action { text: qsTr("OpenMP Program"); onTriggered: macMenuBar.menus[2].actions[2].trigger() }
            }

            delegate: MenuBarItem {
                contentItem: Text {
                    text: parent.text
                    font: parent.font
                    color: "white"
                    verticalAlignment: Text.AlignVCenter
                    elide: Text.ElideRight
                }
            }
        }
    }

    // Dein restlicher Content
    Rectangle {
        anchors.fill: parent
        color: "#202020"
    }
}

