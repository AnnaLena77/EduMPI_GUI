cmake_minimum_required(VERSION 3.19)

project(GUI_Cluster VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_BUILD_TYPE Debug)

set(QT_QML_GENERATE_QMLLS_INI ON)

if(APPLE)
    set(PostgreSQL_ROOT "/opt/homebrew/opt/libpq" CACHE PATH "")
endif()

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
#set(CMAKE_AUTOUIC ON)
#set(QT_QMLTYPE_REGISTRATION ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(WIN32)
    set(CMAKE_PREFIX_PATH "C:/Qt/6.8.1/mingw_64/lib/cmake/Qt6;C:/Qt/6.8.1/mingw_64/lib/cmake")
elseif (LINUX)
    set(CMAKE_PREFIX_PATH "/home/anna-lena/QtDesignStudio/6.8.1/gcc_64/lib/cmake/Qt6;/home/anna-lena/QtDesignStudio/6.8.1/gcc_64/lib/cmake")
endif ()
if(APPLE)
    # AGL existiert auf modernen macOS SDKs nicht mehr
    set(WrapOpenGL_AGL "WrapOpenGL_AGL-NOTFOUND" CACHE FILEPATH "" FORCE)
endif()


find_package(Qt6 REQUIRED COMPONENTS Core Gui Quick QuickControls2 Quick3D Sql)
find_package(PostgreSQL REQUIRED)

qt_standard_project_setup()

# Remember the database password in the keychain of the operating system (QtKeychain).
# An installed QtKeychain (Qt6Keychain) is used if there is one. With -DEDUMPI_FETCH_KEYCHAIN=ON it is
# downloaded and built instead (source: github.com/frankosterfeld/qtkeychain, fixed tag). Without
# either the GUI still works, the password is just not remembered.
option(EDUMPI_FETCH_KEYCHAIN "Download and build QtKeychain if it is not installed" OFF)
find_package(Qt6Keychain CONFIG QUIET)
if(NOT Qt6Keychain_FOUND AND EDUMPI_FETCH_KEYCHAIN)
    include(FetchContent)
    set(BUILD_WITH_QT6 ON CACHE BOOL "" FORCE)
    set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
    set(BUILD_TEST_APPLICATION OFF CACHE BOOL "" FORCE)
    set(BUILD_TRANSLATIONS OFF CACHE BOOL "" FORCE)
    FetchContent_Declare(qtkeychain
        GIT_REPOSITORY https://github.com/frankosterfeld/qtkeychain.git
        GIT_TAG 0.14.3)
    FetchContent_MakeAvailable(qtkeychain)
    set(EDUMPI_KEYCHAIN_FETCHED ON)
endif()
if(Qt6Keychain_FOUND OR EDUMPI_KEYCHAIN_FETCHED)
    set(EDUMPI_KEYCHAIN ON)
else()
    message(STATUS "QtKeychain not found: the database password will not be remembered")
endif()

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
    login_store.h login_store.cpp
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
        CommunicatorState.qml
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
)

install(TARGETS appGUI_Cluster
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

target_link_libraries(appGUI_Cluster PRIVATE
    sidebarplugin
)

if(EDUMPI_KEYCHAIN)
    # the installed package and the downloaded sources name their target differently
    if(TARGET Qt6Keychain::Qt6Keychain)
        target_link_libraries(appGUI_Cluster PRIVATE Qt6Keychain::Qt6Keychain)
    else()
        target_link_libraries(appGUI_Cluster PRIVATE qt6keychain)
    endif()
    target_compile_definitions(appGUI_Cluster PRIVATE EDUMPI_HAVE_KEYCHAIN)
    if(EDUMPI_KEYCHAIN_FETCHED)
        # keychain.h is included as <qt6keychain/keychain.h>
        target_include_directories(appGUI_Cluster PRIVATE ${qtkeychain_BINARY_DIR}/.. ${qtkeychain_SOURCE_DIR}/..)
    endif()
endif()

add_custom_command(TARGET appGUI_Cluster POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E create_symlink
        "${CMAKE_BINARY_DIR}/GUI_Cluster/appGUI_Cluster.qmltypes"
        "${CMAKE_CURRENT_SOURCE_DIR}/GUI_Cluster/appGUI_Cluster.qmltypes"
)

if(APPLE)
    add_custom_command(TARGET appGUI_Cluster POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
            /opt/homebrew/opt/libpq/lib/libpq.5.dylib
            $<TARGET_BUNDLE_DIR:appGUI_Cluster>/Contents/Frameworks/libpq.5.dylib
    )
endif()


