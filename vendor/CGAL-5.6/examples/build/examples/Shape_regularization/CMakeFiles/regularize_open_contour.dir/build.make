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
include examples/Shape_regularization/CMakeFiles/regularize_open_contour.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/Shape_regularization/CMakeFiles/regularize_open_contour.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/Shape_regularization/CMakeFiles/regularize_open_contour.dir/progress.make

# Include the compile flags for this target's objects.
include examples/Shape_regularization/CMakeFiles/regularize_open_contour.dir/flags.make

examples/Shape_regularization/CMakeFiles/regularize_open_contour.dir/regularize_open_contour.cpp.o: examples/Shape_regularization/CMakeFiles/regularize_open_contour.dir/flags.make
examples/Shape_regularization/CMakeFiles/regularize_open_contour.dir/regularize_open_contour.cpp.o: ../Shape_regularization/regularize_open_contour.cpp
examples/Shape_regularization/CMakeFiles/regularize_open_contour.dir/regularize_open_contour.cpp.o: examples/Shape_regularization/CMakeFiles/regularize_open_contour.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/Shape_regularization/CMakeFiles/regularize_open_contour.dir/regularize_open_contour.cpp.o"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Shape_regularization && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/Shape_regularization/CMakeFiles/regularize_open_contour.dir/regularize_open_contour.cpp.o -MF CMakeFiles/regularize_open_contour.dir/regularize_open_contour.cpp.o.d -o CMakeFiles/regularize_open_contour.dir/regularize_open_contour.cpp.o -c /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Shape_regularization/regularize_open_contour.cpp

examples/Shape_regularization/CMakeFiles/regularize_open_contour.dir/regularize_open_contour.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/regularize_open_contour.dir/regularize_open_contour.cpp.i"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Shape_regularization && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Shape_regularization/regularize_open_contour.cpp > CMakeFiles/regularize_open_contour.dir/regularize_open_contour.cpp.i

examples/Shape_regularization/CMakeFiles/regularize_open_contour.dir/regularize_open_contour.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/regularize_open_contour.dir/regularize_open_contour.cpp.s"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Shape_regularization && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Shape_regularization/regularize_open_contour.cpp -o CMakeFiles/regularize_open_contour.dir/regularize_open_contour.cpp.s

# Object files for target regularize_open_contour
regularize_open_contour_OBJECTS = \
"CMakeFiles/regularize_open_contour.dir/regularize_open_contour.cpp.o"

# External object files for target regularize_open_contour
regularize_open_contour_EXTERNAL_OBJECTS =

examples/Shape_regularization/regularize_open_contour: examples/Shape_regularization/CMakeFiles/regularize_open_contour.dir/regularize_open_contour.cpp.o
examples/Shape_regularization/regularize_open_contour: examples/Shape_regularization/CMakeFiles/regularize_open_contour.dir/build.make
examples/Shape_regularization/regularize_open_contour: /usr/lib/x86_64-linux-gnu/libgmpxx.so
examples/Shape_regularization/regularize_open_contour: /usr/lib/x86_64-linux-gnu/libmpfr.so
examples/Shape_regularization/regularize_open_contour: /usr/lib/x86_64-linux-gnu/libgmp.so
examples/Shape_regularization/regularize_open_contour: examples/Shape_regularization/CMakeFiles/regularize_open_contour.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable regularize_open_contour"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Shape_regularization && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/regularize_open_contour.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/Shape_regularization/CMakeFiles/regularize_open_contour.dir/build: examples/Shape_regularization/regularize_open_contour
.PHONY : examples/Shape_regularization/CMakeFiles/regularize_open_contour.dir/build

examples/Shape_regularization/CMakeFiles/regularize_open_contour.dir/clean:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Shape_regularization && $(CMAKE_COMMAND) -P CMakeFiles/regularize_open_contour.dir/cmake_clean.cmake
.PHONY : examples/Shape_regularization/CMakeFiles/regularize_open_contour.dir/clean

examples/Shape_regularization/CMakeFiles/regularize_open_contour.dir/depend:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/melina/dev/Geometry/vendor/CGAL-5.6/examples /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Shape_regularization /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Shape_regularization /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Shape_regularization/CMakeFiles/regularize_open_contour.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/Shape_regularization/CMakeFiles/regularize_open_contour.dir/depend

