cmake_minimum_required(VERSION 3.19)

project(GUI_Cluster VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_BUILD_TYPE Debug)

set(QT_QML_GENERATE_QMLLS_INI ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
#set(CMAKE_AUTOUIC ON)
#set(QT_QMLTYPE_REGISTRATION ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "/home/anna-lena/QtDesignStudio/6.8.1/gcc_64/lib/cmake/Qt6;/home/anna-lena/QtDesignStudio/6.8.1/gcc_64/lib/cmake")

find_package(Qt6 REQUIRED COMPONENTS Core Gui Quick QuickControls2 Quick3D Sql)
find_package(PkgConfig REQUIRED)

qt_standard_project_setup()

qt_policy(SET QTP0001 NEW)  # Automatisches Generieren von qmldir und qmltypes
qt_policy(SET QTP0002 NEW)  # Neues Verhalten für Build-/Installationsverzeichnis
qt_policy(SET QTP0003 NEW)  # Für Plugins, wenn benötigt
qt_policy(SET QTP0004 NEW)  # Module mit mehreren QML-Dateien benötigen ein qmldir

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
    #controller.h
    #controller.cpp
    nodes_instances.h nodes_instances.cpp
    #ranks_instances.h ranks_instances.cpp
    database_thread.h database_thread.cpp
    bash_process_manager.h bash_process_manager.cpp
    table_userid.h table_userid.cpp
    #cluster_architecture.h cluster_architecture.cpp
    database_connection.h database_connection.cpp
    ${QML_RESOURCES}
)

qt_add_qml_module(appGUI_Cluster
    URI GUI_Cluster
    VERSION 1.0
    RESOURCE_PREFIX "/"

    QML_FILES
        main.qml
        Cores2D.qml
        Cores3D.qml
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
        Application_Start_OpenMP.qml
    SOURCES
        controller.cpp
        controller.h
        cluster_architecture.cpp
        cluster_architecture.h
        detailed_p2p_data.h
        detailed_p2p_data.cpp
        ranks_instances.h
        ranks_instances.cpp
        customlinegeometry.h
        customlinegeometry.cpp
)

add_subdirectory(Sidebar)


set_target_properties(appGUI_Cluster PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
    VS_DEBUGGER_ENVIRONMENT "QT_WAYLAND_DISABLE_TEXT_INPUT=1;QT_LOGGING_RULES=qt.qpa.wayland.textinput=false"
    QT_WAYLAND_DISABLE_TEXT_INPUT "1"

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
    sidebarplugin
)

add_custom_command(TARGET appGUI_Cluster POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E create_symlink
        "${CMAKE_BINARY_DIR}/GUI_Cluster/appGUI_Cluster.qmltypes"
        "${CMAKE_CURRENT_SOURCE_DIR}/GUI_Cluster/appGUI_Cluster.qmltypes"
)


