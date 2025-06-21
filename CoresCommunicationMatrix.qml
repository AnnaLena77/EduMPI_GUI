import QtQuick
import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Controls
import GUI_Cluster

Rectangle {
    id: rectangle_cm
    color: "#999999"

    property Cluster_Architecture listNodes: null
    property int coresCount: 0
    property int zoomi: parent ? parent.matrix_zoom : 100
    property real zoom: zoomi/100

    property var p2pSendData: listNodes.p2p_send_volume_matrix
    property var p2pRecvData: null
    property var collSendData: null
    property var collRecvData: null

    // Zoom & Pan
    property real offsetX: 0
    property real offsetY: 0

    onZoomChanged: {
        //console.log("Zoom: " + zoom)
       // canvas.requestPaint()
    }

    //onP2pSendDataChanged: canvas.requestPaint()
    //onCoresCountChanged: canvas.requestPaint()

    onListNodesChanged: {
        if (listNodes) {
            coresCount = 0
            for (var i = 0; i < listNodes.count; i++) {
                coresCount += listNodes.nodeAt(i).count
            }
            console.log("CoresCount: " + coresCount)
            p2pRecvData = listNodes.p2p_recv_volume_matrix
            collSendData = listNodes.coll_recv_volume_matrix
            collRecvData = listNodes.coll_recv_volume_matrix
        }
    }


    ScrollView {
        id: scrollArea
        anchors.fill: parent
        clip: true
        ScrollBar.horizontal.policy: ScrollBar.AlwaysOn
        ScrollBar.vertical.policy: ScrollBar.AlwaysOn

        // Feste Basisgröße
        readonly property real baseSize: rectangle_cm.coresCount * 12
        // Skalierte Größe
        readonly property real scaledSize: baseSize * rectangle_cm.zoom

        // Direkte Zuweisung der Content-Größe ohne Abhängigkeit vom contentItem
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
                width: scrollArea.baseSize + 30  // Extra Platz für Labels
                height: scrollArea.baseSize + 30  // Extra Platz für Labels

                x: 0
                y: 0

                transform: Scale {
                    id: zoomTransform
                    origin.x: 0
                    origin.y: 0
                    xScale: rectangle_cm.zoom
                    yScale: rectangle_cm.zoom
                }

                // Vertikale Prozess-Labels (links)
                Column {
                    x: 20
                    y: 30+1
                    spacing: contentItem.spacing

                    Repeater {
                        model: rectangle_cm.coresCount

                        Text {
                            text: index%5 == 0 ? "P" + (index) : " "
                            //text: "P" + (index)
                            //anchors.right: parent.right
                            width: contentItem.cellSize
                            height: contentItem.cellSize
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignRight
                            font.pixelSize: 6

                        }
                    }
                }

                // Horizontale Prozess-Labels (oben)
                Row {
                    x: 30 + 1
                    y: 20
                    spacing: contentItem.spacing


                   /* Repeater {
                        model: rectangle_cm.coresCount

                        Rectangle {
                            width: contentItem.cellSize
                            height: contentItem.cellSize
                            color: "black"
                        }
                    }*/

                    Repeater {
                        model: rectangle_cm.coresCount
                        Text {
                            text: index%5 == 0 ? "P" + (index) : ""
                            width: contentItem.cellSize
                            height: contentItem.cellSize
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignBottom
                            font.pixelSize: 6
                        }
                    }
                }

                // Container für die Heatmap
                Item {
                    id: heatmapContainer
                    x: 30  // Eingerückt nach den vertikalen Labels
                    y: 30  // Eingerückt nach den horizontalen Labels
                    //width: rectangle_cm.coresCount * 12
                    //height: rectangle_cm.coresCount * 12

                    Heatmap_matrix {
                        id: heatmap
                        anchors.fill: parent
                        gridSize: rectangle_cm.coresCount
                        matrix: rectangle_cm.p2pSendData
                    }

                }
                MouseArea {
                    id: hoverArea
                    anchors.fill: parent
                    hoverEnabled: true
                    acceptedButtons: Qt.NoButton

                    property real zoom: rectangle_cm.zoom
                    property real cellSize: contentItem.totalCellSize
                    property int count: rectangle_cm.coresCount

                    onPositionChanged: (mouse) => {
                        // Rechne Mauskoordinaten in Heatmap-Container um (der ist ungescaled)
                        let pos = hoverArea.mapToItem(heatmapContainer, mouse.x, mouse.y)
                        let relX = pos.x
                        let relY = pos.y

                        let col = Math.floor(relX / cellSize)
                        let row = Math.floor(relY / cellSize)

                        if (row >= 0 && row < count && col >= 0 && col < count) {
                            tooltip.visible = true
                            tooltipText.text = "P" + row + " → P" + col

                            // Tooltip im globalen Kontext verschieben
                            let global = hoverArea.mapToItem(rectangle_cm, mouse.x + 12, mouse.y + 12)
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

