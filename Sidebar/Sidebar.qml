import QtQuick
import QtQuick.Layouts 6.3
import QtQuick.Controls 6.3
import QtQuick.Dialogs

//Source: based on https://forum.qt.io/topic/66565/qml-expandable-menu-with-subitems
//Icons from: https://fontawesome.com/

Item {
    id: item
    width: 260
    property Item rootScreen: parent


    Rectangle {
        id: rectangle
        width: parent.width
        height: parent.height
        anchors.fill: parent
        color: "#383936"

        ListModel {
            id: sidebarModel
            ListElement { name: "MPI Application"; icon: "/icons/terminal.png"; aVisible: true; aSource: "MPI_Application_Start.qml"}
            ListElement { name: "Views"; icon: "qrc:/icons/view.png"; aVisible: false; aSource: "Options_Views.qml"}
            ListElement { name: "Runtime Options"; icon: "/icons/slider.png"; aVisible: false; aSource: "Options.qml" }
            ListElement { name: "Screenshot"; icon: "/icons/camera.png"; aVisible: false; aSource: "Screenshot.qml" }
        }

        Component {
            id: sections

            Rectangle {
                id: sectionsRect
                width: parent.width - 20
                color: "transparent"
                height: 30

                HoverHandler {
                    id: stylus
                    cursorShape: Qt.PointingHandCursor
                }

                property bool isExpanded: ListView.view.expandedSection === section

                onIsExpandedChanged: {
                    for(var i=0; i<sidebarModel.count; i++){
                        var item = sidebarModel.get(i);
                        if(section === item.name)
                            item.aVisible = sectionsRect.isExpanded;
                    }
                }

                RowLayout {
                    anchors.fill: parent
                    spacing: 1

                    Button{
                        id: iconSection
                        //Layout.fillWidth: true
                        height: parent.height
                        Layout.alignment: Qt.AlignLeft
                        Layout.leftMargin: 5
                        //anchors.rightMargin: 5
                        icon.color: sectionsRect.isExpanded ? "#00FF00" : "#999999"
                        background: Rectangle{
                            color: "transparent"
                            border.width: 0
                        }
                        Component.onCompleted: {
                            for(var i=0; i<sidebarModel.count; i++){
                                var item = sidebarModel.get(i);
                                if(section === item.name)
                                    iconSection.icon.source = item.icon
                            }
                        }
                    }

                    Text {
                        id: sectionsText
                        Layout.fillWidth: true
                        text: section
                        height: parent.height
                        //horizontalAlignment: Text.AlignRight
                        //verticalAlignment: Text.AlignRight
                        Layout.alignment: Qt.AlignLeft
                        Layout.leftMargin: 10
                        color: sectionsRect.isExpanded ? "#00FF00" : "#999999"
                        verticalAlignment: Text.AlignVCenter
                        //anchors.centerIn: parent
                    }

                    Button{
                        id: iconUpDown
                        //Layout.fillWidth: true
                        height: parent.height
                        Layout.alignment: Qt.AlignRight
                        Layout.rightMargin: 10
                        //anchors.rightMargin: 10
                        icon.source: sectionsRect.isExpanded ? "qrc:/icons/up.png" : "qrc:/icons/down.png"
                        icon.color: sectionsRect.isExpanded ? "#00FF00" : "#999999"
                        background: Rectangle{
                            color: "transparent"
                            border.width: 0
                        }


                    }
                }

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        sectionsRect.isExpanded = !sectionsRect.isExpanded;
                    }
                    hoverEnabled: true
                    HoverHandler{
                        cursorShape: Qt.PointingHandCursor
                    }
                }
            }
        }


        ListView {
            id: listing
            width: parent.width
            height: rectangle.height
            model: sidebarModel
            delegate: listdelegate

            property string expandedSection: sidebarModel.get(0).name

            section.property: "name"
            section.criteria: ViewSection.FullString
            section.delegate: sections
            boundsBehavior: Flickable.StopAtBounds

            ScrollBar.vertical: ScrollBar { // Scrollbar hinzufügen
                anchors.right: parent.right
                policy: ScrollBar.AlwaysOn

                contentItem: Rectangle {
                    implicitWidth: 5
                    color: "#444444" // Hintergrundfarbe der Scrollbar
                    radius: 6
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom

                    Rectangle {
                        width: parent.width
                        height: Math.max(50, (listing.height / listing.contentHeight) * parent.height)  // Höhe des Scrollbar-Griffs
                        color: "#555555" // Farbe des Scrollbar-Griffs
                        radius: 6
                        y: (listing.contentY / listing.contentHeight) * (listing.height)
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                }
            }
        }


        Component {

            id: listdelegate


            Loader {
                id: menuItem
                source: aSource
                //color: ListView.isCurrentItem ? "lightblue" : "white"
                visible: aVisible
                property int menuItemHeight

                /*onHeightChanged:{
                    console.log("changed height!")
                }*/

                onLoaded:{
                    if(aSource == "Options_Views.qml"){
                        menuItem.item.view = actualScreen
                    }
                    if(aSource == "Screenshot.qml"){
                        menuItem.item.main_item = rootScreen
                    }

                    /*console.log("Test: " +item.implicitHeight)
                    menuItemHeight = item.height

                    item.heightChanged.connect(function(){
                        console.log("testiiii");
                    });*/
                }

                Behavior on height {
                    NumberAnimation { duration: 200 }
                }

                onVisibleChanged: {
                    if(visible){
                        height = item.implicitHeight
                        //console.log("Height: " + height)
                        //console.log(expandContentLoader.item.height)
                    }
                    else{
                        height = 0;
                    }
                }
            }
        }
    }
}
