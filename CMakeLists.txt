cmake_minimum_required(VERSION 3.16)

project(GUI_Cluster VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "/home/anna-lena/QtDesignStudio/6.5.0/gcc_64/lib/cmake/Qt6;/home/anna-lena/QtDesignStudio/6.5.0/gcc_64/lib" ${CMAKE_MODULE_PATH})

find_package(Qt6 REQUIRED COMPONENTS Core Gui Quick QuickControls2 Quick3D Sql)
find_package(PkgConfig REQUIRED)

pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

INCLUDE_DIRECTORIES("/usr/include/postgresql")
LINK_DIRECTORIES("/usr/lib/postgresql/12/lib")

qt6_add_resources(QML_RESOURCES resources.qrc)

qt_add_executable(appGUI_Cluster
    main.cpp
    cluster_node.h
    cluster_node.cpp
    cluster_rank.h
    cluster_rank.cpp
    controller.h
    controller.cpp
    nodes_instances.h nodes_instances.cpp
    ranks_instances.h ranks_instances.cpp
    database_thread.h database_thread.cpp
    bash_process_manager.h bash_process_manager.cpp
    table_userid.h table_userid.cpp
     cluster_architecture.h cluster_architecture.cpp

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
        Sidebar_Item.qml
        MPI_Application_Start.qml
        Options.qml
        Menu_Bar.qml
        Bottom_Bar.qml
        Cluster_Connection_Formular.qml
        DB_Connection_Formular.qml
        Key_Gen_Guide.qml
        Bash_Skript_Manual.qml
        Error.qml
        Custom_BusyIndicator.qml
        Loading.qml
        Output_File.qml
        Application_Start_without.qml
        Application_Start_Scorep.qml
        Table_Userid_Selection.qml
        MPI_Run_Analysis.qml
        SOURCES database_connection.h database_connection.cpp
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
    Qt6::QuickControls2
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
    Qt6::QuickControls2
    Qt6::Quick3D
    Qt6::Sql
)

