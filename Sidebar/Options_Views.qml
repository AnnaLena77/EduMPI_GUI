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

    property StackView view;

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
                text: qsTr("Select representation view:")
                color: "white"
                font.pointSize: 12
                Layout.alignment: Qt.AlignHCenter
            }
            CheckBox {
                id: three_d_check
                HoverHandler {
                    cursorShape: Qt.PointingHandCursor
                }
                Layout.alignment: Qt.AlignLeft
                Layout.leftMargin: 40
                checked: true
                text: qsTr("3D Nodes (Cube View)")
                onCheckStateChanged: {
                    if(checked){
                        view.replace("/Cores3D.qml", {listNodes : nodesList})
                    }
                    two_d_check.checked = !three_d_check.checked
                }
            }
            CheckBox {
                id: two_d_check
                HoverHandler {
                    cursorShape: Qt.PointingHandCursor
                }
                Layout.alignment: Qt.AlignLeft
                Layout.leftMargin: 40
                checked: false
                text: qsTr("2D Nodes (List View)")
                onCheckStateChanged: {
                    if(checked){
                        view.replace("/Cores2D.qml", {listNodes : nodesList})
                    }
                    three_d_check.checked = !two_d_check.checked
                }
            }
        }

    }
}

