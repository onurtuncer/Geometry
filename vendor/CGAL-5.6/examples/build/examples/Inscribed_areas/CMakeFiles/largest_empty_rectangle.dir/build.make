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
include examples/Inscribed_areas/CMakeFiles/largest_empty_rectangle.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/Inscribed_areas/CMakeFiles/largest_empty_rectangle.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/Inscribed_areas/CMakeFiles/largest_empty_rectangle.dir/progress.make

# Include the compile flags for this target's objects.
include examples/Inscribed_areas/CMakeFiles/largest_empty_rectangle.dir/flags.make

examples/Inscribed_areas/CMakeFiles/largest_empty_rectangle.dir/largest_empty_rectangle.cpp.o: examples/Inscribed_areas/CMakeFiles/largest_empty_rectangle.dir/flags.make
examples/Inscribed_areas/CMakeFiles/largest_empty_rectangle.dir/largest_empty_rectangle.cpp.o: ../Inscribed_areas/largest_empty_rectangle.cpp
examples/Inscribed_areas/CMakeFiles/largest_empty_rectangle.dir/largest_empty_rectangle.cpp.o: examples/Inscribed_areas/CMakeFiles/largest_empty_rectangle.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/Inscribed_areas/CMakeFiles/largest_empty_rectangle.dir/largest_empty_rectangle.cpp.o"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Inscribed_areas && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/Inscribed_areas/CMakeFiles/largest_empty_rectangle.dir/largest_empty_rectangle.cpp.o -MF CMakeFiles/largest_empty_rectangle.dir/largest_empty_rectangle.cpp.o.d -o CMakeFiles/largest_empty_rectangle.dir/largest_empty_rectangle.cpp.o -c /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Inscribed_areas/largest_empty_rectangle.cpp

examples/Inscribed_areas/CMakeFiles/largest_empty_rectangle.dir/largest_empty_rectangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/largest_empty_rectangle.dir/largest_empty_rectangle.cpp.i"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Inscribed_areas && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Inscribed_areas/largest_empty_rectangle.cpp > CMakeFiles/largest_empty_rectangle.dir/largest_empty_rectangle.cpp.i

examples/Inscribed_areas/CMakeFiles/largest_empty_rectangle.dir/largest_empty_rectangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/largest_empty_rectangle.dir/largest_empty_rectangle.cpp.s"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Inscribed_areas && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Inscribed_areas/largest_empty_rectangle.cpp -o CMakeFiles/largest_empty_rectangle.dir/largest_empty_rectangle.cpp.s

# Object files for target largest_empty_rectangle
largest_empty_rectangle_OBJECTS = \
"CMakeFiles/largest_empty_rectangle.dir/largest_empty_rectangle.cpp.o"

# External object files for target largest_empty_rectangle
largest_empty_rectangle_EXTERNAL_OBJECTS =

examples/Inscribed_areas/largest_empty_rectangle: examples/Inscribed_areas/CMakeFiles/largest_empty_rectangle.dir/largest_empty_rectangle.cpp.o
examples/Inscribed_areas/largest_empty_rectangle: examples/Inscribed_areas/CMakeFiles/largest_empty_rectangle.dir/build.make
examples/Inscribed_areas/largest_empty_rectangle: /usr/lib/x86_64-linux-gnu/libgmpxx.so
examples/Inscribed_areas/largest_empty_rectangle: /usr/lib/x86_64-linux-gnu/libmpfr.so
examples/Inscribed_areas/largest_empty_rectangle: /usr/lib/x86_64-linux-gnu/libgmp.so
examples/Inscribed_areas/largest_empty_rectangle: examples/Inscribed_areas/CMakeFiles/largest_empty_rectangle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable largest_empty_rectangle"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Inscribed_areas && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/largest_empty_rectangle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/Inscribed_areas/CMakeFiles/largest_empty_rectangle.dir/build: examples/Inscribed_areas/largest_empty_rectangle
.PHONY : examples/Inscribed_areas/CMakeFiles/largest_empty_rectangle.dir/build

examples/Inscribed_areas/CMakeFiles/largest_empty_rectangle.dir/clean:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Inscribed_areas && $(CMAKE_COMMAND) -P CMakeFiles/largest_empty_rectangle.dir/cmake_clean.cmake
.PHONY : examples/Inscribed_areas/CMakeFiles/largest_empty_rectangle.dir/clean

examples/Inscribed_areas/CMakeFiles/largest_empty_rectangle.dir/depend:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/melina/dev/Geometry/vendor/CGAL-5.6/examples /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Inscribed_areas /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Inscribed_areas /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Inscribed_areas/CMakeFiles/largest_empty_rectangle.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/Inscribed_areas/CMakeFiles/largest_empty_rectangle.dir/depend

