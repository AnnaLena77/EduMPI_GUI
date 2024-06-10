import QtQuick
import QtQuick.Controls
import QtQuick.Layouts 6.3
import QtQuick.Dialogs

Rectangle {
    id: runtime_options
    width: 250
    height: 300
    implicitHeight: 300
    color: "#383936"

    Button {
        text: "start"
        onClicked: {
            //nodesList.writeLocalBashFile("/home/anna-lena/Desktop/MPI_Exams_Test", "matrix_matrix_mult.c", false);
        }
    }

}
