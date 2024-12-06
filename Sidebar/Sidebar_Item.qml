import QtQuick

Item {

    Column {
      default property alias item: ld.sourceComponent
      Rectangle {
        width: 200
        height: 50
        color: "red"
        MouseArea {
          anchors.fill: parent
          onClicked: info.show = !info.show
        }
      }
      Rectangle {
        id: info
        width: 200
        height: show ? ld.height : 0
        property bool show : false
        color: "green"
        clip: true
        Loader {
          id: ld
          y: info.height - height
          //anchors.horizontalCenter: info.horizontalCenter
        }
        Behavior on height {
          NumberAnimation { duration: 200; easing.type: Easing.InOutQuad }
        }
      }
    }

}
