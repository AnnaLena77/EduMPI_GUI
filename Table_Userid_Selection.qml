import QtQuick
import QtQuick.Controls

import Qt.db 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("User IDs")

    Column {
        anchors.centerIn: parent

        // Lade die User_IDs in das Modell
        Button {
            text: "Lade User IDs"
            //onClicked: userModel.loadUsers()
        }

            // Zeige die User_IDs in einer Liste an
        ListView {
            width: 200
            height: 300
            model: Table_UserID


            delegate: Item {
                width: parent.width
                height: 40
                Text {
                text: model.userId
                }
            }
        }
    }

}
