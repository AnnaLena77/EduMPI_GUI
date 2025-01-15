import QtQuick
import QtQuick3D 6.8
import GUI_Cluster
//import Qt3D.Render 2.5

Rectangle {
    id: rectangle
    //height: parent.height
    color: "#5bc2c6"
    //anchors.fill: parent

    property Cluster_Architecture listNodes: null

    /*Component.onCompleted: {
        console.log("Nodes_List received:", listNodes)
    }*/

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
                        instanceRoot: outerCube

                        Component.onCompleted: {
                            //console.log("Nodes" +listNodes.nodeAt(0))
                        }

                        instancing: Ranks_Instances {
                            //outerInstanceData : outerCube.instancing.instancePosition()
                            id: instanceData
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
                            Component.onCompleted: {
                                //console.log(model.index + ", " + index)
                                //console.log("Rows: " + rowsColumns)
                            }
                        }

                        materials: [
                            PrincipledMaterial{
                               //baseColor: Qt.rgba(Math.random(), Math.random(), Math.random(), 1)
                                //opacity: 0.5
                            }
                        ]

                        //onBoundsChanged: console.log("hallo" + index)
                    }
                }
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
   Component.onDestruction: {
       //console.log("destroy")
       viewport.destroy()
   }
}


