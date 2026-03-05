import QtQuick
import QtQuick.Controls

Window {
    id: key_gen_guide
    visible: true
    width: 800
    height: 600
    title: "SSH Key Generation Guide (for passwordless authentication)"

    Rectangle{
        id: background
        color: "#383936"
        anchors.fill: parent
    }

    ScrollView{
        anchors.fill: parent

        Column {
                spacing: 20

            Text {
                id: guide_text
                width: parent.width
                wrapMode: Text.WordWrap
                color: "white"
                topPadding: 20
                leftPadding: 10
                rightPadding: 10
                text: "<b>If you use the tool for the first time on a computer, it is necessary to establish a passwordless connection to the remote master of your cluster:</b>"
            }

        TextArea {
                id: guide_description
                width: parent.width
                wrapMode: Text.WordWrap
                textFormat: Text.RichText

                //lineHeight: 1.3
                readOnly: true
                text: "<ol>" +
                      "<li>Open a terminal (Command Prompt for Windows users) on your local computer.</li><br></br>" +
                      "<li>Generate a new rsa key pair on your local computer (If you already have one, you can use this.):</li>" +
                      "<br><font face='Courier'>$ ssh-keygen -b 4096</font><br>" +
                      "<li>Enter a file in which to save the key. You can confirm the default path specified here with enter. <br>
                       <b> If you do not manage your passphrase passwords with a password manager, please do not set a passphrase here!</b> Just press the enter key.</li>" +
                       "<br><font face='Courier'>$ cat .ssh/id_******</font> <i>(enter the name of your key or use the Tab key)</i><br>" +
                       "<li>Copy the generated key to the remote cluster. <br>
                            Enter your ID for 'user' (on the HS Fulda cluster this is your FD number: fdai$$$$) <br>
                            For 'host', enter the address via which the cluster can be reached (the HS Fulda cluster has the following host address: 10.32.47.10)</li>" +
                       "<br><font face='Courier'>$ ssh-copy-id -i .ssh/id_*****.pub fd******@10.32.47.10</font> <br><i>(enter the name of your key and your personal fd ID)</i> <br>" +
                       "<li>Try to log in to the cluster without a password. Once this has worked, the setup is complete.</li>" +
                       "<br><font face='Courier'>$ ssh fd******@10.32.47.10</font> <i>(enter your personal fd ID)</i> </br>" +
                       "</ol>"

                MouseArea {
                        anchors.fill: parent
                        acceptedButtons: Qt.RightButton
                        onClicked: (event) => {
                            if (event.button === Qt.RightButton) {
                                contextMenu.x = event.x
                                contextMenu.y = event.y
                                contextMenu.open()
                            }
                        }
                    }

                    Menu {
                        id: contextMenu
                        MenuItem {
                            text: "Copy"
                            onTriggered: {
                                guide_description.copy()
                            }
                        }
                    }
            }
            Text {
                width: key_gen_guide.width
                wrapMode: Text.WordWrap
            }

        }
    }
}
