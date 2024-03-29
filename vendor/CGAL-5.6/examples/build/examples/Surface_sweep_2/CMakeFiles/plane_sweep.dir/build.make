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
include examples/Surface_sweep_2/CMakeFiles/plane_sweep.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/Surface_sweep_2/CMakeFiles/plane_sweep.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/Surface_sweep_2/CMakeFiles/plane_sweep.dir/progress.make

# Include the compile flags for this target's objects.
include examples/Surface_sweep_2/CMakeFiles/plane_sweep.dir/flags.make

examples/Surface_sweep_2/CMakeFiles/plane_sweep.dir/plane_sweep.cpp.o: examples/Surface_sweep_2/CMakeFiles/plane_sweep.dir/flags.make
examples/Surface_sweep_2/CMakeFiles/plane_sweep.dir/plane_sweep.cpp.o: ../Surface_sweep_2/plane_sweep.cpp
examples/Surface_sweep_2/CMakeFiles/plane_sweep.dir/plane_sweep.cpp.o: examples/Surface_sweep_2/CMakeFiles/plane_sweep.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/Surface_sweep_2/CMakeFiles/plane_sweep.dir/plane_sweep.cpp.o"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Surface_sweep_2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/Surface_sweep_2/CMakeFiles/plane_sweep.dir/plane_sweep.cpp.o -MF CMakeFiles/plane_sweep.dir/plane_sweep.cpp.o.d -o CMakeFiles/plane_sweep.dir/plane_sweep.cpp.o -c /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Surface_sweep_2/plane_sweep.cpp

examples/Surface_sweep_2/CMakeFiles/plane_sweep.dir/plane_sweep.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plane_sweep.dir/plane_sweep.cpp.i"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Surface_sweep_2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Surface_sweep_2/plane_sweep.cpp > CMakeFiles/plane_sweep.dir/plane_sweep.cpp.i

examples/Surface_sweep_2/CMakeFiles/plane_sweep.dir/plane_sweep.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plane_sweep.dir/plane_sweep.cpp.s"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Surface_sweep_2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Surface_sweep_2/plane_sweep.cpp -o CMakeFiles/plane_sweep.dir/plane_sweep.cpp.s

# Object files for target plane_sweep
plane_sweep_OBJECTS = \
"CMakeFiles/plane_sweep.dir/plane_sweep.cpp.o"

# External object files for target plane_sweep
plane_sweep_EXTERNAL_OBJECTS =

examples/Surface_sweep_2/plane_sweep: examples/Surface_sweep_2/CMakeFiles/plane_sweep.dir/plane_sweep.cpp.o
examples/Surface_sweep_2/plane_sweep: examples/Surface_sweep_2/CMakeFiles/plane_sweep.dir/build.make
examples/Surface_sweep_2/plane_sweep: /usr/lib/x86_64-linux-gnu/libgmpxx.so
examples/Surface_sweep_2/plane_sweep: /usr/lib/x86_64-linux-gnu/libmpfr.so
examples/Surface_sweep_2/plane_sweep: /usr/lib/x86_64-linux-gnu/libgmp.so
examples/Surface_sweep_2/plane_sweep: examples/Surface_sweep_2/CMakeFiles/plane_sweep.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable plane_sweep"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Surface_sweep_2 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/plane_sweep.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/Surface_sweep_2/CMakeFiles/plane_sweep.dir/build: examples/Surface_sweep_2/plane_sweep
.PHONY : examples/Surface_sweep_2/CMakeFiles/plane_sweep.dir/build

examples/Surface_sweep_2/CMakeFiles/plane_sweep.dir/clean:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Surface_sweep_2 && $(CMAKE_COMMAND) -P CMakeFiles/plane_sweep.dir/cmake_clean.cmake
.PHONY : examples/Surface_sweep_2/CMakeFiles/plane_sweep.dir/clean

examples/Surface_sweep_2/CMakeFiles/plane_sweep.dir/depend:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/melina/dev/Geometry/vendor/CGAL-5.6/examples /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Surface_sweep_2 /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Surface_sweep_2 /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Surface_sweep_2/CMakeFiles/plane_sweep.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/Surface_sweep_2/CMakeFiles/plane_sweep.dir/depend

