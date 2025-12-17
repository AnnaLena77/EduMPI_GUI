import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    property string heading: ""
    property real avgValue: 0
    property real maxValue: 0
    property string tooltipText: ""
    property var colorStops: ["#00ff00", "#ff0000"]

    color: Qt.rgba(1, 1, 1, 0.05)
    border.color: "#aaaaaa"
    border.width: 1
    radius: 6

    Layout.fillWidth: true
    Layout.preferredHeight: 50
    Layout.minimumHeight: 50

    RowLayout {
        anchors.fill: parent
        anchors.margins: 8
        spacing: 20

        RowLayout {
            spacing: 8
            Layout.alignment: Qt.AlignVCenter
            Layout.fillWidth: false

            Text {
                text: heading
                font.bold: true
                font.pixelSize: 14
                color: "white"
            }

            Rectangle {
                id: infoButton
                width: 16
                height: 16
                radius: 8
                color: mouseArea.containsMouse ? "#4a90e2" : "#666666"
                border.color: "#888888"
                border.width: 1

                Text {
                    text: "i"
                    font.pixelSize: 10
                    font.bold: true
                    color: "white"
                    anchors.centerIn: parent
                }

                MouseArea {
                    id: mouseArea
                    anchors.fill: parent
                    hoverEnabled: true
                    onEntered: tooltipTimer.start()
                    onExited: {
                        tooltipTimer.stop()
                        tooltip.visible = false
                    }
                }

                Timer {
                    id: tooltipTimer
                    interval: 500
                    onTriggered: tooltip.visible = true
                }

                Rectangle {
                    id: tooltip
                    visible: false
                    width: 350
                    height: tooltipTextItem.height + 16
                    x: infoButton.width + 5
                    y: -height/2 + infoButton.height/2
                    z: 100

                    color: "#2d2d2d"
                    border.color: "#555555"
                    border.width: 1
                    radius: 4

                    Text {
                        id: tooltipTextItem
                        anchors.centerIn: parent
                        anchors.margins: 8
                        width: parent.width - 16
                        text: tooltipText
                        font.pixelSize: 11
                        color: "white"
                        wrapMode: Text.WordWrap
                    }

                    Timer {
                        id: hideTimer
                        interval: 50000
                        running: tooltip.visible
                        onTriggered: tooltip.visible = false
                    }
                }
            }
        }

        Item {
            Layout.fillWidth: true
            Layout.maximumWidth: 100
        }

        // *** Bedingte Darstellung je nach Option ***
        ColumnLayout {
            id: color_legend
            spacing: 6
            Layout.alignment: Qt.AlignRight

            Loader {
                id: legendLoader
                Layout.alignment: Qt.AlignRight

                sourceComponent: {
                    if (heading.toLowerCase().includes("send/recv ratio")) {
                        return sendRecvRatioLegend
                    } else if (heading.toLowerCase().includes("wait for late")) {
                        return waitForLateLegend
                    } else {
                        return standardLegend
                    }
                }
            }
        }
    }

    // *** Standard Legende für alle anderen Optionen ***
    Component {
        id: standardLegend

        Column {
            spacing: 6

            Row {
                id: colorRow
                spacing: 3  // *** Standard: 3px Abstand ***

                Repeater {
                    model: 15
                    Rectangle {
                        width: 12  // *** Standard: 12px breit ***
                        height: 12
                        radius: 2
                        border.color: "#222"
                        border.width: 1

                        color: {
                            if (index === 0) {
                                return "#eeeeee";
                            }

                            let actualRatio = (index - 1) / 13.0;

                            if (colorStops.length === 2) {
                                let c1 = Qt.color(colorStops[0])
                                let c2 = Qt.color(colorStops[1])
                                return Qt.rgba(
                                    c1.r + actualRatio * (c2.r - c1.r),
                                    c1.g + actualRatio * (c2.g - c1.g),
                                    c1.b + actualRatio * (c2.b - c1.b),
                                    1.0
                                )
                            } else if (colorStops.length === 5) {
                                if (actualRatio < 0.25) {
                                    let t = actualRatio / 0.25;
                                    let c1 = Qt.color(colorStops[0])
                                    let c2 = Qt.color(colorStops[1])
                                    return Qt.rgba(
                                        c1.r + t * (c2.r - c1.r),
                                        c1.g + t * (c2.g - c1.g),
                                        c1.b + t * (c2.b - c1.b),
                                        1.0
                                    )
                                } else if (actualRatio < 0.5) {
                                    let t = (actualRatio - 0.25) / 0.25;
                                    let c1 = Qt.color(colorStops[1])
                                    let c2 = Qt.color(colorStops[2])
                                    return Qt.rgba(
                                        c1.r + t * (c2.r - c1.r),
                                        c1.g + t * (c2.g - c1.g),
                                        c1.b + t * (c2.b - c1.b),
                                        1.0
                                    )
                                } else if (actualRatio < 0.75) {
                                    let t = (actualRatio - 0.5) / 0.25;
                                    let c1 = Qt.color(colorStops[2])
                                    let c2 = Qt.color(colorStops[3])
                                    return Qt.rgba(
                                        c1.r + t * (c2.r - c1.r),
                                        c1.g + t * (c2.g - c1.g),
                                        c1.b + t * (c2.b - c1.b),
                                        1.0
                                    )
                                } else {
                                    let t = (actualRatio - 0.75) / 0.25;
                                    let c1 = Qt.color(colorStops[3])
                                    let c2 = Qt.color(colorStops[4])
                                    return Qt.rgba(
                                        c1.r + t * (c2.r - c1.r),
                                        c1.g + t * (c2.g - c1.g),
                                        c1.b + t * (c2.b - c1.b),
                                        1.0
                                    )
                                }
                            } else {
                                return "#ff0000"
                            }
                        }
                    }
                }
            }

            Item {
                width: colorRow.width
                height: 14

                Text {
                    text: "0"
                    font.pixelSize: 10
                    color: "white"
                    x: 0
                    anchors.verticalCenter: parent.verticalCenter
                }

                Text {
                    text: "Avg: " + parse_ds(avgValue)
                    font.pixelSize: 10
                    color: "white"
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                }

                Text {
                    text: "Max: " + parse_ds(maxValue)
                    font.pixelSize: 10
                    color: "white"
                    x: parent.width - width
                    anchors.verticalCenter: parent.verticalCenter
                }
            }
        }
    }

    // *** Wait For Late Legende ***
    Component {
        id: waitForLateLegend

        Column {
            spacing: 6

            Row {
                id: colorRow
                spacing: 3  // *** Standard: 3px Abstand ***

                Repeater {
                    model: 15
                    Rectangle {
                        width: 12  // *** Standard: 12px breit ***
                        height: 12
                        radius: 2
                        border.color: "#222"
                        border.width: 1

                        color: {
                            if (index === 0) {
                                return "#eeeeee";
                            }

                            let actualRatio = (index - 1) / 13.0;

                            if (colorStops.length === 2) {
                                let c1 = Qt.color(colorStops[0])
                                let c2 = Qt.color(colorStops[1])
                                return Qt.rgba(
                                    c1.r + actualRatio * (c2.r - c1.r),
                                    c1.g + actualRatio * (c2.g - c1.g),
                                    c1.b + actualRatio * (c2.b - c1.b),
                                    1.0
                                )
                            } else {
                                return "#ff0000"
                            }
                        }
                    }
                }
            }

            Item {
                width: colorRow.width
                height: 14

                Text {
                    text: "0%"
                    font.pixelSize: 9
                    color: "white"
                    x: 0
                    anchors.verticalCenter: parent.verticalCenter
                }

                Text {
                    text: "100%"
                    font.pixelSize: 9
                    color: "white"
                    x: parent.width - width
                    anchors.verticalCenter: parent.verticalCenter
                }
            }
        }
    }

    // *** Send/Recv Ratio Legende - MEHR Abstand als Standard ***
    Component {
        id: sendRecvRatioLegend

        Column {
            spacing: 6

            Row {
                spacing: 0

                // *** Links: Computing/Idle Block ***
                Column {
                    spacing: 4

                    Rectangle {
                        width: 12  // *** Gleiche Größe wie Standard ***
                        height: 12
                        radius: 2
                        border.color: "#222"
                        border.width: 1
                        color: "#eeeeee"
                        anchors.horizontalCenter: parent.horizontalCenter
                    }

                    Text {
                        text: "serial comput./idle"
                        font.pixelSize: 10
                        color: "white"
                        width: 30
                        horizontalAlignment: Text.AlignHCenter
                    }
                }

                // *** GROSSER Abstand zwischen den Bereichen ***
                Item {
                    width: 60  // *** 60px Abstand zwischen Idle und Farbbereich ***
                    height: 1
                }

                // *** Rechts: Send/Recv Farbbereich ***
                Column {
                    spacing: 4

                    // *** MEHR Abstand zwischen Kästchen als bei Standard ***
                    Row {
                        spacing: 5  // *** 5px statt 3px - MEHR als Standard! ***

                        Repeater {
                            model: 15  // *** 10 Kästchen für gute Balance ***
                            Rectangle {
                                width: 12   // *** Gleiche Breite wie Standard ***
                                height: 12
                                radius: 2
                                border.color: "#222"
                                border.width: 1

                                color: {
                                    let actualRatio = index / 13.0;  // 0 bis 1

                                    if (colorStops.length === 2) {
                                        let c1 = Qt.color(colorStops[0])  // Grün
                                        let c2 = Qt.color(colorStops[1])  // Rot
                                        return Qt.rgba(
                                            c1.r + actualRatio * (c2.r - c1.r),
                                            c1.g + actualRatio * (c2.g - c1.g),
                                            c1.b + actualRatio * (c2.b - c1.b),
                                            1.0
                                        )
                                    } else {
                                        return "#ff0000"
                                    }
                                }
                            }
                        }
                    }

                    // *** Kurze aber lesbare Texte ***
                    Item {
                        width: 15 * 12 + 14 * 5  // *** Angepasst: 10 Kästchen à 12px + 9 Abstände à 5px ***
                        height: 14

                        Text {
                            text: "mainly send"
                            font.pixelSize: 10  // *** Normale Lesbarkeit ***
                            color: "white"
                            x: 0
                            anchors.verticalCenter: parent.verticalCenter
                        }

                        Text {
                            text: "same send/recv"
                            font.pixelSize: 10
                            color: "white"
                            anchors.horizontalCenter: parent.horizontalCenter
                            anchors.verticalCenter: parent.verticalCenter
                        }

                        Text {
                            text: "mainly recv"
                            font.pixelSize: 10
                            color: "white"
                            anchors.right: parent.right
                            anchors.verticalCenter: parent.verticalCenter
                        }
                    }
                }
            }
        }
    }

    function parse_ds(datasize) {
        function formatValue(value) {
            return value % 1 === 0 ? value.toString() : value.toFixed(2);
        }

        if (datasize < 1000) {
            return datasize + " Byte";
        } else if (datasize < 1000000) {
            return formatValue(datasize / 1000) + " KB";
        } else if (datasize < 1000000000) {
            return formatValue(datasize / 1000000) + " MB";
        } else {
            return formatValue(datasize / 1000000000) + " GB";
        }
    }
}
