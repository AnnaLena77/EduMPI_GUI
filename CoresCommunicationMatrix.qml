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
                matrix_maximum = listNodes.detailed_total_max
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

        Detailed_Information_Bar {
                heading: "Rank-to-Rank Communication Matrix"
                avgValue: listNodes ? listNodes.detailed_total_avg : 10
                maxValue: listNodes ? matrix_maximum : 20
                tooltipText:"This matrix shows the communication between different MPI ranks.\n" +
                            "• Each cell (i,j) represents the data volume sent from rank i to rank j\n" +
                            "• Colors: Blue = low volume, Red = high volume\n" +
                            "• The diagonal indicates intra-rank (self) communication\n" +
                            "• Cells with zero data are shown in white"


                colorStops: [
                        "#0000ff",  // Blau (0.0, 0.0, 1.0)
                        "#00ffff",  // Cyan (0.0, 1.0, 1.0)
                        "#00ff00",  // Grün (0.0, 1.0, 0.0)
                        "#ffff00",  // Gelb (1.0, 1.0, 0.0)
                        "#ff0000"   // Rot (1.0, 0.0, 0.0)
                    ]
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
                                //under toolTip text Average of Data for the cell
                                let data = rectangle_cm.matrix[row][col];
                                if (data === undefined) {
                                    data = 0;
                                }
                                tooltipText.text += "\n" + parse_ds(data);

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
    function parse_ds(datasize) {
        function formatValue(value) {
            // Entferne ".00", wenn keine Nachkommastellen nötig sind
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


