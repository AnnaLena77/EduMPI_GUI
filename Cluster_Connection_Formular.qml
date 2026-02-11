import QtQuick
import QtQuick.Window
import QtQuick.Controls 2.0
import QtQuick.Layouts
import QtQuick.Dialogs

Window {
    id: bashGeneration
    visible: true
    width: 550
    height: 250
    title: "Cluster connection"

        ColumnLayout {
            anchors.fill: parent
            Layout.fillWidth: true
            anchors.margins: 5
            spacing: 4

            Label {
                text: "Hostname/IP address:" //(Cluster HS Fulda: hpc.informatik.hs-fulda.de):"
                wrapMode: Text.WordWrap
                color: "#999999"
            }

            TextField {
                id: hostnameField
                Layout.fillWidth: true
                text: "10.32.47.10"
                placeholderText: "<enter host>"
                background: Rectangle {
                    color: "#4d4d4d"
                }
            }

            Label {
                text: "user name/identifier:"
                color: "#999999"
            }

            TextField {
                id: authField
                Layout.fillWidth: true
                text: ""
                placeholderText: "<enter name>"
                //inputMethodHints: Qt.ImhDigitsOnly
                background: Rectangle {
                    color: "#4d4d4d"
                }
            }

            Label {
                text: "EduMPI installation path (standard: /opt/edumpi)"
                color: "#999999"
            }

            TextField {
                id: installpathField
                text: "/opt/edumpi"
                Layout.fillWidth: true
                placeholderText: "<enter path>"
                background: Rectangle {
                    color: "#4d4d4d"
                }
            }

            Button {
                id: connectButton
                text: "connect"
                HoverHandler {
                        cursorShape: Qt.PointingHandCursor
                }
                Layout.columnSpan: 1
                Layout.fillWidth: true
                onClicked: {
                    root.performanceStartTime = Date.now();
                    busyindicator.running = true
                    successfield.text = "";
                    controller.connectClusterAsync(hostnameField.text, authField.text, installpathField.text, function(result) {
                        //console.log(result);
                        successfield.text = result;
                        busyindicator.running = false;
                        if(controller.cluster_connection){
                            successfield.color="green";
                        } else {
                            successfield.color="red";
                        }
                        root.performanceEndTime = Date.now();
                        const sshConnectionDuration = root.performanceEndTime - root.performanceStartTime
                        console.log("SSH Connection took " + sshConnectionDuration + " ms")
                    });

                }
            }
            Keys.onPressed: (event)=> {
                if (event.key === Qt.Key_Return || event.key === Qt.Key_Enter) {
                    connectButton.clicked(); // Auslösen des Button-Klicks
                }
            }

            RowLayout{
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                    Custom_BusyIndicator{
                        id: busyindicator
                        prop_height: 40
                        prop_width: 40
                        prop_color: "#00FF00"
                        running: false
                    }

                    Label {
                        Layout.topMargin: 2
                        id: successfield
                        Layout.fillWidth: true
                        wrapMode: Text.WordWrap
                    }

                }

    }
}
