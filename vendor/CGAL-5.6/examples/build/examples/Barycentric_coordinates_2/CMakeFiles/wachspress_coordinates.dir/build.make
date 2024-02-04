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
include examples/Barycentric_coordinates_2/CMakeFiles/wachspress_coordinates.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/Barycentric_coordinates_2/CMakeFiles/wachspress_coordinates.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/Barycentric_coordinates_2/CMakeFiles/wachspress_coordinates.dir/progress.make

# Include the compile flags for this target's objects.
include examples/Barycentric_coordinates_2/CMakeFiles/wachspress_coordinates.dir/flags.make

examples/Barycentric_coordinates_2/CMakeFiles/wachspress_coordinates.dir/wachspress_coordinates.cpp.o: examples/Barycentric_coordinates_2/CMakeFiles/wachspress_coordinates.dir/flags.make
examples/Barycentric_coordinates_2/CMakeFiles/wachspress_coordinates.dir/wachspress_coordinates.cpp.o: ../Barycentric_coordinates_2/wachspress_coordinates.cpp
examples/Barycentric_coordinates_2/CMakeFiles/wachspress_coordinates.dir/wachspress_coordinates.cpp.o: examples/Barycentric_coordinates_2/CMakeFiles/wachspress_coordinates.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/Barycentric_coordinates_2/CMakeFiles/wachspress_coordinates.dir/wachspress_coordinates.cpp.o"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Barycentric_coordinates_2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/Barycentric_coordinates_2/CMakeFiles/wachspress_coordinates.dir/wachspress_coordinates.cpp.o -MF CMakeFiles/wachspress_coordinates.dir/wachspress_coordinates.cpp.o.d -o CMakeFiles/wachspress_coordinates.dir/wachspress_coordinates.cpp.o -c /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Barycentric_coordinates_2/wachspress_coordinates.cpp

examples/Barycentric_coordinates_2/CMakeFiles/wachspress_coordinates.dir/wachspress_coordinates.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wachspress_coordinates.dir/wachspress_coordinates.cpp.i"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Barycentric_coordinates_2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Barycentric_coordinates_2/wachspress_coordinates.cpp > CMakeFiles/wachspress_coordinates.dir/wachspress_coordinates.cpp.i

examples/Barycentric_coordinates_2/CMakeFiles/wachspress_coordinates.dir/wachspress_coordinates.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wachspress_coordinates.dir/wachspress_coordinates.cpp.s"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Barycentric_coordinates_2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Barycentric_coordinates_2/wachspress_coordinates.cpp -o CMakeFiles/wachspress_coordinates.dir/wachspress_coordinates.cpp.s

# Object files for target wachspress_coordinates
wachspress_coordinates_OBJECTS = \
"CMakeFiles/wachspress_coordinates.dir/wachspress_coordinates.cpp.o"

# External object files for target wachspress_coordinates
wachspress_coordinates_EXTERNAL_OBJECTS =

examples/Barycentric_coordinates_2/wachspress_coordinates: examples/Barycentric_coordinates_2/CMakeFiles/wachspress_coordinates.dir/wachspress_coordinates.cpp.o
examples/Barycentric_coordinates_2/wachspress_coordinates: examples/Barycentric_coordinates_2/CMakeFiles/wachspress_coordinates.dir/build.make
examples/Barycentric_coordinates_2/wachspress_coordinates: /usr/lib/x86_64-linux-gnu/libgmpxx.so
examples/Barycentric_coordinates_2/wachspress_coordinates: /usr/lib/x86_64-linux-gnu/libmpfr.so
examples/Barycentric_coordinates_2/wachspress_coordinates: /usr/lib/x86_64-linux-gnu/libgmp.so
examples/Barycentric_coordinates_2/wachspress_coordinates: examples/Barycentric_coordinates_2/CMakeFiles/wachspress_coordinates.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable wachspress_coordinates"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Barycentric_coordinates_2 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wachspress_coordinates.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/Barycentric_coordinates_2/CMakeFiles/wachspress_coordinates.dir/build: examples/Barycentric_coordinates_2/wachspress_coordinates
.PHONY : examples/Barycentric_coordinates_2/CMakeFiles/wachspress_coordinates.dir/build

examples/Barycentric_coordinates_2/CMakeFiles/wachspress_coordinates.dir/clean:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Barycentric_coordinates_2 && $(CMAKE_COMMAND) -P CMakeFiles/wachspress_coordinates.dir/cmake_clean.cmake
.PHONY : examples/Barycentric_coordinates_2/CMakeFiles/wachspress_coordinates.dir/clean

examples/Barycentric_coordinates_2/CMakeFiles/wachspress_coordinates.dir/depend:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/melina/dev/Geometry/vendor/CGAL-5.6/examples /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Barycentric_coordinates_2 /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Barycentric_coordinates_2 /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Barycentric_coordinates_2/CMakeFiles/wachspress_coordinates.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/Barycentric_coordinates_2/CMakeFiles/wachspress_coordinates.dir/depend

