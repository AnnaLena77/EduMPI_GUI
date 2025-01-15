import QtQuick
import QtQuick.Window
import QtQuick.Controls 6.2
import GUI_Cluster

Rectangle {
    //Component.onCompleted: listNodes.buildClusterComponents();
    id: screen
    //anchors.fill: parent
    //height: parent.height
    color: "#999999"
    property Cluster_Architecture listNodes: null

    ScrollView{
        anchors.fill: parent

        Column {
            anchors{
                margins: 5
            }

            spacing: 3

            Repeater {

                model: screen.listNodes.count

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
                                    //text: listNodes.nodeAt(node_index).rankAt(model.index).getId()
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

    function get_send_ds(nodeIndex, modelIndex){
        if(p2p && collective){
            let sum1 = Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).p2p_send_datasize);
            let sum2 = Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).coll_send_datasize);
            let sum = sum1 + sum2;
            return sum;
        }
        else if(p2p){
            return listNodes.nodeAt(nodeIndex).rankAt(modelIndex).p2p_send_datasize;
        }
        else if(collective){
            return listNodes.nodeAt(nodeIndex).rankAt(modelIndex).coll_send_datasize;
        }
        else {
            return 0;
        }
    }

    function get_recv_ds(nodeIndex, modelIndex){
        if(p2p && collective){
            var sum = Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).p2p_recv_datasize) + Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).coll_recv_datasize);
            return sum;
        }
        else if(p2p){
            return listNodes.nodeAt(nodeIndex).rankAt(modelIndex).p2p_recv_datasize;
        }
        else if(collective){
            return listNodes.nodeAt(nodeIndex).rankAt(modelIndex).coll_recv_datasize;
        }
        else {
            return 0;
        }
    }

    function createColor(nodeIndex, modelIndex){
        var coll_data, p2p_data, coll_time_diff, p2p_time_diff, p2p_lates, coll_lates, time_diff, weight_p2p, weight_coll;
        var send_ds = get_send_ds(nodeIndex, modelIndex);
        var recv_ds = get_recv_ds(nodeIndex, modelIndex);
        var full_percent, send_percent, recv_percent = 1;
        var red, green, blue = 255;
        if(option == "send/recv ratio (per proc)"){
            gradient1 = "green"
            gradient2 = "red"
            full_percent = Number(send_ds) + Number(recv_ds)
            send_percent = send_ds / full_percent
            recv_percent = recv_ds / full_percent

            red = recv_percent * 255; // Je höher der Empfangsanteil, desto mehr Rot
            green = send_percent * 255; // Je höher der Sendeanteil, desto mehr Grün
            blue = 255 - (red + green); // Rest wird in Blau gemischt

            if(full_percent === 0){
                red = 224;
                green = 224;
                blue = 224;
            }
        }
        else if(option == "max send ratio (across all procs)"){
            gradient1 = "green"
            gradient2 = "white"
            if(p2p && collective){
                full_percent = Number(listNodes.coll_send_max) + Number(listNodes.p2p_send_max);
            } else if(p2p){
                full_percent = Number(listNodes.p2p_send_max);
            } else if(collective){
                full_percent = Number(listNodes.coll_send_max);
            }
            send_percent = send_ds / full_percent
            green = 255;
            red = 255 - send_percent*255; // Je höher der Empfangsanteil, desto mehr Rot
            blue = 255 - send_percent*255; // Rest wird in Blau gemischt
            if(full_percent === 0){
                red = 224;
                green = 224;
                blue = 224;
            }
        }
        else if(option == "max recv ratio (across all procs)"){
            if(p2p && collective){
                full_percent = Number(listNodes.coll_recv_max) + Number(listNodes.p2p_recv_max);
                //console.log(modelIndex + ": " +listNodes.p2p_recv_max);
            } else if(p2p){
                full_percent = Number(listNodes.p2p_recv_max);
            } else if(collective){
                full_percent = Number(listNodes.coll_recv_max);
            }
            recv_percent = recv_ds / full_percent
            red = 255;
            green = 255 - recv_percent*255;
            blue = 255 - recv_percent*255;
            if(full_percent === 0){
                red = 224;
                green = 224;
                blue = 224;
            }

        }
        else if(option == "wait for late sender (per proc)"){
            var lateSenderData = 1;
            coll_data = Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).coll_late_sender);
            p2p_data = Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).p2p_late_sender);
            coll_time_diff = Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).coll_timediff);
            p2p_time_diff = Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).p2p_timediff);

            if(p2p && collective){
                if(coll_data === 0) {
                    lateSenderData = p2p_data/p2p_time_diff;
                } else if (p2p_data === 0){
                    lateSenderData = coll_data/coll_time_diff;
                } else {
                    p2p_lates = p2p_data/p2p_time_diff;
                    coll_lates = coll_data/coll_time_diff;
                    time_diff = p2p_time_diff + coll_time_diff;

                    weight_p2p = (p2p_time_diff/time_diff) * p2p_lates;
                    weight_coll = (coll_time_diff/time_diff) * coll_lates;

                    lateSenderData = weight_p2p + weight_coll;
                }
            } else if(p2p) {
                lateSenderData = p2p_data/p2p_time_diff;
            } else if(coll) {
                lateSenderData = coll_data/coll_time_diff;;
            }

            blue = 255;
            red = 255 - lateSenderData*255;
            green = 255 - lateSenderData*255;

            if(isNaN(lateSenderData)){
                blue = red = green = 255;
            }

        }
        else if(option == "wait for late recver (per proc)"){
            var lateRecvrData;
            coll_data = Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).coll_late_recvr);
            p2p_data = Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).p2p_late_recvr);
            coll_time_diff = Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).coll_timediff);
            p2p_time_diff = Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).p2p_timediff);

            if(p2p && collective){
                if(coll_data === 0) {
                    lateRecvrData = p2p_data/p2p_time_diff;
                } else if (p2p_data === 0){
                    lateRecvrData = coll_data/coll_time_diff;
                } else {
                    p2p_lates = p2p_data/p2p_time_diff;
                    coll_lates = coll_data/coll_time_diff;
                    time_diff = p2p_time_diff + coll_time_diff;

                    weight_p2p = (p2p_time_diff/time_diff) * p2p_lates;
                    weight_coll = (coll_time_diff/time_diff) * coll_lates;

                    lateRecvrData = weight_p2p + weight_coll;
                }
            } else if(p2p) {
                lateRecvrData = p2p_data/p2p_time_diff;
            } else if(coll) {
                lateRecvrData = coll_data/coll_time_diff;;
            }

            blue = 255;
            red = 255 - lateRecvrData*255;
            green = 255 - lateRecvrData*255;

            if(isNaN(lateRecvrData)){
                blue = red = green = 255;
            }

        }

        //console.log("Red: " + red + " Green: " + green + " Blue: " + blue)
        return "#" + componentToHex(red) + componentToHex(green) + componentToHex(blue);
    }

    function componentToHex(c) {
            //console.log("test");
            var hex = Math.round(c).toString(16);
            return hex.length == 1 ? "0" + hex : hex;
    }
}
