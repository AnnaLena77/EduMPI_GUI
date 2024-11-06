import QtQuick

import QtQuick
import QtQuick.Controls

//Code Source: https://doc.qt.io/qt-6/qtquickcontrols-customize.html#customizing-busyindicator

BusyIndicator {
    property color prop_color;
    property int prop_height;
    property int prop_width;
    property int helper: prop_height/2;

    id: control
    implicitHeight: prop_height
    implicitWidth: prop_width

    //implicitWidth: 64

    contentItem: Item {
        implicitWidth: parent.width
        implicitHeight: parent.height

        Item {
            id: item
            x: parent.width / 2 - helper
            y: parent.height / 2 - helper
            width: prop_width
            height: prop_height
            opacity: control.running ? 1 : 0

            Behavior on opacity {
                OpacityAnimator {
                    duration: 250
                }
            }

            RotationAnimator {
                target: item
                running: control.visible && control.running
                from: 0
                to: 360
                loops: Animation.Infinite
                duration: 1250
            }

            Repeater {
                id: repeater
                model: 6

                Rectangle {
                    id: delegate

                    x: item.width / 2 - width / 2
                    y: item.height / 2 - height / 2
                    implicitWidth: 10
                    implicitHeight: 10
                    radius: 5
                    color: prop_color

                    required property int index

                    transform: [
                        Translate {
                            y: -Math.min(item.width, item.height) * 0.5 + 5
                        },
                        Rotation {
                            angle: delegate.index / repeater.count * 360
                            origin.x: 5
                            origin.y: 5
                        }
                    ]
                }
            }
        }
    }
}
