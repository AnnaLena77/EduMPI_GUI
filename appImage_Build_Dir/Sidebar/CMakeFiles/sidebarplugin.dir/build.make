# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/anna-lena/QtDesignStudio/Tools/CMake/bin/cmake

# The command to remove a file.
RM = /home/anna-lena/QtDesignStudio/Tools/CMake/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/anna-lena/GUI_Cluster

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anna-lena/GUI_Cluster/appImage_Build_Dir

# Include any dependencies generated for this target.
include Sidebar/CMakeFiles/sidebarplugin.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Sidebar/CMakeFiles/sidebarplugin.dir/compiler_depend.make

# Include the progress variables for this target.
include Sidebar/CMakeFiles/sidebarplugin.dir/progress.make

# Include the compile flags for this target's objects.
include Sidebar/CMakeFiles/sidebarplugin.dir/flags.make

Sidebar/sidebarplugin_autogen/timestamp: /home/anna-lena/QtDesignStudio/6.8.1/gcc_64/libexec/moc
Sidebar/sidebarplugin_autogen/timestamp: Sidebar/CMakeFiles/sidebarplugin.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/anna-lena/GUI_Cluster/appImage_Build_Dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target sidebarplugin"
	cd /home/anna-lena/GUI_Cluster/appImage_Build_Dir/Sidebar && /home/anna-lena/QtDesignStudio/Tools/CMake/bin/cmake -E cmake_autogen /home/anna-lena/GUI_Cluster/appImage_Build_Dir/Sidebar/CMakeFiles/sidebarplugin_autogen.dir/AutogenInfo.json ""
	cd /home/anna-lena/GUI_Cluster/appImage_Build_Dir/Sidebar && /home/anna-lena/QtDesignStudio/Tools/CMake/bin/cmake -E touch /home/anna-lena/GUI_Cluster/appImage_Build_Dir/Sidebar/sidebarplugin_autogen/timestamp

Sidebar/CMakeFiles/sidebarplugin.dir/sidebarplugin_autogen/mocs_compilation.cpp.o: Sidebar/CMakeFiles/sidebarplugin.dir/flags.make
Sidebar/CMakeFiles/sidebarplugin.dir/sidebarplugin_autogen/mocs_compilation.cpp.o: Sidebar/sidebarplugin_autogen/mocs_compilation.cpp
Sidebar/CMakeFiles/sidebarplugin.dir/sidebarplugin_autogen/mocs_compilation.cpp.o: Sidebar/CMakeFiles/sidebarplugin.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/anna-lena/GUI_Cluster/appImage_Build_Dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Sidebar/CMakeFiles/sidebarplugin.dir/sidebarplugin_autogen/mocs_compilation.cpp.o"
	cd /home/anna-lena/GUI_Cluster/appImage_Build_Dir/Sidebar && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Sidebar/CMakeFiles/sidebarplugin.dir/sidebarplugin_autogen/mocs_compilation.cpp.o -MF CMakeFiles/sidebarplugin.dir/sidebarplugin_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/sidebarplugin.dir/sidebarplugin_autogen/mocs_compilation.cpp.o -c /home/anna-lena/GUI_Cluster/appImage_Build_Dir/Sidebar/sidebarplugin_autogen/mocs_compilation.cpp

Sidebar/CMakeFiles/sidebarplugin.dir/sidebarplugin_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sidebarplugin.dir/sidebarplugin_autogen/mocs_compilation.cpp.i"
	cd /home/anna-lena/GUI_Cluster/appImage_Build_Dir/Sidebar && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anna-lena/GUI_Cluster/appImage_Build_Dir/Sidebar/sidebarplugin_autogen/mocs_compilation.cpp > CMakeFiles/sidebarplugin.dir/sidebarplugin_autogen/mocs_compilation.cpp.i

Sidebar/CMakeFiles/sidebarplugin.dir/sidebarplugin_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sidebarplugin.dir/sidebarplugin_autogen/mocs_compilation.cpp.s"
	cd /home/anna-lena/GUI_Cluster/appImage_Build_Dir/Sidebar && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anna-lena/GUI_Cluster/appImage_Build_Dir/Sidebar/sidebarplugin_autogen/mocs_compilation.cpp -o CMakeFiles/sidebarplugin.dir/sidebarplugin_autogen/mocs_compilation.cpp.s

