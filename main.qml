import QtQuick
import QtQuick.Controls
import QtQuick.Window
//import appGui_Cluster.Controller 1.0
//import appGui_Cluster.Nodes 1.0
import GUI_Cluster 1.0
import Sidebar 1.0
import "."

Window {
    id: root
    width: 1920
    height: 1080
    visible: true
    onClosing: {
        controller.closeApp()
    }

    //property alias actualScreen: actualScreen
    title: qsTr("EduMPI")

    property bool p2p: true
    property bool collective: true
    property string option: "send/recv ratio (per proc)"
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
    property int endTime: 0
    property int delayedEndTime: 0
    property string loaderText: ""
    property bool visualization: true

    property bool enable_start: true
    property bool build_numbers: false

    property int restarts: -1

    property bool p2p_send_lines: false
    property bool p2p_recv_lines: false

    onRestartsChanged: {
        if(restarts > 0) {
            controller.copyEnvFile();
            actualScreen.clear();
            startTime = 0;
            endTime = 0;
            delayedEndTime = 0;
            enable_timeline = false;
            controller.setComponentsBuild(false);
            nodesList.resetCluster_Architecture();
            loaderText = ""
        }
    }


    Item {
        id: rootItem
        anchors.fill: parent
        width: parent.width
        height: parent.height
        property int endTime: root.endTime
        property string option: root.option

        function flash() {
            opacityAnimation.start();
        }

        // Transparenz-Animation
        NumberAnimation {
            id: opacityAnimation
            target: rootItem
            property: "opacity"
            from: 1.0
            to: 0.1
            duration: 400 // Dauer des Aufblitzens (ms)
            onStopped: rootItem.opacity = 1.0 // Zurück zur Original-Transparenz
        }


        Cluster_Architecture{
            id: nodesList
            onComponentsBuilt: {
                controller.setComponentsBuild(true)
                //actualScreen.source = ""
                //actualScreen.source = "Cores3D.qml"
                actualScreen.push("Cores3D.qml", {listNodes : nodesList})
                //actualScreen.sourceComponent.nodesListModel = nodesList;
                //playbutton.enabled = true
            }
            onDataIn: (timestamp, qTimestamp, start)=>{
                if(start){
                    if(root.endTime == 0){
                        root.endTime = root.delayedEndTime
                    }
                    root.startTime = timestamp;
                    var qtime = qTimestamp;
                    root.enable_timeline = true;
                    controller.setTimestamp(qtime)
                    console.log("startTime: "+ root.startTime)
                } else {
                    //root.endTime = timestamp;
                    //root.enable_start = true;
                }
            }
            Component.onCompleted: {
                if(root.db_connection_success){
                    //nodesList.initialize(controller.getDatabaseConnection)
                    //nodesList.startThread()
                }
            }
        }

        Controller{
            id: controller

            onSignalEndTime: (time)=>{
                if(root.startTime == 0){
                    nodesList.set_end_time(-1);
                    root.delayedEndTime = time;
                } else {
                    root.endTime = time;
                    nodesList.set_end_time(root.endTime-root.startTime)
                }
            }

            onLiveSlurmID: (slurm_id)=>{
                if(root.visualization){
                    nodesList.setOption(0);
                }
                nodesList.set_slurm_id(slurm_id);
                    slurmnotifier.sl_id = slurm_id
                }

            onConnectionSignal: (success)=>{
                if(success){
                    root.success_color = "green"
                    root.success_text = "Database connection successfully established"
                    if(!controller.getDatabaseConnection){

                    } else {
                        var dbConnection = controller.getDatabaseConnection()
                        nodesList.initialize(dbConnection, true);
                    }
                } else {
                    root.success_color = "red"
                    root.success_text = "Database connection failed. Check the access data and password. Make sure that any necessary VPN connection is established."
                }
            }
            onSignalSlurmStatusChanged: (status)=>{
                if(root.visualization){
                    if(status === "pending"){
                        root.slurm_status = "pending"
                        root.loaderText = "Job-Status: Pending! \nYour job is in the SLURM queue and is waiting for free resources. Please be patient."
                    } else if(status === "running"){
                        root.slurm_status = "running"
                        root.loaderText = "Job-Status: Running! \nYour Slurm job is in the start process, waiting for MPI communication... ."
                    } else if(status === "cancelled"){
                        nodesList.waitForEnd()
                        root.slurm_status = "cancelled"
                        root.loaderText = "Job-Status: Cancelled!"
                    } else if(status === "completed"){
                        nodesList.waitForEnd()
                        root.slurm_status = "completed"
                        root.loaderText = "Job-Status: Completed! \nYour Slurm job ended unexpectedly. Check the output to analyze possible errors."
                    }
                } else {
                    if(status === "pending"){
                        root.slurm_status = "pending"
                        root.loaderText = "Job-Status: Pending! \nYour job is in the Slurm queue and is waiting for free resources. Please be patient."
                    } else if(status === "running"){
                        root.slurm_status = "running"
                        root.loaderText = "Job-Status: Running!"
                    } else if(status === "cancelled"){
                        root.slurm_status = "cancelled"
                        root.loaderText = "Job-Status: Cancelled! "
                    } else if(status === "completed"){
                        root.slurm_status = "completed"
                        root.loaderText = "Job-Status: Completed!"
                    }
                }
            }
            onCopiedOutputFile: (output_path) => {
                if(root.visualization && root.startTime == 0){
                    delayTimer.path = output_path
                    delayTimer.start();
                } else {
                    outputHandling(output_path);
                }
            }
            function outputHandling(output_path){
                if(root.visualization && root.startTime == 0){
                    var window;
                    var component = Qt.createComponent("Output_File.qml");
                    if(component.status === Component.Ready){
                        window = component.createObject(root, {"path": output_path, "success" : false});
                        window.x = (root.width - window.width) / 2;
                        window.y = (root.height - window.height) / 2;
                        window.show();
                    }
                    root.startTime = 0;
                    root.endTime = 0;
                    root.enable_start = true;

                } else {
                    var window;
                    var component = Qt.createComponent("Output_File.qml");
                    if(component.status === Component.Ready){
                        window = component.createObject(root, {"path": output_path, "success": true});
                        window.x = (root.width - window.width) / 2;
                        window.y = (root.height - window.height) / 2;
                        window.show();
                    }
                }
            }
        }

        Menu_Bar{
            id: menu

        }

        Rectangle{
            id: slurmnotifier
            property int sl_id: 0
            width: parent.width
            height: 30
            anchors {
                top: menu.bottom
            }
            color: "#4d4d4d"
            Text {
                text: "EduMPI-Run ID: " + slurmnotifier.sl_id
                verticalAlignment: Text.AlignVCenter
                leftPadding: 5
                width: parent.width
                height: parent.height
                color: "#00FF00"
            }
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

        StackView{
            id: actualScreen
            property int twoD_columns: 10
            property int threeD_depth: 2
            height: parent.height

            anchors {
                left: parent.left
                //right: options.left
                top: slurmnotifier.bottom
                bottom: timeline_main.top
            }
            width: root.width - options.width

            /*onLoaded: {
            //if(actualScreen.item) {
                if(actualScreen.source == "Cores3D.qml"){
                   actualScreen.item.listNodes = nodesList
                } else if(actualScreen.source == "Cores2D.qml"){
                   actualScreen.item.listNodes = nodesList
                }
           // }
        }*/

            //anchors.fill: parent
            //source: "Cores2D.qml"
        }
        Sidebar{
            id: options

            height: root.height - timeline_main.height - menu.height
            anchors.right: parent.right
            //anchors.verticalCenter: parent.verticalCenter
            //anchors.bottom: timeline_main.top
            anchors.top: menu.bottom
        }
        Bottom_Bar{
            id: timeline_main
            anchors.bottom: parent.bottom
        }
    }
    Timer {
        id: delayTimer
        property string path
        interval: 2000 // Verzögerung in Millisekunden (2 Sekunden)
        repeat: false // Nur einmal ausführen
        onTriggered: {
            controller.outputHandling(path);
                // Hier kommt die Logik, die nach der Verzögerung ausgeführt werden soll
        }
    }
}
