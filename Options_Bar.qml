import QtQuick
import QtQuick.Layouts 6.3
import QtQuick.Controls 6.3

Item {
        id: item
        width: 250
        height: parent.height

        Rectangle {
            id: rectangle
            //anchors.fill: parent
            x: 0
            y: 0
            width: parent.width
            height: parent.height
            color: "#383936"

            ColumnLayout{
                //anchors.
                width: parent.width
                //height: parent.height
                Layout.alignment: Qt.AlignHCenter
                Layout.fillHeight: false
                Layout.leftMargin: 20
                Layout.fillWidth: false
                Layout.columnSpan: 2

                Text {
                    id: headline
                    //anchors.fill: parent
                    Layout.alignment: Qt.AlignHCenter
                    topPadding: 15
                    //bottomPadding: 20
                    horizontalAlignment: Text.AlignHCenter
                    font.family: "Helvetica"
                    font.pointSize: 22
                    text: qsTr("Options")
                    color: "white"
                }
                GridLayout{
                    width: parent.width
                    columns: 3
                    Layout.topMargin: 40
                    Layout.alignment: Qt.AlignHCenter

                    Button {
                        id: mpi_start_button
                        text: "Start MPI-Program"
                        palette.buttonText: "white"
                        palette.button: "#666666"

                        HoverHandler {
                            cursorShape: Qt.PointingHandCursor
                        }

                        onClicked:{
                            if(nodesList.db_connection){
                                nodesList.startBash(parseInt(np.text))
                                //nodesList.buildClusterComponents(parseInt(np.text))
                            }
                            else {

                            }
                        }
                    }
                    TextField {
                        id: np
                        color: "black"
                        maximumLength: 3
                        placeholderText: "400"
                        rightPadding: 1
                        text: "400"
                        inputMethodHints: "ImhFormattedNumbersOnly";
                        background: Rectangle {
                            color: "white"
                        }
                    }
                    Text {
                        color: "white"
                        text: "Procs"
                    }
                }

                ComboBox {
                    //width: parent
                    implicitWidth: 230
                    Layout.topMargin: 20
                    // Layout.bottomMargin: 100
                    Layout.alignment: Qt.AlignHCenter
                    font.pointSize: 11
                    HoverHandler {
                        cursorShape: Qt.PointingHandCursor
                    }

                    palette.button: "#666666"
                    palette.buttonText: "white"

                    model: ListModel {
                        id: model
                        ListElement {
                            text: "Send/Recv Ratio (per Proc)"

                        }
                        ListElement {
                            text: "Max Send Ratio (over all Procs)"
                            //font.pointSize: 11
                        }
                        ListElement {
                            text: "Max Recv Ratio (over all Procs)"
                            //font.pointSize: 11
                        }
                        //ListElement { text: "Wait Ratio" }
                    }
                    onActivated:{
                        option = currentValue;
                        if(option == "Send/Recv Ratio"){
                            gradient1 = "green"
                            gradient2 = "red"
                            gradient_text1 = "Send"
                            gradient_text2 = "Recv"
                        }
                        else if (option == "Max Send Ratio"){
                            gradient1 = "green"
                            gradient2 = "white"
                            gradient_text1 = "Max Send"
                            gradient_text2 = "No Send"
                        }
                        else if(option == "Max Recv Ratio"){
                            gradient1 = "white"
                            gradient2 = "red"
                            gradient_text1 = "No Recv"
                            gradient_text2 = "Max Recv"
                        }

                    }
                }
                Rectangle{
                    width: 10
                    height: 200
                    Layout.bottomMargin: -95
                    rotation: 90
                    gradient: Gradient {
                        GradientStop { position: 0.0; color: gradient2 }
                        GradientStop { position: 1.0; color: gradient1 }
                    }
                    Layout.alignment: Qt.AlignCenter

                }
                GridLayout{
                    width: parent.width
                    columns: 2
                    Layout.bottomMargin: 20
                    //Layout.alignment: Qt.AlignHCenter

                    Text {
                        text: gradient_text1
                        color: "white"
                        //anchors.left: parent.left
                        leftPadding: 10
                        Layout.fillWidth: true
                        //horizontalAlignment: Qt.AlignHLeft
                    }
                    Text {
                        text: gradient_text2
                        color: "white"
                        Layout.fillWidth: true
                        horizontalAlignment: Text.AlignRight
                        //anchors.right: parent.right
                        rightPadding: 10
                        //horizontalAlignment: Qt.AlignHRight
                        //Layout.alignment: Qt.AlignHRight
                    }
                }

                Text {
                    id: text2
                    text: qsTr("Communication-Type:")
                    color: "white"
                    font.pointSize: 12
                    Layout.alignment: Qt.AlignHCenter
                }
                CheckBox {
                    id: p2p_check
                    HoverHandler {
                        cursorShape: Qt.PointingHandCursor
                    }
                    Layout.alignment: Qt.AlignLeft
                    Layout.leftMargin: 40
                    checked: true
                    text: qsTr("P2P")
                    onCheckStateChanged: {
                        p2p = p2p_check.checkState
                    }
                }
                CheckBox {
                    id: coll_check
                    HoverHandler {
                        cursorShape: Qt.PointingHandCursor
                    }
                    Layout.alignment: Qt.AlignLeft
                    Layout.leftMargin: 40
                    checked: true
                    text: qsTr("Collective")
                    onCheckStateChanged: {
                        collective = coll_check.checkState
                    }
                }
                /*CheckBox {
                    checked: true
                    text: qsTr("One-Sided")
                }*/

                Text {
                    id: text3
                    text: qsTr("Time display:")
                    color: "white"
                    font.pointSize: 12
                    Layout.alignment: Qt.AlignHCenter
                    Layout.topMargin: 20
                }
                CheckBox {
                    id: secondly_check
                    HoverHandler {
                        cursorShape: Qt.PointingHandCursor
                    }
                    Layout.alignment: Qt.AlignLeft
                    Layout.leftMargin: 40
                    checked: true
                    text: qsTr("Secondly data")
                    onCheckStateChanged: {
                        if(secondly_check.checked == true) nodesList.time_display = 0;
                        total_check.checked = !secondly_check.checked
                    }
                }
                CheckBox {
                    id: total_check
                    HoverHandler {
                        cursorShape: Qt.PointingHandCursor
                    }
                    Layout.alignment: Qt.AlignLeft
                    Layout.leftMargin: 40
                    checked: false
                    text: qsTr("total data")
                    onCheckStateChanged: {
                        if(total_check.checked == true) nodesList.time_display = 1;
                        secondly_check.checked = !total_check.checked
                    }
                }
            }
        }

    }
