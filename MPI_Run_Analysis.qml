import QtQuick
import QtQuick.Controls
import QtQuick.Window
import Qt.db.nodes 1.0
import Qt.db.Singleton 1.0

Window {
    id: run_analysis_win
    width: 1440
    height: 810
    visible: true

    property alias a_screen: a_screen
    title: qsTr("EduMPI")

    property int analysis_slurm_id: 0
    property Controller controller: null

    property bool p2p: true
    property bool collective: true
    property string option: "Send/Recv Ratio (per Proc)"
    property color gradient1: "green"
    property color gradient2: "red"
    property string gradient_text1: "Send"
    property string gradient_text2: "Recv"

    //Properties for timeline
    property bool enable_timeline
    property int startTime: 0
    property int endTime: 0
    property string loaderText: ""
    property bool visualization: true

    property bool enable_start: true
    property bool build_numbers: false

    onControllerChanged: {
        //console.log("Controller changed")
    }

    onStartTimeChanged: {
        //console.log("startTime: " + startTime)
        //console.log("endTime: " + endTime)
    }


    Nodes_List{
        id: nodesList
        onComponentsBuilt: {
            a_screen.source = ""
            a_screen.source = "Cores3D.qml"
            console.log("components build from run analysis")
            //actualScreen.sourceComponent.nodesListModel = nodesList;
            //playbutton.enabled = true
        }
        onDataIn: (timestamp, qTimestamp)=>{
            startTime = timestamp;
            var qtime = qTimestamp;
            enable_timeline = true;

            nodesList.startAndStop(true);
            nodesList.showConditionAt(0,0)
            bottom_main.live = false
            //controller.setTimestamp(qtime)
            console.log("startTime: "+ timestamp)
        }
        Component.onCompleted: {
            if(controller == null){
                console.log("CONTROLLER NULL")
            }
            else {
                if(controller.getDatabaseConnection() === null){
                    console.log("CONTROLLER GET DATABASE CONNECTION NULL")
                }
                else {
                    nodesList.initialize(controller.getDatabaseConnection(), false)
                    nodesList.setOption(0)
                    nodesList.set_proc_num(-1234)
                    nodesList.set_slurm_id(analysis_slurm_id)
                    //nodesList.startThread()
                }
            }
        }
    }
    Loader{
        id: a_screen

        focus: true
        anchors {
            left: parent.left
            right: options_analysis.left
            top: parent.top
            bottom: parent.bottom
        }
        onLoaded: {
                if(a_screen.source == "Cores3D.qml"){
                    a_screen.item.listNodes = nodesList
                } else if(a_screen.source == "Cores2D.qml"){
                    a_screen.item.listNodes = nodesList
                }
        }
        function reload(){
            a_screen.source = "";
            QmlEngine.clearCache();
        }
    }
    Sidebar{
        id: options_analysis
        anchors.right: parent.right
        //anchors.verticalCenter: parent.verticalCenter
        anchors.bottom: bottom_main.top
        anchors.top: parent.top
        //anchors.top: menu.bottom
    }
    Bottom_Bar{
        id: bottom_main
        anchors.bottom: parent.bottom
    }

}
