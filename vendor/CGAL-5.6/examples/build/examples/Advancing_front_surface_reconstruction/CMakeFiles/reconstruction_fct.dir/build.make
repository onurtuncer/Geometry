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
include examples/Advancing_front_surface_reconstruction/CMakeFiles/reconstruction_fct.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/Advancing_front_surface_reconstruction/CMakeFiles/reconstruction_fct.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/Advancing_front_surface_reconstruction/CMakeFiles/reconstruction_fct.dir/progress.make

# Include the compile flags for this target's objects.
include examples/Advancing_front_surface_reconstruction/CMakeFiles/reconstruction_fct.dir/flags.make

examples/Advancing_front_surface_reconstruction/CMakeFiles/reconstruction_fct.dir/reconstruction_fct.cpp.o: examples/Advancing_front_surface_reconstruction/CMakeFiles/reconstruction_fct.dir/flags.make
examples/Advancing_front_surface_reconstruction/CMakeFiles/reconstruction_fct.dir/reconstruction_fct.cpp.o: ../Advancing_front_surface_reconstruction/reconstruction_fct.cpp
examples/Advancing_front_surface_reconstruction/CMakeFiles/reconstruction_fct.dir/reconstruction_fct.cpp.o: examples/Advancing_front_surface_reconstruction/CMakeFiles/reconstruction_fct.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/Advancing_front_surface_reconstruction/CMakeFiles/reconstruction_fct.dir/reconstruction_fct.cpp.o"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Advancing_front_surface_reconstruction && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/Advancing_front_surface_reconstruction/CMakeFiles/reconstruction_fct.dir/reconstruction_fct.cpp.o -MF CMakeFiles/reconstruction_fct.dir/reconstruction_fct.cpp.o.d -o CMakeFiles/reconstruction_fct.dir/reconstruction_fct.cpp.o -c /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Advancing_front_surface_reconstruction/reconstruction_fct.cpp

examples/Advancing_front_surface_reconstruction/CMakeFiles/reconstruction_fct.dir/reconstruction_fct.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reconstruction_fct.dir/reconstruction_fct.cpp.i"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Advancing_front_surface_reconstruction && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Advancing_front_surface_reconstruction/reconstruction_fct.cpp > CMakeFiles/reconstruction_fct.dir/reconstruction_fct.cpp.i

examples/Advancing_front_surface_reconstruction/CMakeFiles/reconstruction_fct.dir/reconstruction_fct.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reconstruction_fct.dir/reconstruction_fct.cpp.s"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Advancing_front_surface_reconstruction && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Advancing_front_surface_reconstruction/reconstruction_fct.cpp -o CMakeFiles/reconstruction_fct.dir/reconstruction_fct.cpp.s

# Object files for target reconstruction_fct
reconstruction_fct_OBJECTS = \
"CMakeFiles/reconstruction_fct.dir/reconstruction_fct.cpp.o"

# External object files for target reconstruction_fct
reconstruction_fct_EXTERNAL_OBJECTS =

examples/Advancing_front_surface_reconstruction/reconstruction_fct: examples/Advancing_front_surface_reconstruction/CMakeFiles/reconstruction_fct.dir/reconstruction_fct.cpp.o
examples/Advancing_front_surface_reconstruction/reconstruction_fct: examples/Advancing_front_surface_reconstruction/CMakeFiles/reconstruction_fct.dir/build.make
examples/Advancing_front_surface_reconstruction/reconstruction_fct: /usr/lib/x86_64-linux-gnu/libgmpxx.so
examples/Advancing_front_surface_reconstruction/reconstruction_fct: /usr/lib/x86_64-linux-gnu/libmpfr.so
examples/Advancing_front_surface_reconstruction/reconstruction_fct: /usr/lib/x86_64-linux-gnu/libgmp.so
examples/Advancing_front_surface_reconstruction/reconstruction_fct: examples/Advancing_front_surface_reconstruction/CMakeFiles/reconstruction_fct.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable reconstruction_fct"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Advancing_front_surface_reconstruction && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/reconstruction_fct.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/Advancing_front_surface_reconstruction/CMakeFiles/reconstruction_fct.dir/build: examples/Advancing_front_surface_reconstruction/reconstruction_fct
.PHONY : examples/Advancing_front_surface_reconstruction/CMakeFiles/reconstruction_fct.dir/build

examples/Advancing_front_surface_reconstruction/CMakeFiles/reconstruction_fct.dir/clean:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Advancing_front_surface_reconstruction && $(CMAKE_COMMAND) -P CMakeFiles/reconstruction_fct.dir/cmake_clean.cmake
.PHONY : examples/Advancing_front_surface_reconstruction/CMakeFiles/reconstruction_fct.dir/clean

examples/Advancing_front_surface_reconstruction/CMakeFiles/reconstruction_fct.dir/depend:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/melina/dev/Geometry/vendor/CGAL-5.6/examples /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Advancing_front_surface_reconstruction /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Advancing_front_surface_reconstruction /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Advancing_front_surface_reconstruction/CMakeFiles/reconstruction_fct.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/Advancing_front_surface_reconstruction/CMakeFiles/reconstruction_fct.dir/depend

