import QtQuick
import QtQml
import QtQuick.Controls
import QtQuick.Layouts

//icons: https://fontawesome.com

Window {
    id: load
    property string message: ""
    property bool showLoader: enable_timeline

    onShowLoaderChanged: {
        if(showLoader == true){
            load.close()
        }
    }

    title: "Loading"
    visible: true
    width: 300
    height: 200
    maximumHeight: 200
    maximumWidth: 300

    ColumnLayout {
        anchors.fill: parent
        width: parent.width
        Layout.alignment: Qt.AlignVCenter
        Layout.fillWidth: true
        anchors.margins: 3

        Custom_BusyIndicator{
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter
            id: busyindicator
            prop_height: 40
            prop_width: 40
            prop_color: "#00FF00"
            running: true
        }


        Text {
            id: msg
            text: loaderText
            Layout.fillWidth: true
            wrapMode: Text.WordWrap
            Layout.margins: 5
            horizontalAlignment: Text.AlignHCenter
            onTextChanged: {
                if(visualization && slurm_status == "completed"){
                    load.close();
                }
            }
        }
    }
}
