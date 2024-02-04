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
include examples/Surface_mesh_segmentation/CMakeFiles/sdf_values_example.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/Surface_mesh_segmentation/CMakeFiles/sdf_values_example.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/Surface_mesh_segmentation/CMakeFiles/sdf_values_example.dir/progress.make

# Include the compile flags for this target's objects.
include examples/Surface_mesh_segmentation/CMakeFiles/sdf_values_example.dir/flags.make

examples/Surface_mesh_segmentation/CMakeFiles/sdf_values_example.dir/sdf_values_example.cpp.o: examples/Surface_mesh_segmentation/CMakeFiles/sdf_values_example.dir/flags.make
examples/Surface_mesh_segmentation/CMakeFiles/sdf_values_example.dir/sdf_values_example.cpp.o: ../Surface_mesh_segmentation/sdf_values_example.cpp
examples/Surface_mesh_segmentation/CMakeFiles/sdf_values_example.dir/sdf_values_example.cpp.o: examples/Surface_mesh_segmentation/CMakeFiles/sdf_values_example.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/Surface_mesh_segmentation/CMakeFiles/sdf_values_example.dir/sdf_values_example.cpp.o"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Surface_mesh_segmentation && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/Surface_mesh_segmentation/CMakeFiles/sdf_values_example.dir/sdf_values_example.cpp.o -MF CMakeFiles/sdf_values_example.dir/sdf_values_example.cpp.o.d -o CMakeFiles/sdf_values_example.dir/sdf_values_example.cpp.o -c /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Surface_mesh_segmentation/sdf_values_example.cpp

examples/Surface_mesh_segmentation/CMakeFiles/sdf_values_example.dir/sdf_values_example.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sdf_values_example.dir/sdf_values_example.cpp.i"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Surface_mesh_segmentation && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Surface_mesh_segmentation/sdf_values_example.cpp > CMakeFiles/sdf_values_example.dir/sdf_values_example.cpp.i

examples/Surface_mesh_segmentation/CMakeFiles/sdf_values_example.dir/sdf_values_example.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sdf_values_example.dir/sdf_values_example.cpp.s"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Surface_mesh_segmentation && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Surface_mesh_segmentation/sdf_values_example.cpp -o CMakeFiles/sdf_values_example.dir/sdf_values_example.cpp.s

# Object files for target sdf_values_example
sdf_values_example_OBJECTS = \
"CMakeFiles/sdf_values_example.dir/sdf_values_example.cpp.o"

# External object files for target sdf_values_example
sdf_values_example_EXTERNAL_OBJECTS =

examples/Surface_mesh_segmentation/sdf_values_example: examples/Surface_mesh_segmentation/CMakeFiles/sdf_values_example.dir/sdf_values_example.cpp.o
examples/Surface_mesh_segmentation/sdf_values_example: examples/Surface_mesh_segmentation/CMakeFiles/sdf_values_example.dir/build.make
examples/Surface_mesh_segmentation/sdf_values_example: /usr/lib/x86_64-linux-gnu/libgmpxx.so
examples/Surface_mesh_segmentation/sdf_values_example: /usr/lib/x86_64-linux-gnu/libmpfr.so
examples/Surface_mesh_segmentation/sdf_values_example: /usr/lib/x86_64-linux-gnu/libgmp.so
examples/Surface_mesh_segmentation/sdf_values_example: examples/Surface_mesh_segmentation/CMakeFiles/sdf_values_example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sdf_values_example"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Surface_mesh_segmentation && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sdf_values_example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/Surface_mesh_segmentation/CMakeFiles/sdf_values_example.dir/build: examples/Surface_mesh_segmentation/sdf_values_example
.PHONY : examples/Surface_mesh_segmentation/CMakeFiles/sdf_values_example.dir/build

examples/Surface_mesh_segmentation/CMakeFiles/sdf_values_example.dir/clean:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Surface_mesh_segmentation && $(CMAKE_COMMAND) -P CMakeFiles/sdf_values_example.dir/cmake_clean.cmake
.PHONY : examples/Surface_mesh_segmentation/CMakeFiles/sdf_values_example.dir/clean

examples/Surface_mesh_segmentation/CMakeFiles/sdf_values_example.dir/depend:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/melina/dev/Geometry/vendor/CGAL-5.6/examples /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Surface_mesh_segmentation /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Surface_mesh_segmentation /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Surface_mesh_segmentation/CMakeFiles/sdf_values_example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/Surface_mesh_segmentation/CMakeFiles/sdf_values_example.dir/depend

