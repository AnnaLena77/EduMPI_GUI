import QtQuick
import QtQuick.Controls
import QtQuick.Window
//import appGui_Cluster.Controller 1.0
//import appGui_Cluster.Nodes 1.0
import GUI_Cluster 1.0
import Sidebar 1.0
import "."

Window {
    id: run_analysis_win
    width: 1440
    height: 810
    visible: true

    //property alias ascreen: ascreen
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

    Item {
        id: run_analysis_win_Item
        anchors.fill: parent
        property int endTime: run_analysis_win.endTime

        Cluster_Architecture{
            id: nodesList

            onComponentsBuilt: {
                console.log("components build from run analysis")
                ascreen.push("Cores3D.qml", {listNodes: nodesList})
                //actualScreen.sourceComponent.nodesListModel = nodesList;
                //playbutton.enabled = true
            }
            onDataIn: (timestamp, qTimestamp)=>{
                          run_analysis_win.startTime = timestamp;
                          var qtime = qTimestamp;
                          run_analysis_win.enable_timeline = true;
                          //bottom_main.live = false

                          //nodesList.startAndStop(true);
                          nodesList.showConditionAt(0,0)
                          //controller.setTimestamp(qtime)
                          console.log("startTime: "+ timestamp)
                      }
            Component.onCompleted: {
                if(run_analysis_win.controller == null){
                    console.log("CONTROLLER NULL")
                }
                else {
                    if(run_analysis_win.controller.getDatabaseConnection() === null){
                        console.log("CONTROLLER GET DATABASE CONNECTION NULL")
                    }
                    else {
                        nodesList.initialize(run_analysis_win.controller.getDatabaseConnection(), false)
                        nodesList.setOption(0)
                        nodesList.set_proc_num(-1234)
                        nodesList.set_slurm_id(run_analysis_win.analysis_slurm_id)
                        //nodesList.startThread()
                    }
                }
            }
        }
        StackView{
            id: ascreen

            //focus: true
            anchors {
                left: parent.left
                right: options_analysis.left
                top: parent.top
                bottom: parent.bottom
            }

            onDepthChanged: {
                console.log(ascreen.depth)
            }



            Component.onCompleted: {
                /*Qt.callLater(() => {
                ascreen.push("Cores3D.qml", {listNodes: nodesList})
            })*/

            }

            /*onLoaded: {
                if(ascreen.source == "Cores3D.qml"){
                    //ascreen.item.listNodes = nodesList
                } else if(ascreen.source == "Cores2D.qml"){
                   // ascreen.item.listNodes = nodesList
                }
        }*/
            /*function reload(){
            ascreen.source = "";
            ascreen.reload()
        }*/
        }
        Sidebar_Run_Analysis{
            id: options_analysis
            anchors.right: parent.right
            //anchors.verticalCenter: parent.verticalCenter
            anchors.bottom: bottom_main.top
            anchors.top: parent.top
            //anchors.top: menu.bottom
        }
        Bottom_Bar{
            id: bottom_main
            live: false
            anchors.bottom: parent.bottom
        }
    }

}