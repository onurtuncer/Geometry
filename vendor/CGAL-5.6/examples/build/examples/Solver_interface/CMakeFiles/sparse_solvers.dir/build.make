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
include examples/Solver_interface/CMakeFiles/sparse_solvers.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/Solver_interface/CMakeFiles/sparse_solvers.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/Solver_interface/CMakeFiles/sparse_solvers.dir/progress.make

# Include the compile flags for this target's objects.
include examples/Solver_interface/CMakeFiles/sparse_solvers.dir/flags.make

examples/Solver_interface/CMakeFiles/sparse_solvers.dir/sparse_solvers.cpp.o: examples/Solver_interface/CMakeFiles/sparse_solvers.dir/flags.make
examples/Solver_interface/CMakeFiles/sparse_solvers.dir/sparse_solvers.cpp.o: ../Solver_interface/sparse_solvers.cpp
examples/Solver_interface/CMakeFiles/sparse_solvers.dir/sparse_solvers.cpp.o: examples/Solver_interface/CMakeFiles/sparse_solvers.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/Solver_interface/CMakeFiles/sparse_solvers.dir/sparse_solvers.cpp.o"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Solver_interface && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/Solver_interface/CMakeFiles/sparse_solvers.dir/sparse_solvers.cpp.o -MF CMakeFiles/sparse_solvers.dir/sparse_solvers.cpp.o.d -o CMakeFiles/sparse_solvers.dir/sparse_solvers.cpp.o -c /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Solver_interface/sparse_solvers.cpp

examples/Solver_interface/CMakeFiles/sparse_solvers.dir/sparse_solvers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sparse_solvers.dir/sparse_solvers.cpp.i"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Solver_interface && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Solver_interface/sparse_solvers.cpp > CMakeFiles/sparse_solvers.dir/sparse_solvers.cpp.i

examples/Solver_interface/CMakeFiles/sparse_solvers.dir/sparse_solvers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sparse_solvers.dir/sparse_solvers.cpp.s"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Solver_interface && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Solver_interface/sparse_solvers.cpp -o CMakeFiles/sparse_solvers.dir/sparse_solvers.cpp.s

# Object files for target sparse_solvers
sparse_solvers_OBJECTS = \
"CMakeFiles/sparse_solvers.dir/sparse_solvers.cpp.o"

# External object files for target sparse_solvers
sparse_solvers_EXTERNAL_OBJECTS =

examples/Solver_interface/sparse_solvers: examples/Solver_interface/CMakeFiles/sparse_solvers.dir/sparse_solvers.cpp.o
examples/Solver_interface/sparse_solvers: examples/Solver_interface/CMakeFiles/sparse_solvers.dir/build.make
examples/Solver_interface/sparse_solvers: /usr/lib/x86_64-linux-gnu/libgmpxx.so
examples/Solver_interface/sparse_solvers: /usr/lib/x86_64-linux-gnu/libmpfr.so
examples/Solver_interface/sparse_solvers: /usr/lib/x86_64-linux-gnu/libgmp.so
examples/Solver_interface/sparse_solvers: examples/Solver_interface/CMakeFiles/sparse_solvers.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sparse_solvers"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Solver_interface && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sparse_solvers.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/Solver_interface/CMakeFiles/sparse_solvers.dir/build: examples/Solver_interface/sparse_solvers
.PHONY : examples/Solver_interface/CMakeFiles/sparse_solvers.dir/build

examples/Solver_interface/CMakeFiles/sparse_solvers.dir/clean:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Solver_interface && $(CMAKE_COMMAND) -P CMakeFiles/sparse_solvers.dir/cmake_clean.cmake
.PHONY : examples/Solver_interface/CMakeFiles/sparse_solvers.dir/clean

examples/Solver_interface/CMakeFiles/sparse_solvers.dir/depend:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/melina/dev/Geometry/vendor/CGAL-5.6/examples /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Solver_interface /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Solver_interface /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Solver_interface/CMakeFiles/sparse_solvers.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/Solver_interface/CMakeFiles/sparse_solvers.dir/depend

