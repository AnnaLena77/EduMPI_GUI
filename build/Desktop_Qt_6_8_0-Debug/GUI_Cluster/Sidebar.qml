import QtQuick
import QtQuick.Layouts 6.3
import QtQuick.Controls 6.3
import QtQuick.Dialogs

//Source: based on https://forum.qt.io/topic/66565/qml-expandable-menu-with-subitems
//Icons from: https://fontawesome.com/

Item {
    id: item
    width: 250
    height: parent.height - 60 -70

    Rectangle {
        id: rectangle
        //anchors.fill: parent
        //x: 0
        //y: 0
        width: parent.width
        height: parent.height
        anchors.fill: parent
        color: "#383936"

        ListModel {
            id: sidebarModel
            ListElement { name: "MPI Application"; icon: "qrc:/icons/terminal.png"; aVisible: true; aSource: "MPI_Application_Start.qml"}
            ListElement { name: "Runtime Options"; icon: "qrc:/icons/slider.png"; aVisible: false; aSource: "Options.qml" }
        }

        Component {
            id: sections

            Rectangle {
                id: sectionsRect
                width: parent.width
                color: "transparent"
                height: 30

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
                        height: parent.height
                        Layout.alignment: Qt.AlignLeft
                        Layout.leftMargin: 5
                        //anchors.rightMargin: 5
                        icon.color: sectionsRect.isExpanded ? "#00FF00" : "white"
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
                        text: section
                        height: parent.height
                        //verticalAlignment: Text.AlignVCenter
                        color: sectionsRect.isExpanded ? "#00FF00" : "white"
                        //anchors.centerIn: parent
                    }

                    Button{
                        id: iconUpDown
                        height: parent.height
                        Layout.alignment: Qt.AlignRight
                        Layout.rightMargin: 10
                        //anchors.rightMargin: 10
                        icon.source: sectionsRect.isExpanded ? "qrc:/icons/up.png" : "qrc:/icons/down.png"
                        icon.color: sectionsRect.isExpanded ? "#00FF00" : "white"
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
                        /*if(sectionHeaderRect.isExpanded){
                            iconUpDown.icon.source = "qrc:/icons/up.png"
                        } else{
                            iconUpDown.icon.source = "qrc:/icons/down.png"
                        }*/
                    }
                }
            }
        }


        ListView {
            //Visualization of List-Elements
            id: listing
            width: parent.width
            height: parent.height
            model: sidebarModel

            property string expandedSection: sidebarModel.get(0).name

            delegate: listdelegate

            //sectionicon.property: "icon"

            section.property: "name"
            section.criteria: ViewSection.FullString
            section.delegate: sections
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
