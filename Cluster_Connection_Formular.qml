import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs

Window {
    id: bashGeneration
    visible: true
    width: 600
    height: 400
    title: "Login to HPC@HS-Fulda"

    ScrollView{
        anchors.fill: parent

        Rectangle{
            width: parent
        }
        ColumnLayout {
            anchors.fill: parent
            Layout.fillWidth: true
            anchors.margins: 5
            spacing: 4

            Label {
                text: "Remote Hostname - HPC Cluster HS Fulda (10.32.47.10):"
                color: "#999999"
            }

            TextField {
                id: hostnameField
                Layout.fillWidth: true
                text: "10.32.47.10"
                //placeholderText: "<Enter host running MQTT broker>"
                background: Rectangle {
                    color: "#4d4d4d"
                }
            }

            Label {
                text: "FDAI authentication key:"
                color: "#999999"
            }

            TextField {
                id: fdaiField
                Layout.fillWidth: true
                text: "fdai0231"
                placeholderText: "<fd number>"
                //inputMethodHints: Qt.ImhDigitsOnly
                background: Rectangle {
                    color: "#4d4d4d"
                }
            }

            Label {
                text: "EduMPI installation path (standard: /EduMPI_Install)"
                color: "#999999"
            }

            TextField {
                id: installpathField
                text: "/EduMPI_Testumgebung"
                Layout.fillWidth: true
                placeholderText: "<installation path>"
                background: Rectangle {
                    color: "#4d4d4d"
                }
            }

            Label {
                text: "Choose a .c file or a full folder that includes your program"
                color: "#999999"
            }

            GridLayout{
                columns: 2

                /*Label {
                    text: ".c File"
                }
                Switch{
                    text: "test"
                }
                Label {
                    text: "Folder"
                }*/
                RadioButton{
                    id: fileButton
                    text: ".c File"
                    checked: true
                    HoverHandler {
                        cursorShape: Qt.PointingHandCursor
                    }
                }
                RadioButton{
                    id: folderButton
                    text: "Folder"
                    checked: false
                    HoverHandler {
                        cursorShape: Qt.PointingHandCursor
                    }
                }

            }

            /*TextField {
                id:
                text: "/EduMPI_Testumgebung"
                Layout.fillWidth: true
                placeholderText: "<installation path>"
            }*/
            GridLayout{
                width: bashGeneration.width
                //width: bashGeneration.width
                //anchors.right: parent
                //anchors.margins: 5
                columns: 2
                Button {
                    text: "Upload " + (fileButton.checked ? "File" : "Folder");
                    background: Rectangle {
                        color: "#C0C0C0"
                    }
                    HoverHandler {
                            id: stylus
                            cursorShape: Qt.PointingHandCursor
                    }
                    onClicked: {
                        fileButton.checked ? fileDialog.open() : folderDialog.open()
                    }
                }
                TextField{
                    Layout.fillWidth: true
                    //width: 400
                    id: uploadPath
                    text: ""
                    background: Rectangle {
                        color: "#4d4d4d"
                    }
                }
            }

            FileDialog {
            id: fileDialog
                //currentFolder: StandardPaths.standardLocations(StandardPaths.PicturesLocation)[0]
                onAccepted: uploadPath.text = selectedFile
            }
            FolderDialog {
            id: folderDialog
                //currentFolder: StandardPaths.standardLocations(StandardPaths.PicturesLocation)[0]
                onAccepted: uploadPath.text = selectedFolder
            }

            Label {
                text: "name of the program to be executed"
                color: "#999999"
            }

            GridLayout{
                width: bashGeneration.width
                columns: 2

                TextField {
                    id: programNameField
                    //text: ""
                    Layout.fillWidth: true
                    placeholderText: "<program name>"
                    background: Rectangle {
                        color: "#4d4d4d"
                    }
                }
                Label {
                    text: ".c"
                    color: "#999999"
                }

            }

            Button {
                id: connectButton
                text: "Generate Bash-Skript"
                HoverHandler {
                        cursorShape: Qt.PointingHandCursor
                }
                Layout.columnSpan: 1
                Layout.fillWidth: true
                onClicked: {
                    nodesList.createBashSkript(hostnameField.text, fdaiField.text, installpathField.text, uploadPath.text, programNameField.text, fileButton.checked)
                    bashGeneration.close()
                }
            }
            Keys.onPressed: (event)=> {
                if (event.key === Qt.Key_Return || event.key === Qt.Key_Enter) {
                    connectButton.clicked(); // Auslösen des Button-Klicks
                }
            }
        }

    }
}
