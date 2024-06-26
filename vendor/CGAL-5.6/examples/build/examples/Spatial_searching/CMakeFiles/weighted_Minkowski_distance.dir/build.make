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
include examples/Spatial_searching/CMakeFiles/weighted_Minkowski_distance.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/Spatial_searching/CMakeFiles/weighted_Minkowski_distance.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/Spatial_searching/CMakeFiles/weighted_Minkowski_distance.dir/progress.make

# Include the compile flags for this target's objects.
include examples/Spatial_searching/CMakeFiles/weighted_Minkowski_distance.dir/flags.make

examples/Spatial_searching/CMakeFiles/weighted_Minkowski_distance.dir/weighted_Minkowski_distance.cpp.o: examples/Spatial_searching/CMakeFiles/weighted_Minkowski_distance.dir/flags.make
examples/Spatial_searching/CMakeFiles/weighted_Minkowski_distance.dir/weighted_Minkowski_distance.cpp.o: ../Spatial_searching/weighted_Minkowski_distance.cpp
examples/Spatial_searching/CMakeFiles/weighted_Minkowski_distance.dir/weighted_Minkowski_distance.cpp.o: examples/Spatial_searching/CMakeFiles/weighted_Minkowski_distance.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/Spatial_searching/CMakeFiles/weighted_Minkowski_distance.dir/weighted_Minkowski_distance.cpp.o"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Spatial_searching && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/Spatial_searching/CMakeFiles/weighted_Minkowski_distance.dir/weighted_Minkowski_distance.cpp.o -MF CMakeFiles/weighted_Minkowski_distance.dir/weighted_Minkowski_distance.cpp.o.d -o CMakeFiles/weighted_Minkowski_distance.dir/weighted_Minkowski_distance.cpp.o -c /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Spatial_searching/weighted_Minkowski_distance.cpp

examples/Spatial_searching/CMakeFiles/weighted_Minkowski_distance.dir/weighted_Minkowski_distance.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/weighted_Minkowski_distance.dir/weighted_Minkowski_distance.cpp.i"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Spatial_searching && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Spatial_searching/weighted_Minkowski_distance.cpp > CMakeFiles/weighted_Minkowski_distance.dir/weighted_Minkowski_distance.cpp.i

examples/Spatial_searching/CMakeFiles/weighted_Minkowski_distance.dir/weighted_Minkowski_distance.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/weighted_Minkowski_distance.dir/weighted_Minkowski_distance.cpp.s"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Spatial_searching && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Spatial_searching/weighted_Minkowski_distance.cpp -o CMakeFiles/weighted_Minkowski_distance.dir/weighted_Minkowski_distance.cpp.s

# Object files for target weighted_Minkowski_distance
weighted_Minkowski_distance_OBJECTS = \
"CMakeFiles/weighted_Minkowski_distance.dir/weighted_Minkowski_distance.cpp.o"

# External object files for target weighted_Minkowski_distance
weighted_Minkowski_distance_EXTERNAL_OBJECTS =

examples/Spatial_searching/weighted_Minkowski_distance: examples/Spatial_searching/CMakeFiles/weighted_Minkowski_distance.dir/weighted_Minkowski_distance.cpp.o
examples/Spatial_searching/weighted_Minkowski_distance: examples/Spatial_searching/CMakeFiles/weighted_Minkowski_distance.dir/build.make
examples/Spatial_searching/weighted_Minkowski_distance: /usr/lib/x86_64-linux-gnu/libgmpxx.so
examples/Spatial_searching/weighted_Minkowski_distance: /usr/lib/x86_64-linux-gnu/libmpfr.so
examples/Spatial_searching/weighted_Minkowski_distance: /usr/lib/x86_64-linux-gnu/libgmp.so
examples/Spatial_searching/weighted_Minkowski_distance: examples/Spatial_searching/CMakeFiles/weighted_Minkowski_distance.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable weighted_Minkowski_distance"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Spatial_searching && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/weighted_Minkowski_distance.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/Spatial_searching/CMakeFiles/weighted_Minkowski_distance.dir/build: examples/Spatial_searching/weighted_Minkowski_distance
.PHONY : examples/Spatial_searching/CMakeFiles/weighted_Minkowski_distance.dir/build

examples/Spatial_searching/CMakeFiles/weighted_Minkowski_distance.dir/clean:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Spatial_searching && $(CMAKE_COMMAND) -P CMakeFiles/weighted_Minkowski_distance.dir/cmake_clean.cmake
.PHONY : examples/Spatial_searching/CMakeFiles/weighted_Minkowski_distance.dir/clean

examples/Spatial_searching/CMakeFiles/weighted_Minkowski_distance.dir/depend:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/melina/dev/Geometry/vendor/CGAL-5.6/examples /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Spatial_searching /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Spatial_searching /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Spatial_searching/CMakeFiles/weighted_Minkowski_distance.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/Spatial_searching/CMakeFiles/weighted_Minkowski_distance.dir/depend

