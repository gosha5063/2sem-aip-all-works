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
CMAKE_SOURCE_DIR = /home/user5063/study/calcDialog

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user5063/study/build-calcDialog-Desktop-Release

# Include any dependencies generated for this target.
include CMakeFiles/calcDialog.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/calcDialog.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/calcDialog.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/calcDialog.dir/flags.make

CMakeFiles/calcDialog.dir/calcDialog_autogen/mocs_compilation.cpp.o: CMakeFiles/calcDialog.dir/flags.make
CMakeFiles/calcDialog.dir/calcDialog_autogen/mocs_compilation.cpp.o: calcDialog_autogen/mocs_compilation.cpp
CMakeFiles/calcDialog.dir/calcDialog_autogen/mocs_compilation.cpp.o: CMakeFiles/calcDialog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/user5063/study/build-calcDialog-Desktop-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/calcDialog.dir/calcDialog_autogen/mocs_compilation.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/calcDialog.dir/calcDialog_autogen/mocs_compilation.cpp.o -MF CMakeFiles/calcDialog.dir/calcDialog_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/calcDialog.dir/calcDialog_autogen/mocs_compilation.cpp.o -c /home/user5063/study/build-calcDialog-Desktop-Release/calcDialog_autogen/mocs_compilation.cpp

CMakeFiles/calcDialog.dir/calcDialog_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/calcDialog.dir/calcDialog_autogen/mocs_compilation.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user5063/study/build-calcDialog-Desktop-Release/calcDialog_autogen/mocs_compilation.cpp > CMakeFiles/calcDialog.dir/calcDialog_autogen/mocs_compilation.cpp.i

CMakeFiles/calcDialog.dir/calcDialog_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/calcDialog.dir/calcDialog_autogen/mocs_compilation.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user5063/study/build-calcDialog-Desktop-Release/calcDialog_autogen/mocs_compilation.cpp -o CMakeFiles/calcDialog.dir/calcDialog_autogen/mocs_compilation.cpp.s

CMakeFiles/calcDialog.dir/main.cpp.o: CMakeFiles/calcDialog.dir/flags.make
CMakeFiles/calcDialog.dir/main.cpp.o: /home/user5063/study/calcDialog/main.cpp
CMakeFiles/calcDialog.dir/main.cpp.o: CMakeFiles/calcDialog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/user5063/study/build-calcDialog-Desktop-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/calcDialog.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/calcDialog.dir/main.cpp.o -MF CMakeFiles/calcDialog.dir/main.cpp.o.d -o CMakeFiles/calcDialog.dir/main.cpp.o -c /home/user5063/study/calcDialog/main.cpp

CMakeFiles/calcDialog.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/calcDialog.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user5063/study/calcDialog/main.cpp > CMakeFiles/calcDialog.dir/main.cpp.i

CMakeFiles/calcDialog.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/calcDialog.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user5063/study/calcDialog/main.cpp -o CMakeFiles/calcDialog.dir/main.cpp.s

CMakeFiles/calcDialog.dir/calcdialog.cpp.o: CMakeFiles/calcDialog.dir/flags.make
CMakeFiles/calcDialog.dir/calcdialog.cpp.o: /home/user5063/study/calcDialog/calcdialog.cpp
CMakeFiles/calcDialog.dir/calcdialog.cpp.o: CMakeFiles/calcDialog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/user5063/study/build-calcDialog-Desktop-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/calcDialog.dir/calcdialog.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/calcDialog.dir/calcdialog.cpp.o -MF CMakeFiles/calcDialog.dir/calcdialog.cpp.o.d -o CMakeFiles/calcDialog.dir/calcdialog.cpp.o -c /home/user5063/study/calcDialog/calcdialog.cpp

CMakeFiles/calcDialog.dir/calcdialog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/calcDialog.dir/calcdialog.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user5063/study/calcDialog/calcdialog.cpp > CMakeFiles/calcDialog.dir/calcdialog.cpp.i

CMakeFiles/calcDialog.dir/calcdialog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/calcDialog.dir/calcdialog.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user5063/study/calcDialog/calcdialog.cpp -o CMakeFiles/calcDialog.dir/calcdialog.cpp.s

# Object files for target calcDialog
calcDialog_OBJECTS = \
"CMakeFiles/calcDialog.dir/calcDialog_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/calcDialog.dir/main.cpp.o" \
"CMakeFiles/calcDialog.dir/calcdialog.cpp.o"

# External object files for target calcDialog
calcDialog_EXTERNAL_OBJECTS =

calcDialog: CMakeFiles/calcDialog.dir/calcDialog_autogen/mocs_compilation.cpp.o
calcDialog: CMakeFiles/calcDialog.dir/main.cpp.o
calcDialog: CMakeFiles/calcDialog.dir/calcdialog.cpp.o
calcDialog: CMakeFiles/calcDialog.dir/build.make
calcDialog: /usr/lib64/libQt5Widgets.so.5.15.12
calcDialog: /usr/lib64/libQt5Gui.so.5.15.12
calcDialog: /usr/lib64/libQt5Core.so.5.15.12
calcDialog: CMakeFiles/calcDialog.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/user5063/study/build-calcDialog-Desktop-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable calcDialog"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/calcDialog.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/calcDialog.dir/build: calcDialog
.PHONY : CMakeFiles/calcDialog.dir/build

CMakeFiles/calcDialog.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/calcDialog.dir/cmake_clean.cmake
.PHONY : CMakeFiles/calcDialog.dir/clean

CMakeFiles/calcDialog.dir/depend:
	cd /home/user5063/study/build-calcDialog-Desktop-Release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user5063/study/calcDialog /home/user5063/study/calcDialog /home/user5063/study/build-calcDialog-Desktop-Release /home/user5063/study/build-calcDialog-Desktop-Release /home/user5063/study/build-calcDialog-Desktop-Release/CMakeFiles/calcDialog.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/calcDialog.dir/depend

