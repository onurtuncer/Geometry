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
include examples/Polynomial/CMakeFiles/construction.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/Polynomial/CMakeFiles/construction.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/Polynomial/CMakeFiles/construction.dir/progress.make

# Include the compile flags for this target's objects.
include examples/Polynomial/CMakeFiles/construction.dir/flags.make

examples/Polynomial/CMakeFiles/construction.dir/construction.cpp.o: examples/Polynomial/CMakeFiles/construction.dir/flags.make
examples/Polynomial/CMakeFiles/construction.dir/construction.cpp.o: ../Polynomial/construction.cpp
examples/Polynomial/CMakeFiles/construction.dir/construction.cpp.o: examples/Polynomial/CMakeFiles/construction.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/Polynomial/CMakeFiles/construction.dir/construction.cpp.o"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Polynomial && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/Polynomial/CMakeFiles/construction.dir/construction.cpp.o -MF CMakeFiles/construction.dir/construction.cpp.o.d -o CMakeFiles/construction.dir/construction.cpp.o -c /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Polynomial/construction.cpp

examples/Polynomial/CMakeFiles/construction.dir/construction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/construction.dir/construction.cpp.i"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Polynomial && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Polynomial/construction.cpp > CMakeFiles/construction.dir/construction.cpp.i

examples/Polynomial/CMakeFiles/construction.dir/construction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/construction.dir/construction.cpp.s"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Polynomial && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Polynomial/construction.cpp -o CMakeFiles/construction.dir/construction.cpp.s

# Object files for target construction
construction_OBJECTS = \
"CMakeFiles/construction.dir/construction.cpp.o"

# External object files for target construction
construction_EXTERNAL_OBJECTS =

examples/Polynomial/construction: examples/Polynomial/CMakeFiles/construction.dir/construction.cpp.o
examples/Polynomial/construction: examples/Polynomial/CMakeFiles/construction.dir/build.make
examples/Polynomial/construction: /usr/lib/x86_64-linux-gnu/libgmpxx.so
examples/Polynomial/construction: /usr/lib/x86_64-linux-gnu/libmpfr.so
examples/Polynomial/construction: /usr/lib/x86_64-linux-gnu/libgmp.so
examples/Polynomial/construction: examples/Polynomial/CMakeFiles/construction.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable construction"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Polynomial && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/construction.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/Polynomial/CMakeFiles/construction.dir/build: examples/Polynomial/construction
.PHONY : examples/Polynomial/CMakeFiles/construction.dir/build

examples/Polynomial/CMakeFiles/construction.dir/clean:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Polynomial && $(CMAKE_COMMAND) -P CMakeFiles/construction.dir/cmake_clean.cmake
.PHONY : examples/Polynomial/CMakeFiles/construction.dir/clean

examples/Polynomial/CMakeFiles/construction.dir/depend:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/melina/dev/Geometry/vendor/CGAL-5.6/examples /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Polynomial /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Polynomial /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Polynomial/CMakeFiles/construction.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/Polynomial/CMakeFiles/construction.dir/depend

