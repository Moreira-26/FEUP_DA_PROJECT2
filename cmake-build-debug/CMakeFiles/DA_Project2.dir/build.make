# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/hugogomes/FEUP/DA/projeto2/DA_Project2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/hugogomes/FEUP/DA/projeto2/DA_Project2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DA_Project2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/DA_Project2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/DA_Project2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DA_Project2.dir/flags.make

CMakeFiles/DA_Project2.dir/main.cpp.o: CMakeFiles/DA_Project2.dir/flags.make
CMakeFiles/DA_Project2.dir/main.cpp.o: ../main.cpp
CMakeFiles/DA_Project2.dir/main.cpp.o: CMakeFiles/DA_Project2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hugogomes/FEUP/DA/projeto2/DA_Project2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DA_Project2.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DA_Project2.dir/main.cpp.o -MF CMakeFiles/DA_Project2.dir/main.cpp.o.d -o CMakeFiles/DA_Project2.dir/main.cpp.o -c /Users/hugogomes/FEUP/DA/projeto2/DA_Project2/main.cpp

CMakeFiles/DA_Project2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DA_Project2.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hugogomes/FEUP/DA/projeto2/DA_Project2/main.cpp > CMakeFiles/DA_Project2.dir/main.cpp.i

CMakeFiles/DA_Project2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DA_Project2.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hugogomes/FEUP/DA/projeto2/DA_Project2/main.cpp -o CMakeFiles/DA_Project2.dir/main.cpp.s

CMakeFiles/DA_Project2.dir/graph.cpp.o: CMakeFiles/DA_Project2.dir/flags.make
CMakeFiles/DA_Project2.dir/graph.cpp.o: ../graph.cpp
CMakeFiles/DA_Project2.dir/graph.cpp.o: CMakeFiles/DA_Project2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hugogomes/FEUP/DA/projeto2/DA_Project2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DA_Project2.dir/graph.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DA_Project2.dir/graph.cpp.o -MF CMakeFiles/DA_Project2.dir/graph.cpp.o.d -o CMakeFiles/DA_Project2.dir/graph.cpp.o -c /Users/hugogomes/FEUP/DA/projeto2/DA_Project2/graph.cpp

CMakeFiles/DA_Project2.dir/graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DA_Project2.dir/graph.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hugogomes/FEUP/DA/projeto2/DA_Project2/graph.cpp > CMakeFiles/DA_Project2.dir/graph.cpp.i

CMakeFiles/DA_Project2.dir/graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DA_Project2.dir/graph.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hugogomes/FEUP/DA/projeto2/DA_Project2/graph.cpp -o CMakeFiles/DA_Project2.dir/graph.cpp.s

CMakeFiles/DA_Project2.dir/load.cpp.o: CMakeFiles/DA_Project2.dir/flags.make
CMakeFiles/DA_Project2.dir/load.cpp.o: ../load.cpp
CMakeFiles/DA_Project2.dir/load.cpp.o: CMakeFiles/DA_Project2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hugogomes/FEUP/DA/projeto2/DA_Project2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/DA_Project2.dir/load.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DA_Project2.dir/load.cpp.o -MF CMakeFiles/DA_Project2.dir/load.cpp.o.d -o CMakeFiles/DA_Project2.dir/load.cpp.o -c /Users/hugogomes/FEUP/DA/projeto2/DA_Project2/load.cpp

CMakeFiles/DA_Project2.dir/load.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DA_Project2.dir/load.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hugogomes/FEUP/DA/projeto2/DA_Project2/load.cpp > CMakeFiles/DA_Project2.dir/load.cpp.i

CMakeFiles/DA_Project2.dir/load.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DA_Project2.dir/load.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hugogomes/FEUP/DA/projeto2/DA_Project2/load.cpp -o CMakeFiles/DA_Project2.dir/load.cpp.s

CMakeFiles/DA_Project2.dir/menus.cpp.o: CMakeFiles/DA_Project2.dir/flags.make
CMakeFiles/DA_Project2.dir/menus.cpp.o: ../menus.cpp
CMakeFiles/DA_Project2.dir/menus.cpp.o: CMakeFiles/DA_Project2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hugogomes/FEUP/DA/projeto2/DA_Project2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/DA_Project2.dir/menus.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DA_Project2.dir/menus.cpp.o -MF CMakeFiles/DA_Project2.dir/menus.cpp.o.d -o CMakeFiles/DA_Project2.dir/menus.cpp.o -c /Users/hugogomes/FEUP/DA/projeto2/DA_Project2/menus.cpp

CMakeFiles/DA_Project2.dir/menus.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DA_Project2.dir/menus.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hugogomes/FEUP/DA/projeto2/DA_Project2/menus.cpp > CMakeFiles/DA_Project2.dir/menus.cpp.i

CMakeFiles/DA_Project2.dir/menus.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DA_Project2.dir/menus.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hugogomes/FEUP/DA/projeto2/DA_Project2/menus.cpp -o CMakeFiles/DA_Project2.dir/menus.cpp.s

# Object files for target DA_Project2
DA_Project2_OBJECTS = \
"CMakeFiles/DA_Project2.dir/main.cpp.o" \
"CMakeFiles/DA_Project2.dir/graph.cpp.o" \
"CMakeFiles/DA_Project2.dir/load.cpp.o" \
"CMakeFiles/DA_Project2.dir/menus.cpp.o"

# External object files for target DA_Project2
DA_Project2_EXTERNAL_OBJECTS =

DA_Project2: CMakeFiles/DA_Project2.dir/main.cpp.o
DA_Project2: CMakeFiles/DA_Project2.dir/graph.cpp.o
DA_Project2: CMakeFiles/DA_Project2.dir/load.cpp.o
DA_Project2: CMakeFiles/DA_Project2.dir/menus.cpp.o
DA_Project2: CMakeFiles/DA_Project2.dir/build.make
DA_Project2: CMakeFiles/DA_Project2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/hugogomes/FEUP/DA/projeto2/DA_Project2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable DA_Project2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DA_Project2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DA_Project2.dir/build: DA_Project2
.PHONY : CMakeFiles/DA_Project2.dir/build

CMakeFiles/DA_Project2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DA_Project2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DA_Project2.dir/clean

CMakeFiles/DA_Project2.dir/depend:
	cd /Users/hugogomes/FEUP/DA/projeto2/DA_Project2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/hugogomes/FEUP/DA/projeto2/DA_Project2 /Users/hugogomes/FEUP/DA/projeto2/DA_Project2 /Users/hugogomes/FEUP/DA/projeto2/DA_Project2/cmake-build-debug /Users/hugogomes/FEUP/DA/projeto2/DA_Project2/cmake-build-debug /Users/hugogomes/FEUP/DA/projeto2/DA_Project2/cmake-build-debug/CMakeFiles/DA_Project2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DA_Project2.dir/depend

