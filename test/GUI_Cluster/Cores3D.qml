import QtQuick
import QtQuick3D
import QtQuick3D.Effects
import QtQuick3D.Helpers
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Particles
import GUI_Cluster
//import Qt3D.Render 2.5

Rectangle {
    id: rectangle
    height: parent.height
    color: "#5bc2c6"

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

            function zoom(distance){
                cameraNode.z+=distance;
            }
        }

        MouseArea{
            anchors.fill: parent
            onWheel: {
                if(wheel.angleDelta.y>0){
                    cameraNode.zoom(-10)
                }
                else {
                    cameraNode.zoom(10);
                }
            }
            propagateComposedEvents: true
            onClicked: {
                // Maus- und Kamera-Position im dreidimensionalen Raum
                var mousePos = Qt.vector3d(mouse.x, mouse.y, 0);
                var rayOrigin = cameraNode.position;
                var rayDirection = (viewport.mapTo3DScene(mousePos).minus(rayOrigin)).normalized();
                // Ray wird gesendet, erstes Objekt, welches getroffen wird, ist "hitResult"
                var hitResult = viewport.rayPick(rayOrigin, rayDirection);

                if(hitResult.objectHit){
                    var pickedObject = hitResult.objectHit;
                    pickedObject.isPicked = !pickedObject.isPicked;

                    var objectPosition = pickedObject.position;
                    console.log("Position " + objectPosition);

                    var zoomDistance = 10; // Entfernung der Kamera zum Objekt
                    var cameraDirection = Qt.vector3d(0, 0, -1); // Richtung der Kamera (zum Beispiel nach vorne gerichtet)
                    var cameraPosition = Qt.vector3d(objectPosition.x, objectPosition.y, objectPosition.z+150);

                    console.log("Kameraposition " + cameraPosition);

                    cameraNode.position = cameraPosition;
                    cameraNode.lookAt(objectPosition); // Kamera auf das Objekt ausrichten
                }
            }
        }
        Repeater3D{
            id: outerCubeRepeater
            model: nodesList.count
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
                        opacity: outerCube.isPicked ? 1 : 0.1
                            //shadingMode: CustomMaterial.Shaded
                            //vertexShader: "qrc:/shaders/simple.vert"
                            //fragmentShader: "qrc:/shaders/glass.frag"
                    }
                ]

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

                        instancing: Ranks_Instances {
                            //outerInstanceData : outerCube.instancing.instancePosition()
                            p2p_show: p2p
                            coll_show: collective
                            combobox: option
                            nodes: nodesList
                            send_datasize: nodesList.nodeAt(model.index).rankAt(index).p2p_send_datasize; //Das ist noch keine perfekte Lösung!
                            instanceCount: nodesList.nodeAt(model.index).count
                            instanceRanks: nodesList.nodeAt(model.index)
                            outerCubeLength: 100 //outerCube.bounds.maximum.x - (outerCube.bounds.minimum.x)
                            innerCubeCount: instanceCount
                            innerCubeSpacing: 0.4
                            rowsColumns: Math.ceil(Math.pow(innerCubeCount, 1/3));
                            innerCubeScale: outerCube.scale.x / rowsColumns * (1 - innerCubeSpacing) // Berechnung der Skalierung des inneren Würfels
                        }
                        materials: [
                            PrincipledMaterial{
                               /* baseColor: Qt.rgba(Math.random(), Math.random(), Math.random(), 1)
                                opacity: 0.5*/
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
}


