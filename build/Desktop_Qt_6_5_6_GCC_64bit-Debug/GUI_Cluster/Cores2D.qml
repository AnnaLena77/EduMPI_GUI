import QtQuick
import QtQuick.Window
import QtQuick.Controls 6.2
import Qt.db.nodes 1.0

Rectangle {
    //Component.onCompleted: listNodes.buildClusterComponents();
    id: screen
    height: parent.height
    color: "#999999"
    property Nodes_List listNodes: null

    ScrollView{
        anchors.fill: parent

        Column {
            anchors{
                margins: 5
            }

            spacing: 3

            Repeater {

                model: listNodes.count

                delegate: Rectangle {
                    width: screen.width
                    height: 300
                    color: "#999999"

                    Rectangle{
                        width: parent.width
                        height: 20
                        Text {
                            text: listNodes.nodeAt(model.index).getName();
                        }
                    }

                    property int ranks_in_node: listNodes.nodeAt(model.index).count
                    property int node_index: model.index

                    Grid{
                        x: 5
                        y: 30
                        width: parent.width
                        height: parent.height-30 // Hoehe - 20 für den Namen
                        columns: 10
                        spacing: calculate_spacing(ranks_in_node, columns)

                        function calculate_spacing(ranks_in_node, columns){
                           var spacing = ranks_in_node/columns;
                           return spacing >= 1 ? Math.ceil(spacing) : 1;
                        }

                        Repeater{
                            model: ranks_in_node

                            delegate: Rectangle {
                                id: datarect

                                property real send_ds: get_send_ds(node_index, model.index);//listNodes.nodeAt(node_index).rankAt(model.index).send_datasize
                                property real recv_ds: get_recv_ds(node_index, model.index);//listNodes.nodeAt(node_index).rankAt(model.index).p2p_recv_datasize

                                height: (parent.height/parent.spacing)-5
                                width: parent.width/parent.columns-5

                                Text{
                                    text: listNodes.nodeAt(node_index).rankAt(model.index).getId()
                                }
                                Text{
                                    y: 20
                                    text: "Send: " + send_ds
                                }
                                Text{
                                    y: 40
                                    text: "Recv: " + recv_ds
                                }

                                color: createColor(node_index, model.index)

                                /*Component.onCompleted: {
                                    console.log("Rectangle, modelindex: " + model.index)
                                }*/
                            }
                        }
                    }
                }
            }
        }
    }
}
