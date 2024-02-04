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
include examples/Min_quadrilateral_2/CMakeFiles/minimum_enclosing_strip_2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/Min_quadrilateral_2/CMakeFiles/minimum_enclosing_strip_2.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/Min_quadrilateral_2/CMakeFiles/minimum_enclosing_strip_2.dir/progress.make

# Include the compile flags for this target's objects.
include examples/Min_quadrilateral_2/CMakeFiles/minimum_enclosing_strip_2.dir/flags.make

examples/Min_quadrilateral_2/CMakeFiles/minimum_enclosing_strip_2.dir/minimum_enclosing_strip_2.cpp.o: examples/Min_quadrilateral_2/CMakeFiles/minimum_enclosing_strip_2.dir/flags.make
examples/Min_quadrilateral_2/CMakeFiles/minimum_enclosing_strip_2.dir/minimum_enclosing_strip_2.cpp.o: ../Min_quadrilateral_2/minimum_enclosing_strip_2.cpp
examples/Min_quadrilateral_2/CMakeFiles/minimum_enclosing_strip_2.dir/minimum_enclosing_strip_2.cpp.o: examples/Min_quadrilateral_2/CMakeFiles/minimum_enclosing_strip_2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/Min_quadrilateral_2/CMakeFiles/minimum_enclosing_strip_2.dir/minimum_enclosing_strip_2.cpp.o"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Min_quadrilateral_2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/Min_quadrilateral_2/CMakeFiles/minimum_enclosing_strip_2.dir/minimum_enclosing_strip_2.cpp.o -MF CMakeFiles/minimum_enclosing_strip_2.dir/minimum_enclosing_strip_2.cpp.o.d -o CMakeFiles/minimum_enclosing_strip_2.dir/minimum_enclosing_strip_2.cpp.o -c /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Min_quadrilateral_2/minimum_enclosing_strip_2.cpp

examples/Min_quadrilateral_2/CMakeFiles/minimum_enclosing_strip_2.dir/minimum_enclosing_strip_2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/minimum_enclosing_strip_2.dir/minimum_enclosing_strip_2.cpp.i"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Min_quadrilateral_2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Min_quadrilateral_2/minimum_enclosing_strip_2.cpp > CMakeFiles/minimum_enclosing_strip_2.dir/minimum_enclosing_strip_2.cpp.i

examples/Min_quadrilateral_2/CMakeFiles/minimum_enclosing_strip_2.dir/minimum_enclosing_strip_2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/minimum_enclosing_strip_2.dir/minimum_enclosing_strip_2.cpp.s"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Min_quadrilateral_2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Min_quadrilateral_2/minimum_enclosing_strip_2.cpp -o CMakeFiles/minimum_enclosing_strip_2.dir/minimum_enclosing_strip_2.cpp.s

# Object files for target minimum_enclosing_strip_2
minimum_enclosing_strip_2_OBJECTS = \
"CMakeFiles/minimum_enclosing_strip_2.dir/minimum_enclosing_strip_2.cpp.o"

# External object files for target minimum_enclosing_strip_2
minimum_enclosing_strip_2_EXTERNAL_OBJECTS =

examples/Min_quadrilateral_2/minimum_enclosing_strip_2: examples/Min_quadrilateral_2/CMakeFiles/minimum_enclosing_strip_2.dir/minimum_enclosing_strip_2.cpp.o
examples/Min_quadrilateral_2/minimum_enclosing_strip_2: examples/Min_quadrilateral_2/CMakeFiles/minimum_enclosing_strip_2.dir/build.make
examples/Min_quadrilateral_2/minimum_enclosing_strip_2: /usr/lib/x86_64-linux-gnu/libgmpxx.so
examples/Min_quadrilateral_2/minimum_enclosing_strip_2: /usr/lib/x86_64-linux-gnu/libmpfr.so
examples/Min_quadrilateral_2/minimum_enclosing_strip_2: /usr/lib/x86_64-linux-gnu/libgmp.so
examples/Min_quadrilateral_2/minimum_enclosing_strip_2: examples/Min_quadrilateral_2/CMakeFiles/minimum_enclosing_strip_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable minimum_enclosing_strip_2"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Min_quadrilateral_2 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/minimum_enclosing_strip_2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/Min_quadrilateral_2/CMakeFiles/minimum_enclosing_strip_2.dir/build: examples/Min_quadrilateral_2/minimum_enclosing_strip_2
.PHONY : examples/Min_quadrilateral_2/CMakeFiles/minimum_enclosing_strip_2.dir/build

examples/Min_quadrilateral_2/CMakeFiles/minimum_enclosing_strip_2.dir/clean:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Min_quadrilateral_2 && $(CMAKE_COMMAND) -P CMakeFiles/minimum_enclosing_strip_2.dir/cmake_clean.cmake
.PHONY : examples/Min_quadrilateral_2/CMakeFiles/minimum_enclosing_strip_2.dir/clean

examples/Min_quadrilateral_2/CMakeFiles/minimum_enclosing_strip_2.dir/depend:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/melina/dev/Geometry/vendor/CGAL-5.6/examples /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Min_quadrilateral_2 /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Min_quadrilateral_2 /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Min_quadrilateral_2/CMakeFiles/minimum_enclosing_strip_2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/Min_quadrilateral_2/CMakeFiles/minimum_enclosing_strip_2.dir/depend

