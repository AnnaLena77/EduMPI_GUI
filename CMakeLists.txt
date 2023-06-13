cmake_minimum_required(VERSION 3.16)

project(GUI_Cluster VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 REQUIRED COMPONENTS Core Gui Quick Quick3D)
find_package(Qt6 COMPONENTS ShaderTools)

qt6_add_resources(QML_RESOURCES resources.qrc)

qt6_add_shaders(SHADER_RESOURCES
    FILES
        shaders/glass.frag
        shaders/simple.vert
)

qt_add_executable(appGUI_Cluster
    main.cpp
    mongodata.h
    mongodata.cpp
    cluster_node.h
    cluster_node.cpp
    cluster_core.h
    cluster_core.cpp
    database_connection.h
    database_connection.cpp
    nodes_instances.h nodes_instances.cpp
    cores_instances.h cores_instances.cpp

    ${QML_RESOURCES}
    ${SHADER_RESOURCES}
)

qt_add_qml_module(appGUI_Cluster
    URI GUI_Cluster
    VERSION 1.0
    QML_FILES
        main.qml
        Cores2D.qml
        Cores3D.qml
        Sidebar.qml
        Options_Bar.qml
        3D-Scene/Lights.qml
    RESOURCES
        maps/OpenfootageNET_garage-1024.hdr
        shaders/glass.frag
        shaders/simple.vert
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
)

install(TARGETS appGUI_Cluster
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})


find_package(mongocxx REQUIRED)
find_package(bsoncxx REQUIRED)
include_directories(${LIBMONGOCXX_INCLUDE_DIR})
include_directories(${LIBBSONCXX_INCLUDE_DIR})
include_directories("/usr/local/include/mongocxx/v_noabi")
include_directories("/usr/local/include/bsoncxx/v_noabi")
include_directories("/usr/local/include/libmongoc-1.0")
include_directories("/usr/local/include/libbson-1.0")
include_directories("/usr/local/lib")

target_link_libraries(appGUI_Cluster PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Quick
    Qt6::Quick3D
)
target_link_libraries(appGUI_Cluster PRIVATE mongo::bsoncxx_shared)
target_link_libraries(appGUI_Cluster PRIVATE mongo::mongocxx_shared)


