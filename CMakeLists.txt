cmake_minimum_required(VERSION 3.19)

project(GUI_Cluster VERSION 1.0.0 LANGUAGES CXX)

# Debug, solange nichts anderes übergeben wird (-DCMAKE_BUILD_TYPE=Release für Pakete)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

set(QT_QML_GENERATE_QMLLS_INI ON)

set(PostgreSQL_ROOT "/opt/homebrew/opt/libpq" CACHE PATH "")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
#set(CMAKE_AUTOUIC ON)
#set(QT_QMLTYPE_REGISTRATION ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(APPLE)
    # AGL existiert auf modernen macOS SDKs nicht mehr
    set(WrapOpenGL_AGL "WrapOpenGL_AGL-NOTFOUND" CACHE FILEPATH "" FORCE)
endif()


find_package(Qt6 REQUIRED COMPONENTS Core Gui Quick QuickControls2 Quick3D Sql Concurrent OpenGL)
find_package(PostgreSQL REQUIRED)

qt_standard_project_setup()

qt_policy(SET QTP0001 NEW)  # Automatisches Generieren von qmldir und qmltypes
qt_policy(SET QTP0002 NEW)  # Neues Verhalten für Build-/Installationsverzeichnis
qt_policy(SET QTP0003 NEW)  # Für Plugins, wenn benötigt
qt_policy(SET QTP0004 NEW)  # Module mit mehreren QML-Dateien benötigen ein qmldir

if (LINUX)
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
endif ()

#INCLUDE_DIRECTORIES("/usr/include/postgresql")
#LINK_DIRECTORIES("/usr/lib/postgresql/12/lib")
include_directories(${PostgreSQL_INCLUDE_DIRS})
link_directories(${PostgreSQL_LIBRARY_DIRS})

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
    app_mode.h app_mode.cpp
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
        CoresCommunicationMatrix.qml
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
        Detailed_Information_Bar.qml
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
        detailed_coll_data.h
        detailed_coll_data.cpp
        heatmap_matrix.h
        heatmap_matrix.cpp
        heatmapmaterial.h
        heatmapmaterial.cpp

)

add_subdirectory(Sidebar)


set_target_properties(appGUI_Cluster PROPERTIES
    #MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    #MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    #MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
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
    Qt6::Concurrent
    Qt6::OpenGL
)

# Auto-Connect-Modi (siehe app_mode.h), nie in normalen Release-Builds:
#  - Dev-Modus für den lokalen Dev-Cluster (EduMPI/dev): Werte aus EDUMPI_DEV_ENV
#  - Demo-Modus für das Demo-Repo tool-edumpi-docker: Werte aus EDUMPI_DEMO_ENV, ssh/scp mit
#    Demo-Port und -Key, ohne Verbindungsdialoge und ohne das Menü "Non-Visualization"
# Beide sind erst aktiv, wenn die jeweilige Umgebungsvariable gesetzt ist.
option(EDUMPI_DEV_MODE "Dev-Modus: Auto-Connect gegen den lokalen Dev-Cluster" OFF)
option(EDUMPI_DEMO_MODE "Demo-Modus: Auto-Connect gegen den Demo-Cluster aus tool-edumpi-docker" OFF)
if(EDUMPI_DEV_MODE AND EDUMPI_DEMO_MODE)
    message(FATAL_ERROR "EDUMPI_DEV_MODE und EDUMPI_DEMO_MODE schließen sich aus")
endif()
if(EDUMPI_DEV_MODE)
    target_compile_definitions(appGUI_Cluster PRIVATE EDUMPI_DEV_MODE)
endif()
if(EDUMPI_DEMO_MODE)
    target_compile_definitions(appGUI_Cluster PRIVATE EDUMPI_DEMO_MODE)
endif()

install(TARGETS appGUI_Cluster
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

target_link_libraries(appGUI_Cluster PRIVATE
    sidebarplugin
)

if(APPLE)
    add_custom_command(TARGET appGUI_Cluster POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy
              /opt/homebrew/opt/libpq/lib/libpq.5.dylib
              $<TARGET_BUNDLE_DIR:appGUI_Cluster>/Contents/Frameworks/libpq.5.dylib
    )
endif()


