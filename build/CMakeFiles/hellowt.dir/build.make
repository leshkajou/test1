# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/user/ws/test1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/ws/test1/build

# Include any dependencies generated for this target.
include CMakeFiles/hellowt.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hellowt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hellowt.dir/flags.make

CMakeFiles/hellowt.dir/main.cpp.o: CMakeFiles/hellowt.dir/flags.make
CMakeFiles/hellowt.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/ws/test1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hellowt.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hellowt.dir/main.cpp.o -c /home/user/ws/test1/main.cpp

CMakeFiles/hellowt.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hellowt.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/ws/test1/main.cpp > CMakeFiles/hellowt.dir/main.cpp.i

CMakeFiles/hellowt.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hellowt.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/ws/test1/main.cpp -o CMakeFiles/hellowt.dir/main.cpp.s

CMakeFiles/hellowt.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/hellowt.dir/main.cpp.o.requires

CMakeFiles/hellowt.dir/main.cpp.o.provides: CMakeFiles/hellowt.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/hellowt.dir/build.make CMakeFiles/hellowt.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/hellowt.dir/main.cpp.o.provides

CMakeFiles/hellowt.dir/main.cpp.o.provides.build: CMakeFiles/hellowt.dir/main.cpp.o


# Object files for target hellowt
hellowt_OBJECTS = \
"CMakeFiles/hellowt.dir/main.cpp.o"

# External object files for target hellowt
hellowt_EXTERNAL_OBJECTS =

hellowt: CMakeFiles/hellowt.dir/main.cpp.o
hellowt: CMakeFiles/hellowt.dir/build.make
hellowt: /usr/lib/x86_64-linux-gnu/libboost_system.so
hellowt: /usr/lib/x86_64-linux-gnu/libboost_thread.so
hellowt: /usr/lib/x86_64-linux-gnu/libboost_signals.so
hellowt: CMakeFiles/hellowt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/ws/test1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hellowt"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hellowt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hellowt.dir/build: hellowt

.PHONY : CMakeFiles/hellowt.dir/build

CMakeFiles/hellowt.dir/requires: CMakeFiles/hellowt.dir/main.cpp.o.requires

.PHONY : CMakeFiles/hellowt.dir/requires

CMakeFiles/hellowt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hellowt.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hellowt.dir/clean

CMakeFiles/hellowt.dir/depend:
	cd /home/user/ws/test1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/ws/test1 /home/user/ws/test1 /home/user/ws/test1/build /home/user/ws/test1/build /home/user/ws/test1/build/CMakeFiles/hellowt.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hellowt.dir/depend

