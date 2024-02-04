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
include examples/Combinatorial_map/CMakeFiles/map_3_operations.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/Combinatorial_map/CMakeFiles/map_3_operations.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/Combinatorial_map/CMakeFiles/map_3_operations.dir/progress.make

# Include the compile flags for this target's objects.
include examples/Combinatorial_map/CMakeFiles/map_3_operations.dir/flags.make

examples/Combinatorial_map/CMakeFiles/map_3_operations.dir/map_3_operations.cpp.o: examples/Combinatorial_map/CMakeFiles/map_3_operations.dir/flags.make
examples/Combinatorial_map/CMakeFiles/map_3_operations.dir/map_3_operations.cpp.o: ../Combinatorial_map/map_3_operations.cpp
examples/Combinatorial_map/CMakeFiles/map_3_operations.dir/map_3_operations.cpp.o: examples/Combinatorial_map/CMakeFiles/map_3_operations.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/Combinatorial_map/CMakeFiles/map_3_operations.dir/map_3_operations.cpp.o"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Combinatorial_map && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/Combinatorial_map/CMakeFiles/map_3_operations.dir/map_3_operations.cpp.o -MF CMakeFiles/map_3_operations.dir/map_3_operations.cpp.o.d -o CMakeFiles/map_3_operations.dir/map_3_operations.cpp.o -c /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Combinatorial_map/map_3_operations.cpp

examples/Combinatorial_map/CMakeFiles/map_3_operations.dir/map_3_operations.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/map_3_operations.dir/map_3_operations.cpp.i"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Combinatorial_map && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Combinatorial_map/map_3_operations.cpp > CMakeFiles/map_3_operations.dir/map_3_operations.cpp.i

examples/Combinatorial_map/CMakeFiles/map_3_operations.dir/map_3_operations.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/map_3_operations.dir/map_3_operations.cpp.s"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Combinatorial_map && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Combinatorial_map/map_3_operations.cpp -o CMakeFiles/map_3_operations.dir/map_3_operations.cpp.s

# Object files for target map_3_operations
map_3_operations_OBJECTS = \
"CMakeFiles/map_3_operations.dir/map_3_operations.cpp.o"

# External object files for target map_3_operations
map_3_operations_EXTERNAL_OBJECTS =

examples/Combinatorial_map/map_3_operations: examples/Combinatorial_map/CMakeFiles/map_3_operations.dir/map_3_operations.cpp.o
examples/Combinatorial_map/map_3_operations: examples/Combinatorial_map/CMakeFiles/map_3_operations.dir/build.make
examples/Combinatorial_map/map_3_operations: /usr/lib/x86_64-linux-gnu/libgmpxx.so
examples/Combinatorial_map/map_3_operations: /usr/lib/x86_64-linux-gnu/libmpfr.so
examples/Combinatorial_map/map_3_operations: /usr/lib/x86_64-linux-gnu/libgmp.so
examples/Combinatorial_map/map_3_operations: examples/Combinatorial_map/CMakeFiles/map_3_operations.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable map_3_operations"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Combinatorial_map && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/map_3_operations.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/Combinatorial_map/CMakeFiles/map_3_operations.dir/build: examples/Combinatorial_map/map_3_operations
.PHONY : examples/Combinatorial_map/CMakeFiles/map_3_operations.dir/build

examples/Combinatorial_map/CMakeFiles/map_3_operations.dir/clean:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Combinatorial_map && $(CMAKE_COMMAND) -P CMakeFiles/map_3_operations.dir/cmake_clean.cmake
.PHONY : examples/Combinatorial_map/CMakeFiles/map_3_operations.dir/clean

examples/Combinatorial_map/CMakeFiles/map_3_operations.dir/depend:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/melina/dev/Geometry/vendor/CGAL-5.6/examples /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Combinatorial_map /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Combinatorial_map /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Combinatorial_map/CMakeFiles/map_3_operations.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/Combinatorial_map/CMakeFiles/map_3_operations.dir/depend

