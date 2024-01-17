import QtQuick
import QtQuick.Layouts 6.3
import QtQuick.Controls 6.3

Item {
        id: item
        width: 200
        height: parent.height

        Rectangle {
            id: rectangle
            //anchors.fill: parent
            x: 0
            y: 0
            width: parent.width
            height: parent.height
            color: "black"

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
                    columns: 2
                    Layout.topMargin: 40
                    Layout.alignment: Qt.AlignHCenter

                    Button {
                        text: "Start MPI-Program"
                        onClicked:{
                            if(nodesList.db_connection){
                                nodesList.startBash(parseInt(np.text))
                                nodesList.buildClusterComponents(parseInt(np.text))
                            }
                            else {

                            }
                        }
                    }
                    TextInput {
                        id: np
                        color: "white"
                        text: "400"
                        inputMethodHints: "ImhFormattedNumbersOnly";
                    }
                }

                ComboBox {
                    //width: parent
                    implicitWidth: 160
                    Layout.topMargin: 20
                    Layout.bottomMargin: 100
                    Layout.alignment: Qt.AlignHCenter
                    font.pointSize: 12
                    model: ListModel {
                        id: model
                        ListElement { text: "Send/Recv Ratio" }
                        ListElement { text: "Max Send Ratio" }
                        ListElement { text: "Max Recv Ratio" }
                        ListElement { text: "Wait Ratio" }
                    }
                    onActivated:
                        option = currentValue;
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
