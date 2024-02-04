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
include examples/BGL_surface_mesh/CMakeFiles/gwdwg.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/BGL_surface_mesh/CMakeFiles/gwdwg.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/BGL_surface_mesh/CMakeFiles/gwdwg.dir/progress.make

# Include the compile flags for this target's objects.
include examples/BGL_surface_mesh/CMakeFiles/gwdwg.dir/flags.make

examples/BGL_surface_mesh/CMakeFiles/gwdwg.dir/gwdwg.cpp.o: examples/BGL_surface_mesh/CMakeFiles/gwdwg.dir/flags.make
examples/BGL_surface_mesh/CMakeFiles/gwdwg.dir/gwdwg.cpp.o: ../BGL_surface_mesh/gwdwg.cpp
examples/BGL_surface_mesh/CMakeFiles/gwdwg.dir/gwdwg.cpp.o: examples/BGL_surface_mesh/CMakeFiles/gwdwg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/BGL_surface_mesh/CMakeFiles/gwdwg.dir/gwdwg.cpp.o"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/BGL_surface_mesh && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/BGL_surface_mesh/CMakeFiles/gwdwg.dir/gwdwg.cpp.o -MF CMakeFiles/gwdwg.dir/gwdwg.cpp.o.d -o CMakeFiles/gwdwg.dir/gwdwg.cpp.o -c /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/BGL_surface_mesh/gwdwg.cpp

examples/BGL_surface_mesh/CMakeFiles/gwdwg.dir/gwdwg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gwdwg.dir/gwdwg.cpp.i"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/BGL_surface_mesh && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/BGL_surface_mesh/gwdwg.cpp > CMakeFiles/gwdwg.dir/gwdwg.cpp.i

examples/BGL_surface_mesh/CMakeFiles/gwdwg.dir/gwdwg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gwdwg.dir/gwdwg.cpp.s"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/BGL_surface_mesh && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/BGL_surface_mesh/gwdwg.cpp -o CMakeFiles/gwdwg.dir/gwdwg.cpp.s

# Object files for target gwdwg
gwdwg_OBJECTS = \
"CMakeFiles/gwdwg.dir/gwdwg.cpp.o"

# External object files for target gwdwg
gwdwg_EXTERNAL_OBJECTS =

examples/BGL_surface_mesh/gwdwg: examples/BGL_surface_mesh/CMakeFiles/gwdwg.dir/gwdwg.cpp.o
examples/BGL_surface_mesh/gwdwg: examples/BGL_surface_mesh/CMakeFiles/gwdwg.dir/build.make
examples/BGL_surface_mesh/gwdwg: /usr/lib/x86_64-linux-gnu/libgmpxx.so
examples/BGL_surface_mesh/gwdwg: /usr/lib/x86_64-linux-gnu/libmpfr.so
examples/BGL_surface_mesh/gwdwg: /usr/lib/x86_64-linux-gnu/libgmp.so
examples/BGL_surface_mesh/gwdwg: examples/BGL_surface_mesh/CMakeFiles/gwdwg.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable gwdwg"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/BGL_surface_mesh && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gwdwg.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/BGL_surface_mesh/CMakeFiles/gwdwg.dir/build: examples/BGL_surface_mesh/gwdwg
.PHONY : examples/BGL_surface_mesh/CMakeFiles/gwdwg.dir/build

examples/BGL_surface_mesh/CMakeFiles/gwdwg.dir/clean:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/BGL_surface_mesh && $(CMAKE_COMMAND) -P CMakeFiles/gwdwg.dir/cmake_clean.cmake
.PHONY : examples/BGL_surface_mesh/CMakeFiles/gwdwg.dir/clean

examples/BGL_surface_mesh/CMakeFiles/gwdwg.dir/depend:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/melina/dev/Geometry/vendor/CGAL-5.6/examples /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/BGL_surface_mesh /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/BGL_surface_mesh /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/BGL_surface_mesh/CMakeFiles/gwdwg.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/BGL_surface_mesh/CMakeFiles/gwdwg.dir/depend

