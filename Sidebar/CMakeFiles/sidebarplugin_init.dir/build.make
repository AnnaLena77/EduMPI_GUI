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
CMAKE_BINARY_DIR = /home/anna-lena/GUI_Cluster

# Include any dependencies generated for this target.
include Sidebar/CMakeFiles/sidebarplugin_init.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Sidebar/CMakeFiles/sidebarplugin_init.dir/compiler_depend.make

# Include the progress variables for this target.
include Sidebar/CMakeFiles/sidebarplugin_init.dir/progress.make

# Include the compile flags for this target's objects.
include Sidebar/CMakeFiles/sidebarplugin_init.dir/flags.make

Sidebar/meta_types/qt6sidebarplugin_init_metatypes.json.gen: /home/anna-lena/QtDesignStudio/6.8.1/gcc_64/libexec/moc
Sidebar/meta_types/qt6sidebarplugin_init_metatypes.json.gen: Sidebar/meta_types/sidebarplugin_init_json_file_list.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/anna-lena/GUI_Cluster/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Running moc --collect-json for target sidebarplugin_init"
	cd /home/anna-lena/GUI_Cluster/Sidebar && /home/anna-lena/QtDesignStudio/6.8.1/gcc_64/libexec/moc -o /home/anna-lena/GUI_Cluster/Sidebar/meta_types/qt6sidebarplugin_init_metatypes.json.gen --collect-json @/home/anna-lena/GUI_Cluster/Sidebar/meta_types/sidebarplugin_init_json_file_list.txt
	cd /home/anna-lena/GUI_Cluster/Sidebar && /home/anna-lena/QtDesignStudio/Tools/CMake/bin/cmake -E copy_if_different /home/anna-lena/GUI_Cluster/Sidebar/meta_types/qt6sidebarplugin_init_metatypes.json.gen /home/anna-lena/GUI_Cluster/Sidebar/meta_types/qt6sidebarplugin_init_metatypes.json

Sidebar/sidebarplugin_init_autogen/timestamp: /home/anna-lena/QtDesignStudio/6.8.1/gcc_64/libexec/moc
Sidebar/sidebarplugin_init_autogen/timestamp: Sidebar/CMakeFiles/sidebarplugin_init.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/anna-lena/GUI_Cluster/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Automatic MOC and UIC for target sidebarplugin_init"
	cd /home/anna-lena/GUI_Cluster/Sidebar && /home/anna-lena/QtDesignStudio/Tools/CMake/bin/cmake -E cmake_autogen /home/anna-lena/GUI_Cluster/Sidebar/CMakeFiles/sidebarplugin_init_autogen.dir/AutogenInfo.json ""
	cd /home/anna-lena/GUI_Cluster/Sidebar && /home/anna-lena/QtDesignStudio/Tools/CMake/bin/cmake -E touch /home/anna-lena/GUI_Cluster/Sidebar/sidebarplugin_init_autogen/timestamp

Sidebar/meta_types/sidebarplugin_init_json_file_list.txt: /home/anna-lena/QtDesignStudio/6.8.1/gcc_64/libexec/cmake_automoc_parser
Sidebar/meta_types/sidebarplugin_init_json_file_list.txt: Sidebar/sidebarplugin_init_autogen/timestamp
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/anna-lena/GUI_Cluster/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Running AUTOMOC file extraction for target sidebarplugin_init"
	cd /home/anna-lena/GUI_Cluster/Sidebar && /home/anna-lena/QtDesignStudio/6.8.1/gcc_64/libexec/cmake_automoc_parser --cmake-autogen-cache-file /home/anna-lena/GUI_Cluster/Sidebar/CMakeFiles/sidebarplugin_init_autogen.dir/ParseCache.txt --cmake-autogen-info-file /home/anna-lena/GUI_Cluster/Sidebar/CMakeFiles/sidebarplugin_init_autogen.dir/AutogenInfo.json --output-file-path /home/anna-lena/GUI_Cluster/Sidebar/meta_types/sidebarplugin_init_json_file_list.txt --timestamp-file-path /home/anna-lena/GUI_Cluster/Sidebar/meta_types/sidebarplugin_init_json_file_list.txt.timestamp --cmake-autogen-include-dir-path /home/anna-lena/GUI_Cluster/Sidebar/sidebarplugin_init_autogen/include

Sidebar/CMakeFiles/sidebarplugin_init.dir/sidebarplugin_init_autogen/mocs_compilation.cpp.o: Sidebar/CMakeFiles/sidebarplugin_init.dir/flags.make
Sidebar/CMakeFiles/sidebarplugin_init.dir/sidebarplugin_init_autogen/mocs_compilation.cpp.o: Sidebar/sidebarplugin_init_autogen/mocs_compilation.cpp
Sidebar/CMakeFiles/sidebarplugin_init.dir/sidebarplugin_init_autogen/mocs_compilation.cpp.o: Sidebar/CMakeFiles/sidebarplugin_init.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/anna-lena/GUI_Cluster/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object Sidebar/CMakeFiles/sidebarplugin_init.dir/sidebarplugin_init_autogen/mocs_compilation.cpp.o"
	cd /home/anna-lena/GUI_Cluster/Sidebar && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Sidebar/CMakeFiles/sidebarplugin_init.dir/sidebarplugin_init_autogen/mocs_compilation.cpp.o -MF CMakeFiles/sidebarplugin_init.dir/sidebarplugin_init_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/sidebarplugin_init.dir/sidebarplugin_init_autogen/mocs_compilation.cpp.o -c /home/anna-lena/GUI_Cluster/Sidebar/sidebarplugin_init_autogen/mocs_compilation.cpp

