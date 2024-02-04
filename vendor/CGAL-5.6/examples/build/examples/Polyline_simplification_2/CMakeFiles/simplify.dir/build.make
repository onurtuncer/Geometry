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
include examples/Polyline_simplification_2/CMakeFiles/simplify.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/Polyline_simplification_2/CMakeFiles/simplify.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/Polyline_simplification_2/CMakeFiles/simplify.dir/progress.make

# Include the compile flags for this target's objects.
include examples/Polyline_simplification_2/CMakeFiles/simplify.dir/flags.make

examples/Polyline_simplification_2/CMakeFiles/simplify.dir/simplify.cpp.o: examples/Polyline_simplification_2/CMakeFiles/simplify.dir/flags.make
examples/Polyline_simplification_2/CMakeFiles/simplify.dir/simplify.cpp.o: ../Polyline_simplification_2/simplify.cpp
examples/Polyline_simplification_2/CMakeFiles/simplify.dir/simplify.cpp.o: examples/Polyline_simplification_2/CMakeFiles/simplify.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/Polyline_simplification_2/CMakeFiles/simplify.dir/simplify.cpp.o"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Polyline_simplification_2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/Polyline_simplification_2/CMakeFiles/simplify.dir/simplify.cpp.o -MF CMakeFiles/simplify.dir/simplify.cpp.o.d -o CMakeFiles/simplify.dir/simplify.cpp.o -c /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Polyline_simplification_2/simplify.cpp

examples/Polyline_simplification_2/CMakeFiles/simplify.dir/simplify.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simplify.dir/simplify.cpp.i"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Polyline_simplification_2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Polyline_simplification_2/simplify.cpp > CMakeFiles/simplify.dir/simplify.cpp.i

examples/Polyline_simplification_2/CMakeFiles/simplify.dir/simplify.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simplify.dir/simplify.cpp.s"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Polyline_simplification_2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Polyline_simplification_2/simplify.cpp -o CMakeFiles/simplify.dir/simplify.cpp.s

# Object files for target simplify
simplify_OBJECTS = \
"CMakeFiles/simplify.dir/simplify.cpp.o"

# External object files for target simplify
simplify_EXTERNAL_OBJECTS =

examples/Polyline_simplification_2/simplify: examples/Polyline_simplification_2/CMakeFiles/simplify.dir/simplify.cpp.o
examples/Polyline_simplification_2/simplify: examples/Polyline_simplification_2/CMakeFiles/simplify.dir/build.make
examples/Polyline_simplification_2/simplify: /usr/lib/x86_64-linux-gnu/libgmpxx.so
examples/Polyline_simplification_2/simplify: /usr/lib/x86_64-linux-gnu/libmpfr.so
examples/Polyline_simplification_2/simplify: /usr/lib/x86_64-linux-gnu/libgmp.so
examples/Polyline_simplification_2/simplify: examples/Polyline_simplification_2/CMakeFiles/simplify.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable simplify"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Polyline_simplification_2 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simplify.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/Polyline_simplification_2/CMakeFiles/simplify.dir/build: examples/Polyline_simplification_2/simplify
.PHONY : examples/Polyline_simplification_2/CMakeFiles/simplify.dir/build

examples/Polyline_simplification_2/CMakeFiles/simplify.dir/clean:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Polyline_simplification_2 && $(CMAKE_COMMAND) -P CMakeFiles/simplify.dir/cmake_clean.cmake
.PHONY : examples/Polyline_simplification_2/CMakeFiles/simplify.dir/clean

examples/Polyline_simplification_2/CMakeFiles/simplify.dir/depend:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/melina/dev/Geometry/vendor/CGAL-5.6/examples /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Polyline_simplification_2 /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Polyline_simplification_2 /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Polyline_simplification_2/CMakeFiles/simplify.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/Polyline_simplification_2/CMakeFiles/simplify.dir/depend

