import QtQuick
import QtQuick.Controls
import QtQuick.Window
import Qt.db.qobjectSingleton 1.0

Window {
    id: root
    width: 1920
    height: 1080
    visible: true
    onClosing: {
        nodesList.closeApp()
    }

    property alias actualScreen: actualScreen
    title: qsTr("EduMPI")

    property bool p2p: true
    property bool collective: true
    property string option: "Send/Recv Ratio (per Proc)"
    property color gradient1: "green"
    property color gradient2: "red"
    property string gradient_text1: "Send"
    property string gradient_text2: "Recv"

    property string db_host: ""
    property string db_port: ""
    property string db_name: ""
    property string db_user: ""
    property string db_password: ""
    property bool db_connection_success: false
    property string success_text: ""
    property color success_color: "white"

    property string slurm_status: ""

    //Properties for timeline
    property bool enable_timeline
    property int startTime: 0
    property string loaderText: ""
    property bool visualization: true

    property bool enable_start: true

    Item {
        id: rootItem
        anchors.fill: parent
    }


    NodesList{
        id: nodesList
        onComponentsBuilt: {
            actualScreen.source = ""
            actualScreen.source = "Cores3D.qml"
            //playbutton.enabled = true
        }
        onConnectionSignal: (success)=>{
            if(success){
                success_color = "green"
                success_text = "Database connection successfully established"
            } else {
                success_color = "red"
                success_text = "Database connection failed. Check the access data and password. Make sure that any necessary VPN connection is established."
            }
        }
        onSignalSlurmStatusChanged: (status)=>{
            if(visualization){
                if(status === "pending"){
                    slurm_status = "pending"
                    loaderText = "Job-Status: Pending! \nYour job is in the Slurm queue and is waiting for free resources. Please be patient for a moment."
                } else if(status === "running"){
                    slurm_status = "running"
                    loaderText = "Job-Status: Running! \nYour Slurm job is in the start process, the MPI communication will start at any moment."
                } else if(status === "completed"){
                    slurm_status = "completed"
                    loaderText = "Job-Status: Completed! \nYour Slurm job ended unexpectedly. Check the output to analyze possible errors."
                }
            } else {
                if(status === "pending"){
                    slurm_status = "pending"
                    loaderText = "Job-Status: Pending! \nYour job is in the Slurm queue and is waiting for free resources. Please be patient for a moment."
                } else if(status === "running"){
                    slurm_status = "running"
                    loaderText = "Job-Status: Running!"
                } else if(status === "completed"){
                    slurm_status = "completed"
                    loaderText = "Job-Status: Completed!"
                }
            }
        }

        onDataIn: (timestamp)=>{
            startTime = timestamp;
            enable_timeline = true;
            console.log("startTime: "+ startTime)
        }
        onCopiedOutputFile: (output_path) => {
            var window;
            var component = Qt.createComponent("Output_File.qml");
            if(component.status === Component.Ready){
            window = component.createObject(root, {"path": output_path});
            window.x = (root.width - window.width) / 2;
            window.y = (root.height - window.height) / 2;
            window.show();
            enable_start = true;
            }
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
    Sidebar{
        id: options
        anchors.right: parent.right
        //anchors.verticalCenter: parent.verticalCenter
        anchors.bottom: timeline_main.top
        anchors.top: menu.bottom
    }
    Bottom_Bar{
        id: timeline_main
        anchors.bottom: parent.bottom
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
        if(option == "Send/Recv Ratio (per Proc)"){
            gradient1 = "green"
            gradient2 = "red"
            full_percent = Number(send_ds) + Number(recv_ds)
            send_percent = send_ds / full_percent
            recv_percent = recv_ds / full_percent

            red = recv_percent * 255; // Je höher der Empfangsanteil, desto mehr Rot
            green = send_percent * 255; // Je höher der Sendeanteil, desto mehr Grün
            blue = 255 - (red + green); // Rest wird in Blau gemischt
        }
        else if(option == "Max Send Ratio (over all Procs)"){
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
        else if(option == "Max Recv Ratio (over all Procs)"){
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
        else if(option == "Wait for Late Sender (per Proc)"){
            if(p2p && collective){

            }

        }
        else if(option == "Wait for Late Recver (per Proc)"){
            if(p2p && collective){

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
