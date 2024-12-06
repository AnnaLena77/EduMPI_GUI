import QtQuick
import QtQuick.Controls
import QtQuick.Layouts 6.3
import QtQuick.Dialogs

Window {
    id: application_scorep
    property string message: ""

    title: "Start Open MP Applications on HPC Cluster"
    visible: true
    width: 600
    height: 400
    maximumHeight: 600
    maximumWidth: 600
    color: "#383936"

    // Set the flag directly from QML
    //flags: Qt.FramelessWindowHint

    ColumnLayout {
        anchors.fill: parent
        width: parent.width
        Layout.alignment: Qt.AlignVCenter
        Layout.fillWidth: true
        anchors.margins: 3

        Text {
            id: headline
            //anchors.fill: parent
            //Layout.alignment: Qt.AlignHCenter
            topPadding: 6
            color: "#00FF00"
            //bottomPadding: 20
            //horizontalAlignment: Text.AlignHCenter
            //font.family: "Helvetica"
            //font.pointSize: 16
            text: qsTr("Select an OpenMP Application")
            //color: "Blue"
        }

        Label {
            //Layout.alignment: rectangle.
            width: parent.width
            Layout.fillWidth: true
            wrapMode: Text.WordWrap
            text: "Select a .c file or a full folder that includes your .c file"
            color: "#999999"
        }

        GridLayout{
            columns: 2

            RadioButton{
                id: fileButton
                text: ".c File"
                checked: true
                palette.buttonText: "#999999"
                HoverHandler {
                    cursorShape: Qt.PointingHandCursor
                }
            }
            RadioButton{
                id: folderButton
                text: "Folder"
                checked: false
                palette.buttonText: "#999999"
                HoverHandler {
                    cursorShape: Qt.PointingHandCursor
                }
            }

        }

        GridLayout{
            width: parent.width
            //width: bashGeneration.width
            //anchors.right: parent
            //anchors.margins: 5
            columns: 2
            //Layout.topMargin: 40
            Layout.alignment: Qt.AlignHCenter
            Button {
                //text: "Upload " + (fileButton.checked ? "File" : "Folder");
                text: "Upload"
                palette.button: "#666666"
                palette.buttonText: "white"
                HoverHandler {
                        id: stylus
                        cursorShape: Qt.PointingHandCursor
                }
                onClicked: {
                    fileButton.checked ? fileDialog.open() : folderDialog.open()
                }
            }
            TextField{
                Layout.fillWidth: true
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

        Label {
            width: parent.width
            Layout.fillWidth: true
            wrapMode: Text.WordWrap
            text: "name of the OpenMP program:"
            color: "#999999"
        }

        GridLayout{
            width: parent.width
            columns: 2

            TextField {
                id: programNameField
                //text: ""
                Layout.fillWidth: true
                placeholderText: "<program name>"
                background: Rectangle {
                    color: "#4d4d4d"
                }
            }
            Label {
                text: ".c"
                color: "#999999"
            }

        }

        GridLayout{
            width: parent.width
            columns: 2

            Label {
                text: "Number of Threads:"
                color: "#999999"
            }

            TextField {
                id: numProcs
                text: ""
                Layout.fillWidth: true
                placeholderText: "max 64"
                background: Rectangle {
                    color: "#4d4d4d"
                }
            }

        }

        Button {
            id: mpi_start_button
            text: "Start OpenMP Program"
            palette.button: "#666666"
            palette.buttonText: "white"
            Layout.alignment: Qt.AlignCenter
            Layout.topMargin: 15

            HoverHandler {
                cursorShape: Qt.PointingHandCursor
            }

            onClicked:{
                if(checkInput()){
                    //nodesList.removeClusterComponents();
                    visualization=false;
                    enable_timeline = false;
                    controller.writeRemoteBashFile(programNameField.text, parseInt(numProcs.text), 3)
                    controller.writeLocalBashFile(uploadPath.text, fileButton.checked ? true : false, parseInt(numProcs.text));
                    startup();

                    //nodesList.buildClusterComponents(parseInt(numProcs.text))
                }
            }
        }
        Button {
            id: mpi_cancel_button
            text: "Abort OpenMP Program"
            palette.button: "#666666"
            palette.buttonText: "white"
            Layout.alignment: Qt.AlignCenter
            Layout.topMargin: 15

            HoverHandler {
                cursorShape: Qt.PointingHandCursor
            }

            onClicked:{
                controller.cancelRunningJob()
            }
        }
    }

    property Window window

    function startup(){
        var component = Qt.createComponent("Loading.qml");
        if(component.status === Component.Ready){
            window = component.createObject(root, {"message": "test"});
            window.x = (root.width - window.width) / 2;
            window.y = (root.height - window.height) / 2;
            window.show();
        }
    }

    function checkInput(){
        var component = Qt.createComponent("Error.qml");
        var window;

        if(!controller.cluster_connection){
            if(component.status === Component.Ready){
                window = component.createObject(root, {"message": "There is no valid connection to a HPC Cluster. Please establish a connection: \nSettings > Cluster Connection"});
                window.x = (root.width - window.width) / 2;
                window.y = (root.height - window.height) / 2;
                window.show();
                return false;
            }
        }

        else if(numProcs.text === "" || parseInt(numProcs.text>64) || parseInt(numProcs.text<1)){
            if(component.status === Component.Ready){
                window = component.createObject(root, {"message": "The number of Threads to be used must be between 1 and 64. Please add a desired number and try to start the program again."});
                window.x = (root.width - window.width) / 2;
                window.y = (root.height - window.height) / 2;
                window.show();
                return false;
            }
        }

        else if(!controller.checkFile(uploadPath.text, programNameField.text, fileButton.checked ? true : false)){
            if(component.status === Component.Ready){
                window = component.createObject(root, {"message": "There are problems with the specified program/folder path or with the specified program name. Please check the details."});
                window.x = (root.width - window.width) / 2;
                window.y = (root.height - window.height) / 2;
                window.show();
                return false;
            }
        }
        return true;
    }
}
