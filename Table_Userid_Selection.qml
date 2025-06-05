import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Dialogs
import "."

ApplicationWindow {
    id: table_runs
    visible: true
    width: 640
    height: 480
    title: "EduMPI Runs"
    color: "#4d4d4d"
    modality: Qt.NonModal // Nicht-modales Fenster
    flags: Qt.Window // Standard-Fenster


    property int selected_slurm_id: 0
    property int selected_end_time: 0

    /*Rectangle{
        anchors.fill: parent
        color: "#4d4d4d"
    }*/

    Column {
        spacing: 10
        anchors.fill: parent
        //width: parent.width

        ScrollView { // Verwenden Sie ScrollView für den Scrollbereich
            width: parent.width
            height: parent.height-button_item.height // Höhe an Ihren Bedarf anpassen
            clip: true

        // ListView zur Anzeige der Jobs als Tabellenstruktur
        ListView {
            width: parent.width
            height: parent.height
            model: controller.getJobTable() // Verknüpfe das C++-Model
            spacing: 2
            //highlight: Rectangle { color: "lightblue"; radius: 5 } // Highlight-Stil beim Überfahren
            //highlightFollowsCurrentItem: false // Verhindert, dass sich das Highlight mit der Selektion bewegt
            ScrollBar.vertical: ScrollBar {
                policy: ScrollBar.AlwaysOn

            } // Fügt einen vertikalen ScrollBar hinzu

            delegate: Rectangle {
                    width: table_runs.width-10
                    Layout.alignment: Qt.AlignVCenter
                    height: 40
                    property bool hover: false // Property hinzugefügt, um den Hover-Zustand zu speichern
                    color: model.jobID === selected_slurm_id ? "lightgray" : (hover ? "lightgrey" : "white")
                    //color: hover ? "lightgray" : "white" // Farbänderung bei Hover
                    radius: 5 // Ecken abrunden

                    // Hover-Effekt
                    MouseArea {
                        anchors.fill: parent
                        hoverEnabled: true
                        onEntered: parent.hover = true
                        onExited: parent.hover = false
                        onClicked: {
                            selected_slurm_id = model.jobID

                            var timestamp = model.endTime
                            var hours = timestamp.getHours();
                            var minutes = timestamp.getMinutes();
                            var seconds = timestamp.getSeconds();

                            var secondsSinceMidnight = hours * 3600 + minutes * 60 + seconds;

                            selected_end_time = secondsSinceMidnight
                        }
                        onDoubleClicked: {
                            eduMPIButton.click()
                        }
                    }

                    GridLayout {
                        anchors.fill: parent
                        columns: 3 // Anzahl der Spalten

                        Text {
                            text: "Job ID: " + model.jobID
                            font.bold: true
                            Layout.alignment: Qt.AlignLeft
                            Layout.margins: 10
                        }

                        Text {
                            text: model.programName
                            font.bold: true
                            Layout.margins: 10
                        }

                        Text {
                            property date timestamp : model.startTime
                            text: "Start-Timestamp: " + Qt.formatDateTime(new Date(timestamp), "dd.MM.yyyy hh:mm:ss")
                            Layout.alignment: Qt.AlignRight
                            Layout.margins: 10
                            /*Component.onCompleted : {
                                console.log("Model-StartTime: " + model.startTime)
                            }*/
                        }
                    }
                }
            }
        }
        Item {
                id: button_item
                width: parent.width
                height: 50 // Definieren Sie dieses Maß entsprechend.
                Button {
                    id: eduMPIButton
                    text: "Select EduMPI-Run"
                    anchors.horizontalCenter: parent.horizontalCenter
                    HoverHandler {
                        cursorShape: Qt.PointingHandCursor
                    }
                    onClicked: {
                        console.log("Slurm ID: " + selected_slurm_id)
                        var disable_opening = controller.check_open_window(selected_slurm_id);
                        if(selected_slurm_id != 0 && !disable_opening){
                            var component = Qt.createComponent("MPI_Run_Analysis.qml");
                            if(component.status === Component.Ready){
                                /*if(controller == null){
                                    console.log("CONTROLLER NULL TABLE_USERID")
                                }*/
                                var window = component.createObject(root, {"analysis_slurm_id": selected_slurm_id, "controller":controller, "endTime":selected_end_time});
                                window.x = (root.width - window.width) / 2;
                                window.y = (root.height - window.height) / 2;
                                window.show();
                            }
                        }
                        else {
                            component = Qt.createComponent("Error.qml");
                            var message = "EduMPI window for Slurm Job " + selected_slurm_id + " is already open!"
                            window = component.createObject(root, {"message": message});
                            window.x = (root.width - window.width) / 2;
                            window.y = (root.height - window.height) / 2;
                            window.show();
                            //console.log("block window-opening, slurm-ID is already opened")
                        }
                    }
                    Keys.onPressed: (event)=> {
                        if (event.key === Qt.Key_Return || event.key === Qt.Key_Enter) {
                            eduMPIButton.clicked(); // Auslösen des Button-Klicks
                        }
                    }
                }
        }
    }
}












































