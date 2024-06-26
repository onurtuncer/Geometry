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
include examples/Surface_mesh_shortest_path/CMakeFiles/shortest_paths_multiple_sources.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/Surface_mesh_shortest_path/CMakeFiles/shortest_paths_multiple_sources.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/Surface_mesh_shortest_path/CMakeFiles/shortest_paths_multiple_sources.dir/progress.make

# Include the compile flags for this target's objects.
include examples/Surface_mesh_shortest_path/CMakeFiles/shortest_paths_multiple_sources.dir/flags.make

examples/Surface_mesh_shortest_path/CMakeFiles/shortest_paths_multiple_sources.dir/shortest_paths_multiple_sources.cpp.o: examples/Surface_mesh_shortest_path/CMakeFiles/shortest_paths_multiple_sources.dir/flags.make
examples/Surface_mesh_shortest_path/CMakeFiles/shortest_paths_multiple_sources.dir/shortest_paths_multiple_sources.cpp.o: ../Surface_mesh_shortest_path/shortest_paths_multiple_sources.cpp
examples/Surface_mesh_shortest_path/CMakeFiles/shortest_paths_multiple_sources.dir/shortest_paths_multiple_sources.cpp.o: examples/Surface_mesh_shortest_path/CMakeFiles/shortest_paths_multiple_sources.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/Surface_mesh_shortest_path/CMakeFiles/shortest_paths_multiple_sources.dir/shortest_paths_multiple_sources.cpp.o"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Surface_mesh_shortest_path && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/Surface_mesh_shortest_path/CMakeFiles/shortest_paths_multiple_sources.dir/shortest_paths_multiple_sources.cpp.o -MF CMakeFiles/shortest_paths_multiple_sources.dir/shortest_paths_multiple_sources.cpp.o.d -o CMakeFiles/shortest_paths_multiple_sources.dir/shortest_paths_multiple_sources.cpp.o -c /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Surface_mesh_shortest_path/shortest_paths_multiple_sources.cpp

examples/Surface_mesh_shortest_path/CMakeFiles/shortest_paths_multiple_sources.dir/shortest_paths_multiple_sources.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shortest_paths_multiple_sources.dir/shortest_paths_multiple_sources.cpp.i"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Surface_mesh_shortest_path && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Surface_mesh_shortest_path/shortest_paths_multiple_sources.cpp > CMakeFiles/shortest_paths_multiple_sources.dir/shortest_paths_multiple_sources.cpp.i

examples/Surface_mesh_shortest_path/CMakeFiles/shortest_paths_multiple_sources.dir/shortest_paths_multiple_sources.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shortest_paths_multiple_sources.dir/shortest_paths_multiple_sources.cpp.s"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Surface_mesh_shortest_path && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Surface_mesh_shortest_path/shortest_paths_multiple_sources.cpp -o CMakeFiles/shortest_paths_multiple_sources.dir/shortest_paths_multiple_sources.cpp.s

# Object files for target shortest_paths_multiple_sources
shortest_paths_multiple_sources_OBJECTS = \
"CMakeFiles/shortest_paths_multiple_sources.dir/shortest_paths_multiple_sources.cpp.o"

# External object files for target shortest_paths_multiple_sources
shortest_paths_multiple_sources_EXTERNAL_OBJECTS =

examples/Surface_mesh_shortest_path/shortest_paths_multiple_sources: examples/Surface_mesh_shortest_path/CMakeFiles/shortest_paths_multiple_sources.dir/shortest_paths_multiple_sources.cpp.o
examples/Surface_mesh_shortest_path/shortest_paths_multiple_sources: examples/Surface_mesh_shortest_path/CMakeFiles/shortest_paths_multiple_sources.dir/build.make
examples/Surface_mesh_shortest_path/shortest_paths_multiple_sources: /usr/lib/x86_64-linux-gnu/libgmpxx.so
examples/Surface_mesh_shortest_path/shortest_paths_multiple_sources: /usr/lib/x86_64-linux-gnu/libmpfr.so
examples/Surface_mesh_shortest_path/shortest_paths_multiple_sources: /usr/lib/x86_64-linux-gnu/libgmp.so
examples/Surface_mesh_shortest_path/shortest_paths_multiple_sources: examples/Surface_mesh_shortest_path/CMakeFiles/shortest_paths_multiple_sources.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable shortest_paths_multiple_sources"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Surface_mesh_shortest_path && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/shortest_paths_multiple_sources.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/Surface_mesh_shortest_path/CMakeFiles/shortest_paths_multiple_sources.dir/build: examples/Surface_mesh_shortest_path/shortest_paths_multiple_sources
.PHONY : examples/Surface_mesh_shortest_path/CMakeFiles/shortest_paths_multiple_sources.dir/build

examples/Surface_mesh_shortest_path/CMakeFiles/shortest_paths_multiple_sources.dir/clean:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Surface_mesh_shortest_path && $(CMAKE_COMMAND) -P CMakeFiles/shortest_paths_multiple_sources.dir/cmake_clean.cmake
.PHONY : examples/Surface_mesh_shortest_path/CMakeFiles/shortest_paths_multiple_sources.dir/clean

examples/Surface_mesh_shortest_path/CMakeFiles/shortest_paths_multiple_sources.dir/depend:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/melina/dev/Geometry/vendor/CGAL-5.6/examples /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Surface_mesh_shortest_path /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Surface_mesh_shortest_path /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Surface_mesh_shortest_path/CMakeFiles/shortest_paths_multiple_sources.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/Surface_mesh_shortest_path/CMakeFiles/shortest_paths_multiple_sources.dir/depend

