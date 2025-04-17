import QtQuick
import QtQuick.Window
import QtQuick.Controls 6.2
import QtQuick.Layouts
import GUI_Cluster

Rectangle {
    //Component.onCompleted: listNodes.buildClusterComponents();
    id: screen
    //anchors.fill: parent
    color: "#999999"
    property Cluster_Architecture listNodes: null
    property int cols: parent ? parent.twoD_columns : 0

    ScrollView{
        anchors.fill: parent
        clip: true

        ColumnLayout {
            anchors{
                margins: 5
            }

            spacing: 3

            Repeater {
                id: outerrepeater
                model: screen.listNodes.count

                delegate: Rectangle {
                    property int ranks_in_node: listNodes.nodeAt(model.index).count
                    property int node_index: model.index
                    property int columns2D: cols
                    property int rows2D: Math.ceil(ranks_in_node/cols)

                    width: screen.width
                    height: rows2D * (60 + grid.spacing) + 35
                    Layout.preferredWidth: width
                    Layout.preferredHeight: height
                    color: "#999999"

                    Rectangle{
                        width: parent.width
                        height: 20
                        Text {
                            text: listNodes.nodeAt(model.index).getName();
                        }
                    }

                    Grid{
                        id: grid
                        x: 5
                        y: 30
                        width: parent.width - 10
                        height: parent.height-20 // Hoehe - 20 für den Namen
                        columns: columns2D
                        //rows: rows2D
                        spacing: 1
                        //spacing: calculate_spacing(ranks_in_node, columns)

                        /*onRowsChanged: {
                            console.log("Columns: " + columns)
                            console.log("Rows: " + rows)
                        }*/

                        Repeater{
                            model: ranks_in_node

                            delegate: Rectangle {
                                id: datarect

                                property real send_ds: get_send_ds(node_index, model.index);
                                property real recv_ds: get_recv_ds(node_index, model.index);

                                height: 60//Math.ceil(ranks_in_node/parent.columns))
                                width: (parent.width/parent.columns) -1

                                color: createColor(node_index, model.index)

                                ColumnLayout{
                                    anchors.fill: parent
                                    width: parent.width

                                    Text{
                                        text: "Proc: " + listNodes.nodeAt(node_index).rankAt(model.index).getId()
                                        font.pixelSize: 10
                                        color: "#383936"
                                        visible: (width <= parent.width)
                                    }
                                    Text{
                                        text: "Send: " + parse_ds(send_ds)
                                        visible: (width <= parent.width) && ((option == "send/recv ratio (per proc)") || option == "max send ratio (across all procs)")
                                    }
                                    Text{
                                        text: "Recv: " + parse_ds(recv_ds)
                                        visible: (width <= parent.width) && ((option == "send/recv ratio (per proc)") || option == "max recv ratio (across all procs)")
                                    }
                                    Text{
                                        text: "Wait: " + waitForLatePercent(node_index, model.index, "send")
                                        visible: (width <= parent.width) && (option == "wait for late sender (per proc)")
                                    }
                                    Text{
                                        text: "Wait: " + waitForLatePercent(node_index, model.index, "recv")
                                        visible: (width <= parent.width) && (option == "wait for late recver (per proc)")
                                    }
                                }

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

    function parse_ds(datasize) {
        function formatValue(value) {
            // Entferne ".00", wenn keine Nachkommastellen nötig sind
            return value % 1 === 0 ? value.toString() : value.toFixed(2);
        }

        if (datasize < 1000) {
            return datasize + " Byte";
        } else if (datasize < 1000000) {
            return formatValue(datasize / 1000) + " KB";
        } else if (datasize < 1000000000) {
            return formatValue(datasize / 1000000) + " MB";
        } else {
            return formatValue(datasize / 1000000000) + " GB";
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
                blue = red = green = 224;
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
                blue = red = green = 224;
            }

        }

        //console.log("Red: " + red + " Green: " + green + " Blue: " + blue)
        return "#" + componentToHex(red) + componentToHex(green) + componentToHex(blue);
    }

    function waitForLatePercent(nodeIndex, modelIndex, send_recv){
        var coll_data, p2p_data, coll_time_diff, p2p_time_diff, p2p_lates, coll_lates, time_diff, weight_p2p, weight_coll;
        var full_percent, send_percent, recv_percent = 1;
        if(send_recv == "send"){
            var lateSenderData = 1;
            coll_data = Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).coll_late_sender);
            p2p_data = Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).p2p_late_sender);
            coll_time_diff = Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).coll_timediff);
            p2p_time_diff = Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).p2p_timediff);

            if(coll_data == 0 && p2p_data == 0 && coll_time_diff == 0 && p2p_time_diff == 0){
                return "0.00%"
            }

            if(p2p && collective){
                if(coll_data === 0) {
                    return (p2p_data/p2p_time_diff * 100).toFixed(2) + "%";
                } else if (p2p_data === 0){
                    return (coll_data/coll_time_diff * 100).toFixed(2) + "%";
                } else {
                    p2p_lates = p2p_data/p2p_time_diff;
                    coll_lates = coll_data/coll_time_diff;
                    time_diff = p2p_time_diff + coll_time_diff;

                    weight_p2p = (p2p_time_diff/time_diff) * p2p_lates;
                    weight_coll = (coll_time_diff/time_diff) * coll_lates;

                    return (weight_p2p + weight_coll).toFixed(2) + "%";
                }
            } else if(p2p) {
                return (p2p_data/p2p_time_diff * 100).toFixed(2)+ "%" ;
            } else if(collective) {
                return (coll_data/coll_time_diff * 100).toFixed(2) + "%";
            }
        } else if(send_recv == "recv"){
            var lateRecvrData;
            coll_data = Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).coll_late_recvr);
            p2p_data = Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).p2p_late_recvr);
            coll_time_diff = Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).coll_timediff);
            p2p_time_diff = Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).p2p_timediff);

            if(coll_data == 0 && p2p_data == 0 && coll_time_diff == 0 && p2p_time_diff == 0){
                return "0.00%"
            }

            if(p2p && collective){
                if(coll_data === 0) {
                    return (p2p_data/p2p_time_diff * 100).toFixed(2) + "%";
                } else if (p2p_data === 0){
                    return (coll_data/coll_time_diff * 100).toFixed(2) + "%";
                } else {
                    p2p_lates = p2p_data/p2p_time_diff;
                    coll_lates = coll_data/coll_time_diff;
                    time_diff = p2p_time_diff + coll_time_diff;

                    weight_p2p = (p2p_time_diff/time_diff * 100) * p2p_lates;
                    weight_coll = (coll_time_diff/time_diff) * coll_lates;

                    return (weight_p2p + weight_coll * 100).toFixed(2) + "%";
                }
            } else if(p2p) {
                return (p2p_data/p2p_time_diff * 100).toFixed(2) + "%";
            } else if(collective) {
                return (coll_data/coll_time_diff * 100).toFixed(2) + "%";
            }
        }
    }

    function componentToHex(c) {
            //console.log("test");
            var hex = Math.round(c).toString(16);
            return hex.length == 1 ? "0" + hex : hex;
    }
}
