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
include examples/Scale_space_reconstruction_3/CMakeFiles/scale_space_advancing_front.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/Scale_space_reconstruction_3/CMakeFiles/scale_space_advancing_front.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/Scale_space_reconstruction_3/CMakeFiles/scale_space_advancing_front.dir/progress.make

# Include the compile flags for this target's objects.
include examples/Scale_space_reconstruction_3/CMakeFiles/scale_space_advancing_front.dir/flags.make

examples/Scale_space_reconstruction_3/CMakeFiles/scale_space_advancing_front.dir/scale_space_advancing_front.cpp.o: examples/Scale_space_reconstruction_3/CMakeFiles/scale_space_advancing_front.dir/flags.make
examples/Scale_space_reconstruction_3/CMakeFiles/scale_space_advancing_front.dir/scale_space_advancing_front.cpp.o: ../Scale_space_reconstruction_3/scale_space_advancing_front.cpp
examples/Scale_space_reconstruction_3/CMakeFiles/scale_space_advancing_front.dir/scale_space_advancing_front.cpp.o: examples/Scale_space_reconstruction_3/CMakeFiles/scale_space_advancing_front.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/Scale_space_reconstruction_3/CMakeFiles/scale_space_advancing_front.dir/scale_space_advancing_front.cpp.o"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Scale_space_reconstruction_3 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/Scale_space_reconstruction_3/CMakeFiles/scale_space_advancing_front.dir/scale_space_advancing_front.cpp.o -MF CMakeFiles/scale_space_advancing_front.dir/scale_space_advancing_front.cpp.o.d -o CMakeFiles/scale_space_advancing_front.dir/scale_space_advancing_front.cpp.o -c /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Scale_space_reconstruction_3/scale_space_advancing_front.cpp

examples/Scale_space_reconstruction_3/CMakeFiles/scale_space_advancing_front.dir/scale_space_advancing_front.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/scale_space_advancing_front.dir/scale_space_advancing_front.cpp.i"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Scale_space_reconstruction_3 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Scale_space_reconstruction_3/scale_space_advancing_front.cpp > CMakeFiles/scale_space_advancing_front.dir/scale_space_advancing_front.cpp.i

examples/Scale_space_reconstruction_3/CMakeFiles/scale_space_advancing_front.dir/scale_space_advancing_front.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/scale_space_advancing_front.dir/scale_space_advancing_front.cpp.s"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Scale_space_reconstruction_3 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Scale_space_reconstruction_3/scale_space_advancing_front.cpp -o CMakeFiles/scale_space_advancing_front.dir/scale_space_advancing_front.cpp.s

# Object files for target scale_space_advancing_front
scale_space_advancing_front_OBJECTS = \
"CMakeFiles/scale_space_advancing_front.dir/scale_space_advancing_front.cpp.o"

# External object files for target scale_space_advancing_front
scale_space_advancing_front_EXTERNAL_OBJECTS =

examples/Scale_space_reconstruction_3/scale_space_advancing_front: examples/Scale_space_reconstruction_3/CMakeFiles/scale_space_advancing_front.dir/scale_space_advancing_front.cpp.o
examples/Scale_space_reconstruction_3/scale_space_advancing_front: examples/Scale_space_reconstruction_3/CMakeFiles/scale_space_advancing_front.dir/build.make
examples/Scale_space_reconstruction_3/scale_space_advancing_front: /usr/lib/x86_64-linux-gnu/libgmpxx.so
examples/Scale_space_reconstruction_3/scale_space_advancing_front: /usr/lib/x86_64-linux-gnu/libmpfr.so
examples/Scale_space_reconstruction_3/scale_space_advancing_front: /usr/lib/x86_64-linux-gnu/libgmp.so
examples/Scale_space_reconstruction_3/scale_space_advancing_front: /usr/lib/x86_64-linux-gnu/libtbb.so.12.5
examples/Scale_space_reconstruction_3/scale_space_advancing_front: /usr/lib/x86_64-linux-gnu/libtbbmalloc.so.2.5
examples/Scale_space_reconstruction_3/scale_space_advancing_front: examples/Scale_space_reconstruction_3/CMakeFiles/scale_space_advancing_front.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable scale_space_advancing_front"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Scale_space_reconstruction_3 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/scale_space_advancing_front.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/Scale_space_reconstruction_3/CMakeFiles/scale_space_advancing_front.dir/build: examples/Scale_space_reconstruction_3/scale_space_advancing_front
.PHONY : examples/Scale_space_reconstruction_3/CMakeFiles/scale_space_advancing_front.dir/build

examples/Scale_space_reconstruction_3/CMakeFiles/scale_space_advancing_front.dir/clean:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Scale_space_reconstruction_3 && $(CMAKE_COMMAND) -P CMakeFiles/scale_space_advancing_front.dir/cmake_clean.cmake
.PHONY : examples/Scale_space_reconstruction_3/CMakeFiles/scale_space_advancing_front.dir/clean

examples/Scale_space_reconstruction_3/CMakeFiles/scale_space_advancing_front.dir/depend:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/melina/dev/Geometry/vendor/CGAL-5.6/examples /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Scale_space_reconstruction_3 /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Scale_space_reconstruction_3 /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Scale_space_reconstruction_3/CMakeFiles/scale_space_advancing_front.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/Scale_space_reconstruction_3/CMakeFiles/scale_space_advancing_front.dir/depend

