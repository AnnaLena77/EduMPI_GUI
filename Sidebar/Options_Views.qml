import QtQuick
import QtQuick.Controls
import QtQuick.Layouts 6.3
import QtQuick.Dialogs

Rectangle {
    id: option_views
    width: 250
    // the 3D view has the additional communicator selector
    implicitHeight: three_d_check.checked ? 570 : 300
    height: implicitHeight
    color: "#383936"

    property StackView view;

    Rectangle {
        id: rectangle
        //anchors.fill: parent
        x: 5
        y: 5
        radius: 10
        width: parent.width - 10
        anchors.leftMargin:  5
        height: parent.height - 10
        border.width: 2
        border.color: "#00FF00"
        color: "transparent"

        ButtonGroup {
            id: checkboxgroup
        }

        ColumnLayout{
            width: rectangle.width
            anchors.fill: parent
            //height: parent.height
            Layout.alignment: Qt.AlignRight
            Layout.fillWidth: true
            anchors.margins: 5

            Text {
                id: text_view
                text: qsTr("Select representation view:")
                topPadding: 6
                color: "#00FF00"
                //font.pointSize: 12
                //Layout.alignment: Qt.AlignHCenter
            }


            CheckBox {
                id: three_d_check
                ButtonGroup.group: checkboxgroup
                HoverHandler {
                    cursorShape: Qt.PointingHandCursor
                }
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignRight
                Layout.rightMargin: 40
                palette.base: "#333333"
                checked: true
                text: qsTr("3D Nodes (Cube View)")
                onCheckStateChanged: {
                    if(checked){
                        selected_screen = "Cores3D"
                        view.replace("/Cores3D.qml", {listNodes : nodesList})
                        //three_d_check.checked = false
                        //cm_check.checked = false
                    }
                    //two_d_check.checked = !three_d_check.checked && !cm_check.checked
                }
            }
            CheckBox {
                id: two_d_check
                ButtonGroup.group: checkboxgroup
                HoverHandler {
                    cursorShape: Qt.PointingHandCursor
                }
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignRight
                Layout.rightMargin: 40
                palette.base: "#333333"
                checked: false
                text: qsTr("2D Nodes (List View)")
                onCheckStateChanged: {
                    if(checked){
                        selected_screen = "Cores2D"
                        view.replace("/Cores2D.qml", {listNodes : nodesList})
                        //two_d_check.checked = false
                        //cm_check.checked = false
                    }
                    //three_d_check.checked = !two_d_check.checked && !cm_check.checked
                }
            }
            CheckBox {
                id: cm_check
                ButtonGroup.group: checkboxgroup
                HoverHandler {
                    cursorShape: Qt.PointingHandCursor
                }
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignRight
                Layout.rightMargin: 40
                checked: false
                text: qsTr("Communication Matrix")
                onCheckStateChanged: {
                    if(checked){
                        selected_screen = "CoresMatrix"
                        view.replace("/CoresCommunicationMatrix.qml", {listNodes : nodesList})
                        //three_d_check.checked = false
                        //two_d_check.checked = false
                    }
                    //cm_check.checked = !two_d_check.checked && !three_d_check.checked
                }
            }


            Rectangle {
                id: slider_rect
                width: parent.width
                height: 80
                color: "transparent"
                Layout.alignment: Qt.AlignHCenter
                visible: two_d_check.checked

                ColumnLayout {
                    anchors.fill: parent
                    //anchors.margins: 5

                    Text {
                        text: "Columns:   " + mySlider.value.toFixed(0)
                        color: "#999999"
                        font.pointSize: 12
                    }

                    Slider {
                        id: mySlider
                        from: 1      // Minimalwert
                        to: 32       // Maximalwert
                        stepSize: 1  // Schrittweite
                        value: 10    // Initialwert
                        Layout.alignment: Qt.AlignHCenter

                        onValueChanged: {
                            view.twoD_columns = value;
                        }

                        background: Rectangle {
                            x: mySlider.leftPadding
                            y: mySlider.topPadding + mySlider.availableHeight/2 - height/2
                            implicitWidth: 200
                            width: mySlider.availableWidth
                            implicitHeight: 5
                            height: 5
                            color: "#00FF00"
                        }
                    }

                    RowLayout {
                        //spacing: 10
                        //Layout.leftMargin: mySlider.leftPadding
                        Layout.alignment: Qt.AlignHCenter
                        Layout.fillWidth: mySlider.availableWidth
                        Layout.preferredWidth: mySlider.width

                        Text {
                            text: mySlider.from
                            font.pixelSize: 14
                            color: "#999999"
                            Layout.alignment: Qt.AlignLeft
                            //Layout.preferredWidth: mySlider.width / 3
                        }

                        Text {
                            text: mySlider.to
                            font.pixelSize: 14
                            color: "#999999"
                            Layout.alignment: Qt.AlignRight
                            //Layout.preferredWidth: mySlider.width / 3
                        }
                    }
                }
            }

            Rectangle {
                id: communication_lines_checker
                width: parent.width
                height: 100
                color: "transparent"
                Layout.alignment: Qt.AlignHCenter
                visible: three_d_check.checked

                ColumnLayout{
                    anchors.fill: parent

                    Text {
                        width: rectangle.width
                        text: qsTr("Show detailed MPI communication patterns:")
                        //font.pointSize: 12
                        Layout.alignment: Qt.AlignHCenter
                        Layout.preferredWidth: parent.width
                        Layout.fillWidth: true
                        wrapMode: Text.WordWrap
                        color: "#999999"
                    }
                    Row {
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        spacing: 8

                        Switch {
                            id: sendlines
                            HoverHandler {
                                cursorShape: Qt.PointingHandCursor
                            }

                            indicator: Rectangle{
                                radius: 13
                                color: sendlines.checked ? "#00FF00" : "#999999"
                                implicitHeight: 20
                                implicitWidth:  40
                                x: sendlines.width - width - sendlines.rightPadding
                                y: parent.height / 2 - height /2
                                border.color: "#999999"

                                Rectangle {
                                    x: sendlines.checked ? parent.width - width : 0
                                    width: 20
                                    height: 20
                                    radius: 13
                                    border.color: "#999999"
                                }
                            }

                            //Layout.alignment: Qt.AlignRight
                            Layout.alignment: Qt.AlignVCenter
                            //Layout.rightMargin: 40
                            checked: false

                            onCheckedChanged: {
                                if(checked){
                                    p2p_send_lines = true
                                } else {
                                    p2p_send_lines = false
                                }
                            }
                        }

                        Text {
                            text: "P2P - Send arrows"
                            color: "#999999"
                            Layout.alignment: Qt.AlignBottom
                            Layout.fillHeight: true
                            Layout.preferredHeight: sendlines.height
                        }
                    }

                    Row {
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        spacing: 8

                        Switch {
                            id: recvlines
                            HoverHandler {
                                cursorShape: Qt.PointingHandCursor
                            }

                            indicator: Rectangle{
                                radius: 13
                                color: recvlines.checked ? "red" : "#999999"
                                implicitHeight: 20
                                implicitWidth:  40
                                x: recvlines.width - width - recvlines.rightPadding
                                y: parent.height / 2 - height /2
                                border.color: "#999999"

                                Rectangle {
                                    x: recvlines.checked ? parent.width - width : 0
                                    width: 20
                                    height: 20
                                    radius: 13
                                    border.color: "#999999"
                                }
                            }

                            //Layout.alignment: Qt.AlignRight
                            Layout.alignment: Qt.AlignVCenter
                            Layout.rightMargin: 40
                            checked: false

                            onCheckedChanged: {
                                if(checked){
                                    p2p_recv_lines = true
                                } else {
                                    p2p_recv_lines = false
                                }
                            }
                        }
                        Text {
                            text: "P2P - Recv arrows"
                            color: "#999999"
                            Layout.alignment: Qt.AlignVCenter
                            Layout.fillHeight: true
                        }

                    }
                    Row {
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        spacing: 8

                        Switch {
                            id: colllines
                            HoverHandler {
                                cursorShape: Qt.PointingHandCursor
                            }

                            indicator: Rectangle{
                                radius: 13
                                color: colllines.checked ? "black" : "#999999"
                                implicitHeight: 20
                                implicitWidth:  40
                                x: colllines.width - width - colllines.rightPadding
                                y: parent.height / 2 - height /2
                                border.color: "#999999"

                                Rectangle {
                                    x: colllines.checked ? parent.width - width : 0
                                    width: 20
                                    height: 20
                                    radius: 13
                                    border.color: "#999999"
                                }
                            }

                            //Layout.alignment: Qt.AlignRight
                            Layout.alignment: Qt.AlignVCenter
                            Layout.rightMargin: 40
                            checked: false

                            onCheckedChanged: {
                                if(checked){
                                    coll_lines = true
                                    nodesList.p2pData
                                } else {
                                    coll_lines = false
                                }
                            }
                        }
                        Text {
                            text: "Collective arrows"
                            color: "#999999"
                            Layout.alignment: Qt.AlignVCenter
                            //Layout.fillHeight: true
                        }

                    }
                }
            }
            Rectangle {
                id: pair_filter
                width: parent.width
                height: 120
                Layout.preferredHeight: 120
                Layout.fillWidth: true
                color: "transparent"
                visible: three_d_check.checked

                // steps of the limit in bytes; the labels use powers of 1000
                property var steps: [0, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000]
                function label(b) {
                    if(b === 0) return qsTr("all pairs")
                    if(b < 1000) return qsTr("%1 B").arg(b)
                    if(b < 1000000) return qsTr("%1 KB").arg(b / 1000)
                    return qsTr("%1 MB").arg(b / 1000000)
                }

                ColumnLayout {
                    anchors.fill: parent
                    spacing: 4

                    Text {
                        Layout.alignment: Qt.AlignHCenter
                        Layout.preferredWidth: parent.width - 20
                        horizontalAlignment: Text.AlignHCenter
                        wrapMode: Text.WordWrap
                        color: "#999999"
                        text: qsTr("Hide pairs below: %1").arg(pair_filter.label(min_pair_bytes))
                    }

                    Slider {
                        id: pairSlider
                        objectName: "pairSlider"
                        Layout.alignment: Qt.AlignHCenter
                        Layout.preferredWidth: parent.width - 30
                        from: 0
                        to: pair_filter.steps.length - 1
                        stepSize: 1
                        snapMode: Slider.SnapAlways
                        value: 0
                        onMoved: min_pair_bytes = pair_filter.steps[Math.round(value)]

                        background: Rectangle {
                            x: pairSlider.leftPadding
                            y: pairSlider.topPadding + pairSlider.availableHeight / 2 - height / 2
                            width: pairSlider.availableWidth
                            height: 5
                            color: "#00FF00"
                        }
                    }

                    Text {
                        Layout.alignment: Qt.AlignHCenter
                        Layout.preferredWidth: parent.width - 20
                        wrapMode: Text.WordWrap
                        color: "#999999"
                        font.pointSize: 10
                        text: qsTr("Total per pair. Hides e.g. the small requests of an HPX broadcast (P2P arrows, fan-in/fan-out).")
                    }
                }
            }

            Rectangle {
                id: communicator_selector

                function selectedSize() {
                    for(var i = 0; i < communicatorList.length; i++){
                        if(communicatorList[i].name === selected_comm) return communicatorList[i].size
                    }
                    return 0
                }
                width: parent.width
                height: 130
                Layout.preferredHeight: 130
                Layout.fillWidth: true
                color: "transparent"
                Layout.alignment: Qt.AlignHCenter
                visible: three_d_check.checked

                ColumnLayout {
                    anchors.fill: parent
                    spacing: 6

                    Text {
                        text: qsTr("Communicator:")
                        color: "#999999"
                        Layout.alignment: Qt.AlignHCenter
                    }

                    ComboBox {
                        id: commBox
                        objectName: "commBox"
                        implicitWidth: 230
                        Layout.alignment: Qt.AlignHCenter
                        font.pointSize: 10
                        palette.button: "#666666"
                        palette.buttonText: "white"
                        textRole: "label"
                        enabled: communicatorList.length > 0

                        HoverHandler {
                            cursorShape: Qt.PointingHandCursor
                        }

                        // "All communicators" and one entry per communicator seen in the selected second
                        model: {
                            var m = [{label: "All communicators", name: ""}]
                            for(var i = 0; i < communicatorList.length; i++){
                                m.push({label: communicatorList[i].name + "  (" + communicatorList[i].size + " procs)",
                                        name: communicatorList[i].name})
                            }
                            return m
                        }

                        function syncIndex() {
                            for(var i = 0; i < model.length; i++){
                                if(model[i].name === selected_comm){
                                    currentIndex = i
                                    return
                                }
                            }
                            currentIndex = 0
                        }
                        onModelChanged: syncIndex()
                        onActivated: selected_comm = model[currentIndex].name
                    }

                    Text {
                        Layout.alignment: Qt.AlignHCenter
                        Layout.preferredWidth: parent.width - 20
                        wrapMode: Text.WordWrap
                        color: "#999999"
                        font.pointSize: 10
                        text: communicatorList.length === 0
                              ? qsTr("No communicator data for this time (needs EduMPI with communicator labels and the migrated EduStore).")
                              : (selected_comm === ""
                                 ? qsTr("Select a communicator to see which processes take part.")
                                 : qsTr("%1 processes take part in it; the other cubes are grey. Turn on the arrow switches to see its messages.").arg(communicator_selector.selectedSize()))
                    }
                }
            }
            Rectangle {
                id: slider_rect_zoom
                width: parent.width
                height: 80
                color: "transparent"
                Layout.alignment: Qt.AlignHCenter
                visible: cm_check.checked

                ColumnLayout {
                    anchors.fill: parent
                    //anchors.margins: 5

                    Text {
                        text: "Zoom:   " + mySlider_zoom.value.toFixed(0) + "%"
                        color: "#999999"
                        font.pointSize: 12
                    }

                    Slider {
                        id: mySlider_zoom
                        from: 20      // Minimalwert
                        to: 300       // Maximalwert
                        stepSize: 10  // Schrittweite
                        value: 100    // Initialwert
                        Layout.alignment: Qt.AlignHCenter

                        onValueChanged: {
                            //view.twoD_columns = value;
                            view.matrix_zoom = value;
                        }

                        background: Rectangle {
                            x: mySlider_zoom.leftPadding
                            y: mySlider_zoom.topPadding + mySlider_zoom.availableHeight/2 - height/2
                            implicitWidth: 200
                            width: mySlider_zoom.availableWidth
                            implicitHeight: 5
                            height: 5
                            color: "#00FF00"
                        }
                    }

                    RowLayout {
                        //spacing: 10
                        //Layout.leftMargin: mySlider.leftPadding
                        Layout.alignment: Qt.AlignHCenter
                        Layout.fillWidth: mySlider_zoom.availableWidth
                        Layout.preferredWidth: mySlider_zoom.width

                        Text {
                            text: mySlider_zoom.from + "%"
                            font.pixelSize: 14
                            color: "#999999"
                            Layout.alignment: Qt.AlignLeft
                            //Layout.preferredWidth: mySlider.width / 3
                        }

                        Text {
                            text: mySlider_zoom.to + "%"
                            font.pixelSize: 14
                            color: "#999999"
                            Layout.alignment: Qt.AlignRight
                            //Layout.preferredWidth: mySlider.width / 3
                        }
                    }
                }
            }
        }
    }
}



