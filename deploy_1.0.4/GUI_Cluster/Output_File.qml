import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

//icons: https://fontawesome.com

Window {
    id: outputfile
    property string path: ""
    property bool success

    title: "Slurm Job Finished!"
    visible: true
    width: 300
    height: 200
    maximumHeight: 200
    maximumWidth: 300

    ColumnLayout {
        anchors.fill: parent
        width: parent.width
        Layout.alignment: Qt.AlignVCenter
        Layout.fillWidth: true
        anchors.margins: 3

        RoundButton{
            id: xmark
            //scale: 2.0
            //anchors.rightMargin: 10
            icon.width: 40
            icon.height: 40
            icon.source: outputfile.success ? "qrc:/icons/checkmark.png" : "qrc:/icons/xmark.png"
            icon.color: outputfile.success ?"green" : "red"
            background: Rectangle{
                color: "transparent"
                border.width: 0
            }
            Layout.alignment: Qt.AlignHCenter
            Layout.bottomMargin: -10
            //Layout.fillHeight: true
            //Layout.fillWidth: true
        }


        Text {
            text: outputfile.success ? "The Slurm job has been completed. \nOutput: " + outputfile.path :
                                       "Your Slurm job ended unexpectedly or you started no MPI Program. \nSee Output: " + path
            Layout.fillWidth: true
            wrapMode: Text.WordWrap
            Layout.margins: 5
        }

        Button {
            id: ok_button
            text: "OK"
            HoverHandler {
                cursorShape: Qt.PointingHandCursor
            }
            onClicked: outputfile.close()
            Layout.alignment: Qt.AlignHCenter
        }
        Keys.onPressed: (event)=> {
            if (event.key === Qt.Key_Return || event.key === Qt.Key_Enter) {
                ok_button.clicked(); // Auslösen des Button-Klicks
            }
        }
    }
}
