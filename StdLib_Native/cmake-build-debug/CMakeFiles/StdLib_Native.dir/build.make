# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /williamye/program/antlr/erable/StdLib_Native

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /williamye/program/antlr/erable/StdLib_Native/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/StdLib_Native.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/StdLib_Native.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/StdLib_Native.dir/flags.make

CMakeFiles/StdLib_Native.dir/IOS.cpp.o: CMakeFiles/StdLib_Native.dir/flags.make
CMakeFiles/StdLib_Native.dir/IOS.cpp.o: ../IOS.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/williamye/program/antlr/erable/StdLib_Native/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/StdLib_Native.dir/IOS.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/StdLib_Native.dir/IOS.cpp.o -c /williamye/program/antlr/erable/StdLib_Native/IOS.cpp

CMakeFiles/StdLib_Native.dir/IOS.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StdLib_Native.dir/IOS.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /williamye/program/antlr/erable/StdLib_Native/IOS.cpp > CMakeFiles/StdLib_Native.dir/IOS.cpp.i

CMakeFiles/StdLib_Native.dir/IOS.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StdLib_Native.dir/IOS.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /williamye/program/antlr/erable/StdLib_Native/IOS.cpp -o CMakeFiles/StdLib_Native.dir/IOS.cpp.s

# Object files for target StdLib_Native
StdLib_Native_OBJECTS = \
"CMakeFiles/StdLib_Native.dir/IOS.cpp.o"

# External object files for target StdLib_Native
StdLib_Native_EXTERNAL_OBJECTS =

libStdLib_Native.dylib: CMakeFiles/StdLib_Native.dir/IOS.cpp.o
libStdLib_Native.dylib: CMakeFiles/StdLib_Native.dir/build.make
libStdLib_Native.dylib: CMakeFiles/StdLib_Native.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/williamye/program/antlr/erable/StdLib_Native/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libStdLib_Native.dylib"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/StdLib_Native.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/StdLib_Native.dir/build: libStdLib_Native.dylib

.PHONY : CMakeFiles/StdLib_Native.dir/build

CMakeFiles/StdLib_Native.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/StdLib_Native.dir/cmake_clean.cmake
.PHONY : CMakeFiles/StdLib_Native.dir/clean

CMakeFiles/StdLib_Native.dir/depend:
	cd /williamye/program/antlr/erable/StdLib_Native/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /williamye/program/antlr/erable/StdLib_Native /williamye/program/antlr/erable/StdLib_Native /williamye/program/antlr/erable/StdLib_Native/cmake-build-debug /williamye/program/antlr/erable/StdLib_Native/cmake-build-debug /williamye/program/antlr/erable/StdLib_Native/cmake-build-debug/CMakeFiles/StdLib_Native.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/StdLib_Native.dir/depend

