import QtQuick
import QtQuick.Controls
import QtQuick.Layouts 6.3
import QtQuick.Dialogs

Rectangle {
    id: options
    width: 250
    height: 500
    implicitHeight: 500
    color: "#383936"

    property string screen: selected_screen;

    onScreenChanged: {
        combo.updateComboOptions()

    }

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

            ComboBox {
                id: combo
                implicitWidth: 230
                Layout.topMargin: 20
                Layout.alignment: Qt.AlignHCenter
                font.pointSize: 10

                property bool useMultiColorGradient: false
                property string gradient1: "white"
                property string gradient2: "blue"
                property string gradient3: ""
                property string gradient4: ""
                property string gradient_text1: ""
                property string gradient_text2: ""

                HoverHandler {
                    cursorShape: Qt.PointingHandCursor
                }

                palette.button: "#666666"
                palette.buttonText: "white"

                model: ListModel {
                    id: comboModel
                }

                Component.onCompleted: updateComboOptions()

                function updateComboOptions() {
                    comboModel.clear()

                    if (screen === "CoresMatrix") {
                        comboModel.append({ text: "heatmap - message volume" })
                        //comboModel.append({ text: "max send ratio (across all procs)" })
                        //comboModel.append({ text: "max recv ratio (across all procs)" })
                    } else {
                        comboModel.append({ text: "send/recv ratio (per proc)" })
                        comboModel.append({ text: "max send ratio (across all procs)" })
                        comboModel.append({ text: "max recv ratio (across all procs)" })
                        comboModel.append({ text: "wait for late sender (per proc)" })
                        comboModel.append({ text: "wait for late recver (per proc)" })
                    }

                    combo.currentIndex = 0
                    option = combo.currentText
                    setComboColors(option)
                }

                function setComboColors(value) {
                    // Standard 2-Farben-Verläufe
                    if (option === "send/recv ratio (per proc)") {
                        useMultiColorGradient = false
                        gradient1 = "green"
                        gradient2 = "red"
                        gradient3 = ""
                        gradient4 = ""
                        gradient_text1 = "Send"
                        gradient_text2 = "Recv"

                    } else if (option === "max send ratio (across all procs)") {
                        useMultiColorGradient = false
                        gradient1 = "green"
                        gradient2 = "white"
                        gradient3 = ""
                        gradient4 = ""
                        gradient_text1 = "Max Send"
                        gradient_text2 = "No Send"

                    } else if (option === "max recv ratio (across all procs)") {
                        useMultiColorGradient = false
                        gradient1 = "white"
                        gradient2 = "red"
                        gradient3 = ""
                        gradient4 = ""
                        gradient_text1 = "No Recv"
                        gradient_text2 = "Max Recv"

                    } else if (option === "wait for late sender (per proc)" || option === "wait for late recver (per proc)") {
                        useMultiColorGradient = false
                        gradient1 = "white"
                        gradient2 = "blue"
                        gradient3 = ""
                        gradient4 = ""
                        gradient_text1 = "low (%)"
                        gradient_text2 = "high (%)"

                    } else if (option === "heatmap - message volume") {
                        // 4-Farben-Verlauf
                        useMultiColorGradient = true
                        gradient1 = "blue"
                        gradient2 = "green"
                        gradient3 = "yellow"
                        gradient4 = "red"
                        gradient_text1 = "0%"
                        gradient_text2 = "total msg vol. (100%)"
                    }

                }

                onActivated: {
                    option = currentValue
                    setComboColors(currentValue)

                }
            }


            Rectangle {
                width: 10
                height: 200
                Layout.bottomMargin: -95
                rotation: 90
                Layout.alignment: Qt.AlignCenter

                gradient: Gradient {
                        GradientStop { position: 0.0; color: combo.gradient4 !== "" ? combo.gradient4 : combo.gradient2 }
                        GradientStop { position: 0.33; color: combo.useMultiColorGradient ? combo.gradient3 : combo.gradient2 }
                        GradientStop { position: 0.66; color: combo.useMultiColorGradient ? combo.gradient2 : combo.gradient1 }
                        GradientStop { position: 1.0; color: combo.gradient1 }

                }
            }

            GridLayout{
                width: parent.width
                columns: 2
                Layout.bottomMargin: 20
                //Layout.alignment: Qt.AlignHCenter

                Text {
                    text: combo.gradient_text1
                    color: "white"
                    //anchors.left: parent.left
                    leftPadding: 10
                    Layout.fillWidth: true
                    //horizontalAlignment: Qt.AlignHLeft
                }
                Text {
                    text: combo.gradient_text2
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
            CheckBox {
                id: osc_check
                HoverHandler {
                    cursorShape: Qt.PointingHandCursor
                }
                Layout.alignment: Qt.AlignLeft
                Layout.leftMargin: 40
                checked: true
                text: qsTr("One-Sided")
                onCheckStateChanged: {

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
                text: qsTr("per second")
                onCheckStateChanged: {
                    if(secondly_check.checked == true) nodesList.set_time_display(0);
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
                    if(total_check.checked == true) nodesList.set_time_display(1);
                    secondly_check.checked = !total_check.checked
                }
            }
        }

    }
}

