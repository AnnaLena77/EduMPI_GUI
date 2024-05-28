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
    title: "Login to HPC@HS-Fulda"

        ColumnLayout {
            anchors.fill: parent
            Layout.fillWidth: true
            anchors.margins: 5
            spacing: 4

            Label {
                text: "Remote Hostname or IP-Address (Cluster HS Fulda: hpc.informatik.hs-fulda.de):"
                wrapMode: Text.WordWrap
                color: "#999999"
            }

            TextField {
                id: hostnameField
                Layout.fillWidth: true
                text: "hpc.informatik.hs-fulda.de"
                background: Rectangle {
                    color: "#4d4d4d"
                }
            }

            Label {
                text: "Authentication (FDAI authentication key):"
                color: "#999999"
            }

            TextField {
                id: authField
                Layout.fillWidth: true
                text: "fdai0231"
                placeholderText: "<fd number>"
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
                placeholderText: "<installation path>"
                background: Rectangle {
                    color: "#4d4d4d"
                }
            }

            Button {
                id: connectButton
                text: "Connect to HPC Cluster"
                HoverHandler {
                        cursorShape: Qt.PointingHandCursor
                }
                Layout.columnSpan: 1
                Layout.fillWidth: true
                onClicked: {
                    busyindicator.running = true
                    successfield.text = "";
                    nodesList.connectClusterAsync(hostnameField.text, authField.text, installpathField.text, function(result) {
                        //console.log(result);
                        successfield.text = result;
                        busyindicator.running = false;
                        if(nodesList.cluster_connection){
                            successfield.color="green";
                        } else {
                            successfield.color="red";
                        }
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
