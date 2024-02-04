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
include examples/Point_set_2/CMakeFiles/nearest_neighbor.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/Point_set_2/CMakeFiles/nearest_neighbor.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/Point_set_2/CMakeFiles/nearest_neighbor.dir/progress.make

# Include the compile flags for this target's objects.
include examples/Point_set_2/CMakeFiles/nearest_neighbor.dir/flags.make

examples/Point_set_2/CMakeFiles/nearest_neighbor.dir/nearest_neighbor.cpp.o: examples/Point_set_2/CMakeFiles/nearest_neighbor.dir/flags.make
examples/Point_set_2/CMakeFiles/nearest_neighbor.dir/nearest_neighbor.cpp.o: ../Point_set_2/nearest_neighbor.cpp
examples/Point_set_2/CMakeFiles/nearest_neighbor.dir/nearest_neighbor.cpp.o: examples/Point_set_2/CMakeFiles/nearest_neighbor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/Point_set_2/CMakeFiles/nearest_neighbor.dir/nearest_neighbor.cpp.o"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Point_set_2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/Point_set_2/CMakeFiles/nearest_neighbor.dir/nearest_neighbor.cpp.o -MF CMakeFiles/nearest_neighbor.dir/nearest_neighbor.cpp.o.d -o CMakeFiles/nearest_neighbor.dir/nearest_neighbor.cpp.o -c /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Point_set_2/nearest_neighbor.cpp

examples/Point_set_2/CMakeFiles/nearest_neighbor.dir/nearest_neighbor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nearest_neighbor.dir/nearest_neighbor.cpp.i"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Point_set_2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Point_set_2/nearest_neighbor.cpp > CMakeFiles/nearest_neighbor.dir/nearest_neighbor.cpp.i

examples/Point_set_2/CMakeFiles/nearest_neighbor.dir/nearest_neighbor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nearest_neighbor.dir/nearest_neighbor.cpp.s"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Point_set_2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Point_set_2/nearest_neighbor.cpp -o CMakeFiles/nearest_neighbor.dir/nearest_neighbor.cpp.s

# Object files for target nearest_neighbor
nearest_neighbor_OBJECTS = \
"CMakeFiles/nearest_neighbor.dir/nearest_neighbor.cpp.o"

# External object files for target nearest_neighbor
nearest_neighbor_EXTERNAL_OBJECTS =

examples/Point_set_2/nearest_neighbor: examples/Point_set_2/CMakeFiles/nearest_neighbor.dir/nearest_neighbor.cpp.o
examples/Point_set_2/nearest_neighbor: examples/Point_set_2/CMakeFiles/nearest_neighbor.dir/build.make
examples/Point_set_2/nearest_neighbor: /usr/lib/x86_64-linux-gnu/libgmpxx.so
examples/Point_set_2/nearest_neighbor: /usr/lib/x86_64-linux-gnu/libmpfr.so
examples/Point_set_2/nearest_neighbor: /usr/lib/x86_64-linux-gnu/libgmp.so
examples/Point_set_2/nearest_neighbor: examples/Point_set_2/CMakeFiles/nearest_neighbor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable nearest_neighbor"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Point_set_2 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/nearest_neighbor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/Point_set_2/CMakeFiles/nearest_neighbor.dir/build: examples/Point_set_2/nearest_neighbor
.PHONY : examples/Point_set_2/CMakeFiles/nearest_neighbor.dir/build

examples/Point_set_2/CMakeFiles/nearest_neighbor.dir/clean:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Point_set_2 && $(CMAKE_COMMAND) -P CMakeFiles/nearest_neighbor.dir/cmake_clean.cmake
.PHONY : examples/Point_set_2/CMakeFiles/nearest_neighbor.dir/clean

examples/Point_set_2/CMakeFiles/nearest_neighbor.dir/depend:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/melina/dev/Geometry/vendor/CGAL-5.6/examples /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Point_set_2 /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Point_set_2 /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Point_set_2/CMakeFiles/nearest_neighbor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/Point_set_2/CMakeFiles/nearest_neighbor.dir/depend