Sidebar/CMakeFiles/sidebarplugin.dir/sidebarplugin_SidebarPlugin.cpp.o: Sidebar/CMakeFiles/sidebarplugin.dir/flags.make
Sidebar/CMakeFiles/sidebarplugin.dir/sidebarplugin_SidebarPlugin.cpp.o: Sidebar/sidebarplugin_SidebarPlugin.cpp
Sidebar/CMakeFiles/sidebarplugin.dir/sidebarplugin_SidebarPlugin.cpp.o: Sidebar/CMakeFiles/sidebarplugin.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/anna-lena/GUI_Cluster/appImage_Build_Dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object Sidebar/CMakeFiles/sidebarplugin.dir/sidebarplugin_SidebarPlugin.cpp.o"
	cd /home/anna-lena/GUI_Cluster/appImage_Build_Dir/Sidebar && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Sidebar/CMakeFiles/sidebarplugin.dir/sidebarplugin_SidebarPlugin.cpp.o -MF CMakeFiles/sidebarplugin.dir/sidebarplugin_SidebarPlugin.cpp.o.d -o CMakeFiles/sidebarplugin.dir/sidebarplugin_SidebarPlugin.cpp.o -c /home/anna-lena/GUI_Cluster/appImage_Build_Dir/Sidebar/sidebarplugin_SidebarPlugin.cpp

Sidebar/CMakeFiles/sidebarplugin.dir/sidebarplugin_SidebarPlugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sidebarplugin.dir/sidebarplugin_SidebarPlugin.cpp.i"
	cd /home/anna-lena/GUI_Cluster/appImage_Build_Dir/Sidebar && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anna-lena/GUI_Cluster/appImage_Build_Dir/Sidebar/sidebarplugin_SidebarPlugin.cpp > CMakeFiles/sidebarplugin.dir/sidebarplugin_SidebarPlugin.cpp.i

Sidebar/CMakeFiles/sidebarplugin.dir/sidebarplugin_SidebarPlugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sidebarplugin.dir/sidebarplugin_SidebarPlugin.cpp.s"
	cd /home/anna-lena/GUI_Cluster/appImage_Build_Dir/Sidebar && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anna-lena/GUI_Cluster/appImage_Build_Dir/Sidebar/sidebarplugin_SidebarPlugin.cpp -o CMakeFiles/sidebarplugin.dir/sidebarplugin_SidebarPlugin.cpp.s

# Object files for target sidebarplugin
sidebarplugin_OBJECTS = \
"CMakeFiles/sidebarplugin.dir/sidebarplugin_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/sidebarplugin.dir/sidebarplugin_SidebarPlugin.cpp.o"

# External object files for target sidebarplugin
sidebarplugin_EXTERNAL_OBJECTS =

/home/anna-lena/GUI_Cluster/Sidebar/libsidebarplugin.a: Sidebar/CMakeFiles/sidebarplugin.dir/sidebarplugin_autogen/mocs_compilation.cpp.o
/home/anna-lena/GUI_Cluster/Sidebar/libsidebarplugin.a: Sidebar/CMakeFiles/sidebarplugin.dir/sidebarplugin_SidebarPlugin.cpp.o
/home/anna-lena/GUI_Cluster/Sidebar/libsidebarplugin.a: Sidebar/CMakeFiles/sidebarplugin.dir/build.make
/home/anna-lena/GUI_Cluster/Sidebar/libsidebarplugin.a: Sidebar/CMakeFiles/sidebarplugin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/anna-lena/GUI_Cluster/appImage_Build_Dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library /home/anna-lena/GUI_Cluster/Sidebar/libsidebarplugin.a"
	cd /home/anna-lena/GUI_Cluster/appImage_Build_Dir/Sidebar && $(CMAKE_COMMAND) -P CMakeFiles/sidebarplugin.dir/cmake_clean_target.cmake
	cd /home/anna-lena/GUI_Cluster/appImage_Build_Dir/Sidebar && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sidebarplugin.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Sidebar/CMakeFiles/sidebarplugin.dir/build: /home/anna-lena/GUI_Cluster/Sidebar/libsidebarplugin.a
.PHONY : Sidebar/CMakeFiles/sidebarplugin.dir/build

Sidebar/CMakeFiles/sidebarplugin.dir/clean:
	cd /home/anna-lena/GUI_Cluster/appImage_Build_Dir/Sidebar && $(CMAKE_COMMAND) -P CMakeFiles/sidebarplugin.dir/cmake_clean.cmake
.PHONY : Sidebar/CMakeFiles/sidebarplugin.dir/clean

Sidebar/CMakeFiles/sidebarplugin.dir/depend: Sidebar/sidebarplugin_autogen/timestamp
	cd /home/anna-lena/GUI_Cluster/appImage_Build_Dir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anna-lena/GUI_Cluster /home/anna-lena/GUI_Cluster/Sidebar /home/anna-lena/GUI_Cluster/appImage_Build_Dir /home/anna-lena/GUI_Cluster/appImage_Build_Dir/Sidebar /home/anna-lena/GUI_Cluster/appImage_Build_Dir/Sidebar/CMakeFiles/sidebarplugin.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : Sidebar/CMakeFiles/sidebarplugin.dir/depend
