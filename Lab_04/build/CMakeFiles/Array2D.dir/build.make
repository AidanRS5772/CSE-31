# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/aidansgarlato/Programing/CSE-31/Lab_04

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/aidansgarlato/Programing/CSE-31/Lab_04/build

# Include any dependencies generated for this target.
include CMakeFiles/Array2D.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Array2D.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Array2D.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Array2D.dir/flags.make

CMakeFiles/Array2D.dir/Array2D.c.o: CMakeFiles/Array2D.dir/flags.make
CMakeFiles/Array2D.dir/Array2D.c.o: /Users/aidansgarlato/Programing/CSE-31/Lab_04/Array2D.c
CMakeFiles/Array2D.dir/Array2D.c.o: CMakeFiles/Array2D.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/aidansgarlato/Programing/CSE-31/Lab_04/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Array2D.dir/Array2D.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Array2D.dir/Array2D.c.o -MF CMakeFiles/Array2D.dir/Array2D.c.o.d -o CMakeFiles/Array2D.dir/Array2D.c.o -c /Users/aidansgarlato/Programing/CSE-31/Lab_04/Array2D.c

CMakeFiles/Array2D.dir/Array2D.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Array2D.dir/Array2D.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/aidansgarlato/Programing/CSE-31/Lab_04/Array2D.c > CMakeFiles/Array2D.dir/Array2D.c.i

CMakeFiles/Array2D.dir/Array2D.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Array2D.dir/Array2D.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/aidansgarlato/Programing/CSE-31/Lab_04/Array2D.c -o CMakeFiles/Array2D.dir/Array2D.c.s

# Object files for target Array2D
Array2D_OBJECTS = \
"CMakeFiles/Array2D.dir/Array2D.c.o"

# External object files for target Array2D
Array2D_EXTERNAL_OBJECTS =

bin/Array2D: CMakeFiles/Array2D.dir/Array2D.c.o
bin/Array2D: CMakeFiles/Array2D.dir/build.make
bin/Array2D: CMakeFiles/Array2D.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/aidansgarlato/Programing/CSE-31/Lab_04/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable bin/Array2D"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Array2D.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Array2D.dir/build: bin/Array2D
.PHONY : CMakeFiles/Array2D.dir/build

CMakeFiles/Array2D.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Array2D.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Array2D.dir/clean

CMakeFiles/Array2D.dir/depend:
	cd /Users/aidansgarlato/Programing/CSE-31/Lab_04/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/aidansgarlato/Programing/CSE-31/Lab_04 /Users/aidansgarlato/Programing/CSE-31/Lab_04 /Users/aidansgarlato/Programing/CSE-31/Lab_04/build /Users/aidansgarlato/Programing/CSE-31/Lab_04/build /Users/aidansgarlato/Programing/CSE-31/Lab_04/build/CMakeFiles/Array2D.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Array2D.dir/depend

