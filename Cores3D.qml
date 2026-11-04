import QtQuick
import QtQuick3D 6.8
import GUI_Cluster
import QtQuick3D.Helpers
import QtQuick.Layouts

Rectangle {
    id: rectangle
    color: "#999999"

    property Cluster_Architecture listNodes: null
    property var p2pData: null
    property var collData: null
    property var positionMap: []
    property bool load: true

    // Thickness of the P2P arrows (scene units): the thickest arrow is the pair with the most
    // data. The width grows with the square root of the data volume: a logarithmic scale made a
    // direction with 6% of the data nearly as thick as the main direction.
    property real arrowMinWidth: 0.25
    property real arrowMaxWidth: 1.6
    // Arrows with less than this fraction of the largest volume are not drawn (0: draw all).
    // For example 0.1 hides the small requests that go back up the edge of a broadcast.
    property real arrowMinFraction: 0.0
    // The arrows end at the surface of the rank cubes. A cube of the 3D view has an edge of 100
    // units times its scale (the scale of the node cube divided by the cubes per side, times 1 -
    // the spacing of 0.45), and the rank cubes are children of the node cube, so its scale
    // applies a second time.
    property real nodeCubeScale: 1.2
    property real rankCubeHalfSize: {
        if(!listNodes || listNodes.count === 0) return 0
        var perSide = Math.ceil(Math.pow(listNodes.nodeAt(0).count, 1/3))
        return 50 * (nodeCubeScale / perSide * (1 - 0.45)) * nodeCubeScale
    }
    // Send arrows are shifted up and receive arrows down by this distance (world y), so that
    // both can be seen. Within each type the two directions of a pair get their own lane, this
    // far above and below: four arrows of one pair do not overlap.
    property real arrowLateralOffset: 4.5
    property real arrowDirectionOffset: 2.0
    // With many arrows (many ranks) the same width fills the picture. Up to this many arrows per
    // direction the widths stay as they are, above it they shrink with the square root of the
    // count; they are also capped by the size of the rank cubes.
    property int arrowCountFull: 64
    property real arrowMaxCubeFraction: 0.12
    function arrowWidth(volume, maxVolume, count) {
        var density = count > arrowCountFull ? Math.sqrt(arrowCountFull / count) : 1.0
        var maxW = arrowMaxWidth
        if (rankCubeHalfSize > 0) maxW = Math.min(maxW, arrowMaxCubeFraction * rankCubeHalfSize)
        maxW *= density
        var minW = Math.min(arrowMinWidth, maxW) * density
        if (maxVolume <= 0) return minW
        var f = Math.sqrt(volume / maxVolume)
        return minW + (maxW - minW) * f
    }

    property bool p2p_lines: p2p_send_lines
    property bool c_lines: coll_lines

    onListNodesChanged: {
        updateCheckTimer.start()
        if(listNodes){
            p2pData =  listNodes.detailedP2P
            collData = listNodes.detailedColl
        }
    }

    // *** Communicators ***
    // The communicators of the selected second and the ranks that take part in them. The sidebar
    // lists them (communicatorList, defined in main.qml); selecting one (selected_comm) greys out
    // the ranks that are not part of it and draws only its arrows.
    property string commFilter: comm.filter
    CommunicatorState {
        id: comm
        p2pData: rectangle.p2pData
        collData: rectangle.collData
        filter: selected_comm
        onListChanged: communicatorList = comm.list
    }
    // pairs that exchanged less than this are hidden (point-to-point arrows) and ignored by the fan modes
    property double minPairBytes: min_pair_bytes
    onMinPairBytesChanged: redrawP2P()
    Binding { target: listNodes; property: "minPairBytes"; value: rectangle.minPairBytes; when: listNodes !== null }

    property var selectedRanks: comm.selectedRanks
    property bool selectedActive: comm.selectedActive

    onCommFilterChanged: {
        redrawP2P()
        redrawColl()
    }

    function redrawP2P() {
            if(!p2pData) return
            customGeoSend.clearLines()
            customGeoRecv.clearLines()
            // bytes per pair of ranks (one arrow per pair, as thick as its data volume)
            var sendPairs = {}
            var recvPairs = {}
            var maxSend = 0
            var maxRecv = 0
            for(var row=0; row< p2pData.rowCount(); row++){
                var type = p2pData.simple_data(row, "function")
                var proc = p2pData.simple_data(row, "processrank")
                var partner = p2pData.simple_data(row, "partnerrank")
                // Arrows only for communication that moved data
                var sendSize = Number(p2pData.simple_data(row, "send_size"))
                var recvSize = Number(p2pData.simple_data(row, "recv_size"))

                // A row without a partner rank (-1: e.g. a receive that was cancelled and
                // never got a message) has no position. Passing undefined to addLine() is
                // a TypeError that aborts this handler, so no line would be drawn at all.
                if(positionMap[proc] === undefined || positionMap[partner] === undefined){
                    continue
                }

                // only the communicator selected in the sidebar
                if(commFilter !== "" && p2pData.simple_data(row, "communicator") !== commFilter){
                    continue
                }

                var key = proc + "," + partner
                if(type.includes("end") && sendSize > 0){
                    if(sendPairs[key] === undefined) sendPairs[key] = {proc: proc, partner: partner, bytes: 0}
                    sendPairs[key].bytes += sendSize
                    maxSend = Math.max(maxSend, sendPairs[key].bytes)
                }
                if(type.includes("ecv") && recvSize > 0){
                    if(recvPairs[key] === undefined) recvPairs[key] = {proc: proc, partner: partner, bytes: 0}
                    recvPairs[key].bytes += recvSize
                    maxRecv = Math.max(maxRecv, recvPairs[key].bytes)
                }
            }
            var nSend = Object.keys(sendPairs).length
            var nRecv = Object.keys(recvPairs).length
            for(var sk in sendPairs){
                var sp = sendPairs[sk]
                if(sp.bytes < arrowMinFraction * maxSend) continue
                if(sp.bytes < min_pair_bytes) continue
                customGeoSend.addLine(positionMap[sp.proc], positionMap[sp.partner], arrowWidth(sp.bytes, maxSend, nSend))
            }
            for(var rk in recvPairs){
                var rp = recvPairs[rk]
                if(rp.bytes < arrowMinFraction * maxRecv) continue
                if(rp.bytes < min_pair_bytes) continue
                customGeoRecv.addLine(positionMap[rp.proc], positionMap[rp.partner], arrowWidth(rp.bytes, maxRecv, nRecv))
            }
            customGeoSend.newFrame()
            customGeoRecv.newFrame()
    }

    Connections {
        target: p2pData
        function onNewDataInsertion() {
            redrawP2P()
        }
    }

    function redrawColl() {
            if(!collData) return
            customGeoColl.clearLines()
            // The collective rows carry no byte volume: one common width (the same as a send
            // arrow of medium volume), reduced for many arrows like the p2p arrows.
            var nColl = 0
            for(var cr=0; cr< collData.rowCount(); cr++){
                if(commFilter !== "" && collData.simple_data(cr, "communicator") !== commFilter) continue
                var cp = collData.simple_data(cr, "coll_partnerranks")
                if(cp === "" || cp === undefined) continue
                if(!(cp instanceof Array)) cp = Object.values(cp)
                nColl += cp.length
            }
            var collWidth = arrowWidth(0.25, 1.0, nColl)
            for(var row=0; row< collData.rowCount(); row++){
                var type = collData.simple_data(row, "function")
                var proc = collData.simple_data(row, "processrank")
                var partner = collData.simple_data(row, "coll_partnerranks")

                if(type.includes("Barrier")){
                    continue;
                }
                if(commFilter !== "" && collData.simple_data(row, "communicator") !== commFilter){
                    continue;
                }

                if(partner !== ""){
                    if (!(partner instanceof Array)) {
                        partner = Object.values(partner);
                    }
                    for(var par of partner){
                        var procPosition = positionMap[proc]
                        var partnerPosition = positionMap[par]

                        // Nur addLine() aufrufen wenn beide Positionen existieren
                        if(procPosition !== undefined && partnerPosition !== undefined) {
                            // Zusätzliche Validierung: Sind es gültige Vector3D-Objekte?
                            if(procPosition.x !== undefined && procPosition.y !== undefined && procPosition.z !== undefined &&
                               partnerPosition.x !== undefined && partnerPosition.y !== undefined && partnerPosition.z !== undefined) {
                                customGeoColl.addLine(procPosition, partnerPosition, collWidth)
                            } else {
                                console.log("Invalid position data for proc:", proc, "partner:", par)
                            }
                        } else {
                            console.log("Missing position data for proc:", proc, "or partner:", par)
                        }
                    }
                }
            }
            customGeoColl.newFrame()
    }

    Connections {
        target: collData
        function onNewDataInsertion() {
            redrawColl()
            comm.update()
        }
    }

    // *** Layout für Information Bar und 3D View ***
    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 5
        spacing: 8

        // *** Information Bar oben fixiert ***
        Detailed_Information_Bar {
            visible: listNodes && listNodes.count > 0
            heading: getHeadingForOption()
            avgValue: getAvgValueForOption()
            maxValue: getMaxValueForOption()
            colorStops: getColorStopsForOption()
            tooltipText: getTooltipForOption()
            z: 1000
        }

        // *** 3D View nimmt den Rest des Platzes ein ***
        View3D {
            id: viewport
            Layout.fillWidth: true
            Layout.fillHeight: true
            camera: cameraNode
            environment: SceneEnvironment {
                backgroundMode: SceneEnvironment.Color
                clearColor: "white"
                property bool enableEffects: false
            }

            PerspectiveCamera {
                id: cameraNode
                z: 600
                eulerRotation: Qt.vector3d(0,0,0)

                property vector3d initialPosition: Qt.vector3d(0, 0, 600)
                property vector3d target: Qt.vector3d(0,25,0)
                property real distance: 600
                property real angleX: 0
                property real angleY: 0

                function updatePosition() {
                    cameraNode.x = cameraNode.target.x + cameraNode.distance * Math.sin(cameraNode.angleY) * Math.cos(cameraNode.angleX)
                    cameraNode.y = cameraNode.target.y + cameraNode.distance * Math.sin(cameraNode.angleX)
                    cameraNode.z = cameraNode.target.z + cameraNode.distance * Math.cos(cameraNode.angleY) * Math.cos(cameraNode.angleX)
                    cameraNode.lookAt(cameraNode.target)
                }

                function zoom(distance){
                    cameraNode.distance += distance
                    if (cameraNode.distance >= 700) {
                        cameraNode.distance = 700
                        cameraNode.position = cameraNode.initialPosition
                        cameraNode.angleX = 0
                        cameraNode.angleY = 0
                        cameraNode.lookAt(cameraNode.target)
                    } else {
                        cameraNode.updatePosition()
                    }
                }
            }

            WheelHandler{
                acceptedDevices: PointerDevice.Mouse | PointerDevice.TouchPad
                onWheel: event=>{
                    if(event.angleDelta.y>0){
                        cameraNode.zoom(-10)
                    }
                    else {
                        cameraNode.zoom(10);
                    }
                }
            }

            MouseArea{
                anchors.fill: parent
                propagateComposedEvents: true
                property bool rotating: false
                property real lastX: 0
                property real lastY: 0

                onPressed: event => {
                    rotating = true
                    lastX = event.x
                    lastY = event.y
                }
                onReleased: event => {
                    rotating = false
                }

                onPositionChanged: event => {
                    if (rotating) {
                        var deltaX = event.x - lastX
                        var deltaY = event.y - lastY
                        lastX = event.x
                        lastY = event.y

                        cameraNode.angleY -= deltaX * 0.01
                        cameraNode.angleX -= deltaY * 0.01
                        cameraNode.angleX = Math.max(Math.min(cameraNode.angleX, Math.PI / 2), -Math.PI / 2)

                        cameraNode.updatePosition()
                    }
                }

                onClicked: event=>{
                    var mousePos = Qt.vector3d(event.x, event.y, 0);
                    var rayOrigin = cameraNode.position;
                    var rayDirection = (viewport.mapTo3DScene(mousePos).minus(rayOrigin)).normalized();
                    var hitResult = viewport.rayPick(rayOrigin, rayDirection);

                    if(hitResult.objectHit){
                        var pickedObject = hitResult.objectHit;
                        pickedObject.isPicked = !pickedObject.isPicked;

                        var objectPosition = pickedObject.position;
                        var zoomDistance = 15;
                        var cameraDirection = Qt.vector3d(0, 0, -1);
                        var cameraPosition = Qt.vector3d(objectPosition.x, objectPosition.y, objectPosition.z+170);

                        cameraNode.position = cameraPosition;
                        cameraNode.lookAt(objectPosition);
                    }
                }
            }

            Repeater3D{
                id: outerCubeRepeater
                model: listNodes.count
                delegate: Model {
                    id: outerCube
                    property int outerCubeId: index
                    source: "#Cube"
                    scale: Qt.vector3d(1.2, 1.2, 1.2)
                    position: Qt.vector3d(
                                  ((index % 2) * 600 - 300),
                                  ((Math.floor(index / 2) % 4)) * 150 - 200,
                                  (Math.floor(index / 8) * -300)
                                  )
                    pickable: true
                    property bool isPicked: false
                    materials: [
                        PrincipledMaterial {
                            id: glassMaterial
                            lineWidth: 1
                            opacity: 0.1
                        }
                    ]

                    property int outerCubeIndex: model.index

                    onBoundsChanged : {
                        var outerCubeLength = 100
                        var innerCubeCount = 14;
                        var innerCubeSpacing = 0.4;
                        var rowsColumns = Math.ceil(Math.pow(innerCubeCount, 1/3));
                        var innerCubeScale = outerCube.scale.x / rowsColumns * (1 - innerCubeSpacing);
                    }

                    Node {
                        id: cubes

                        Model {
                            id: innerCube
                            source: "#Cube"
                            depthBias: 0.01

                            Connections {
                                target: listNodes
                                function onP2p_send_volume_matrix_changed() { instanceDatas.timerRanksChanged() }
                                function onP2p_recv_volume_matrix_changed() { instanceDatas.timerRanksChanged() }
                                function onColl_send_volume_matrix_changed() { instanceDatas.timerRanksChanged() }
                                function onColl_recv_volume_matrix_changed() { instanceDatas.timerRanksChanged() }
                                function onMinPairBytesChanged() { instanceDatas.timerRanksChanged() }
                            }

                            instancing: Ranks_Instances {
                                id: instanceDatas
                                p2p_show: p2p
                                coll_show: collective
                                combobox: option
                                highlightRanks: rectangle.selectedRanks
                                highlightActive: rectangle.selectedActive
                                nodes: listNodes
                                send_datasize: listNodes.nodeAt(model.index).rankAt(0).p2p_send_datasize;
                                instanceCount: listNodes.nodeAt(model.index).count
                                instanceRanks: listNodes.nodeAt(model.index)
                                outerCubeLength: 100
                                innerCubeCount: instanceCount
                                innerCubeSpacing: 0.45
                                rowsColumns: Math.ceil(Math.pow(innerCubeCount, 1/3));
                                innerCubeScale: outerCube.scale.x / rowsColumns * (1 - innerCubeSpacing)
                            }

                            materials: [
                                DefaultMaterial{
                                    depthDrawMode: Material.AlwaysDepthDraw
                                    opacity: (coll_lines || p2p_send_lines || p2p_recv_lines) ? 0.6 : 1.0
                                }
                            ]
                        }
                    }
                    Repeater3D {
                        id: innerCubeNumbers
                        visible: true
                        model: listNodes.nodeAt(outerCubeId).count
                        delegate: Model {
                            property double sc: outerCube.scale.x / Math.ceil(Math.pow(listNodes.nodeAt(outerCubeId).count, 1/3)) * (1 - 0.45) + 0.001
                            source: "#Cube"
                            position: listNodes.nodeAt(outerCubeId).rankAt(index).position
                            scale: Qt.vector3d(sc, sc, sc)
                            materials: [
                                DefaultMaterial{
                                    depthDrawMode: (coll_lines || p2p_send_lines || p2p_recv_lines) ?
                                                       Material.OpaqueOnlyDepthDraw : Material.AlwaysDepthDraw
                                    diffuseMap: Texture {
                                        sourceItem: Rectangle {
                                            width: 200 / instanceDatas.rowsColumns
                                            height: 200 / instanceDatas.rowsColumns
                                            color: "transparent"

                                            Text {
                                                anchors.left: parent.left
                                                anchors.bottom: parent.bottom
                                                text: "" + listNodes.nodeAt(outerCubeId).rankAt(index).getId()
                                                color: "black"
                                                font.pixelSize: 20
                                            }
                                        }
                                    }
                                }
                            ]
                            onPositionChanged: {
                                if(rectangle.load){
                                    if(position != Qt.vector3d(0.0, 0.0, 0.0)){
                                        var id = listNodes.nodeAt(outerCubeId).rankAt(index).getId()
                                        var pos = Qt.vector3d(position.x, position.y, position.z)
                                        // position of the rank cube in the scene: its position inside
                                        // the node cube, scaled with the node cube, plus the
                                        // position of the node cube
                                        var globalPos = outerCube.position.plus(position.times(outerCube.scale.x));
                                        var halfSize = sc / 2;
                                        var mappedPos = mapPositionToScene(position);
                                        positionMap[id] = globalPos
                                    }
                                }
                            }
                        }
                    }
                }
            }
            Model {
                id: lineModelSend
                geometry: CustomLineGeometry{
                    id: customGeoSend
                    cubeHalfSize: rectangle.rankCubeHalfSize
                    lateralOffset: rectangle.arrowLateralOffset      // up
                    directionOffset: rectangle.arrowDirectionOffset
                }
                visible: p2p_send_lines

                materials: DefaultMaterial {
                    diffuseColor: "#00D500"
                    emissiveFactor: Qt.vector3d(0.1, 0.5, 0.1)
                    lineWidth: 1.0
                    cullMode: Material.NoCulling
                }
            }

            Model {
                id: lineModelRecv
                geometry: CustomLineGeometry{
                    id: customGeoRecv
                    cubeHalfSize: rectangle.rankCubeHalfSize
                    lateralOffset: -rectangle.arrowLateralOffset     // down
                    directionOffset: rectangle.arrowDirectionOffset
                }

                visible: p2p_recv_lines

                materials: DefaultMaterial {
                    diffuseColor: "red"
                    emissiveFactor: Qt.vector3d(0.1, 0.1, 0.1)
                    lineWidth: 2.0
                    cullMode: Material.NoCulling
                }
            }
            Model {
                id: lineModelColl
                geometry: CustomLineGeometry{
                    id: customGeoColl
                    cubeHalfSize: rectangle.rankCubeHalfSize
                    lateralOffset: 0
                    directionOffset: rectangle.arrowDirectionOffset
                }
                visible: coll_lines
                materials: DefaultMaterial {
                    depthDrawMode: Material.AlwaysDepthDraw
                    diffuseColor: "black"
                    emissiveFactor: Qt.vector3d(0.05, 0.05, 0.05)
                    lineWidth: 1.2
                    cullMode: Material.NoCulling
                }
            }

            DirectionalLight {
                eulerRotation: Qt.vector3d(250, -30, 0);
                brightness: 0.8
                ambientColor: "#7f7f7f"
            }
        }
    }

    Timer {
       id: updateCheckTimer
       interval: 10
       repeat: false
       onTriggered: {
            if(rectangle.parent.reload){
               rectangle.parent.map = positionMap
               rectangle.parent.reload = false
            } else {
                rectangle.parent.reload = false
                positionMap = rectangle.parent.map
            }
       }
   }

    // *** Funktionen für die Information Bar ***
    function getHeadingForOption() {
        if (!listNodes || listNodes.count === 0) return "Loading 3D View..."

        switch(option) {
            case "send/recv ratio (per proc)": return "3D Cluster Overview: Send/Recv Ratio per Process"
            case "max send ratio (across all procs)": return "3D Cluster Overview: Max Send Ratio (All Processes)"
            case "max recv ratio (across all procs)": return "3D Cluster Overview: Max Recv Ratio (All Processes)"
            case "wait for late sender (per proc)": return "3D Cluster Overview: Wait for Late Sender"
            case "wait for late recver (per proc)": return "3D Cluster Overview: Wait for Late Receiver"
            case "fan-out: distinct receivers (per proc)": return "3D Cluster Overview: Fan-out (number of distinct receivers)"
            case "fan-in: distinct senders (per proc)": return "3D Cluster Overview: Fan-in (number of distinct senders)"
            default: return "3D Process Communication View"
        }
    }

    function getColorStopsForOption() {
        switch(option) {
            case "send/recv ratio (per proc)":
                return ["#00ff00", "#ff0000"]  // Grün zu Rot
            case "max send ratio (across all procs)":
                return ["#ffffff", "#00ff00"]  // Weiß zu Grün
            case "max recv ratio (across all procs)":
                return ["#ffffff", "#ff0000"]  // Weiß zu Rot
            case "wait for late sender (per proc)":
                return ["#ffffff", "#0000ff"]  // Weiß zu Blau
            case "wait for late recver (per proc)":
                return ["#ffffff", "#0000ff"]  // Weiß zu Blau
            case "fan-out: distinct receivers (per proc)":
                return ["#ffffff", "#00ff00"]
            case "fan-in: distinct senders (per proc)":
                return ["#ffffff", "#ff0000"]
            default:
                return ["#ffffff", "#000000"]  // Weiß zu Schwarz
        }
    }

    function getAvgValueForOption() {
        if (!listNodes || listNodes.count === 0) return 0

        switch(option) {
            case "send/recv ratio (per proc)": return calculateAvgSendRecv()
            case "max send ratio (across all procs)": return calculateAvgSend()
            case "max recv ratio (across all procs)": return calculateAvgRecv()
            default: return 0
        }
    }

    function getMaxValueForOption() {
        if (!listNodes || listNodes.count === 0) return 100

        switch(option) {
            case "send/recv ratio (per proc)": return calculateMaxSendRecv()
            case "fan-out: distinct receivers (per proc)": return listNodes.fanMax(true, p2p, collective)
            case "fan-in: distinct senders (per proc)": return listNodes.fanMax(false, p2p, collective)
            case "max send ratio (across all procs)":
                if(p2p && collective) return Number(listNodes.coll_send_max) + Number(listNodes.p2p_send_max)
                else if(p2p) return Number(listNodes.p2p_send_max)
                else if(collective) return Number(listNodes.coll_send_max)
                return 0
            case "max recv ratio (across all procs)":
                if(p2p && collective) return Number(listNodes.coll_recv_max) + Number(listNodes.p2p_recv_max)
                else if(p2p) return Number(listNodes.p2p_recv_max)
                else if(collective) return Number(listNodes.coll_recv_max)
                return 0
            default: return 100
        }
    }

    function getTooltipForOption() {
        switch(option) {
        case "send/recv ratio (per proc)":
            return "3D Cluster view: Outer cubes = Nodes, inner cubes = Processes\nRatio between sent and received data per process.\n- Green = more sent data\n- Red = more received data\n- Brown/Ochre = Sent and received data are approximately equal\n- White = No MPI communication."
        case "max send ratio (across all procs)":
            return "3D Cluster view: Maximum send ratio across all processes.\n- White = No data\n- Green = Highest amount of sent data"

        case "max recv ratio (across all procs)":
            return "3D Cluster view: Maximum receive ratio across all processes.\n- White = No data\n- Red = Highest amount of received data"

        case "wait for late sender (per proc)":
            return "3D Cluster view: Wait time for late senders per process.\n- White = No wait time\n- Blue = High wait time"

        case "wait for late recver (per proc)":
            return "3D Cluster view: Wait time for late receivers per process.\n- White = No wait time\n- Blue = High wait time"

        case "fan-out: distinct receivers (per proc)":
            return "3D Cluster view: Number of different processes a process sent data to.\n- White = none\n- Green = most receivers (a hot spot of a flat broadcast)\nPairs below the size set in the Views panel are ignored."

        case "fan-in: distinct senders (per proc)":
            return "3D Cluster view: Number of different processes a process received data from.\n- White = none\n- Red = most senders\nPairs below the size set in the Views panel are ignored."

        default:
            return "3D Process Communication Visualization\n- Mouse wheel = Zoom\n- Drag = Rotate view\n- Click on cube = Focus on process"
        }
    }

    // Hilfsfunktionen für Durchschnittswerte
    function calculateAvgSendRecv() {
        if (!listNodes || listNodes.count === 0) return 0
        return 50000  // Platzhalter - hier könntest du echte 3D-Berechnungen machen
    }

    function calculateAvgSend() {
        if (!listNodes || listNodes.count === 0) return 0
        return 25000  // Platzhalter
    }

    function calculateAvgRecv() {
        if (!listNodes || listNodes.count === 0) return 0
        return 25000  // Platzhalter
    }

    function calculateMaxSendRecv() {
        if (!listNodes || listNodes.count === 0) return 0
        return 100000  // Platzhalter
    }

   Component.onDestruction: {
       cameraNode.destroy()
       viewport.destroy()
   }
}


