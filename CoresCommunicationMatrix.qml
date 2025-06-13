import QtQuick
import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Controls
import GUI_Cluster

Rectangle {
    id: rectangle_cm
    color: "#5bc2c6"

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
        canvas.requestPaint()
    }

    onP2pSendDataChanged: canvas.requestPaint()
    onCoresCountChanged: canvas.requestPaint()

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
        id: scroll_area
        anchors.fill: parent
        clip: true

        Rectangle {
            id: zoomContainer

            property int canvasWidth: rectangle_cm.coresCount * cellSize
            property int canvasHeight: rectangle_cm.coresCount * cellSize
            readonly property int cellSize: 10  // Basisgröße pro Zelle

            width: canvasWidth * rectangle_cm.zoom
            height: canvasHeight * rectangle_cm.zoom
            scale: 1.0
            color: "transparent"

            Canvas {
                id: canvas
                anchors.fill: parent
                renderStrategy: Canvas.Immediate

                onPaint: {
                    if (!rectangle_cm.p2pSendData || rectangle_cm.coresCount <= 0)
                        return

                    var ctx = getContext("2d")
                    ctx.reset()
                    ctx.clearRect(0, 0, width, height)

                    var gridSize = rectangle_cm.coresCount

                    var cell = zoomContainer.cellSize * rectangle_cm.zoom

                    for (var i = 0; i < rectangle_cm.coresCount; ++i) {
                        for (var j = 0; j < rectangle_cm.coresCount; ++j) {
                            var value = rectangle_cm.p2pSendData[i][j]
                            ctx.fillStyle = value > 0 ? "red" : "blue"
                            ctx.fillRect(j * cell, i * cell, cell, cell)

                            // Draw visible cell borders
                            ctx.strokeStyle = "#444"
                            ctx.lineWidth = 0.5
                            ctx.strokeRect(j * cell, i * cell, cell, cell)
                        }
                    }
                }
                onWidthChanged: requestPaint()
                onHeightChanged: requestPaint()
                Component.onCompleted: requestPaint()
            }
        }
    }
}

