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
include examples/Minkowski_sum_2/CMakeFiles/sum_by_decomposition.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/Minkowski_sum_2/CMakeFiles/sum_by_decomposition.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/Minkowski_sum_2/CMakeFiles/sum_by_decomposition.dir/progress.make

# Include the compile flags for this target's objects.
include examples/Minkowski_sum_2/CMakeFiles/sum_by_decomposition.dir/flags.make

examples/Minkowski_sum_2/CMakeFiles/sum_by_decomposition.dir/sum_by_decomposition.cpp.o: examples/Minkowski_sum_2/CMakeFiles/sum_by_decomposition.dir/flags.make
examples/Minkowski_sum_2/CMakeFiles/sum_by_decomposition.dir/sum_by_decomposition.cpp.o: ../Minkowski_sum_2/sum_by_decomposition.cpp
examples/Minkowski_sum_2/CMakeFiles/sum_by_decomposition.dir/sum_by_decomposition.cpp.o: examples/Minkowski_sum_2/CMakeFiles/sum_by_decomposition.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/Minkowski_sum_2/CMakeFiles/sum_by_decomposition.dir/sum_by_decomposition.cpp.o"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Minkowski_sum_2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/Minkowski_sum_2/CMakeFiles/sum_by_decomposition.dir/sum_by_decomposition.cpp.o -MF CMakeFiles/sum_by_decomposition.dir/sum_by_decomposition.cpp.o.d -o CMakeFiles/sum_by_decomposition.dir/sum_by_decomposition.cpp.o -c /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Minkowski_sum_2/sum_by_decomposition.cpp

examples/Minkowski_sum_2/CMakeFiles/sum_by_decomposition.dir/sum_by_decomposition.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sum_by_decomposition.dir/sum_by_decomposition.cpp.i"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Minkowski_sum_2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Minkowski_sum_2/sum_by_decomposition.cpp > CMakeFiles/sum_by_decomposition.dir/sum_by_decomposition.cpp.i

examples/Minkowski_sum_2/CMakeFiles/sum_by_decomposition.dir/sum_by_decomposition.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sum_by_decomposition.dir/sum_by_decomposition.cpp.s"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Minkowski_sum_2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Minkowski_sum_2/sum_by_decomposition.cpp -o CMakeFiles/sum_by_decomposition.dir/sum_by_decomposition.cpp.s

# Object files for target sum_by_decomposition
sum_by_decomposition_OBJECTS = \
"CMakeFiles/sum_by_decomposition.dir/sum_by_decomposition.cpp.o"

# External object files for target sum_by_decomposition
sum_by_decomposition_EXTERNAL_OBJECTS =

examples/Minkowski_sum_2/sum_by_decomposition: examples/Minkowski_sum_2/CMakeFiles/sum_by_decomposition.dir/sum_by_decomposition.cpp.o
examples/Minkowski_sum_2/sum_by_decomposition: examples/Minkowski_sum_2/CMakeFiles/sum_by_decomposition.dir/build.make
examples/Minkowski_sum_2/sum_by_decomposition: /usr/lib/x86_64-linux-gnu/libgmpxx.so
examples/Minkowski_sum_2/sum_by_decomposition: /usr/lib/x86_64-linux-gnu/libmpfr.so
examples/Minkowski_sum_2/sum_by_decomposition: /usr/lib/x86_64-linux-gnu/libgmp.so
examples/Minkowski_sum_2/sum_by_decomposition: examples/Minkowski_sum_2/CMakeFiles/sum_by_decomposition.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sum_by_decomposition"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Minkowski_sum_2 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sum_by_decomposition.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/Minkowski_sum_2/CMakeFiles/sum_by_decomposition.dir/build: examples/Minkowski_sum_2/sum_by_decomposition
.PHONY : examples/Minkowski_sum_2/CMakeFiles/sum_by_decomposition.dir/build

examples/Minkowski_sum_2/CMakeFiles/sum_by_decomposition.dir/clean:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Minkowski_sum_2 && $(CMAKE_COMMAND) -P CMakeFiles/sum_by_decomposition.dir/cmake_clean.cmake
.PHONY : examples/Minkowski_sum_2/CMakeFiles/sum_by_decomposition.dir/clean

examples/Minkowski_sum_2/CMakeFiles/sum_by_decomposition.dir/depend:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/melina/dev/Geometry/vendor/CGAL-5.6/examples /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Minkowski_sum_2 /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Minkowski_sum_2 /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Minkowski_sum_2/CMakeFiles/sum_by_decomposition.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/Minkowski_sum_2/CMakeFiles/sum_by_decomposition.dir/depend