Sidebar/CMakeFiles/sidebarplugin_init.dir/sidebarplugin_init_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sidebarplugin_init.dir/sidebarplugin_init_autogen/mocs_compilation.cpp.i"
	cd /home/anna-lena/GUI_Cluster/Sidebar && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anna-lena/GUI_Cluster/Sidebar/sidebarplugin_init_autogen/mocs_compilation.cpp > CMakeFiles/sidebarplugin_init.dir/sidebarplugin_init_autogen/mocs_compilation.cpp.i

Sidebar/CMakeFiles/sidebarplugin_init.dir/sidebarplugin_init_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sidebarplugin_init.dir/sidebarplugin_init_autogen/mocs_compilation.cpp.s"
	cd /home/anna-lena/GUI_Cluster/Sidebar && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anna-lena/GUI_Cluster/Sidebar/sidebarplugin_init_autogen/mocs_compilation.cpp -o CMakeFiles/sidebarplugin_init.dir/sidebarplugin_init_autogen/mocs_compilation.cpp.s

Sidebar/CMakeFiles/sidebarplugin_init.dir/sidebarplugin_init.cpp.o: Sidebar/CMakeFiles/sidebarplugin_init.dir/flags.make
Sidebar/CMakeFiles/sidebarplugin_init.dir/sidebarplugin_init.cpp.o: Sidebar/sidebarplugin_init.cpp
Sidebar/CMakeFiles/sidebarplugin_init.dir/sidebarplugin_init.cpp.o: Sidebar/CMakeFiles/sidebarplugin_init.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/anna-lena/GUI_Cluster/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object Sidebar/CMakeFiles/sidebarplugin_init.dir/sidebarplugin_init.cpp.o"
	cd /home/anna-lena/GUI_Cluster/Sidebar && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Sidebar/CMakeFiles/sidebarplugin_init.dir/sidebarplugin_init.cpp.o -MF CMakeFiles/sidebarplugin_init.dir/sidebarplugin_init.cpp.o.d -o CMakeFiles/sidebarplugin_init.dir/sidebarplugin_init.cpp.o -c /home/anna-lena/GUI_Cluster/Sidebar/sidebarplugin_init.cpp

Sidebar/CMakeFiles/sidebarplugin_init.dir/sidebarplugin_init.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sidebarplugin_init.dir/sidebarplugin_init.cpp.i"
	cd /home/anna-lena/GUI_Cluster/Sidebar && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anna-lena/GUI_Cluster/Sidebar/sidebarplugin_init.cpp > CMakeFiles/sidebarplugin_init.dir/sidebarplugin_init.cpp.i

Sidebar/CMakeFiles/sidebarplugin_init.dir/sidebarplugin_init.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sidebarplugin_init.dir/sidebarplugin_init.cpp.s"
	cd /home/anna-lena/GUI_Cluster/Sidebar && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anna-lena/GUI_Cluster/Sidebar/sidebarplugin_init.cpp -o CMakeFiles/sidebarplugin_init.dir/sidebarplugin_init.cpp.s

sidebarplugin_init: Sidebar/CMakeFiles/sidebarplugin_init.dir/sidebarplugin_init_autogen/mocs_compilation.cpp.o
sidebarplugin_init: Sidebar/CMakeFiles/sidebarplugin_init.dir/sidebarplugin_init.cpp.o
sidebarplugin_init: Sidebar/CMakeFiles/sidebarplugin_init.dir/build.make
.PHONY : sidebarplugin_init

# Rule to build all files generated by this target.
Sidebar/CMakeFiles/sidebarplugin_init.dir/build: sidebarplugin_init
.PHONY : Sidebar/CMakeFiles/sidebarplugin_init.dir/build

Sidebar/CMakeFiles/sidebarplugin_init.dir/clean:
	cd /home/anna-lena/GUI_Cluster/Sidebar && $(CMAKE_COMMAND) -P CMakeFiles/sidebarplugin_init.dir/cmake_clean.cmake
.PHONY : Sidebar/CMakeFiles/sidebarplugin_init.dir/clean

Sidebar/CMakeFiles/sidebarplugin_init.dir/depend: Sidebar/meta_types/qt6sidebarplugin_init_metatypes.json.gen
Sidebar/CMakeFiles/sidebarplugin_init.dir/depend: Sidebar/meta_types/sidebarplugin_init_json_file_list.txt
Sidebar/CMakeFiles/sidebarplugin_init.dir/depend: Sidebar/sidebarplugin_init_autogen/timestamp
	cd /home/anna-lena/GUI_Cluster && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anna-lena/GUI_Cluster /home/anna-lena/GUI_Cluster/Sidebar /home/anna-lena/GUI_Cluster /home/anna-lena/GUI_Cluster/Sidebar /home/anna-lena/GUI_Cluster/Sidebar/CMakeFiles/sidebarplugin_init.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : Sidebar/CMakeFiles/sidebarplugin_init.dir/depend
