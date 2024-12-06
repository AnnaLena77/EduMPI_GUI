import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    id: bash_skript
    visible: true
    width: 800
    height: 500
    title: "Edit Bash Skript manually"

    ColumnLayout{
        //anchors.fill: parent
        height: parent.height
        width: parent.width

        ScrollView{
            Layout.fillHeight: true
            Layout.fillWidth: true
            //width: bash_skript.width

            RowLayout {
                width: bash_skript.width
                //height: parent
                    ListView {
                        Layout.preferredWidth: 30
                        Layout.fillHeight: true
                        model: textEdit.text.split(/\n/g)
                        delegate: Text {
                            text: index + 1
                            font.family: "Courier"
                            font.pixelSize: 14
                        }
                    }
                    TextEdit {
                        id: textEdit
                        //width: 800
                        //height: 600
                        width: parent
                        wrapMode: TextEdit.Wrap
                        Layout.fillWidth: true
                        Layout.fillHeight: parent
                        text: nodesList.readBash()
                        font.family: "Courier"
                        font.pixelSize: 14
                        color: "black"
                        focus: true
                    }
                }
        }
        Button{
            id: changeBashButton
            text: "Submit"
            padding: 10
            onClicked: {
                nodesList.writeBash(textEdit.text)
                bash_skript.close()
            }
            HoverHandler {
                cursorShape: Qt.PointingHandCursor
            }
            palette.buttonText: "white"
            palette.button: "#666666"
        }
        Keys.onPressed: (event)=> {
            if (event.key === Qt.Key_Return || event.key === Qt.Key_Enter) {
                changeBashButton.clicked(); // Auslösen des Button-Klicks
            }
        }
    }
}
