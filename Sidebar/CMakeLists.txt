# Copyright (C) 2022 The Qt Company Ltd.
# SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

qt_add_library(sidebar STATIC)
qt_add_qml_module(sidebar
    URI "Sidebar"
    VERSION 1.0
    OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
    QML_FILES
        Sidebar.qml
        Sidebar_Item.qml
        MPI_Application_Start.qml
        Sidebar_Run_Analysis.qml
        Options.qml
        Options_Bar.qml
        Options_Views.qml
        Screenshot.qml
)
