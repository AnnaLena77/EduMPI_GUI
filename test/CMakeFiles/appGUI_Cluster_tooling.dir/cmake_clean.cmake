file(REMOVE_RECURSE
  "GUI_Cluster/Bash_Skript_Manual.qml"
  "GUI_Cluster/Bottom_Bar.qml"
  "GUI_Cluster/Cluster_Connection_Formular.qml"
  "GUI_Cluster/Cores2D.qml"
  "GUI_Cluster/Cores3D.qml"
  "GUI_Cluster/Custom_BusyIndicator.qml"
  "GUI_Cluster/DB_Connection_Formular.qml"
  "GUI_Cluster/Error.qml"
  "GUI_Cluster/Key_Gen_Guide.qml"
  "GUI_Cluster/MPI_Application_Start.qml"
  "GUI_Cluster/Menu_Bar.qml"
  "GUI_Cluster/Options.qml"
  "GUI_Cluster/Options_Bar.qml"
  "GUI_Cluster/Sidebar.qml"
  "GUI_Cluster/Sidebar_Item.qml"
  "GUI_Cluster/main.qml"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/appGUI_Cluster_tooling.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()