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
        }

        TextField {
            id: hostnameField
            Layout.fillWidth: true
            text: "10.35.8.10"
            placeholderText: "<Enter host address>"
        }

        Label {
            text: "Port:"
        }

        TextField {
            id: portField
            Layout.fillWidth: true
            text: "5432"
            placeholderText: "<Enter port>"
            //inputMethodHints: Qt.ImhDigitsOnly
        }

        Label {
            text: "Database:"
        }

        TextField {
            id: nameField
            Layout.fillWidth: true
            text: "tsdb"
            placeholderText: "<Enter database name>"
        }

        Label {
            text: "User:"
        }

        TextField {
            id: userField
            Layout.fillWidth: true
            text: "postgres"
            placeholderText: "<Enter user name>"
        }

        Label {
            text: "Password"
        }
        TextField {
            id: passwordField
            echoMode: TextInput.Password
            Layout.fillWidth: true
            placeholderText: "<password>"
        }

        Button {
            id: connectButton
            text: "confirm"
            Layout.columnSpan: 2
            Layout.fillWidth: true
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

    }
}
