// Copyright (C) 2024 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

import QtQuick
import QtQuick.Controls.impl
import QtQuick.Controls.FluentWinUI3.impl
import QtQuick.Templates as T

T.Button {
    id: control

    implicitWidth: Math.max(implicitBackgroundWidth + leftInset + rightInset,
                            implicitContentWidth + leftPadding + rightPadding)
    implicitHeight: Math.max(implicitBackgroundHeight + topInset + bottomInset,
                             implicitContentHeight + topPadding + bottomPadding)

    spacing: config.spacing || 0

    topPadding: config.topPadding || 0
    bottomPadding: config.bottomPadding || 0
    leftPadding: config.leftPadding || 0
    rightPadding: config.rightPadding || 0

    topInset: -config.topInset || 0
    bottomInset: -config.bottomInset || 0
    leftInset: -config.leftInset || 0
    rightInset: -config.rightInset || 0

    icon.width: config.icon.width
    icon.height: config.icon.height
    icon.color: __buttonText

    readonly property color __buttonText: {
        if (control.down) {
            return (control.checked || control.highlighted)
                ? Application.styleHints.colorScheme == Qt.Light
                    ? Color.transparent("white", 0.7) : Color.transparent("black", 0.5)
                : (Application.styleHints.colorScheme === Qt.Light
                    ? Color.transparent(control.palette.buttonText, 0.62)
                    : Color.transparent(control.palette.buttonText, 0.7725))
        } else if (control.checked || control.highlighted) {
            return (Application.styleHints.colorScheme === Qt.Dark && !control.enabled)
                ? Color.transparent("white", 0.5302)
                : (Application.styleHints.colorScheme === Qt.Dark ? "black" : "white")
        } else {
            return control.palette.buttonText
        }
    }

    readonly property string __currentState: [
        (control.checked || control.highlighted) && "checked",
        !control.enabled && "disabled",
        control.enabled && !control.down && control.hovered && "hovered",
        control.down && "pressed"
    ].filter(Boolean).join("_") || "normal"
    readonly property var config: (control.flat && Config.controls.flatbutton
        ? Config.controls.flatbutton[__currentState]
        : Config.controls.button[__currentState]) || {}

    readonly property Item __focusFrameTarget: control

    contentItem: IconLabel {
        spacing: control.spacing
        mirrored: control.mirrored
        display: control.display
        alignment: control.config.label.textVAlignment | control.config.label.textHAlignment
        icon: control.icon
        text: control.text
        font: control.font
        color: control.icon.color
    }

    background: ButtonBackground {
        control: control
        implicitHeight: control.config.background.height
        implicitWidth: control.config.background.width
        radius: control.config.background.topOffset
        subtle: control.flat
    }
}
