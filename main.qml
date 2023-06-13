import QtQuick
import QtQuick.VirtualKeyboard
import QtQuick.Controls

Window {
    id: window
    width: 1920
    height: 1080
    visible: true
    property alias actualScreen: actualScreen
    title: qsTr("Hello World")

    Sidebar {
        id: sidebar
    }

    Loader{
        id: actualScreen

        focus: true
        anchors {
            left: sidebar.right
            right: options.left
            top: parent.top
            bottom: parent.bottom
        }

        function reload(){
            actualScreen.source = "";
            QmlEngine.clearCache();
        }

        //anchors.fill: parent
        //source: "Cores2D.qml"
    }
    Options_Bar{
        id: options
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
    }
}
