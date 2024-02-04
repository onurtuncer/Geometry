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
include examples/Partition_2/CMakeFiles/y_monotone_partition_indices_2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/Partition_2/CMakeFiles/y_monotone_partition_indices_2.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/Partition_2/CMakeFiles/y_monotone_partition_indices_2.dir/progress.make

# Include the compile flags for this target's objects.
include examples/Partition_2/CMakeFiles/y_monotone_partition_indices_2.dir/flags.make

examples/Partition_2/CMakeFiles/y_monotone_partition_indices_2.dir/y_monotone_partition_indices_2.cpp.o: examples/Partition_2/CMakeFiles/y_monotone_partition_indices_2.dir/flags.make
examples/Partition_2/CMakeFiles/y_monotone_partition_indices_2.dir/y_monotone_partition_indices_2.cpp.o: ../Partition_2/y_monotone_partition_indices_2.cpp
examples/Partition_2/CMakeFiles/y_monotone_partition_indices_2.dir/y_monotone_partition_indices_2.cpp.o: examples/Partition_2/CMakeFiles/y_monotone_partition_indices_2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/Partition_2/CMakeFiles/y_monotone_partition_indices_2.dir/y_monotone_partition_indices_2.cpp.o"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Partition_2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/Partition_2/CMakeFiles/y_monotone_partition_indices_2.dir/y_monotone_partition_indices_2.cpp.o -MF CMakeFiles/y_monotone_partition_indices_2.dir/y_monotone_partition_indices_2.cpp.o.d -o CMakeFiles/y_monotone_partition_indices_2.dir/y_monotone_partition_indices_2.cpp.o -c /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Partition_2/y_monotone_partition_indices_2.cpp

examples/Partition_2/CMakeFiles/y_monotone_partition_indices_2.dir/y_monotone_partition_indices_2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/y_monotone_partition_indices_2.dir/y_monotone_partition_indices_2.cpp.i"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Partition_2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Partition_2/y_monotone_partition_indices_2.cpp > CMakeFiles/y_monotone_partition_indices_2.dir/y_monotone_partition_indices_2.cpp.i

examples/Partition_2/CMakeFiles/y_monotone_partition_indices_2.dir/y_monotone_partition_indices_2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/y_monotone_partition_indices_2.dir/y_monotone_partition_indices_2.cpp.s"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Partition_2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Partition_2/y_monotone_partition_indices_2.cpp -o CMakeFiles/y_monotone_partition_indices_2.dir/y_monotone_partition_indices_2.cpp.s

# Object files for target y_monotone_partition_indices_2
y_monotone_partition_indices_2_OBJECTS = \
"CMakeFiles/y_monotone_partition_indices_2.dir/y_monotone_partition_indices_2.cpp.o"

# External object files for target y_monotone_partition_indices_2
y_monotone_partition_indices_2_EXTERNAL_OBJECTS =

examples/Partition_2/y_monotone_partition_indices_2: examples/Partition_2/CMakeFiles/y_monotone_partition_indices_2.dir/y_monotone_partition_indices_2.cpp.o
examples/Partition_2/y_monotone_partition_indices_2: examples/Partition_2/CMakeFiles/y_monotone_partition_indices_2.dir/build.make
examples/Partition_2/y_monotone_partition_indices_2: /usr/lib/x86_64-linux-gnu/libgmpxx.so
examples/Partition_2/y_monotone_partition_indices_2: /usr/lib/x86_64-linux-gnu/libmpfr.so
examples/Partition_2/y_monotone_partition_indices_2: /usr/lib/x86_64-linux-gnu/libgmp.so
examples/Partition_2/y_monotone_partition_indices_2: examples/Partition_2/CMakeFiles/y_monotone_partition_indices_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable y_monotone_partition_indices_2"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Partition_2 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/y_monotone_partition_indices_2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/Partition_2/CMakeFiles/y_monotone_partition_indices_2.dir/build: examples/Partition_2/y_monotone_partition_indices_2
.PHONY : examples/Partition_2/CMakeFiles/y_monotone_partition_indices_2.dir/build

examples/Partition_2/CMakeFiles/y_monotone_partition_indices_2.dir/clean:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Partition_2 && $(CMAKE_COMMAND) -P CMakeFiles/y_monotone_partition_indices_2.dir/cmake_clean.cmake
.PHONY : examples/Partition_2/CMakeFiles/y_monotone_partition_indices_2.dir/clean

examples/Partition_2/CMakeFiles/y_monotone_partition_indices_2.dir/depend:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/melina/dev/Geometry/vendor/CGAL-5.6/examples /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Partition_2 /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Partition_2 /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Partition_2/CMakeFiles/y_monotone_partition_indices_2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/Partition_2/CMakeFiles/y_monotone_partition_indices_2.dir/depend

