import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Dialogs

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: "Job List Example"

    property int selected_slurm_id: 0
    property int selected_end_time: 0

    Column {
        spacing: 10
        width: parent.width

        ScrollView { // Verwenden Sie ScrollView für den Scrollbereich
            width: parent.width
            height: 440 // Höhe an Ihren Bedarf anpassen

        // ListView zur Anzeige der Jobs als Tabellenstruktur
        ListView {
            width: parent.width
            height: 400
            model: controller.getJobTable() // Verknüpfe das C++-Model
            highlight: Rectangle { color: "lightblue"; radius: 5 } // Highlight-Stil beim Überfahren
            highlightFollowsCurrentItem: false // Verhindert, dass sich das Highlight mit der Selektion bewegt
            ScrollBar.vertical: ScrollBar {} // Fügt einen vertikalen ScrollBar hinzu

            delegate: Rectangle {
                    width: parent.width
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
                    }

                    GridLayout {
                        width: parent.width
                        height: parent.height
                        columns: 2 // Anzahl der Spalten

                        Text {
                            text: "Job ID: " + model.jobID
                            font.bold: true
                            Layout.alignment: Qt.AlignLeft
                        }

                        Text {
                            property date timestamp : model.startTime
                            text: "Start-Timestamp: " + Qt.formatDateTime(new Date(timestamp), "dd.MM.yyyy hh:mm:ss")
                            Layout.alignment: Qt.AlignLeft
                        }
                    }
                }
            }
        }
        Item {
                width: parent.width
                height: 20 // Definieren Sie dieses Maß entsprechend.
                Button {
                    id: eduMPIButton
                    text: "Select EduMPI-Run"
                    anchors.horizontalCenter: parent.horizontalCenter
                    onClicked: {
                        console.log("slurm id: " + selected_slurm_id)
                        if(selected_slurm_id != 0){
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
                    }
                }
        }
    }
}












































