cmake_minimum_required(VERSION 3.16)

project(GUI_Cluster VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Quick Quick3D Sql)

INCLUDE_DIRECTORIES("/usr/include/postgresql")
LINK_DIRECTORIES("/usr/lib/postgresql/12/lib")

qt6_add_resources(QML_RESOURCES resources.qrc)

qt_add_executable(appGUI_Cluster
    main.cpp
    cluster_node.h
    cluster_node.cpp
    cluster_rank.h
    cluster_rank.cpp
    database_connection.h
    database_connection.cpp
    nodes_instances.h nodes_instances.cpp
    ranks_instances.h ranks_instances.cpp
    database_thread.h database_thread.cpp

    ${QML_RESOURCES}
    ${SHADER_RESOURCES}
)

qt_add_qml_module(appGUI_Cluster
    URI GUI_Cluster
    VERSION 1.0
    QML_FILES
        main.qml
        #qmldir
        #Style.qml
        Cores2D.qml
        Cores3D.qml
        Sidebar.qml
        Options_Bar.qml
        Menu_Bar.qml
        Cluster_Connection_Formular.qml
        DB_Connection_Formular.qml
        Key_Gen_Guide.qml
        Bash_Skript_Manual.qml
        3D-Scene/Lights.qml
)

set_target_properties(appGUI_Cluster PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appGUI_Cluster PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Quick
    Qt6::Quick3D
    Qt6::Sql
)

install(TARGETS appGUI_Cluster
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

target_link_libraries(appGUI_Cluster PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Quick
    Qt6::Quick3D
    Qt6::Sql
)

