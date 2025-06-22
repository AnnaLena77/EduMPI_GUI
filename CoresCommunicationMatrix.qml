import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import GUI_Cluster

Rectangle {
    id: rectangle_cm
    color: "#999999"

    property Cluster_Architecture listNodes: null
    property int coresCount: 0
    property int zoomi: parent ? parent.matrix_zoom : 100
    property real zoom: zoomi/100

    property var p2pSendData: listNodes.total_send_volume_matrix
    property var matrix: listNodes.total_send_volume_matrix
    property real matrix_maximum: 0

    // Zoom & Pan
    property real offsetX: 0
    property real offsetY: 0

    property int test: 0

    onListNodesChanged: {
        if (listNodes) {
            coresCount = 0
            for (var i = 0; i < listNodes.count; i++)
                coresCount += listNodes.nodeAt(i).count
        }
    }

    onP2pSendDataChanged: {
        if(listNodes){
            if(p2p && collective){
                matrix = listNodes.total_send_volume_matrix
                matrix_maximum = listNodes.detailed_p2p_max + listNodes.detailed_coll_max
            } else if (p2p) {
                matrix = listNodes.p2p_send_volume_matrix
                matrix_maximum = listNodes.detailed_p2p_max
            } else if (collective) {
                matrix = listNodes.coll_send_volume_matrix
                matrix_maximum = listNodes.detailed_coll_max
            }
        }
    }


    ColumnLayout {
        anchors.fill: parent
        spacing: 8
        //padding: 8
        // ------------------- HEADER + LEGEND -------------------
        Rectangle {
            color: Qt.rgba(1, 1, 1, 0.05)
            border.color: "#aaaaaa"
            border.width: 1
            radius: 6
            Layout.fillWidth: true
            Layout.preferredHeight: 40

            RowLayout {
                anchors.fill: parent
                anchors.margins: 8
                spacing: 20

                Text {
                    text: "Rank-to-Rank Communication Matrix"
                    font.bold: true
                    font.pixelSize: 14
                    color: "white"
                    Layout.alignment: Qt.AlignVCenter
                }

                ColumnLayout {
                    spacing: 4

                    // Farblegende (richtige Heatmapfarben von dunkelblau → rot)
                    RowLayout {
                        spacing: 2
                        Repeater {
                            model: 14  // 0 = grau, 1–13 = Farbskala
                            Rectangle {
                                width: 12
                                height: 12
                                radius: 2
                                border.color: "#222"
                                border.width: 1

                                property real ratio: (index - 1) / 13.0  // -1 weil Index 0 hellgrau ist

                                color: {
                                    if (index === 0) {
                                        return "#eeeeee";  // Hellgrau für genau 0
                                    }

                                    if (ratio < 0.25) {
                                        let t = ratio / 0.25;
                                        return Qt.rgba(0.0, t, 1.0, 1.0); // Blau → Cyan
                                    } else if (ratio < 0.5) {
                                        let t = (ratio - 0.25) / 0.25;
                                        return Qt.rgba(0.0, 1.0, 1.0 - t, 1.0); // Cyan → Grün
                                    } else if (ratio < 0.75) {
                                        let t = (ratio - 0.5) / 0.25;
                                        return Qt.rgba(t, 1.0, 0.0, 1.0); // Grün → Gelb
                                    } else {
                                        let t = (ratio - 0.75) / 0.25;
                                        return Qt.rgba(1.0, 1.0 - t, 0.0, 1.0); // Gelb → Rot
                                    }
                                }
                            }
                        }

                    }

                    // Skalenwerte
                    RowLayout {
                        spacing: 170
                        Layout.alignment: Qt.AlignLeft

                        Text {
                            text: "0"
                            font.pixelSize: 9
                            color: "white"
                            horizontalAlignment: Text.AlignHCenter
                        }

                        Text {
                            text: "Max: " + (listNodes ? matrix_maximum : 0)
                            font.pixelSize: 9
                            color: "white"
                            horizontalAlignment: Text.AlignHCenter
                        }
                    }
                }
            }
        }






        // ------------------- HEATMAP -------------------
        ScrollView {
            id: scrollArea
            Layout.fillWidth: true
            Layout.fillHeight: true
            clip: true

            readonly property real baseSize: rectangle_cm.coresCount * 12
            readonly property real scaledSize: baseSize * rectangle_cm.zoom

            contentWidth: Math.max(width, scaledSize)
            contentHeight: Math.max(height, scaledSize)

            Item {
                id: contentItem
                implicitWidth: scrollArea.contentWidth
                implicitHeight: scrollArea.contentHeight

                readonly property real cellSize: 8.5
                readonly property real spacing: 1.5
                readonly property real totalCellSize: cellSize + spacing

                Item {
                    id: zoomContainer
                    width: scrollArea.baseSize + 30
                    height: scrollArea.baseSize + 30
                    transform: Scale {
                        xScale: rectangle_cm.zoom
                        yScale: rectangle_cm.zoom
                    }

                    // Vertikale Labels
                    Column {
                        x: 20
                        y: 31
                        spacing: contentItem.spacing
                        Repeater {
                            model: rectangle_cm.coresCount
                            Text {
                                text: index % 5 === 0 ? "P" + index : " "
                                width: contentItem.cellSize
                                height: contentItem.cellSize
                                verticalAlignment: Text.AlignVCenter
                                horizontalAlignment: Text.AlignRight
                                font.pixelSize: 6
                            }
                        }
                    }

                    // Horizontale Labels
                    Row {
                        x: 31
                        y: 20
                        spacing: contentItem.spacing
                        Repeater {
                            model: rectangle_cm.coresCount
                            Text {
                                text: index % 5 === 0 ? "P" + index : ""
                                width: contentItem.cellSize
                                height: contentItem.cellSize
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignBottom
                                font.pixelSize: 6
                            }
                        }
                    }

                    // Heatmap
                    Item {
                        id: heatmapContainer
                        x: 30
                        y: 30

                        Heatmap_matrix {
                            id: heatmap
                            anchors.fill: parent
                            gridSize: rectangle_cm.coresCount
                            matrix: rectangle_cm.matrix
                            matrix_max: matrix_maximum
                            combobox: option
                        }
                    }

                    // Hoverfläche
                    MouseArea {
                        id: hoverArea
                        anchors.fill: parent
                        hoverEnabled: true
                        acceptedButtons: Qt.NoButton

                        property real zoom: rectangle_cm.zoom
                        property real cellSize: contentItem.totalCellSize
                        property int count: rectangle_cm.coresCount

                        onPositionChanged: (mouse) => {
                            let pos = hoverArea.mapToItem(heatmapContainer, mouse.x, mouse.y)
                            let col = Math.floor(pos.x / cellSize)
                            let row = Math.floor(pos.y / cellSize)

                            if (row >= 0 && row < count && col >= 0 && col < count) {
                                tooltip.visible = true
                                tooltipText.text = "P" + row + " → P" + col
                                let global = hoverArea.mapToItem(rectangle_cm, mouse.x + 10, mouse.y + 10)
                                tooltip.x = global.x
                                tooltip.y = global.y
                            } else {
                                tooltip.visible = false
                            }
                        }

                        onExited: tooltip.visible = false
                    }
                }
            }
        }
    }

    // Tooltip
    Rectangle {
        id: tooltip
        visible: false
        color: "#333"
        radius: 4
        border.color: "white"
        border.width: 1
        z: 1000
        opacity: 0.95
        width: tooltipText.implicitWidth + 10
        height: tooltipText.implicitHeight + 6

        Text {
            id: tooltipText
            color: "white"
            font.pixelSize: 10
            anchors.centerIn: parent
        }
    }
}

