import QtQuick
import QtQuick.Controls
import QtQuick.Layouts 6.3
import QtQuick.Dialogs

Rectangle {
    id: option_views
    width: 250
    height: 220
    implicitHeight: 220
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

            Rectangle {
                id: slider_rect
                width: parent.width
                height: 80
                color: "transparent"
                Layout.alignment: Qt.AlignHCenter
                visible: two_d_check.checked

                ColumnLayout {
                    anchors.fill: parent
                    //anchors.margins: 5

                    Text {
                        text: "Columns:   " + mySlider.value.toFixed(0)
                        color: "#999999"
                        font.pointSize: 12
                    }

                    Slider {
                        id: mySlider
                        from: 1      // Minimalwert
                        to: 32       // Maximalwert
                        stepSize: 1  // Schrittweite
                        value: 10    // Initialwert
                        Layout.alignment: Qt.AlignHCenter

                        onValueChanged: {
                            view.twoD_columns = value;
                        }

                        background: Rectangle {
                            x: mySlider.leftPadding
                            y: mySlider.topPadding + mySlider.availableHeight/2 - height/2
                            implicitWidth: 200
                            width: mySlider.availableWidth
                            implicitHeight: 5
                            height: 5
                            color: "#00FF00"
                        }
                    }

                    RowLayout {
                        //spacing: 10
                        //Layout.leftMargin: mySlider.leftPadding
                        Layout.alignment: Qt.AlignHCenter
                        Layout.fillWidth: mySlider.availableWidth
                        Layout.preferredWidth: mySlider.width

                        Text {
                            text: mySlider.from
                            font.pixelSize: 14
                            color: "#999999"
                            Layout.alignment: Qt.AlignLeft
                            //Layout.preferredWidth: mySlider.width / 3
                        }

                        Text {
                            text: mySlider.to
                            font.pixelSize: 14
                            color: "#999999"
                            Layout.alignment: Qt.AlignRight
                            //Layout.preferredWidth: mySlider.width / 3
                        }
                    }
                }
            }

            Rectangle {
                id: communication_lines_checker
                width: parent.width
                height: 100
                color: "transparent"
                Layout.alignment: Qt.AlignHCenter
                visible: three_d_check.checked

                ColumnLayout{
                    anchors.fill: parent

                    Text {
                        width: rectangle.width
                        text: qsTr("Show detailed communication links:")
                        font.pointSize: 12
                        Layout.alignment: Qt.AlignHCenter
                        Layout.preferredWidth: parent.width
                        Layout.fillWidth: true
                        wrapMode: Text.WordWrap
                        color: "#999999"
                    }

                    Switch {
                        id: sendlines
                        HoverHandler {
                            cursorShape: Qt.PointingHandCursor
                        }
                        Layout.alignment: Qt.AlignCenter
                        Layout.leftMargin: 40
                        checked: false
                        text: qsTr("P2P - Send lines")
                    }
                    Switch {
                        id: recvlines
                        HoverHandler {
                            cursorShape: Qt.PointingHandCursor
                        }
                        Layout.alignment: Qt.AlignCenter
                        Layout.leftMargin: 40
                        checked: false
                        text: Text {
                            text: "test"
                        }

                        //qsTr("P2P - Recv lines")
                        //text.color: "#999999"
                    }
                }
                /*Rectangle {
                id: slider_rect_3D
                width: parent.width
                height: 80
                color: "transparent"
                Layout.alignment: Qt.AlignHCenter
                visible: three_d_check.checked

                ColumnLayout {
                    anchors.fill: parent
                    //anchors.margins: 5

                    Text {
                        text: "Depth:   " + slider_3D.value.toFixed(0)
                        color: "white"
                        font.pointSize: 12
                    }

                    Slider {
                        id: slider_3D
                        from: 1      // Minimalwert
                        to: 32       // Maximalwert
                        stepSize: 1  // Schrittweite
                        value: 10    // Initialwert
                        Layout.alignment: Qt.AlignHCenter

                        onValueChanged: {
                            view.threeD_depth = value;
                        }

                        background: Rectangle {
                            x: slider_3D.leftPadding
                            y: slider_3D.topPadding + slider_3D.availableHeight/2 - height/2
                            implicitWidth: 200
                            width: slider_3D.availableWidth
                            implicitHeight: 5
                            height: 5
                            color: "#00FF00"
                            }
                        }

                        RowLayout {
                            //spacing: 10
                            //Layout.leftMargin: slider_3D.leftPadding
                            Layout.alignment: Qt.AlignHCenter
                            Layout.fillWidth: slider_3D.availableWidth
                            Layout.preferredWidth: slider_3D.width

                            Text {
                                text: slider_3D.from
                                font.pixelSize: 14
                                color: "gray"
                                Layout.alignment: Qt.AlignLeft
                                //Layout.preferredWidth: slider_3D.width / 3
                            }

                            Text {
                                text: slider_3D.to
                                font.pixelSize: 14
                                color: "gray"
                                Layout.alignment: Qt.AlignRight
                                //Layout.preferredWidth: slider_3D.width / 3
                            }
                        }
                    }
                }*/
            }
        }
    }
}



