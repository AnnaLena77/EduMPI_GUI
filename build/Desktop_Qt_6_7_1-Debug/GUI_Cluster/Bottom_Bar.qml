import QtQuick
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5

//icon source: https://fontawesome.com

Item {
    property int tick: 15;
    property int screenEdge: parent.width
    property int container_stopPositionX: 0
    property int positionmarker_stopPositionX: 0
    property int currentTime: 0
    id: bottom_timeline_bar
    width: parent.width
    height: 70
    onWidthChanged: {
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
             width: 150
             z: 1
             height: parent.height
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
                    icon.source: "qrc:/icons/pause.png"
                    icon.color: "grey"
                    enabled: enable_timeline

                    onEnabledChanged: {
                        if (enabled == true){
                            currentTime = startTime
                            timeline_timer.start()
                            icon.color = "red"
                            timeline.width+=1
                        }
                    }

                    onClicked: {
                        if(icon.name==="pause"){
                            icon.color = "red"
                            icon.source= "qrc:/icons/play.png"
                            icon.name= "play"
                            timeline_timer.stop()
                            container_stopPositionX = timeline_container.contentX
                            positionmarker_stopPositionX = timeline_positionmarker.x
                            timeline_container.interactive=true
                            nodesList.startAndStop(true);
                        }
                        else {
                            icon.color = "red"
                            icon.source= "qrc:/icons/pause.png"
                            icon.name= "pause"
                            timeline_timer.start()
                            timeline_container.contentX=container_stopPositionX
                            timeline_positionmarker.x = positionmarker_stopPositionX
                            timeline_container.interactive=false
                            nodesList.startAndStop(false);
                        }
                    }
                }
                RoundButton{
                    //icon.name: "backward"
                    scale: 1.2
                    icon.source: "qrc:/icons/backward_step.png"
                    icon.color: "white"
                    onClicked: {
                    }
                }
                RoundButton{
                    //icon.name: "forward-step"
                    scale: 1.2
                    icon.source: "qrc:/icons/forward_step.png"
                    icon.color: "white"
                    onClicked: {
                    }
                }
            }
        }
        Rectangle{
            width: parent.width-timeline_buttons.width
            height: parent.height
            Layout.fillWidth: true

            Flickable{
                id: timeline_container
                width: parent.width
                height: parent.height
                contentWidth: timeline.width
                contentHeight: parent.height
                boundsBehavior: Flickable.StopAtBounds
                interactive: false

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
                            if(playbutton.icon.name==="play"){
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
            timeline_positionmarker.x +=tick
            ticker_counter++

            if(timeline_positionmarker.mapToItem(root,0,0).x>=parent.width-50){
                //currentTime=0
                timeline.width += parent.width + 50
                timeline_container.contentX+=ticker_counter*tick
                ticker_counter=0
                //timestamp.text=Date()
            }
        }
    }


}
