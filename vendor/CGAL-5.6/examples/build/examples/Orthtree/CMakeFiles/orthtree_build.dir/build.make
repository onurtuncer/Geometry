# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/melina/dev/Geometry/vendor/CGAL-5.6/examples

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build

# Include any dependencies generated for this target.
include examples/Orthtree/CMakeFiles/orthtree_build.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/Orthtree/CMakeFiles/orthtree_build.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/Orthtree/CMakeFiles/orthtree_build.dir/progress.make

# Include the compile flags for this target's objects.
include examples/Orthtree/CMakeFiles/orthtree_build.dir/flags.make

examples/Orthtree/CMakeFiles/orthtree_build.dir/orthtree_build.cpp.o: examples/Orthtree/CMakeFiles/orthtree_build.dir/flags.make
examples/Orthtree/CMakeFiles/orthtree_build.dir/orthtree_build.cpp.o: ../Orthtree/orthtree_build.cpp
examples/Orthtree/CMakeFiles/orthtree_build.dir/orthtree_build.cpp.o: examples/Orthtree/CMakeFiles/orthtree_build.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/Orthtree/CMakeFiles/orthtree_build.dir/orthtree_build.cpp.o"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Orthtree && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/Orthtree/CMakeFiles/orthtree_build.dir/orthtree_build.cpp.o -MF CMakeFiles/orthtree_build.dir/orthtree_build.cpp.o.d -o CMakeFiles/orthtree_build.dir/orthtree_build.cpp.o -c /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Orthtree/orthtree_build.cpp

examples/Orthtree/CMakeFiles/orthtree_build.dir/orthtree_build.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/orthtree_build.dir/orthtree_build.cpp.i"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Orthtree && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Orthtree/orthtree_build.cpp > CMakeFiles/orthtree_build.dir/orthtree_build.cpp.i

examples/Orthtree/CMakeFiles/orthtree_build.dir/orthtree_build.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/orthtree_build.dir/orthtree_build.cpp.s"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Orthtree && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Orthtree/orthtree_build.cpp -o CMakeFiles/orthtree_build.dir/orthtree_build.cpp.s

# Object files for target orthtree_build
orthtree_build_OBJECTS = \
"CMakeFiles/orthtree_build.dir/orthtree_build.cpp.o"

# External object files for target orthtree_build
orthtree_build_EXTERNAL_OBJECTS =

examples/Orthtree/orthtree_build: examples/Orthtree/CMakeFiles/orthtree_build.dir/orthtree_build.cpp.o
examples/Orthtree/orthtree_build: examples/Orthtree/CMakeFiles/orthtree_build.dir/build.make
examples/Orthtree/orthtree_build: /usr/lib/x86_64-linux-gnu/libgmpxx.so
examples/Orthtree/orthtree_build: /usr/lib/x86_64-linux-gnu/libmpfr.so
examples/Orthtree/orthtree_build: /usr/lib/x86_64-linux-gnu/libgmp.so
examples/Orthtree/orthtree_build: examples/Orthtree/CMakeFiles/orthtree_build.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable orthtree_build"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Orthtree && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/orthtree_build.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/Orthtree/CMakeFiles/orthtree_build.dir/build: examples/Orthtree/orthtree_build
.PHONY : examples/Orthtree/CMakeFiles/orthtree_build.dir/build

examples/Orthtree/CMakeFiles/orthtree_build.dir/clean:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Orthtree && $(CMAKE_COMMAND) -P CMakeFiles/orthtree_build.dir/cmake_clean.cmake
.PHONY : examples/Orthtree/CMakeFiles/orthtree_build.dir/clean

examples/Orthtree/CMakeFiles/orthtree_build.dir/depend:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/melina/dev/Geometry/vendor/CGAL-5.6/examples /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Orthtree /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Orthtree /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Orthtree/CMakeFiles/orthtree_build.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/Orthtree/CMakeFiles/orthtree_build.dir/depend

