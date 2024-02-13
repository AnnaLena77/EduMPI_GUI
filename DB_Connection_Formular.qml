import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts

Window {
    id: dbFormular
    visible: true
    width: 400
    height: 300
    title: "Timescale Connection"

    GridLayout {
        anchors.fill: parent
        anchors.margins: 10
        columns: 2

        Label {
            text: "Hostname:"
            color: "#999999"
        }

        TextField {
            id: hostnameField
            Layout.fillWidth: true
            text: "10.35.8.10"
            placeholderText: "<Enter host address>"
            color: "white"
            background: Rectangle {
                color: "#4d4d4d"
            }
        }

        Label {
            text: "Port:"
            color: "#999999"
        }

        TextField {
            id: portField
            Layout.fillWidth: true
            text: "5432"
            placeholderText: "<Enter port>"
            //inputMethodHints: Qt.ImhDigitsOnly
            color: "white"
            background: Rectangle {
                color: "#4d4d4d"
            }
        }

        Label {
            text: "Database:"
            color: "#999999"
        }

        TextField {
            id: nameField
            Layout.fillWidth: true
            text: "tsdb"
            placeholderText: "<Enter database name>"
            color: "white"
            background: Rectangle {
                color: "#4d4d4d"
            }
        }

        Label {
            text: "User:"
            color: "#999999"
        }

        TextField {
            id: userField
            Layout.fillWidth: true
            text: "postgres"
            placeholderText: "<Enter user name>"
            color: "white"
            background: Rectangle {
                color: "#4d4d4d"
            }
        }

        Label {
            text: "Password"
            color: "#999999"
        }
        TextField {
            id: passwordField
            echoMode: TextInput.Password
            Layout.fillWidth: true
            placeholderText: "<password>"
            color: "white"
            background: Rectangle {
                color: "#4d4d4d"
            }
        }

        Button {
            id: connectButton
            text: "confirm"
            Layout.columnSpan: 2
            Layout.fillWidth: true
            palette.button: "#404040"
            palette.buttonText: "white"
            onClicked: {
                db_user = userField.text
                db_password = passwordField.text
                db_port = portField.text
                db_name = nameField.text
                db_host = hostnameField.text
                nodesList.connect(db_host, db_name, db_port , db_user, db_password)
                dbFormular.close()
            }
        }
        Keys.onPressed: (event)=> {
            if (event.key === Qt.Key_Return || event.key === Qt.Key_Enter) {
                connectButton.clicked(); // Auslösen des Button-Klicks
            }
        }

    }
}
