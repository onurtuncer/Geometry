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
include examples/Polygon_mesh_processing/CMakeFiles/locate_example.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/Polygon_mesh_processing/CMakeFiles/locate_example.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/Polygon_mesh_processing/CMakeFiles/locate_example.dir/progress.make

# Include the compile flags for this target's objects.
include examples/Polygon_mesh_processing/CMakeFiles/locate_example.dir/flags.make

examples/Polygon_mesh_processing/CMakeFiles/locate_example.dir/locate_example.cpp.o: examples/Polygon_mesh_processing/CMakeFiles/locate_example.dir/flags.make
examples/Polygon_mesh_processing/CMakeFiles/locate_example.dir/locate_example.cpp.o: ../Polygon_mesh_processing/locate_example.cpp
examples/Polygon_mesh_processing/CMakeFiles/locate_example.dir/locate_example.cpp.o: examples/Polygon_mesh_processing/CMakeFiles/locate_example.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/Polygon_mesh_processing/CMakeFiles/locate_example.dir/locate_example.cpp.o"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Polygon_mesh_processing && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/Polygon_mesh_processing/CMakeFiles/locate_example.dir/locate_example.cpp.o -MF CMakeFiles/locate_example.dir/locate_example.cpp.o.d -o CMakeFiles/locate_example.dir/locate_example.cpp.o -c /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Polygon_mesh_processing/locate_example.cpp

examples/Polygon_mesh_processing/CMakeFiles/locate_example.dir/locate_example.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/locate_example.dir/locate_example.cpp.i"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Polygon_mesh_processing && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Polygon_mesh_processing/locate_example.cpp > CMakeFiles/locate_example.dir/locate_example.cpp.i

examples/Polygon_mesh_processing/CMakeFiles/locate_example.dir/locate_example.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/locate_example.dir/locate_example.cpp.s"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Polygon_mesh_processing && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Polygon_mesh_processing/locate_example.cpp -o CMakeFiles/locate_example.dir/locate_example.cpp.s

# Object files for target locate_example
locate_example_OBJECTS = \
"CMakeFiles/locate_example.dir/locate_example.cpp.o"

# External object files for target locate_example
locate_example_EXTERNAL_OBJECTS =

examples/Polygon_mesh_processing/locate_example: examples/Polygon_mesh_processing/CMakeFiles/locate_example.dir/locate_example.cpp.o
examples/Polygon_mesh_processing/locate_example: examples/Polygon_mesh_processing/CMakeFiles/locate_example.dir/build.make
examples/Polygon_mesh_processing/locate_example: /usr/lib/x86_64-linux-gnu/libgmpxx.so
examples/Polygon_mesh_processing/locate_example: /usr/lib/x86_64-linux-gnu/libmpfr.so
examples/Polygon_mesh_processing/locate_example: /usr/lib/x86_64-linux-gnu/libgmp.so
examples/Polygon_mesh_processing/locate_example: examples/Polygon_mesh_processing/CMakeFiles/locate_example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable locate_example"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Polygon_mesh_processing && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/locate_example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/Polygon_mesh_processing/CMakeFiles/locate_example.dir/build: examples/Polygon_mesh_processing/locate_example
.PHONY : examples/Polygon_mesh_processing/CMakeFiles/locate_example.dir/build

examples/Polygon_mesh_processing/CMakeFiles/locate_example.dir/clean:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Polygon_mesh_processing && $(CMAKE_COMMAND) -P CMakeFiles/locate_example.dir/cmake_clean.cmake
.PHONY : examples/Polygon_mesh_processing/CMakeFiles/locate_example.dir/clean

examples/Polygon_mesh_processing/CMakeFiles/locate_example.dir/depend:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/melina/dev/Geometry/vendor/CGAL-5.6/examples /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Polygon_mesh_processing /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Polygon_mesh_processing /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Polygon_mesh_processing/CMakeFiles/locate_example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/Polygon_mesh_processing/CMakeFiles/locate_example.dir/depend

