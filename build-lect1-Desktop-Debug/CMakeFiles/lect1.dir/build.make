# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/user5063/lect1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user5063/build-lect1-Desktop-Debug

# Include any dependencies generated for this target.
include CMakeFiles/lect1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lect1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lect1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lect1.dir/flags.make

CMakeFiles/lect1.dir/lect1_autogen/mocs_compilation.cpp.o: CMakeFiles/lect1.dir/flags.make
CMakeFiles/lect1.dir/lect1_autogen/mocs_compilation.cpp.o: lect1_autogen/mocs_compilation.cpp
CMakeFiles/lect1.dir/lect1_autogen/mocs_compilation.cpp.o: CMakeFiles/lect1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/user5063/build-lect1-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lect1.dir/lect1_autogen/mocs_compilation.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lect1.dir/lect1_autogen/mocs_compilation.cpp.o -MF CMakeFiles/lect1.dir/lect1_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/lect1.dir/lect1_autogen/mocs_compilation.cpp.o -c /home/user5063/build-lect1-Desktop-Debug/lect1_autogen/mocs_compilation.cpp

CMakeFiles/lect1.dir/lect1_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lect1.dir/lect1_autogen/mocs_compilation.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user5063/build-lect1-Desktop-Debug/lect1_autogen/mocs_compilation.cpp > CMakeFiles/lect1.dir/lect1_autogen/mocs_compilation.cpp.i

CMakeFiles/lect1.dir/lect1_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lect1.dir/lect1_autogen/mocs_compilation.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user5063/build-lect1-Desktop-Debug/lect1_autogen/mocs_compilation.cpp -o CMakeFiles/lect1.dir/lect1_autogen/mocs_compilation.cpp.s

CMakeFiles/lect1.dir/main.cpp.o: CMakeFiles/lect1.dir/flags.make
CMakeFiles/lect1.dir/main.cpp.o: /home/user5063/lect1/main.cpp
CMakeFiles/lect1.dir/main.cpp.o: CMakeFiles/lect1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/user5063/build-lect1-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lect1.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lect1.dir/main.cpp.o -MF CMakeFiles/lect1.dir/main.cpp.o.d -o CMakeFiles/lect1.dir/main.cpp.o -c /home/user5063/lect1/main.cpp

CMakeFiles/lect1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lect1.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user5063/lect1/main.cpp > CMakeFiles/lect1.dir/main.cpp.i

CMakeFiles/lect1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lect1.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user5063/lect1/main.cpp -o CMakeFiles/lect1.dir/main.cpp.s

CMakeFiles/lect1.dir/mainwindow.cpp.o: CMakeFiles/lect1.dir/flags.make
CMakeFiles/lect1.dir/mainwindow.cpp.o: /home/user5063/lect1/mainwindow.cpp
CMakeFiles/lect1.dir/mainwindow.cpp.o: CMakeFiles/lect1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/user5063/build-lect1-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/lect1.dir/mainwindow.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lect1.dir/mainwindow.cpp.o -MF CMakeFiles/lect1.dir/mainwindow.cpp.o.d -o CMakeFiles/lect1.dir/mainwindow.cpp.o -c /home/user5063/lect1/mainwindow.cpp

CMakeFiles/lect1.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lect1.dir/mainwindow.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user5063/lect1/mainwindow.cpp > CMakeFiles/lect1.dir/mainwindow.cpp.i

CMakeFiles/lect1.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lect1.dir/mainwindow.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user5063/lect1/mainwindow.cpp -o CMakeFiles/lect1.dir/mainwindow.cpp.s

# Object files for target lect1
lect1_OBJECTS = \
"CMakeFiles/lect1.dir/lect1_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/lect1.dir/main.cpp.o" \
"CMakeFiles/lect1.dir/mainwindow.cpp.o"

# External object files for target lect1
lect1_EXTERNAL_OBJECTS =

lect1: CMakeFiles/lect1.dir/lect1_autogen/mocs_compilation.cpp.o
lect1: CMakeFiles/lect1.dir/main.cpp.o
lect1: CMakeFiles/lect1.dir/mainwindow.cpp.o
lect1: CMakeFiles/lect1.dir/build.make
lect1: /usr/lib64/libQt5Widgets.so.5.15.11
lect1: /usr/lib64/libQt5Gui.so.5.15.11
lect1: /usr/lib64/libQt5Core.so.5.15.11
lect1: CMakeFiles/lect1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/user5063/build-lect1-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable lect1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lect1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lect1.dir/build: lect1
.PHONY : CMakeFiles/lect1.dir/build

CMakeFiles/lect1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lect1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lect1.dir/clean

CMakeFiles/lect1.dir/depend:
	cd /home/user5063/build-lect1-Desktop-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user5063/lect1 /home/user5063/lect1 /home/user5063/build-lect1-Desktop-Debug /home/user5063/build-lect1-Desktop-Debug /home/user5063/build-lect1-Desktop-Debug/CMakeFiles/lect1.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/lect1.dir/depend

