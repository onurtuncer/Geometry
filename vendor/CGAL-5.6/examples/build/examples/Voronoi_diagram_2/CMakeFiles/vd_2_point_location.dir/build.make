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
include examples/Voronoi_diagram_2/CMakeFiles/vd_2_point_location.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/Voronoi_diagram_2/CMakeFiles/vd_2_point_location.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/Voronoi_diagram_2/CMakeFiles/vd_2_point_location.dir/progress.make

# Include the compile flags for this target's objects.
include examples/Voronoi_diagram_2/CMakeFiles/vd_2_point_location.dir/flags.make

examples/Voronoi_diagram_2/CMakeFiles/vd_2_point_location.dir/vd_2_point_location.cpp.o: examples/Voronoi_diagram_2/CMakeFiles/vd_2_point_location.dir/flags.make
examples/Voronoi_diagram_2/CMakeFiles/vd_2_point_location.dir/vd_2_point_location.cpp.o: ../Voronoi_diagram_2/vd_2_point_location.cpp
examples/Voronoi_diagram_2/CMakeFiles/vd_2_point_location.dir/vd_2_point_location.cpp.o: examples/Voronoi_diagram_2/CMakeFiles/vd_2_point_location.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/Voronoi_diagram_2/CMakeFiles/vd_2_point_location.dir/vd_2_point_location.cpp.o"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Voronoi_diagram_2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/Voronoi_diagram_2/CMakeFiles/vd_2_point_location.dir/vd_2_point_location.cpp.o -MF CMakeFiles/vd_2_point_location.dir/vd_2_point_location.cpp.o.d -o CMakeFiles/vd_2_point_location.dir/vd_2_point_location.cpp.o -c /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Voronoi_diagram_2/vd_2_point_location.cpp

examples/Voronoi_diagram_2/CMakeFiles/vd_2_point_location.dir/vd_2_point_location.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vd_2_point_location.dir/vd_2_point_location.cpp.i"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Voronoi_diagram_2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Voronoi_diagram_2/vd_2_point_location.cpp > CMakeFiles/vd_2_point_location.dir/vd_2_point_location.cpp.i

examples/Voronoi_diagram_2/CMakeFiles/vd_2_point_location.dir/vd_2_point_location.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vd_2_point_location.dir/vd_2_point_location.cpp.s"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Voronoi_diagram_2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Voronoi_diagram_2/vd_2_point_location.cpp -o CMakeFiles/vd_2_point_location.dir/vd_2_point_location.cpp.s

# Object files for target vd_2_point_location
vd_2_point_location_OBJECTS = \
"CMakeFiles/vd_2_point_location.dir/vd_2_point_location.cpp.o"

# External object files for target vd_2_point_location
vd_2_point_location_EXTERNAL_OBJECTS =

examples/Voronoi_diagram_2/vd_2_point_location: examples/Voronoi_diagram_2/CMakeFiles/vd_2_point_location.dir/vd_2_point_location.cpp.o
examples/Voronoi_diagram_2/vd_2_point_location: examples/Voronoi_diagram_2/CMakeFiles/vd_2_point_location.dir/build.make
examples/Voronoi_diagram_2/vd_2_point_location: examples/Arrangement_on_surface_2/libCGAL_Qt5_moc_and_resources.a
examples/Voronoi_diagram_2/vd_2_point_location: /usr/lib/x86_64-linux-gnu/libgmpxx.so
examples/Voronoi_diagram_2/vd_2_point_location: /usr/lib/x86_64-linux-gnu/libmpfr.so
examples/Voronoi_diagram_2/vd_2_point_location: /usr/lib/x86_64-linux-gnu/libgmp.so
examples/Voronoi_diagram_2/vd_2_point_location: /usr/lib/x86_64-linux-gnu/libQt5OpenGL.so.5.15.3
examples/Voronoi_diagram_2/vd_2_point_location: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.3
examples/Voronoi_diagram_2/vd_2_point_location: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.3
examples/Voronoi_diagram_2/vd_2_point_location: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.3
examples/Voronoi_diagram_2/vd_2_point_location: examples/Voronoi_diagram_2/CMakeFiles/vd_2_point_location.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable vd_2_point_location"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Voronoi_diagram_2 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vd_2_point_location.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/Voronoi_diagram_2/CMakeFiles/vd_2_point_location.dir/build: examples/Voronoi_diagram_2/vd_2_point_location
.PHONY : examples/Voronoi_diagram_2/CMakeFiles/vd_2_point_location.dir/build

examples/Voronoi_diagram_2/CMakeFiles/vd_2_point_location.dir/clean:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Voronoi_diagram_2 && $(CMAKE_COMMAND) -P CMakeFiles/vd_2_point_location.dir/cmake_clean.cmake
.PHONY : examples/Voronoi_diagram_2/CMakeFiles/vd_2_point_location.dir/clean

examples/Voronoi_diagram_2/CMakeFiles/vd_2_point_location.dir/depend:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/melina/dev/Geometry/vendor/CGAL-5.6/examples /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Voronoi_diagram_2 /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Voronoi_diagram_2 /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Voronoi_diagram_2/CMakeFiles/vd_2_point_location.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/Voronoi_diagram_2/CMakeFiles/vd_2_point_location.dir/depend

