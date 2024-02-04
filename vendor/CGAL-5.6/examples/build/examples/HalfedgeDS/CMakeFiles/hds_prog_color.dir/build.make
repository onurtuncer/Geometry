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
include examples/HalfedgeDS/CMakeFiles/hds_prog_color.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/HalfedgeDS/CMakeFiles/hds_prog_color.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/HalfedgeDS/CMakeFiles/hds_prog_color.dir/progress.make

# Include the compile flags for this target's objects.
include examples/HalfedgeDS/CMakeFiles/hds_prog_color.dir/flags.make

examples/HalfedgeDS/CMakeFiles/hds_prog_color.dir/hds_prog_color.cpp.o: examples/HalfedgeDS/CMakeFiles/hds_prog_color.dir/flags.make
examples/HalfedgeDS/CMakeFiles/hds_prog_color.dir/hds_prog_color.cpp.o: ../HalfedgeDS/hds_prog_color.cpp
examples/HalfedgeDS/CMakeFiles/hds_prog_color.dir/hds_prog_color.cpp.o: examples/HalfedgeDS/CMakeFiles/hds_prog_color.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/HalfedgeDS/CMakeFiles/hds_prog_color.dir/hds_prog_color.cpp.o"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/HalfedgeDS && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/HalfedgeDS/CMakeFiles/hds_prog_color.dir/hds_prog_color.cpp.o -MF CMakeFiles/hds_prog_color.dir/hds_prog_color.cpp.o.d -o CMakeFiles/hds_prog_color.dir/hds_prog_color.cpp.o -c /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/HalfedgeDS/hds_prog_color.cpp

examples/HalfedgeDS/CMakeFiles/hds_prog_color.dir/hds_prog_color.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hds_prog_color.dir/hds_prog_color.cpp.i"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/HalfedgeDS && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/HalfedgeDS/hds_prog_color.cpp > CMakeFiles/hds_prog_color.dir/hds_prog_color.cpp.i

examples/HalfedgeDS/CMakeFiles/hds_prog_color.dir/hds_prog_color.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hds_prog_color.dir/hds_prog_color.cpp.s"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/HalfedgeDS && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/HalfedgeDS/hds_prog_color.cpp -o CMakeFiles/hds_prog_color.dir/hds_prog_color.cpp.s

# Object files for target hds_prog_color
hds_prog_color_OBJECTS = \
"CMakeFiles/hds_prog_color.dir/hds_prog_color.cpp.o"

# External object files for target hds_prog_color
hds_prog_color_EXTERNAL_OBJECTS =

examples/HalfedgeDS/hds_prog_color: examples/HalfedgeDS/CMakeFiles/hds_prog_color.dir/hds_prog_color.cpp.o
examples/HalfedgeDS/hds_prog_color: examples/HalfedgeDS/CMakeFiles/hds_prog_color.dir/build.make
examples/HalfedgeDS/hds_prog_color: /usr/lib/x86_64-linux-gnu/libgmpxx.so
examples/HalfedgeDS/hds_prog_color: /usr/lib/x86_64-linux-gnu/libmpfr.so
examples/HalfedgeDS/hds_prog_color: /usr/lib/x86_64-linux-gnu/libgmp.so
examples/HalfedgeDS/hds_prog_color: examples/HalfedgeDS/CMakeFiles/hds_prog_color.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hds_prog_color"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/HalfedgeDS && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hds_prog_color.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/HalfedgeDS/CMakeFiles/hds_prog_color.dir/build: examples/HalfedgeDS/hds_prog_color
.PHONY : examples/HalfedgeDS/CMakeFiles/hds_prog_color.dir/build

examples/HalfedgeDS/CMakeFiles/hds_prog_color.dir/clean:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/HalfedgeDS && $(CMAKE_COMMAND) -P CMakeFiles/hds_prog_color.dir/cmake_clean.cmake
.PHONY : examples/HalfedgeDS/CMakeFiles/hds_prog_color.dir/clean

examples/HalfedgeDS/CMakeFiles/hds_prog_color.dir/depend:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/melina/dev/Geometry/vendor/CGAL-5.6/examples /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/HalfedgeDS /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/HalfedgeDS /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/HalfedgeDS/CMakeFiles/hds_prog_color.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/HalfedgeDS/CMakeFiles/hds_prog_color.dir/depend

