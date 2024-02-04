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
include examples/Triangulation/CMakeFiles/barycentric_subdivision.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/Triangulation/CMakeFiles/barycentric_subdivision.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/Triangulation/CMakeFiles/barycentric_subdivision.dir/progress.make

# Include the compile flags for this target's objects.
include examples/Triangulation/CMakeFiles/barycentric_subdivision.dir/flags.make

examples/Triangulation/CMakeFiles/barycentric_subdivision.dir/barycentric_subdivision.cpp.o: examples/Triangulation/CMakeFiles/barycentric_subdivision.dir/flags.make
examples/Triangulation/CMakeFiles/barycentric_subdivision.dir/barycentric_subdivision.cpp.o: ../Triangulation/barycentric_subdivision.cpp
examples/Triangulation/CMakeFiles/barycentric_subdivision.dir/barycentric_subdivision.cpp.o: examples/Triangulation/CMakeFiles/barycentric_subdivision.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/Triangulation/CMakeFiles/barycentric_subdivision.dir/barycentric_subdivision.cpp.o"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Triangulation && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/Triangulation/CMakeFiles/barycentric_subdivision.dir/barycentric_subdivision.cpp.o -MF CMakeFiles/barycentric_subdivision.dir/barycentric_subdivision.cpp.o.d -o CMakeFiles/barycentric_subdivision.dir/barycentric_subdivision.cpp.o -c /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Triangulation/barycentric_subdivision.cpp

examples/Triangulation/CMakeFiles/barycentric_subdivision.dir/barycentric_subdivision.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/barycentric_subdivision.dir/barycentric_subdivision.cpp.i"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Triangulation && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Triangulation/barycentric_subdivision.cpp > CMakeFiles/barycentric_subdivision.dir/barycentric_subdivision.cpp.i

examples/Triangulation/CMakeFiles/barycentric_subdivision.dir/barycentric_subdivision.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/barycentric_subdivision.dir/barycentric_subdivision.cpp.s"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Triangulation && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Triangulation/barycentric_subdivision.cpp -o CMakeFiles/barycentric_subdivision.dir/barycentric_subdivision.cpp.s

# Object files for target barycentric_subdivision
barycentric_subdivision_OBJECTS = \
"CMakeFiles/barycentric_subdivision.dir/barycentric_subdivision.cpp.o"

# External object files for target barycentric_subdivision
barycentric_subdivision_EXTERNAL_OBJECTS =

examples/Triangulation/barycentric_subdivision: examples/Triangulation/CMakeFiles/barycentric_subdivision.dir/barycentric_subdivision.cpp.o
examples/Triangulation/barycentric_subdivision: examples/Triangulation/CMakeFiles/barycentric_subdivision.dir/build.make
examples/Triangulation/barycentric_subdivision: /usr/lib/x86_64-linux-gnu/libgmpxx.so
examples/Triangulation/barycentric_subdivision: /usr/lib/x86_64-linux-gnu/libmpfr.so
examples/Triangulation/barycentric_subdivision: /usr/lib/x86_64-linux-gnu/libgmp.so
examples/Triangulation/barycentric_subdivision: examples/Triangulation/CMakeFiles/barycentric_subdivision.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable barycentric_subdivision"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Triangulation && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/barycentric_subdivision.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/Triangulation/CMakeFiles/barycentric_subdivision.dir/build: examples/Triangulation/barycentric_subdivision
.PHONY : examples/Triangulation/CMakeFiles/barycentric_subdivision.dir/build

examples/Triangulation/CMakeFiles/barycentric_subdivision.dir/clean:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Triangulation && $(CMAKE_COMMAND) -P CMakeFiles/barycentric_subdivision.dir/cmake_clean.cmake
.PHONY : examples/Triangulation/CMakeFiles/barycentric_subdivision.dir/clean

examples/Triangulation/CMakeFiles/barycentric_subdivision.dir/depend:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/melina/dev/Geometry/vendor/CGAL-5.6/examples /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Triangulation /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Triangulation /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Triangulation/CMakeFiles/barycentric_subdivision.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/Triangulation/CMakeFiles/barycentric_subdivision.dir/depend

