import QtQuick
import QtQuick.Controls

Window {
    id: key_gen_guide
    visible: true
    width: 800
    height: 600
    title: "SSH Key Generation Guide (for passwordless authentication)"

    ScrollView{
        anchors.fill: parent

        Column {
                spacing: 20

            Text {
                id: guide_text
                width: parent.width
                wrapMode: Text.WordWrap
                topPadding: 20
                leftPadding: 10
                rightPadding: 10
                text: "If you use the tool for the first time on a computer, it is necessary to establish a passwordless connection to the remote master of your cluster:"
            }

        Text {
                width: parent.width
                wrapMode: Text.WordWrap
                textFormat: Text.RichText
                lineHeight: 1.3
                text: "<ol>" +
                      "<li>Open a terminal on your local computer.</li>" +
                      "<li>Generate a new rsa key pair on your local computer (If you already have one, you can use this.):</li>" +
                      "<br> :~§ ssh-keygen -b 4096<br>" +
                      "<li>Enter file in which to save the key. You can confirm the default path specified here with enter. <br>
                           For your security, it makes sense to choose a passphrase and remember it. However, you can also continue without entering a passphrase by pressing the enter key.</li>" +
                       "<br> :~$ cat ./ssh id_rsa <br>" +
                       "<li>Copy the displayed key! </li>" +
                       "<br> :~$ ssh-copy-id -i .ssh/id_rsa.pub user@host <br>" +
                       "<li>Now paste the generated key to the remote cluster. <br>
                            Enter your ID for 'user' (on the HS Fulda cluster this is your FD number: fdai$$$$) <br>
                            For 'host', enter the address via which the cluster can be reached (the HS Fulda cluster has the following host address: 10.32.47.10)</li>" +
                       "<br> :~$ ssh user@host <br>" +
                       "<li>Try to log in to the cluster without a password. Once this has worked, the setup is complete.</li>" +
                       "</ol>"
            }
            Text {
                width: key_gen_guide.width
                wrapMode: Text.WordWrap
            }
        }
    }
}
