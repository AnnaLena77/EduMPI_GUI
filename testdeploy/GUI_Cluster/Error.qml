import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

//icons: https://fontawesome.com

Window {
    id: error
    property string message: ""

    title: "Error"
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
            icon.source: "qrc:/icons/xmark.png"
            icon.color: "red"
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
            text: error.message
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
            onClicked: error.close()
            Layout.alignment: Qt.AlignHCenter
        }
        Keys.onPressed: (event)=> {
            if (event.key === Qt.Key_Return || event.key === Qt.Key_Enter) {
                ok_button.clicked(); // Auslösen des Button-Klicks
            }
        }
    }
}
