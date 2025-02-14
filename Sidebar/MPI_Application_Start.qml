import QtQuick
import QtQuick.Controls
import QtQuick.Layouts 6.3
import QtQuick.Dialogs

Rectangle {

    id: mpi_application
    width: 250
    height: 350
    implicitHeight: 350
    color: "#383936"
    signal changeMessage()

    //Component.onCompleted: console.log("Inner: " + height )

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
                text: qsTr("Select MPI Application")
                //color: "Blue"
            }

            Label {
                //Layout.alignment: rectangle.
                Layout.preferredWidth: parent.width
                Layout.fillWidth: true
                wrapMode: Text.WordWrap
                text: "Select a .c file or a full folder that includes your program"
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
                implicitWidth: parent.width
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
                onAccepted: {
                    uploadPath.text = selectedFile
                    var fileName = uploadPath.text.split('/').pop()
                    if(fileName.split('.').pop() == "c"){
                        fileName = fileName.split('.').shift()
                        programNameField.text = fileName
                    }
                    else {
                        var component = Qt.createComponent("/Error.qml");
                        var window;
                        if(component.status === Component.Ready){
                            window = component.createObject(root, {"message": "The selected file is not a .c file. Please select an MPI program that is written in .c."});
                            window.x = (root.width - window.width) / 2;
                            window.y = (root.height - window.height) / 2;
                            window.show();
                            return false;
                        }
                    }
                }

            }
            FolderDialog {
            id: folderDialog
                //currentFolder: StandardPaths.standardLocations(StandardPaths.PicturesLocation)[0]
                onAccepted: uploadPath.text = selectedFolder
            }

            Label {
                Layout.preferredWidth: parent.width
                Layout.fillWidth: true
                wrapMode: Text.WordWrap
                text: "name of the MPI program:"
                color: "#999999"
            }

            GridLayout{
                implicitWidth: parent.width
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
                implicitWidth: parent.width
                columns: 2

                Label {
                    text: "Number of Processes:"
                    color: "#999999"
                }

                TextField {
                    id: numProcs
                    text: ""
                    Layout.fillWidth: true
                    placeholderText: "max 400"
                    background: Rectangle {
                        color: "#4d4d4d"
                    }
                }

            }

            Button {
                id: mpi_start_button
                text: "Start MPI-Program"
                palette.button: "#666666"
                palette.buttonText: "white"
                Layout.alignment: Qt.AlignCenter
                Layout.topMargin: 15

                enabled: enable_start;

                HoverHandler {
                    cursorShape: Qt.PointingHandCursor
                }

                onClicked:{
                    if(checkInput()){
                        restarts++;
                        //nodesList.removeClusterComponents();
                        visualization = true;
                        enable_start = false;
                        enable_timeline = false;
                        controller.writeRemoteBashFile(programNameField.text, parseInt(numProcs.text), 0)
                        controller.writeLocalBashFile(uploadPath.text, fileButton.checked ? true : false, parseInt(numProcs.text));
                        nodesList.set_proc_num(parseInt(numProcs.text))
                        startup();
                        //nodesList.buildClusterComponents(parseInt(numProcs.text))
                    }
                }
            }
            Button {
                id: mpi_cancel_button
                text: "Abort MPI-Program"
                palette.button: "#666666"
                palette.buttonText: "white"
                Layout.alignment: Qt.AlignCenter
                //Layout.topMargin: 15

                HoverHandler {
                    cursorShape: Qt.PointingHandCursor
                }

                onClicked:{
                    controller.cancelRunningJob()
                }
            }
        }
    }

    property Window window

    function startup(){
        var component = Qt.createComponent("/Loading.qml");
        if(component.status === Component.Ready){
            window = component.createObject(root, {"message": "test"});
            window.x = (root.width - window.width) / 2;
            window.y = (root.height - window.height) / 2;
            window.show();
        } else if (component.status === Component.Error) {
                console.error("Failed to load component:", component.errorString());
        }
    }


    function checkInput(){
        var component = Qt.createComponent("/Error.qml");
        var window;
        if(!controller.db_connection){
            if(component.status === Component.Ready){
                window = component.createObject(root, {"message": "There is no database connection to a timescale DB. Please establish a connection: \nSettings > Database Connection"});
                window.x = (root.width - window.width) / 2;
                window.y = (root.height - window.height) / 2;
                window.show();
                return false;
            }
        }

        else if(!controller.cluster_connection){
            if(component.status === Component.Ready){
                window = component.createObject(root, {"message": "There is no valid connection to a HPC Cluster. Please establish a connection: \nSettings > Cluster Connection"});
                window.x = (root.width - window.width) / 2;
                window.y = (root.height - window.height) / 2;
                window.show();
                return false;
            }
        }

        else if(numProcs.text === "" || parseInt(numProcs.text>400) || parseInt(numProcs.text<1)){
            if(component.status === Component.Ready){
                window = component.createObject(root, {"message": "The number of processes to be used must be between 1 and 400. Please add a desired number and try to start the program again."});
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
