pragma Singleton
import QtQuick

QtObject{
    property color menuBackground: "#383936"

    property Rectangle menuBG: Rectangle {
        implicitWidth: 200
        //implicitHeight: 20
        color: menuBackground
        border.color: "black"
    }
}
