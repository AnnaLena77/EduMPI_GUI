import QtQuick

Rectangle {
    height: parent.height
    color: "#bbbe8c"

    Column {
        anchors{
            fill: parent
            margins: 5
        }

        spacing: 3

        Repeater {

            model: _nodesList.count

            delegate: Rectangle {
                width: parent.width
                height: 200
                color: "lightblue"

                Rectangle{
                    width: parent.width
                    height: 20
                    Text {
                        text: _nodesList.nodeAt(model.index).getName();
                    }
                }

                property int cores_in_node: _nodesList.nodeAt(model.index).count;
                property int node_index: model.index
                Grid{
                    x: 5
                    y: 30
                    width: parent.width
                    height: parent.height-20
                    columns: 4
                    spacing: calculate_spacing(cores_in_node, columns)

                    function calculate_spacing(cores_in_node, columns){
                       var spacing = cores_in_node/columns;
                       return spacing >= 1 ? spacing : 1;
                    }

                    Repeater{
                        model: cores_in_node

                        delegate: Rectangle {
                            height: (parent.height/parent.spacing)-(20/parent.spacing)
                            width: parent.width/parent.columns-5
                            color: "green"
                            Text{
                                text: _nodesList.nodeAt(node_index).coreAt(model.index).getId();
                            }
                            Text{
                                y: 20
                                text: _nodesList.nodeAt(node_index).coreAt(model.index).datasize
                            }
                        }
                    }
                }
            }
        }
    }
}
