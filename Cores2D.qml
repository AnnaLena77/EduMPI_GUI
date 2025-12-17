import QtQuick
import QtQuick.Window
import QtQuick.Controls 6.2
import QtQuick.Layouts
import GUI_Cluster

Rectangle {
    id: screen
    color: "#999999"
    property Cluster_Architecture listNodes: null
    property int cols: parent ? parent.twoD_columns : 0

    // *** FIX: ColumnLayout um das gesamte Layout ***
    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 5
        spacing: 8

        // *** Information Bar AUSSERHALB des ScrollView ***
        Detailed_Information_Bar {
            visible: listNodes && listNodes.count > 0
            heading: getHeadingForOption()
            avgValue: getAvgValueForOption()
            maxValue: getMaxValueForOption()
            colorStops: getColorStopsForOption()
            tooltipText: getTooltipForOption()
            z: 1000
        }

        // *** ScrollView als zweites Element im Layout ***
        ScrollView {
            Layout.fillWidth: true
            Layout.fillHeight: true
            clip: true

            ColumnLayout {
                width: parent.width
                spacing: 3

                Repeater {
                    id: outerrepeater
                    model: screen.listNodes ? screen.listNodes.count : 0

                    delegate: Rectangle {
                        property int ranks_in_node: listNodes.nodeAt(model.index).count
                        property int node_index: model.index
                        property int columns2D: cols
                        property int rows2D: Math.ceil(ranks_in_node/cols)

                        width: screen.width - 20  // *** Angepasst für ScrollView ***
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
                            height: parent.height-20
                            columns: columns2D
                            spacing: 1

                            Repeater{
                                model: ranks_in_node

                                delegate: Rectangle {
                                    id: datarect

                                    property real send_ds: get_send_ds(node_index, model.index);
                                    property real recv_ds: get_recv_ds(node_index, model.index);

                                    height: 60
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
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // *** Deine Funktionen mit Null-Checks ***
    function getHeadingForOption() {
        if (!listNodes || listNodes.count === 0) return "Loading..."

        switch(option) {
            case "send/recv ratio (per proc)": return "2D Detailed View: Send/Recv Ratio per Process"
            case "max send ratio (across all procs)": return "2D Detailed View: Max Send Ratio (All Processes)"
            case "max recv ratio (across all procs)": return "2D Detailed View: Max Recv Ratio (All Processes)"
            case "wait for late sender (per proc)": return "2D Detailed View: Wait for Late Sender"
            case "wait for late recver (per proc)": return "2D Detailed View: Wait for Late Receiver"
            default: return "Process Communication"
        }
    }

    function getColorStopsForOption() {
        switch(option) {
            case "send/recv ratio (per proc)":
                return ["#00ff00", "#ff0000"]
            case "max send ratio (across all procs)":
                return ["#ffffff", "#00ff00"]
            case "max recv ratio (across all procs)":
                return ["#ffffff", "#ff0000"]
            case "wait for late sender (per proc)":
                return ["#ffffff", "#0000ff"]
            case "wait for late recver (per proc)":
                return ["#ffffff", "#0000ff"]
            default:
                return ["#ffffff", "#000000"]
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
            return "2D Detailed View\nRatio between sent and received data per process.\n- Green = more sent data\n- Red = more received data\n- Brown/Ochre = Sent and received data are approximately equal\n- White = No MPI communication."

        case "max send ratio (across all procs)":
            return "2D Detailed View: Maximum send ratio across all processes.\n- White = No data\n- Green = Highest amount of sent data"

        case "max recv ratio (across all procs)":
            return "2D Detailed View Maximum receive ratio across all processes.\n- White = No data\n- Red = Highest amount of received data"

        case "wait for late sender (per proc)":
            return "2D Detailed View: Wait time for late senders per process.\n- White = No wait time\n- Blue = High wait time"

        case "wait for late recver (per proc)":
            return "2D Detailed View Wait time for late receivers per process.\n- White = No wait time\n- Blue = High wait time"

        default:
            return "2D Detailed View Communication Visualization\n- Mouse wheel = Zoom\n- Drag = Rotate view\n- Click on cube = Focus on process"

        }
    }

    // *** Alle deine anderen Funktionen unverändert ***
    function calculateAvgSendRecv() { return 50000 }
    function calculateAvgSend() { return 25000 }
    function calculateAvgRecv() { return 25000 }
    function calculateMaxSendRecv() { return 100000 }

    function get_send_ds(nodeIndex, modelIndex) {
        if(p2p && collective) {
            let sum1 = Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).p2p_send_datasize);
            let sum2 = Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).coll_send_datasize);
            let sum = sum1 + sum2;
            return sum;
        }
        else if(p2p) {
            return listNodes.nodeAt(nodeIndex).rankAt(modelIndex).p2p_send_datasize;
        }
        else if(collective) {
            return listNodes.nodeAt(nodeIndex).rankAt(modelIndex).coll_send_datasize;
        }
        else {
            return 0;
        }
    }

    function parse_ds(datasize) {
        function formatValue(value) {
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

    function get_recv_ds(nodeIndex, modelIndex) {
        if(p2p && collective) {
            var sum = Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).p2p_recv_datasize) + Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).coll_recv_datasize);
            return sum;
        }
        else if(p2p) {
            return listNodes.nodeAt(nodeIndex).rankAt(modelIndex).p2p_recv_datasize;
        }
        else if(collective) {
            return listNodes.nodeAt(nodeIndex).rankAt(modelIndex).coll_recv_datasize;
        }
        else {
            return 0;
        }
    }

    function createColor(nodeIndex, modelIndex) {
        var coll_data, p2p_data, coll_time_diff, p2p_time_diff, p2p_lates, coll_lates, time_diff, weight_p2p, weight_coll;
        var send_ds = get_send_ds(nodeIndex, modelIndex);
        var recv_ds = get_recv_ds(nodeIndex, modelIndex);
        var full_percent, send_percent, recv_percent = 1;
        var red, green, blue = 255;

        if(option == "send/recv ratio (per proc)") {
            gradient1 = "green"
            gradient2 = "red"
            full_percent = Number(send_ds) + Number(recv_ds)
            send_percent = send_ds / full_percent
            recv_percent = recv_ds / full_percent

            red = recv_percent * 255;
            green = send_percent * 255;
            blue = 255 - (red + green);

            if(full_percent === 0) {
                red = 224;
                green = 224;
                blue = 224;
            }
        }
        else if(option == "max send ratio (across all procs)") {
            gradient1 = "green"
            gradient2 = "white"
            if(p2p && collective) {
                full_percent = Number(listNodes.coll_send_max) + Number(listNodes.p2p_send_max);
            } else if(p2p) {
                full_percent = Number(listNodes.p2p_send_max);
            } else if(collective) {
                full_percent = Number(listNodes.coll_send_max);
            }
            send_percent = send_ds / full_percent
            green = 255;
            red = 255 - send_percent*255;
            blue = 255 - send_percent*255;
            if(full_percent === 0) {
                red = 224;
                green = 224;
                blue = 224;
            }
        }
        else if(option == "max recv ratio (across all procs)") {
            if(p2p && collective) {
                full_percent = Number(listNodes.coll_recv_max) + Number(listNodes.p2p_recv_max);
            } else if(p2p) {
                full_percent = Number(listNodes.p2p_recv_max);
            } else if(collective) {
                full_percent = Number(listNodes.coll_recv_max);
            }
            recv_percent = recv_ds / full_percent
            red = 255;
            green = 255 - recv_percent*255;
            blue = 255 - recv_percent*255;
            if(full_percent === 0) {
                red = 224;
                green = 224;
                blue = 224;
            }
        }
        else if(option == "wait for late sender (per proc)") {
            var lateSenderData = 1;
            coll_data = Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).coll_late_sender);
            p2p_data = Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).p2p_late_sender);
            coll_time_diff = Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).coll_timediff);
            p2p_time_diff = Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).p2p_timediff);

            if(p2p && collective) {
                if(coll_data === 0) {
                    lateSenderData = p2p_data/p2p_time_diff;
                } else if (p2p_data === 0) {
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
                lateSenderData = coll_data/coll_time_diff;
            }

            blue = 255;
            red = 255 - lateSenderData*255;
            green = 255 - lateSenderData*255;

            if(isNaN(lateSenderData)) {
                blue = red = green = 224;
            }
        }
        else if(option == "wait for late recver (per proc)") {
            var lateRecvrData;
            coll_data = Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).coll_late_recvr);
            p2p_data = Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).p2p_late_recvr);
            coll_time_diff = Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).coll_timediff);
            p2p_time_diff = Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).p2p_timediff);

            if(p2p && collective) {
                if(coll_data === 0) {
                    lateRecvrData = p2p_data/p2p_time_diff;
                } else if (p2p_data === 0) {
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
                lateRecvrData = coll_data/coll_time_diff;
            }

            blue = 255;
            red = 255 - lateRecvrData*255;
            green = 255 - lateRecvrData*255;

            if(isNaN(lateRecvrData)) {
                blue = red = green = 224;
            }
        }

        return "#" + componentToHex(red) + componentToHex(green) + componentToHex(blue);
    }

    function waitForLatePercent(nodeIndex, modelIndex, send_recv) {
        var coll_data, p2p_data, coll_time_diff, p2p_time_diff, p2p_lates, coll_lates, time_diff, weight_p2p, weight_coll;
        var full_percent, send_percent, recv_percent = 1;

        if(send_recv == "send") {
            var lateSenderData = 1;
            coll_data = Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).coll_late_sender);
            p2p_data = Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).p2p_late_sender);
            coll_time_diff = Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).coll_timediff);
            p2p_time_diff = Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).p2p_timediff);

            if(coll_data == 0 && p2p_data == 0 && coll_time_diff == 0 && p2p_time_diff == 0) {
                return "0.00%"
            }

            if(p2p && collective) {
                if(coll_data === 0) {
                    return (p2p_data/p2p_time_diff * 100).toFixed(2) + "%";
                } else if (p2p_data === 0) {
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
                return (p2p_data/p2p_time_diff * 100).toFixed(2) + "%";
            } else if(collective) {
                return (coll_data/coll_time_diff * 100).toFixed(2) + "%";
            }
        } else if(send_recv == "recv") {
            var lateRecvrData;
            coll_data = Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).coll_late_recvr);
            p2p_data = Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).p2p_late_recvr);
            coll_time_diff = Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).coll_timediff);
            p2p_time_diff = Number(listNodes.nodeAt(nodeIndex).rankAt(modelIndex).p2p_timediff);

            if(coll_data == 0 && p2p_data == 0 && coll_time_diff == 0 && p2p_time_diff == 0) {
                return "0.00%"
            }

            if(p2p && collective) {
                if(coll_data === 0) {
                    return (p2p_data/p2p_time_diff * 100).toFixed(2) + "%";
                } else if (p2p_data === 0) {
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
        var hex = Math.round(c).toString(16);
        return hex.length == 1 ? "0" + hex : hex;
    }
}
