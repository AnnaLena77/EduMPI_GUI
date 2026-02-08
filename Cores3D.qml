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

    property bool p2p_lines: p2p_send_lines
    property bool c_lines: coll_lines

    onListNodesChanged: {
        updateCheckTimer.start()
        if(listNodes){
            p2pData =  listNodes.detailedP2P
            collData = listNodes.detailedColl
        }
    }

    Connections {
        target: p2pData
        function onNewDataInsertion() {
            customGeoSend.clearLines()
            customGeoRecv.clearLines()
            for(var row=0; row< p2pData.rowCount(); row++){
                var type = p2pData.simple_data(row, "function")
                var proc = p2pData.simple_data(row, "processrank")
                var partner = p2pData.simple_data(row, "partnerrank")

                if(type.includes("end")){
                    customGeoSend.addLine(positionMap[proc], positionMap[partner])
                }
                if(type.includes("ecv")){
                    customGeoRecv.addLine(positionMap[proc], positionMap[partner])
                }
            }
            customGeoSend.newFrame()
            customGeoRecv.newFrame()
        }
    }

    Connections {
        target: collData
        function onNewDataInsertion() {
            customGeoColl.clearLines()
            for(var row=0; row< collData.rowCount(); row++){
                var type = collData.simple_data(row, "function")
                var proc = collData.simple_data(row, "processrank")
                var partner = collData.simple_data(row, "coll_partnerranks")

                if(type.includes("Barrier")){
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
                                customGeoColl.addLine(procPosition, partnerPosition)
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

                            instancing: Ranks_Instances {
                                id: instanceDatas
                                p2p_show: p2p
                                coll_show: collective
                                combobox: option
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
                                        var testPos = mapPositionToNode(cubes, position);
                                        var globalPos = outerCube.position.plus(testPos);
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
                }
                visible: p2p_send_lines

                materials: DefaultMaterial {
                    diffuseColor: "#00D500"
                    emissiveFactor: Qt.vector3d(0.1, 0.5, 0.1)
                    lineWidth: 1.0
                }
            }

            Model {
                id: lineModelRecv
                geometry: CustomLineGeometry{
                    id: customGeoRecv
                }

                visible: p2p_recv_lines
                position: Qt.vector3d(0,2,0);

                materials: DefaultMaterial {
                    diffuseColor: "red"
                    emissiveFactor: Qt.vector3d(0.1, 0.1, 0.1)
                    lineWidth: 2.0
                }
            }
            Model {
                id: lineModelColl
                geometry: CustomLineGeometry{
                    id: customGeoColl
                }
                visible: coll_lines
                materials: DefaultMaterial {
                    depthDrawMode: Material.AlwaysDepthDraw
                    diffuseColor: "black"
                    emissiveFactor: Qt.vector3d(0.05, 0.05, 0.05)
                    lineWidth: 1.2
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


