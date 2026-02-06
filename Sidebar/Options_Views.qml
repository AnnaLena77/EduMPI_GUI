import QtQuick
import QtQuick.Controls
import QtQuick.Layouts 6.3
import QtQuick.Dialogs

Rectangle {
    id: option_views
    width: 250
    height: 300
    implicitHeight: 300
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

        ButtonGroup {
            id: checkboxgroup
        }

        ColumnLayout{
            width: rectangle.width
            anchors.fill: parent
            //height: parent.height
            Layout.alignment: Qt.AlignRight
            Layout.fillWidth: true
            anchors.margins: 5

            Text {
                id: text_view
                text: qsTr("Select representation view:")
                topPadding: 6
                color: "#00FF00"
                //font.pointSize: 12
                //Layout.alignment: Qt.AlignHCenter
            }


            CheckBox {
                id: three_d_check
                ButtonGroup.group: checkboxgroup
                HoverHandler {
                    cursorShape: Qt.PointingHandCursor
                }
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignRight
                Layout.rightMargin: 40
                checked: true
                text: qsTr("3D Nodes (Cube View)")
                onCheckStateChanged: {
                    if(checked){
                        selected_screen = "Cores3D"
                        view.replace("/Cores3D.qml", {listNodes : nodesList})
                        //three_d_check.checked = false
                        //cm_check.checked = false
                    }
                    //two_d_check.checked = !three_d_check.checked && !cm_check.checked
                }
            }
            CheckBox {
                id: two_d_check
                ButtonGroup.group: checkboxgroup
                HoverHandler {
                    cursorShape: Qt.PointingHandCursor
                }
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignRight
                Layout.rightMargin: 40
                checked: false
                text: qsTr("2D Nodes (List View)")
                onCheckStateChanged: {
                    if(checked){
                        selected_screen = "Cores2D"
                        view.replace("/Cores2D.qml", {listNodes : nodesList})
                        //two_d_check.checked = false
                        //cm_check.checked = false
                    }
                    //three_d_check.checked = !two_d_check.checked && !cm_check.checked
                }
            }
            CheckBox {
                id: cm_check
                ButtonGroup.group: checkboxgroup
                HoverHandler {
                    cursorShape: Qt.PointingHandCursor
                }
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignRight
                Layout.rightMargin: 40
                checked: false
                text: qsTr("Communication Matrix")
                onCheckStateChanged: {
                    if(checked){
                        selected_screen = "CoresMatrix"
                        view.replace("/CoresCommunicationMatrix.qml", {listNodes : nodesList})
                        //three_d_check.checked = false
                        //two_d_check.checked = false
                    }
                    //cm_check.checked = !two_d_check.checked && !three_d_check.checked
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
                        text: qsTr("Show detailed MPI communication patterns:")
                        //font.pointSize: 12
                        Layout.alignment: Qt.AlignHCenter
                        Layout.preferredWidth: parent.width
                        Layout.fillWidth: true
                        wrapMode: Text.WordWrap
                        color: "#999999"
                    }
                    Row {
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        spacing: 8

                        Switch {
                            id: sendlines
                            HoverHandler {
                                cursorShape: Qt.PointingHandCursor
                            }

                            indicator: Rectangle{
                                radius: 13
                                color: sendlines.checked ? "#00FF00" : "#999999"
                                implicitHeight: 20
                                implicitWidth:  40
                                x: sendlines.width - width - sendlines.rightPadding
                                y: parent.height / 2 - height /2
                                border.color: "#999999"

                                Rectangle {
                                    x: sendlines.checked ? parent.width - width : 0
                                    width: 20
                                    height: 20
                                    radius: 13
                                    border.color: "#999999"
                                }
                            }

                            //Layout.alignment: Qt.AlignRight
                            Layout.alignment: Qt.AlignVCenter
                            //Layout.rightMargin: 40
                            checked: false

                            onCheckedChanged: {
                                if(checked){
                                    p2p_send_lines = true
                                } else {
                                    p2p_send_lines = false
                                }
                            }
                        }

                        Text {
                            text: "P2P - Send arrows"
                            color: "#999999"
                            Layout.alignment: Qt.AlignBottom
                            Layout.fillHeight: true
                            Layout.preferredHeight: sendlines.height
                        }
                    }

                    Row {
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        spacing: 8

                        Switch {
                            id: recvlines
                            HoverHandler {
                                cursorShape: Qt.PointingHandCursor
                            }

                            indicator: Rectangle{
                                radius: 13
                                color: recvlines.checked ? "red" : "#999999"
                                implicitHeight: 20
                                implicitWidth:  40
                                x: recvlines.width - width - recvlines.rightPadding
                                y: parent.height / 2 - height /2
                                border.color: "#999999"

                                Rectangle {
                                    x: recvlines.checked ? parent.width - width : 0
                                    width: 20
                                    height: 20
                                    radius: 13
                                    border.color: "#999999"
                                }
                            }

                            //Layout.alignment: Qt.AlignRight
                            Layout.alignment: Qt.AlignVCenter
                            Layout.rightMargin: 40
                            checked: false

                            onCheckedChanged: {
                                if(checked){
                                    p2p_recv_lines = true
                                } else {
                                    p2p_recv_lines = false
                                }
                            }
                        }
                        Text {
                            text: "P2P - Recv arrows"
                            color: "#999999"
                            Layout.alignment: Qt.AlignVCenter
                            Layout.fillHeight: true
                        }

                    }
                    Row {
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        spacing: 8

                        Switch {
                            id: colllines
                            HoverHandler {
                                cursorShape: Qt.PointingHandCursor
                            }

                            indicator: Rectangle{
                                radius: 13
                                color: colllines.checked ? "black" : "#999999"
                                implicitHeight: 20
                                implicitWidth:  40
                                x: colllines.width - width - colllines.rightPadding
                                y: parent.height / 2 - height /2
                                border.color: "#999999"

                                Rectangle {
                                    x: colllines.checked ? parent.width - width : 0
                                    width: 20
                                    height: 20
                                    radius: 13
                                    border.color: "#999999"
                                }
                            }

                            //Layout.alignment: Qt.AlignRight
                            Layout.alignment: Qt.AlignVCenter
                            Layout.rightMargin: 40
                            checked: false

                            onCheckedChanged: {
                                if(checked){
                                    coll_lines = true
                                    nodesList.p2pData
                                } else {
                                    coll_lines = false
                                }
                            }
                        }
                        Text {
                            text: "Collective arrows"
                            color: "#999999"
                            Layout.alignment: Qt.AlignVCenter
                            //Layout.fillHeight: true
                        }

                    }
                }
            }
            Rectangle {
                id: slider_rect_zoom
                width: parent.width
                height: 80
                color: "transparent"
                Layout.alignment: Qt.AlignHCenter
                visible: cm_check.checked

                ColumnLayout {
                    anchors.fill: parent
                    //anchors.margins: 5

                    Text {
                        text: "Zoom:   " + mySlider_zoom.value.toFixed(0) + "%"
                        color: "#999999"
                        font.pointSize: 12
                    }

                    Slider {
                        id: mySlider_zoom
                        from: 20      // Minimalwert
                        to: 300       // Maximalwert
                        stepSize: 10  // Schrittweite
                        value: 100    // Initialwert
                        Layout.alignment: Qt.AlignHCenter

                        onValueChanged: {
                            //view.twoD_columns = value;
                            view.matrix_zoom = value;
                        }

                        background: Rectangle {
                            x: mySlider_zoom.leftPadding
                            y: mySlider_zoom.topPadding + mySlider_zoom.availableHeight/2 - height/2
                            implicitWidth: 200
                            width: mySlider_zoom.availableWidth
                            implicitHeight: 5
                            height: 5
                            color: "#00FF00"
                        }
                    }

                    RowLayout {
                        //spacing: 10
                        //Layout.leftMargin: mySlider.leftPadding
                        Layout.alignment: Qt.AlignHCenter
                        Layout.fillWidth: mySlider_zoom.availableWidth
                        Layout.preferredWidth: mySlider_zoom.width

                        Text {
                            text: mySlider_zoom.from + "%"
                            font.pixelSize: 14
                            color: "#999999"
                            Layout.alignment: Qt.AlignLeft
                            //Layout.preferredWidth: mySlider.width / 3
                        }

                        Text {
                            text: mySlider_zoom.to + "%"
                            font.pixelSize: 14
                            color: "#999999"
                            Layout.alignment: Qt.AlignRight
                            //Layout.preferredWidth: mySlider.width / 3
                        }
                    }
                }
            }
        }
    }
}



