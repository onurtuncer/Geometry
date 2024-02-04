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
include examples/Weights/CMakeFiles/convergence.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/Weights/CMakeFiles/convergence.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/Weights/CMakeFiles/convergence.dir/progress.make

# Include the compile flags for this target's objects.
include examples/Weights/CMakeFiles/convergence.dir/flags.make

examples/Weights/CMakeFiles/convergence.dir/convergence.cpp.o: examples/Weights/CMakeFiles/convergence.dir/flags.make
examples/Weights/CMakeFiles/convergence.dir/convergence.cpp.o: ../Weights/convergence.cpp
examples/Weights/CMakeFiles/convergence.dir/convergence.cpp.o: examples/Weights/CMakeFiles/convergence.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/Weights/CMakeFiles/convergence.dir/convergence.cpp.o"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Weights && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/Weights/CMakeFiles/convergence.dir/convergence.cpp.o -MF CMakeFiles/convergence.dir/convergence.cpp.o.d -o CMakeFiles/convergence.dir/convergence.cpp.o -c /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Weights/convergence.cpp

examples/Weights/CMakeFiles/convergence.dir/convergence.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/convergence.dir/convergence.cpp.i"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Weights && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Weights/convergence.cpp > CMakeFiles/convergence.dir/convergence.cpp.i

examples/Weights/CMakeFiles/convergence.dir/convergence.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/convergence.dir/convergence.cpp.s"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Weights && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Weights/convergence.cpp -o CMakeFiles/convergence.dir/convergence.cpp.s

# Object files for target convergence
convergence_OBJECTS = \
"CMakeFiles/convergence.dir/convergence.cpp.o"

# External object files for target convergence
convergence_EXTERNAL_OBJECTS =

examples/Weights/convergence: examples/Weights/CMakeFiles/convergence.dir/convergence.cpp.o
examples/Weights/convergence: examples/Weights/CMakeFiles/convergence.dir/build.make
examples/Weights/convergence: /usr/lib/x86_64-linux-gnu/libgmpxx.so
examples/Weights/convergence: /usr/lib/x86_64-linux-gnu/libmpfr.so
examples/Weights/convergence: /usr/lib/x86_64-linux-gnu/libgmp.so
examples/Weights/convergence: examples/Weights/CMakeFiles/convergence.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable convergence"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Weights && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/convergence.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/Weights/CMakeFiles/convergence.dir/build: examples/Weights/convergence
.PHONY : examples/Weights/CMakeFiles/convergence.dir/build

examples/Weights/CMakeFiles/convergence.dir/clean:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Weights && $(CMAKE_COMMAND) -P CMakeFiles/convergence.dir/cmake_clean.cmake
.PHONY : examples/Weights/CMakeFiles/convergence.dir/clean

examples/Weights/CMakeFiles/convergence.dir/depend:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/melina/dev/Geometry/vendor/CGAL-5.6/examples /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Weights /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Weights /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Weights/CMakeFiles/convergence.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/Weights/CMakeFiles/convergence.dir/depend

