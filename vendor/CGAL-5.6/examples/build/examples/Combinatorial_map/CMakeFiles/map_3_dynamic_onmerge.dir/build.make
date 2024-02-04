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
include examples/Combinatorial_map/CMakeFiles/map_3_dynamic_onmerge.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/Combinatorial_map/CMakeFiles/map_3_dynamic_onmerge.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/Combinatorial_map/CMakeFiles/map_3_dynamic_onmerge.dir/progress.make

# Include the compile flags for this target's objects.
include examples/Combinatorial_map/CMakeFiles/map_3_dynamic_onmerge.dir/flags.make

examples/Combinatorial_map/CMakeFiles/map_3_dynamic_onmerge.dir/map_3_dynamic_onmerge.cpp.o: examples/Combinatorial_map/CMakeFiles/map_3_dynamic_onmerge.dir/flags.make
examples/Combinatorial_map/CMakeFiles/map_3_dynamic_onmerge.dir/map_3_dynamic_onmerge.cpp.o: ../Combinatorial_map/map_3_dynamic_onmerge.cpp
examples/Combinatorial_map/CMakeFiles/map_3_dynamic_onmerge.dir/map_3_dynamic_onmerge.cpp.o: examples/Combinatorial_map/CMakeFiles/map_3_dynamic_onmerge.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/Combinatorial_map/CMakeFiles/map_3_dynamic_onmerge.dir/map_3_dynamic_onmerge.cpp.o"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Combinatorial_map && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/Combinatorial_map/CMakeFiles/map_3_dynamic_onmerge.dir/map_3_dynamic_onmerge.cpp.o -MF CMakeFiles/map_3_dynamic_onmerge.dir/map_3_dynamic_onmerge.cpp.o.d -o CMakeFiles/map_3_dynamic_onmerge.dir/map_3_dynamic_onmerge.cpp.o -c /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Combinatorial_map/map_3_dynamic_onmerge.cpp

examples/Combinatorial_map/CMakeFiles/map_3_dynamic_onmerge.dir/map_3_dynamic_onmerge.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/map_3_dynamic_onmerge.dir/map_3_dynamic_onmerge.cpp.i"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Combinatorial_map && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Combinatorial_map/map_3_dynamic_onmerge.cpp > CMakeFiles/map_3_dynamic_onmerge.dir/map_3_dynamic_onmerge.cpp.i

examples/Combinatorial_map/CMakeFiles/map_3_dynamic_onmerge.dir/map_3_dynamic_onmerge.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/map_3_dynamic_onmerge.dir/map_3_dynamic_onmerge.cpp.s"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Combinatorial_map && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Combinatorial_map/map_3_dynamic_onmerge.cpp -o CMakeFiles/map_3_dynamic_onmerge.dir/map_3_dynamic_onmerge.cpp.s

# Object files for target map_3_dynamic_onmerge
map_3_dynamic_onmerge_OBJECTS = \
"CMakeFiles/map_3_dynamic_onmerge.dir/map_3_dynamic_onmerge.cpp.o"

# External object files for target map_3_dynamic_onmerge
map_3_dynamic_onmerge_EXTERNAL_OBJECTS =

examples/Combinatorial_map/map_3_dynamic_onmerge: examples/Combinatorial_map/CMakeFiles/map_3_dynamic_onmerge.dir/map_3_dynamic_onmerge.cpp.o
examples/Combinatorial_map/map_3_dynamic_onmerge: examples/Combinatorial_map/CMakeFiles/map_3_dynamic_onmerge.dir/build.make
examples/Combinatorial_map/map_3_dynamic_onmerge: /usr/lib/x86_64-linux-gnu/libgmpxx.so
examples/Combinatorial_map/map_3_dynamic_onmerge: /usr/lib/x86_64-linux-gnu/libmpfr.so
examples/Combinatorial_map/map_3_dynamic_onmerge: /usr/lib/x86_64-linux-gnu/libgmp.so
examples/Combinatorial_map/map_3_dynamic_onmerge: examples/Combinatorial_map/CMakeFiles/map_3_dynamic_onmerge.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable map_3_dynamic_onmerge"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Combinatorial_map && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/map_3_dynamic_onmerge.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/Combinatorial_map/CMakeFiles/map_3_dynamic_onmerge.dir/build: examples/Combinatorial_map/map_3_dynamic_onmerge
.PHONY : examples/Combinatorial_map/CMakeFiles/map_3_dynamic_onmerge.dir/build

examples/Combinatorial_map/CMakeFiles/map_3_dynamic_onmerge.dir/clean:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Combinatorial_map && $(CMAKE_COMMAND) -P CMakeFiles/map_3_dynamic_onmerge.dir/cmake_clean.cmake
.PHONY : examples/Combinatorial_map/CMakeFiles/map_3_dynamic_onmerge.dir/clean

examples/Combinatorial_map/CMakeFiles/map_3_dynamic_onmerge.dir/depend:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/melina/dev/Geometry/vendor/CGAL-5.6/examples /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Combinatorial_map /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Combinatorial_map /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Combinatorial_map/CMakeFiles/map_3_dynamic_onmerge.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/Combinatorial_map/CMakeFiles/map_3_dynamic_onmerge.dir/depend

