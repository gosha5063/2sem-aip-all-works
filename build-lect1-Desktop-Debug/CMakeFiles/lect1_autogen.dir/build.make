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

# Utility rule file for lect1_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/lect1_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lect1_autogen.dir/progress.make

CMakeFiles/lect1_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/user5063/build-lect1-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target lect1"
	/usr/bin/cmake -E cmake_autogen /home/user5063/build-lect1-Desktop-Debug/CMakeFiles/lect1_autogen.dir/AutogenInfo.json Debug

lect1_autogen: CMakeFiles/lect1_autogen
lect1_autogen: CMakeFiles/lect1_autogen.dir/build.make
.PHONY : lect1_autogen

# Rule to build all files generated by this target.
CMakeFiles/lect1_autogen.dir/build: lect1_autogen
.PHONY : CMakeFiles/lect1_autogen.dir/build

CMakeFiles/lect1_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lect1_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lect1_autogen.dir/clean

CMakeFiles/lect1_autogen.dir/depend:
	cd /home/user5063/build-lect1-Desktop-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user5063/lect1 /home/user5063/lect1 /home/user5063/build-lect1-Desktop-Debug /home/user5063/build-lect1-Desktop-Debug /home/user5063/build-lect1-Desktop-Debug/CMakeFiles/lect1_autogen.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/lect1_autogen.dir/depend

