import QtQuick
import QtQuick.Controls
import QtQuick.Layouts 6.3
import QtQuick.Dialogs

Rectangle {
    id: option_views
    width: 250
    height: 150
    implicitHeight: 150
    color: "#383936"

    Rectangle {
        id: rectangle
        //anchors.fill: parent
        x: 5
        y: 5
        radius: 10
        width: parent.width - 10
        anchors.leftMargin:  5
        height: parent.height - 10
        border.width: 2
        border.color: "#00FF00"
        color: "transparent"

        ColumnLayout{
            width: rectangle.width
            anchors.fill: parent
            //height: parent.height
            Layout.alignment: Qt.AlignHCenter
            Layout.fillWidth: true
            anchors.margins: 5

            Text {
                id: text_view
                text: qsTr("Take a Screenshot of EduMPI Window")
                color: "white"
                font.pointSize: 12
                Layout.alignment: Qt.AlignHCenter
                width: parent.width
                Layout.fillWidth: true
                wrapMode: Text.WordWrap
            }
            Button {
                text: "Take Screenshot"
                Layout.alignment: Qt.AlignCenter
                onClicked: {
                    screenshot()
                }
            }

        }
    }
    function screenshot() {
        const screen = Screen;
        const savePath = "EduMPI_Screenshot_" + Date.now() + ".png";
        const picturesPath = homeDirectory + "/Pictures/";
        const filePath = picturesPath + "EduMPI_Screenshot_" + Date.now() + ".png"; // Zeitstempel für einzigartigen Namen

        rootScreen.grabToImage(function(result) {
            result.saveToFile(filePath)
        })
        console.log("Screenshot saved to", filePath);
    }

}
