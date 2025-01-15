import QtQuick
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5
import Qt.labs.animation

//icon source: https://fontawesome.com

Item {
    property int tick: 15;
    property int screenEdge: parent.width
    property int container_stopPositionX: 0
    property int container_startPositionX: 0
    property int positionmarker_stopPositionX: 0
    property int currentTime: 0

    property string status: slurm_status
    property bool live:true

    property int endTime: parent.endTime

    property bool bar_enable_timeline : enable_timeline

    id: bottom_timeline_bar
    width: parent.width
    height: 70
    onWidthChanged: {
        timeline.width = width
        currentTime=0
        screenEdge+=parent.width
    }

    RowLayout{
        id: timeline_layout
        anchors.fill: parent
        width: parent.width
        spacing: 0

        Rectangle{
            id: timeline_buttons
             implicitWidth: 150
             z: 1
             implicitHeight: parent.height
             color: "#383936"
             Layout.fillWidth: true
             Layout.maximumWidth: 150
             Layout.minimumWidth: 150

             Component.onCompleted: {
                 //screenEdge=150
             }

             Row{
                padding: 10
                topPadding: 20
                spacing: 10
                //width: parent.width
                //height: parent.height
                RoundButton{
                    id: playbutton
                    scale: 1.2
                    icon.name: "pause"
                    icon.source: "/icons/pause.png"
                    icon.color: "grey"
                    enabled: bar_enable_timeline

                    onEnabledChanged: {
                        if (enabled == true){
                            currentTime = startTime
                            timeline_timer.start()
                            icon.color = "red"
                            timeline.width+=1
                            if(!live){
                                //console.log("enable playbutton clicked")
                                playbutton.clicked()
                            }
                        } else if (enabled == false) {
                            currentTime = 0
                            icon.color = "grey"
                            icon.source = "/icons/pause.png"
                            icon.name = "pause"
                            screenEdge = parent.width
                            container_stopPositionX = 0
                            positionmarker_stopPositionX = 0
                            timeline_positionmarker.x = 0
                            timeline.width = bottom_timeline_bar.width
                            timeline_container.interactive = false
                        }
                    }

                    onClicked: {
                        if(icon.name==="pause"){
                            icon.color = "red"
                            icon.source= "/icons/play.png"
                            icon.name= "play"
                            timeline_timer.stop()
                            container_stopPositionX = timeline_container.contentX
                            /*if(timeline_positionmarker.x >= timeline_endmarker.x){
                                positionmarker_stopPositionX = 0
                                nodesList.reset_bottom_bar()

                            } else {*/
                                positionmarker_stopPositionX = timeline_positionmarker.x
                           // }

                            timeline_container.interactive=true
                            //nodesList.startAndStop(true);
                        }
                        else {
                            icon.color = "red"
                            icon.source= "/icons/pause.png"
                            icon.name= "pause"
                            timeline_timer.start()
                            timeline_container.contentX=container_stopPositionX
                            timeline_positionmarker.x = positionmarker_stopPositionX
                            timeline_container.interactive=false
                            //nodesList.startAndStop(false);
                        }
                    }
                }
                RoundButton{
                    //icon.name: "backward"
                    scale: 1.2
                    icon.source: "/icons/backward_step.png"
                    icon.color: "white"
                    onClicked: {
                        if(playbutton.icon.name==="play"){
                            timeline_positionmarker.x -=tick
                            var timestamp = timeline_positionmarker.x/tick;
                            nodesList.showConditionAt(timestamp, timestamp)
                        }
                    }
                }
                RoundButton{
                    //icon.name: "forward-step"
                    scale: 1.2
                    icon.source: "/icons/forward_step.png"
                    icon.color: "white"
                    onClicked: {
                        if(playbutton.icon.name==="play"){
                            timeline_positionmarker.x +=tick
                            var timestamp = timeline_positionmarker.x/tick;
                            nodesList.showConditionAt(timestamp, timestamp)
                        }
                    }
                }
            }
        }
        Rectangle{
            id: rect_over_timeline_container
            implicitWidth: parent.width-timeline_buttons.width
            implicitHeight: parent.height
            Layout.fillWidth: true

            Flickable{
                id: timeline_container
                width: parent.width
                height: parent.height
                contentWidth: timeline.width
                contentHeight: parent.height
                flickableDirection: Flickable.HorizontalFlick
                clip: true
                boundsBehavior: Flickable.StopAtBounds
                interactive: false

                ScrollBar.horizontal: ScrollBar {
                    id: scrollable_area
                    orientation: Qt.Horizontal
                    visible: timeline_container.interactive

                }
                Component.onCompleted: {
                    container_startPositionX = timeline_container.contentX
                }

                WheelHandler{
                    onWheel: event=>{
                        if(timeline_container.interactive){
                            timeline_container.flick(event.angleDelta.y*event.y, 0)
                        }
                    }
                }

                Rectangle{
                    id: timeline
                    width: bottom_timeline_bar.width//-timeline_buttons.width
                    height: parent.height
                    color: "#383936"
                    //x: timeline_container.visibleArea.xPosition

                    Repeater{
                        id: timeline_repeater
                        model:parent.width/tick
                        anchors.fill: parent
                        delegate: Item {
                            anchors.fill: parent

                            Rectangle{
                                id: second
                                x: index*tick
                                anchors.top: parent.top
                                width: 1
                                height: timeline.height/3
                                color: "grey"
                            }
                            Text{
                                id: timestamp
                                anchors.top: second.bottom
                                x: index*tick
                                font.pointSize: 8
                                color: "grey"
                            }
                            Component.onCompleted: {
                                if(index===0 || index%5==0){
                                    second.height=timeline.height/1.5
                                    //console.log("CurrentTime : "+currentTime)
                                    var hours = Math.floor(currentTime / 3600);
                                    var minutes = Math.floor((currentTime % 3600) / 60);
                                    var seconds = currentTime % 60;

                                    timestamp.text=("0" + hours).slice(-2) + ":" + ("0" + minutes).slice(-2) + ":" + ("0" + seconds).slice(-2);
                                    //console.log(timestamp.text)
                                    currentTime+=5;
                                }
                            }
                        }
                    }

                    Rectangle{
                        id: timeline_endmarker
                        width: 5
                        height: parent.height
                        visible: false
                        color: "blue"
                        opacity: 0.7
                        border.color: "blue"
                        x : (endTime - startTime)*tick
                        onXChanged:{
                            if(endTime == 0){
                                visible = false;
                            }
                            else {
                                visible = true
                                //console.log("timeline_endmarker set: "+ timeline_endmarker.x)
                            }
                            if(startTime!=0 && !live){
                                if(timeline.width < (endTime - startTime)*tick){
                                    //console.log("resize timeline width")
                                    timeline.width = 100 + (endTime - startTime)*tick
                                }
                            }
                        }
                    }

                    Rectangle{
                        id:timeline_positionmarker
                        width: 2
                        height: parent.height
                        color: "red"
                        opacity: 0.3
                        border.color: "red"
                        //anchors.bottom: parent
                    }

                    MouseArea{
                        id: timeline_mousearea
                        anchors.fill: parent
                        property int markerareaStart : 0
                        property int markerareaEnd: 0
                        property int markerareaWidth : 0

                        /*onClicked: {
                            if(playbutton.icon.name==="play"
){
                                timeline_positionmarker.width=2
                                timeline_positionmarker.x = Math.floor(timeline_mousearea.mouseX/15)*15
                            }
                        }*/
                        onPressed: {
                            // Startpunkt des markierten Bereichs
                            if(playbutton.icon.name==="play"){
                                timeline_container.interactive=false
                                timeline_positionmarker.width = 2
                                timeline_positionmarker.x = Math.floor(timeline_mousearea.mouseX/tick)*tick
                                markerareaStart = Math.floor(timeline_mousearea.mouseX/tick)*tick
                            }

                        }
                        onReleased: {
                            // Endpunkt des markierten Bereichs
                            if(playbutton.icon.name==="play"){
                                timeline_container.interactive=true
                                markerareaEnd = Math.floor(timeline_mousearea.mouseX/tick)*tick
                                markerareaWidth = markerareaEnd - markerareaStart
                                if(markerareaWidth>tick-1){
                                     timeline_positionmarker.width = markerareaWidth + 2
                                }

                                var timestampA = timeline_positionmarker.x/tick;
                                var timestampB = markerareaEnd/tick;
                                nodesList.showConditionAt(timestampA, timestampB)
                            }

                        }
                        onPositionChanged: {
                            //console.log(timeline_mousearea.mouseX)
                            if(playbutton.icon.name==="play"){
                                markerareaEnd = timeline_mousearea.mouseX
                                markerareaWidth = markerareaEnd - markerareaStart
                                timeline_positionmarker.width = markerareaWidth
                                if(timeline_mousearea.mouseX >= timeline_container.width-50 && timeline_mousearea.mouseX<timeline.width){
                                    timeline_container.contentX += tick
                                }
                            }
                        }
                    }
                }
            }
        }
    }


    Timer{
        id: timeline_timer
        interval: 1000
        running: false
        repeat: true
        //triggeredOnStart: true
        property int ticker_counter: 0

        onTriggered: {
            if(bottom_timeline_bar.endTime != 0 && timeline_positionmarker.x >= timeline_endmarker.x){
                timeline_positionmarker.x = 0
                ticker_counter = 0;
                timeline_container.contentX = container_startPositionX
            } else {
                timeline_positionmarker.x +=tick
            }
            ticker_counter++
            var mappedPosition = timeline_positionmarker.mapToItem(rootItem, 0.0, 0.0);
            nodesList.signalToUpdateData(nodesList.time_display)

            if(endTime != 0){
                if(timeline_positionmarker.x >= timeline_endmarker.x){
                    playbutton.clicked()
                    nodesList.reset_bottom_bar()
                    enable_start = true
                }
            }

            if(mappedPosition.x>=parent.width-50){
                //currentTime=0
                timeline.width += parent.width + 50
                timeline_container.contentX+=ticker_counter*tick
                ticker_counter=0
                //timestamp.text=Date()
            }
        }
    }


}
