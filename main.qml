import QtQuick
import QtQuick.Controls
import QtQuick.Window
import Qt.db.qobjectSingleton 1.0

Window {
    id: root
    width: 1920
    height: 1080
    visible: true
    property alias actualScreen: actualScreen
    title: qsTr("Hello World")

    onClosing: {
        nodesList.closeApp()
    }

    property bool p2p: true
    property bool collective: true
    property string option: "Send/Recv Ratio"
    property color gradient1: "green"
    property color gradient2: "red"
    property string gradient_text1: "Send"
    property string gradient_text2: "Recv"

    property string db_host: ""
    property string db_port: ""
    property string db_name: ""
    property string db_user: ""
    property string db_password: ""

    NodesList{
        id: nodesList
        onComponentsBuilt: {
            actualScreen.source = "Cores3D.qml"
            console.log("Checki")
        }
    }

    Menu_Bar{
        id: menu

    }

    /*Sidebar {
        id: sidebar
        anchors.top: menu.bottom
    }*/

    /*Cores2D {
        id: cores2d
        anchors {
            left: sidebar.right
            right: options.left
            top: parent.top
            bottom: parent.bottom
        }

    }*/

    Loader{
        id: actualScreen

        focus: true
        anchors {
            left: parent.left
            right: options.left
            top: menu.bottom
            bottom: parent.bottom
        }

        function reload(){
            actualScreen.source = "";
            QmlEngine.clearCache();
        }

        //anchors.fill: parent
        //source: "Cores2D.qml"
    }
    Options_Bar{
        id: options
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
    }


    function get_send_ds(nodeIndex, modelIndex){
        if(p2p && collective){
            let sum1 = Number(nodesList.nodeAt(nodeIndex).rankAt(modelIndex).p2p_send_datasize);
            let sum2 = Number(nodesList.nodeAt(nodeIndex).rankAt(modelIndex).coll_send_datasize);
            let sum = sum1 + sum2;
            return sum;
        }
        else if(p2p){
            return nodesList.nodeAt(nodeIndex).rankAt(modelIndex).p2p_send_datasize;
        }
        else if(collective){
            return nodesList.nodeAt(nodeIndex).rankAt(modelIndex).coll_send_datasize;
        }
        else {
            return 0;
        }
    }

    function get_recv_ds(nodeIndex, modelIndex){
        if(p2p && collective){
            var sum = Number(nodesList.nodeAt(nodeIndex).rankAt(modelIndex).p2p_recv_datasize) + Number(nodesList.nodeAt(nodeIndex).rankAt(modelIndex).coll_recv_datasize);
            return sum;
        }
        else if(p2p){
            return nodesList.nodeAt(nodeIndex).rankAt(modelIndex).p2p_recv_datasize;
        }
        else if(collective){
            return nodesList.nodeAt(nodeIndex).rankAt(modelIndex).coll_recv_datasize;
        }
        else {
            return 0;
        }
    }

    function createColor(send_ds, recv_ds){
        var full_percent, send_percent, recv_percent = 1;
        var red, green, blue = 255;
        if(option == "Send/Recv Ratio"){
            gradient1 = "green"
            gradient2 = "red"
            full_percent = Number(send_ds) + Number(recv_ds)
            send_percent = send_ds / full_percent
            recv_percent = recv_ds / full_percent

            red = recv_percent * 255; // Je höher der Empfangsanteil, desto mehr Rot
            green = send_percent * 255; // Je höher der Sendeanteil, desto mehr Grün
            blue = 255 - (red + green); // Rest wird in Blau gemischt
        }
        else if(option == "Max Send Ratio"){
            gradient1 = "green"
            gradient2 = "white"
            if(p2p && collective){
                full_percent = Number(nodesList.coll_send_max) + Number(nodesList.p2p_send_max);
            } else if(p2p){
                full_percent = Number(nodesList.p2p_send_max);
            } else if(collective){
                full_percent = Number(nodesList.coll_send_max);
            }
            send_percent = send_ds / full_percent
            green = 255;
            red = 255 - send_percent*255; // Je höher der Empfangsanteil, desto mehr Rot
            blue = 255 - send_percent*255; // Rest wird in Blau gemischt
        }
        else if(option == "Max Recv Ratio"){
            if(p2p && collective){
                full_percent = Number(nodesList.coll_recv_max) + Number(nodesList.p2p_recv_max);
            } else if(p2p){
                full_percent = Number(nodesList.p2p_recv_max);
            } else if(collective){
                full_percent = Number(nodesList.coll_recv_max);
            }
            recv_percent = recv_ds / full_percent
            red = 255;
            green = 255 - recv_percent*255;
            blue = 255 - recv_percent*255;

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
