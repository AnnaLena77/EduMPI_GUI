import QtQuick
import QtQuick.Layouts 6.3
import QtQuick.Controls 6.3
import QtQuick.Dialogs

Item {
        width: 200
        height: parent.height

        Rectangle {
            id: rectangle
            x: 0
            y: 0
            width: parent.width
            height: parent.height
            color: "black"

        ToolBar {
                    Button {
                        text: qsTr("Choose Image...")
                        onClicked: fileDialog.open()
                    }
                }

                FileDialog {
                    id: fileDialog
                    currentFolder: StandardPaths.standardLocations(StandardPaths.PicturesLocation)[0]
                    //onAccepted: image.source = selectedFile
                }
        }

    }
