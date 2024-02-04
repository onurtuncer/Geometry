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
include examples/Mesh_3/CMakeFiles/remesh_polyhedral_surface_sm.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/Mesh_3/CMakeFiles/remesh_polyhedral_surface_sm.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/Mesh_3/CMakeFiles/remesh_polyhedral_surface_sm.dir/progress.make

# Include the compile flags for this target's objects.
include examples/Mesh_3/CMakeFiles/remesh_polyhedral_surface_sm.dir/flags.make

examples/Mesh_3/CMakeFiles/remesh_polyhedral_surface_sm.dir/remesh_polyhedral_surface_sm.cpp.o: examples/Mesh_3/CMakeFiles/remesh_polyhedral_surface_sm.dir/flags.make
examples/Mesh_3/CMakeFiles/remesh_polyhedral_surface_sm.dir/remesh_polyhedral_surface_sm.cpp.o: ../Mesh_3/remesh_polyhedral_surface_sm.cpp
examples/Mesh_3/CMakeFiles/remesh_polyhedral_surface_sm.dir/remesh_polyhedral_surface_sm.cpp.o: examples/Mesh_3/CMakeFiles/remesh_polyhedral_surface_sm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/Mesh_3/CMakeFiles/remesh_polyhedral_surface_sm.dir/remesh_polyhedral_surface_sm.cpp.o"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Mesh_3 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/Mesh_3/CMakeFiles/remesh_polyhedral_surface_sm.dir/remesh_polyhedral_surface_sm.cpp.o -MF CMakeFiles/remesh_polyhedral_surface_sm.dir/remesh_polyhedral_surface_sm.cpp.o.d -o CMakeFiles/remesh_polyhedral_surface_sm.dir/remesh_polyhedral_surface_sm.cpp.o -c /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Mesh_3/remesh_polyhedral_surface_sm.cpp

examples/Mesh_3/CMakeFiles/remesh_polyhedral_surface_sm.dir/remesh_polyhedral_surface_sm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/remesh_polyhedral_surface_sm.dir/remesh_polyhedral_surface_sm.cpp.i"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Mesh_3 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Mesh_3/remesh_polyhedral_surface_sm.cpp > CMakeFiles/remesh_polyhedral_surface_sm.dir/remesh_polyhedral_surface_sm.cpp.i

examples/Mesh_3/CMakeFiles/remesh_polyhedral_surface_sm.dir/remesh_polyhedral_surface_sm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/remesh_polyhedral_surface_sm.dir/remesh_polyhedral_surface_sm.cpp.s"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Mesh_3 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Mesh_3/remesh_polyhedral_surface_sm.cpp -o CMakeFiles/remesh_polyhedral_surface_sm.dir/remesh_polyhedral_surface_sm.cpp.s

# Object files for target remesh_polyhedral_surface_sm
remesh_polyhedral_surface_sm_OBJECTS = \
"CMakeFiles/remesh_polyhedral_surface_sm.dir/remesh_polyhedral_surface_sm.cpp.o"

# External object files for target remesh_polyhedral_surface_sm
remesh_polyhedral_surface_sm_EXTERNAL_OBJECTS =

examples/Mesh_3/remesh_polyhedral_surface_sm: examples/Mesh_3/CMakeFiles/remesh_polyhedral_surface_sm.dir/remesh_polyhedral_surface_sm.cpp.o
examples/Mesh_3/remesh_polyhedral_surface_sm: examples/Mesh_3/CMakeFiles/remesh_polyhedral_surface_sm.dir/build.make
examples/Mesh_3/remesh_polyhedral_surface_sm: /usr/lib/x86_64-linux-gnu/libgmpxx.so
examples/Mesh_3/remesh_polyhedral_surface_sm: /usr/lib/x86_64-linux-gnu/libmpfr.so
examples/Mesh_3/remesh_polyhedral_surface_sm: /usr/lib/x86_64-linux-gnu/libgmp.so
examples/Mesh_3/remesh_polyhedral_surface_sm: /usr/lib/x86_64-linux-gnu/libz.so
examples/Mesh_3/remesh_polyhedral_surface_sm: examples/Mesh_3/CMakeFiles/remesh_polyhedral_surface_sm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable remesh_polyhedral_surface_sm"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Mesh_3 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/remesh_polyhedral_surface_sm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/Mesh_3/CMakeFiles/remesh_polyhedral_surface_sm.dir/build: examples/Mesh_3/remesh_polyhedral_surface_sm
.PHONY : examples/Mesh_3/CMakeFiles/remesh_polyhedral_surface_sm.dir/build

examples/Mesh_3/CMakeFiles/remesh_polyhedral_surface_sm.dir/clean:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Mesh_3 && $(CMAKE_COMMAND) -P CMakeFiles/remesh_polyhedral_surface_sm.dir/cmake_clean.cmake
.PHONY : examples/Mesh_3/CMakeFiles/remesh_polyhedral_surface_sm.dir/clean

examples/Mesh_3/CMakeFiles/remesh_polyhedral_surface_sm.dir/depend:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/melina/dev/Geometry/vendor/CGAL-5.6/examples /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Mesh_3 /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Mesh_3 /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Mesh_3/CMakeFiles/remesh_polyhedral_surface_sm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/Mesh_3/CMakeFiles/remesh_polyhedral_surface_sm.dir/depend

