import QtQuick
import QtQuick.Layouts 6.3
import QtQuick.Controls 6.3
import QtQuick.Dialogs

Rectangle {

    id: options
    width: 250
    height: 500
    implicitHeight: 500
    color: "#383936"

    Rectangle {
        id: rectangle
        //anchors.fill: parent
        x: 5
        y: 5
        radius: 10
        width: parent.width - 10
        anchors.leftMargin:  5
        height: parent.height - 10
        border.width: 2
        border.color: "#00FF00"
        color: "transparent"

        ColumnLayout{
            width: rectangle.width
            anchors.fill: parent
            //height: parent.height
            Layout.alignment: Qt.AlignHCenter
            Layout.fillWidth: true
            anchors.margins: 5

            ColumnLayout{
                //anchors.
                width: parent.width
                //height: parent.height
                Layout.alignment: Qt.AlignHCenter
                Layout.fillHeight: false
                Layout.leftMargin: 20
                Layout.fillWidth: false
                Layout.columnSpan: 2

                Text {
                    id: headline
                    //anchors.fill: parent
                    Layout.alignment: Qt.AlignHCenter
                    topPadding: 15
                    //bottomPadding: 20
                    horizontalAlignment: Text.AlignHCenter
                    font.family: "Helvetica"
                    font.pointSize: 12
                    text: qsTr("Choose MPI-Application")
                    color: "Blue"
                }

                GridLayout{
                    width: parent.width
                    //width: bashGeneration.width
                    //anchors.right: parent
                    //anchors.margins: 5
                    columns: 2
                    Layout.topMargin: 40
                    Layout.alignment: Qt.AlignHCenter
                    Button {
                        //text: "Upload " + (fileButton.checked ? "File" : "Folder");
                        text: "Upload"
                        background: Rectangle {
                            color: "#C0C0C0"
                        }
                        HoverHandler {
                                id: stylus
                                cursorShape: Qt.PointingHandCursor
                        }
                        onClicked: {
                            //fileButton.checked ? fileDialog.open() : folderDialog.open()
                        }
                    }
                    TextField{
                        //Layout.fillWidth: true
                        //width: 400
                        id: uploadPath
                        text: ""
                        background: Rectangle {
                            color: "#4d4d4d"
                        }
                    }
                }

                FileDialog {
                id: fileDialog
                    //currentFolder: StandardPaths.standardLocations(StandardPaths.PicturesLocation)[0]
                    onAccepted: uploadPath.text = selectedFile
                }
                FolderDialog {
                id: folderDialog
                    //currentFolder: StandardPaths.standardLocations(StandardPaths.PicturesLocation)[0]
                    onAccepted: uploadPath.text = selectedFolder
                }

                GridLayout{
                    width: parent.width
                    columns: 3
                    Layout.topMargin: 40
                    Layout.alignment: Qt.AlignHCenter

                    Button {
                        id: mpi_start_button
                        text: "Start MPI-Program"
                        palette.buttonText: "white"
                        palette.button: "#666666"

                        HoverHandler {
                            cursorShape: Qt.PointingHandCursor
                        }

                        onClicked:{
                            nodesList.bashTest()
                            /*if(nodesList.db_connection){
                                nodesList.removeClusterComponents()
                                nodesList.startBash(parseInt(np.text))
                                //nodesList.buildClusterComponents(parseInt(np.text))
                            }
                            else {

                            }*/
                        }
                    }
                    TextField {
                        id: np
                        color: "black"
                        maximumLength: 3
                        placeholderText: "400"
                        rightPadding: 1
                        text: "400"
                        inputMethodHints: "ImhFormattedNumbersOnly";
                        background: Rectangle {
                            color: "white"
                        }
                    }
                    Text {
                        color: "white"
                        text: "Procs"
                    }
                }

                ComboBox {
                    //width: parent
                    implicitWidth: 230
                    Layout.topMargin: 20
                    // Layout.bottomMargin: 100
                    Layout.alignment: Qt.AlignHCenter
                    font.pointSize: 11
                    HoverHandler {
                        cursorShape: Qt.PointingHandCursor
                    }

                    palette.button: "#666666"
                    palette.buttonText: "white"

                    model: ListModel {
                        id: model
                        ListElement {
                            text: "send/recv ratio (per proc)"

                        }
                        ListElement {
                            text: "max send ratio (across all procs)"
                            //font.pointSize: 11
                        }
                        ListElement {
                            text: "max recv ratio (across all procs)"
                            //font.pointSize: 11
                        }
                        //ListElement { text: "Wait Ratio" }
                    }
                    onActivated:{
                        option = currentValue;
                        if(option == "send/Recv ratio (per proc)"){
                            gradient1 = "green"
                            gradient2 = "red"
                            gradient_text1 = "Send"
                            gradient_text2 = "Recv"
                        }
                        else if (option == "max send ratio (across all procs)"){
                            gradient1 = "green"
                            gradient2 = "white"
                            gradient_text1 = "Max Send"
                            gradient_text2 = "No Send"
                        }
                        else if(option == "max recv ratio (across all procs)"){
                            gradient1 = "white"
                            gradient2 = "red"
                            gradient_text1 = "No Recv"
                            gradient_text2 = "Max Recv"
                        }

                    }
                }
                Rectangle{
                    width: 10
                    height: 200
                    Layout.bottomMargin: -95
                    rotation: 90
                    gradient: Gradient {
                        GradientStop { position: 0.0; color: gradient2 }
                        GradientStop { position: 1.0; color: gradient1 }
                    }
                    Layout.alignment: Qt.AlignCenter

                }
                GridLayout{
                    width: parent.width
                    columns: 2
                    Layout.bottomMargin: 20
                    //Layout.alignment: Qt.AlignHCenter

                    Text {
                        text: gradient_text1
                        color: "white"
                        //anchors.left: parent.left
                        leftPadding: 10
                        Layout.fillWidth: true
                        //horizontalAlignment: Qt.AlignHLeft
                    }
                    Text {
                        text: gradient_text2
                        color: "white"
                        Layout.fillWidth: true
                        horizontalAlignment: Text.AlignRight
                        //anchors.right: parent.right
                        rightPadding: 10
                        //horizontalAlignment: Qt.AlignHRight
                        //Layout.alignment: Qt.AlignHRight
                    }
                }

                Text {
                    id: text2
                    text: qsTr("Communication-Type:")
                    color: "white"
                    font.pointSize: 12
                    Layout.alignment: Qt.AlignHCenter
                }
                CheckBox {
                    id: p2p_check
                    HoverHandler {
                        cursorShape: Qt.PointingHandCursor
                    }
                    Layout.alignment: Qt.AlignLeft
                    Layout.leftMargin: 40
                    checked: true
                    text: qsTr("P2P")
                    onCheckStateChanged: {
                        p2p = p2p_check.checkState
                    }
                }
                CheckBox {
                    id: coll_check
                    HoverHandler {
                        cursorShape: Qt.PointingHandCursor
                    }
                    Layout.alignment: Qt.AlignLeft
                    Layout.leftMargin: 40
                    checked: true
                    text: qsTr("Collective")
                    onCheckStateChanged: {
                        collective = coll_check.checkState
                    }
                }
                /*CheckBox {
                    checked: true
                    text: qsTr("One-Sided")
                }*/

                Text {
                    id: text3
                    text: qsTr("Time display:")
                    color: "white"
                    font.pointSize: 12
                    Layout.alignment: Qt.AlignHCenter
                    Layout.topMargin: 20
                }
                CheckBox {
                    id: secondly_check
                    HoverHandler {
                        cursorShape: Qt.PointingHandCursor
                    }
                    Layout.alignment: Qt.AlignLeft
                    Layout.leftMargin: 40
                    checked: true
                    text: qsTr("Secondly data")
                    onCheckStateChanged: {
                        if(secondly_check.checked == true) nodesList.time_display = 0;
                        total_check.checked = !secondly_check.checked
                    }
                }
                CheckBox {
                    id: total_check
                    HoverHandler {
                        cursorShape: Qt.PointingHandCursor
                    }
                    Layout.alignment: Qt.AlignLeft
                    Layout.leftMargin: 40
                    checked: false
                    text: qsTr("total data")
                    onCheckStateChanged: {
                        if(total_check.checked == true) nodesList.time_display = 1;
                        secondly_check.checked = !total_check.checked
                    }
                }
            }
        }

    }
}
