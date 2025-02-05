import QtQuick
import QtQuick3D 6.8
import GUI_Cluster
import QtQuick3D.Helpers
//import Qt3D.Render 2.5
//import CustomGeometry 1.0

Rectangle {
    id: rectangle
    //height: parent.height
    color: "#5bc2c6"
    //anchors.fill: parent

    property Cluster_Architecture listNodes: null

    property var p2pData: null
    property var collData: null

    property var positionMap: []

    property bool load: true

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
            //if(lineModelRecv.visible || lineModelSend.visible){
                customGeoSend.clearLines()
                customGeoRecv.clearLines()
                for(var row=0; row< p2pData.rowCount(); row++){
                    var type = p2pData.simple_data(row, "function")
                    var proc = p2pData.simple_data(row, "processrank")
                    var partner = p2pData.simple_data(row, "partnerrank")

                    //console.log(proc)
                    //console.log(positionMap[proc])

                    if(type == "MPI_Send"){
                        //console.log(positionMap[proc])
                        //console.log(customGeo)
                        customGeoSend.addLine(positionMap[proc], positionMap[partner])
                    }
                    else if(type == "MPI_Recv"){
                        customGeoRecv.addLine(positionMap[proc], positionMap[partner])
                    }
                }
                customGeoSend.newFrame()
                customGeoRecv.newFrame()
            //}
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

                if(partner != ""){
                    if (!(partner instanceof Array)) {
                        partner = Object.values(partner);  // Falls partner ein Objekt ist
                    }
                    for(var par of partner){
                        //console.log(proc + " -> " + par)
                        customGeoColl.addLine(positionMap[proc], positionMap[par])
                    }
                }
            }
            customGeoColl.newFrame()
        }
    }


   View3D {

        id: viewport
        anchors.fill: parent
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
            property vector3d target: Qt.vector3d(0,0,0)
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
                if (cameraNode.distance >= 600) {
                    cameraNode.distance = 600
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
                    cameraNode.zoom(-15)
                }
                else {
                    cameraNode.zoom(15);
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
                // Maus- und Kamera-Position im dreidimensionalen Raum
                var mousePos = Qt.vector3d(event.x, event.y, 0);
                var rayOrigin = cameraNode.position;
                var rayDirection = (viewport.mapTo3DScene(mousePos).minus(rayOrigin)).normalized();
                // Ray wird gesendet, erstes Objekt, welches getroffen wird, ist "hitResult"
                var hitResult = viewport.rayPick(rayOrigin, rayDirection);

                if(hitResult.objectHit){
                    var pickedObject = hitResult.objectHit;
                    pickedObject.isPicked = !pickedObject.isPicked;

                    var objectPosition = pickedObject.position;
                    //console.log("Position " + objectPosition);

                    var zoomDistance = 10; // Entfernung der Kamera zum Objekt
                    var cameraDirection = Qt.vector3d(0, 0, -1); // Richtung der Kamera (zum Beispiel nach vorne gerichtet)
                    var cameraPosition = Qt.vector3d(objectPosition.x, objectPosition.y, objectPosition.z+150);

                    //console.log("Kameraposition " + cameraPosition);

                    cameraNode.position = cameraPosition;
                    cameraNode.lookAt(objectPosition); // Kamera auf das Objekt ausrichten
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
                              ((index % 2) * 600 - 300), // x-Position
                              ((Math.floor(index / 2) % 4)) * 150 - 200, // y-Position
                              (Math.floor(index / 8) * -300) // z-Position
                              )
                pickable: true
                property bool isPicked: false
                materials: [
                    PrincipledMaterial {
                        id: glassMaterial
                        lineWidth: 1
                        opacity: 0.1
                            //shadingMode: CustomMaterial.Shaded
                            //vertexShader: "qrc:/shaders/simple.vert"
                            //fragmentShader: "qrc:/shaders/glass.frag"
                    }
                ]

                property int outerCubeIndex: model.index

                onBoundsChanged : {

                    var outerCubeLength = 100//outerCube.bounds.maximum.x - (outerCube.bounds.minimum.x);
                    var innerCubeCount = 14;
                    var innerCubeSpacing = 0.4;
                    var rowsColumns = Math.ceil(Math.pow(innerCubeCount, 1/3));
                    var innerCubeScale = outerCube.scale.x / rowsColumns * (1 - innerCubeSpacing); // Berechnung der Skalierung des inneren Würfels
                    //console.log("outercubebounds" + outerCube.bounds.maximum.x)
                }

                Node {

                    Model {
                        id: innerCube
                        source: "#Cube"
                        //instanceRoot: outerCube

                        depthBias: 0.01

                        instancing: Ranks_Instances {
                            //outerInstanceData : outerCube.instancing.instancePosition()
                            id: instanceDatas
                            p2p_show: p2p
                            coll_show: collective
                            combobox: option
                            nodes: listNodes
                            send_datasize: listNodes.nodeAt(model.index).rankAt(0).p2p_send_datasize; //Das ist noch keine perfekte Lösung!
                            instanceCount: listNodes.nodeAt(model.index).count
                            instanceRanks: listNodes.nodeAt(model.index)
                            outerCubeLength: 100 //outerCube.bounds.maximum.x - (outerCube.bounds.minimum.x)
                            innerCubeCount: instanceCount
                            innerCubeSpacing: 0.45
                            rowsColumns: Math.ceil(Math.pow(innerCubeCount, 1/3));
                            innerCubeScale: outerCube.scale.x / rowsColumns * (1 - innerCubeSpacing) // Berechnung der Skalierung des inneren Würfels
                        }
                        Component.onCompleted: {
                            //console.log(instanceDatas.innerCubeCount)
                        }

                        materials: [
                            DefaultMaterial{
                                depthDrawMode: Material.AlwaysDepthDraw
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
                        //opacity: 0
                        materials: [
                            DefaultMaterial{
                                depthDrawMode: Material.AlwaysDepthDraw
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
                                    var pos = mapPositionToScene(position)
                                    //rectangle.parent.map[id] = pos //Qt.vector3d(pos.x, pos.y, pos.z);
                                    positionMap[id] = pos
                                }
                            }

                            /*if(outerCubeId == 0 && index == 0){
                                console.log(listNodes.nodeAt(outerCubeId).rankAt(index).getId() + ": " + listNodes.nodeAt(outerCubeId).rankAt(index).position)
                            }*/
                            //console.log("OuterCube: " + outerCubeId);
                            //console.log("Rank at: " + index);
                            //console.log("Name: " + listNodes.nodeAt(outerCubeId).getName())
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
                diffuseColor: "#00FF00"
                emissiveFactor: Qt.vector3d(0.1, 0.1, 0.1)
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
                lineWidth: 1.0
            }
        }
        Model {
            id: lineModelColl
            geometry: CustomLineGeometry{
                id: customGeoColl
            }
            visible: coll_lines
            materials: DefaultMaterial {
                diffuseColor: "black"
                emissiveFactor: Qt.vector3d(0.1, 0.1, 0.1)
                lineWidth: 1.0
            }
        }

        DirectionalLight {
            eulerRotation: Qt.vector3d(250, -30, 0);
            brightness: 1.0
            ambientColor: "#7f7f7f"
            /*color: "white"
            worldDirection: Qt.vector3d(250, -30, 0)
            intensity: 1.0*/
        }
    }
    Timer {
       id: updateCheckTimer
       interval: 200 // Wartezeit in Millisekunden (anpassen, falls nötig)
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

   Component.onDestruction: {
       //console.log("destroy")
       cameraNode.destroy()
       viewport.destroy()
   }
}


