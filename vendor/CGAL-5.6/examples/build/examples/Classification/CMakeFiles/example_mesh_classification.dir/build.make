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
include examples/Classification/CMakeFiles/example_mesh_classification.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/Classification/CMakeFiles/example_mesh_classification.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/Classification/CMakeFiles/example_mesh_classification.dir/progress.make

# Include the compile flags for this target's objects.
include examples/Classification/CMakeFiles/example_mesh_classification.dir/flags.make

examples/Classification/CMakeFiles/example_mesh_classification.dir/example_mesh_classification.cpp.o: examples/Classification/CMakeFiles/example_mesh_classification.dir/flags.make
examples/Classification/CMakeFiles/example_mesh_classification.dir/example_mesh_classification.cpp.o: ../Classification/example_mesh_classification.cpp
examples/Classification/CMakeFiles/example_mesh_classification.dir/example_mesh_classification.cpp.o: examples/Classification/CMakeFiles/example_mesh_classification.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/Classification/CMakeFiles/example_mesh_classification.dir/example_mesh_classification.cpp.o"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Classification && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/Classification/CMakeFiles/example_mesh_classification.dir/example_mesh_classification.cpp.o -MF CMakeFiles/example_mesh_classification.dir/example_mesh_classification.cpp.o.d -o CMakeFiles/example_mesh_classification.dir/example_mesh_classification.cpp.o -c /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Classification/example_mesh_classification.cpp

examples/Classification/CMakeFiles/example_mesh_classification.dir/example_mesh_classification.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example_mesh_classification.dir/example_mesh_classification.cpp.i"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Classification && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Classification/example_mesh_classification.cpp > CMakeFiles/example_mesh_classification.dir/example_mesh_classification.cpp.i

examples/Classification/CMakeFiles/example_mesh_classification.dir/example_mesh_classification.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example_mesh_classification.dir/example_mesh_classification.cpp.s"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Classification && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Classification/example_mesh_classification.cpp -o CMakeFiles/example_mesh_classification.dir/example_mesh_classification.cpp.s

# Object files for target example_mesh_classification
example_mesh_classification_OBJECTS = \
"CMakeFiles/example_mesh_classification.dir/example_mesh_classification.cpp.o"

# External object files for target example_mesh_classification
example_mesh_classification_EXTERNAL_OBJECTS =

examples/Classification/example_mesh_classification: examples/Classification/CMakeFiles/example_mesh_classification.dir/example_mesh_classification.cpp.o
examples/Classification/example_mesh_classification: examples/Classification/CMakeFiles/example_mesh_classification.dir/build.make
examples/Classification/example_mesh_classification: /usr/lib/x86_64-linux-gnu/libgmpxx.so
examples/Classification/example_mesh_classification: /usr/lib/x86_64-linux-gnu/libmpfr.so
examples/Classification/example_mesh_classification: /usr/lib/x86_64-linux-gnu/libgmp.so
examples/Classification/example_mesh_classification: /usr/lib/x86_64-linux-gnu/libboost_iostreams.so.1.74.0
examples/Classification/example_mesh_classification: /usr/lib/x86_64-linux-gnu/libz.so
examples/Classification/example_mesh_classification: /usr/lib/x86_64-linux-gnu/libboost_serialization.so.1.74.0
examples/Classification/example_mesh_classification: /usr/lib/x86_64-linux-gnu/libtbb.so.12.5
examples/Classification/example_mesh_classification: /usr/lib/x86_64-linux-gnu/libtbbmalloc.so.2.5
examples/Classification/example_mesh_classification: examples/Classification/CMakeFiles/example_mesh_classification.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable example_mesh_classification"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Classification && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example_mesh_classification.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/Classification/CMakeFiles/example_mesh_classification.dir/build: examples/Classification/example_mesh_classification
.PHONY : examples/Classification/CMakeFiles/example_mesh_classification.dir/build

examples/Classification/CMakeFiles/example_mesh_classification.dir/clean:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Classification && $(CMAKE_COMMAND) -P CMakeFiles/example_mesh_classification.dir/cmake_clean.cmake
.PHONY : examples/Classification/CMakeFiles/example_mesh_classification.dir/clean

examples/Classification/CMakeFiles/example_mesh_classification.dir/depend:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/melina/dev/Geometry/vendor/CGAL-5.6/examples /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Classification /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Classification /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Classification/CMakeFiles/example_mesh_classification.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/Classification/CMakeFiles/example_mesh_classification.dir/depend

