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
include examples/Snap_rounding_2/CMakeFiles/snap_rounding_data.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/Snap_rounding_2/CMakeFiles/snap_rounding_data.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/Snap_rounding_2/CMakeFiles/snap_rounding_data.dir/progress.make

# Include the compile flags for this target's objects.
include examples/Snap_rounding_2/CMakeFiles/snap_rounding_data.dir/flags.make

examples/Snap_rounding_2/CMakeFiles/snap_rounding_data.dir/snap_rounding_data.cpp.o: examples/Snap_rounding_2/CMakeFiles/snap_rounding_data.dir/flags.make
examples/Snap_rounding_2/CMakeFiles/snap_rounding_data.dir/snap_rounding_data.cpp.o: ../Snap_rounding_2/snap_rounding_data.cpp
examples/Snap_rounding_2/CMakeFiles/snap_rounding_data.dir/snap_rounding_data.cpp.o: examples/Snap_rounding_2/CMakeFiles/snap_rounding_data.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/Snap_rounding_2/CMakeFiles/snap_rounding_data.dir/snap_rounding_data.cpp.o"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Snap_rounding_2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/Snap_rounding_2/CMakeFiles/snap_rounding_data.dir/snap_rounding_data.cpp.o -MF CMakeFiles/snap_rounding_data.dir/snap_rounding_data.cpp.o.d -o CMakeFiles/snap_rounding_data.dir/snap_rounding_data.cpp.o -c /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Snap_rounding_2/snap_rounding_data.cpp

examples/Snap_rounding_2/CMakeFiles/snap_rounding_data.dir/snap_rounding_data.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/snap_rounding_data.dir/snap_rounding_data.cpp.i"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Snap_rounding_2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Snap_rounding_2/snap_rounding_data.cpp > CMakeFiles/snap_rounding_data.dir/snap_rounding_data.cpp.i

examples/Snap_rounding_2/CMakeFiles/snap_rounding_data.dir/snap_rounding_data.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/snap_rounding_data.dir/snap_rounding_data.cpp.s"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Snap_rounding_2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Snap_rounding_2/snap_rounding_data.cpp -o CMakeFiles/snap_rounding_data.dir/snap_rounding_data.cpp.s

# Object files for target snap_rounding_data
snap_rounding_data_OBJECTS = \
"CMakeFiles/snap_rounding_data.dir/snap_rounding_data.cpp.o"

# External object files for target snap_rounding_data
snap_rounding_data_EXTERNAL_OBJECTS =

examples/Snap_rounding_2/snap_rounding_data: examples/Snap_rounding_2/CMakeFiles/snap_rounding_data.dir/snap_rounding_data.cpp.o
examples/Snap_rounding_2/snap_rounding_data: examples/Snap_rounding_2/CMakeFiles/snap_rounding_data.dir/build.make
examples/Snap_rounding_2/snap_rounding_data: /usr/lib/x86_64-linux-gnu/libgmpxx.so
examples/Snap_rounding_2/snap_rounding_data: /usr/lib/x86_64-linux-gnu/libmpfr.so
examples/Snap_rounding_2/snap_rounding_data: /usr/lib/x86_64-linux-gnu/libgmp.so
examples/Snap_rounding_2/snap_rounding_data: examples/Snap_rounding_2/CMakeFiles/snap_rounding_data.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable snap_rounding_data"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Snap_rounding_2 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/snap_rounding_data.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/Snap_rounding_2/CMakeFiles/snap_rounding_data.dir/build: examples/Snap_rounding_2/snap_rounding_data
.PHONY : examples/Snap_rounding_2/CMakeFiles/snap_rounding_data.dir/build

examples/Snap_rounding_2/CMakeFiles/snap_rounding_data.dir/clean:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Snap_rounding_2 && $(CMAKE_COMMAND) -P CMakeFiles/snap_rounding_data.dir/cmake_clean.cmake
.PHONY : examples/Snap_rounding_2/CMakeFiles/snap_rounding_data.dir/clean

examples/Snap_rounding_2/CMakeFiles/snap_rounding_data.dir/depend:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/melina/dev/Geometry/vendor/CGAL-5.6/examples /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Snap_rounding_2 /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Snap_rounding_2 /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Snap_rounding_2/CMakeFiles/snap_rounding_data.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/Snap_rounding_2/CMakeFiles/snap_rounding_data.dir/depend

