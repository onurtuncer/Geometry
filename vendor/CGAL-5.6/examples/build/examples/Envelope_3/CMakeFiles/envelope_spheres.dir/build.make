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
include examples/Envelope_3/CMakeFiles/envelope_spheres.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/Envelope_3/CMakeFiles/envelope_spheres.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/Envelope_3/CMakeFiles/envelope_spheres.dir/progress.make

# Include the compile flags for this target's objects.
include examples/Envelope_3/CMakeFiles/envelope_spheres.dir/flags.make

examples/Envelope_3/CMakeFiles/envelope_spheres.dir/envelope_spheres.cpp.o: examples/Envelope_3/CMakeFiles/envelope_spheres.dir/flags.make
examples/Envelope_3/CMakeFiles/envelope_spheres.dir/envelope_spheres.cpp.o: ../Envelope_3/envelope_spheres.cpp
examples/Envelope_3/CMakeFiles/envelope_spheres.dir/envelope_spheres.cpp.o: examples/Envelope_3/CMakeFiles/envelope_spheres.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/Envelope_3/CMakeFiles/envelope_spheres.dir/envelope_spheres.cpp.o"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Envelope_3 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/Envelope_3/CMakeFiles/envelope_spheres.dir/envelope_spheres.cpp.o -MF CMakeFiles/envelope_spheres.dir/envelope_spheres.cpp.o.d -o CMakeFiles/envelope_spheres.dir/envelope_spheres.cpp.o -c /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Envelope_3/envelope_spheres.cpp

examples/Envelope_3/CMakeFiles/envelope_spheres.dir/envelope_spheres.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/envelope_spheres.dir/envelope_spheres.cpp.i"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Envelope_3 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Envelope_3/envelope_spheres.cpp > CMakeFiles/envelope_spheres.dir/envelope_spheres.cpp.i

examples/Envelope_3/CMakeFiles/envelope_spheres.dir/envelope_spheres.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/envelope_spheres.dir/envelope_spheres.cpp.s"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Envelope_3 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Envelope_3/envelope_spheres.cpp -o CMakeFiles/envelope_spheres.dir/envelope_spheres.cpp.s

# Object files for target envelope_spheres
envelope_spheres_OBJECTS = \
"CMakeFiles/envelope_spheres.dir/envelope_spheres.cpp.o"

# External object files for target envelope_spheres
envelope_spheres_EXTERNAL_OBJECTS =

examples/Envelope_3/envelope_spheres: examples/Envelope_3/CMakeFiles/envelope_spheres.dir/envelope_spheres.cpp.o
examples/Envelope_3/envelope_spheres: examples/Envelope_3/CMakeFiles/envelope_spheres.dir/build.make
examples/Envelope_3/envelope_spheres: /usr/lib/x86_64-linux-gnu/libgmpxx.so
examples/Envelope_3/envelope_spheres: /usr/lib/x86_64-linux-gnu/libmpfr.so
examples/Envelope_3/envelope_spheres: /usr/lib/x86_64-linux-gnu/libgmp.so
examples/Envelope_3/envelope_spheres: examples/Envelope_3/CMakeFiles/envelope_spheres.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable envelope_spheres"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Envelope_3 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/envelope_spheres.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/Envelope_3/CMakeFiles/envelope_spheres.dir/build: examples/Envelope_3/envelope_spheres
.PHONY : examples/Envelope_3/CMakeFiles/envelope_spheres.dir/build

examples/Envelope_3/CMakeFiles/envelope_spheres.dir/clean:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Envelope_3 && $(CMAKE_COMMAND) -P CMakeFiles/envelope_spheres.dir/cmake_clean.cmake
.PHONY : examples/Envelope_3/CMakeFiles/envelope_spheres.dir/clean

examples/Envelope_3/CMakeFiles/envelope_spheres.dir/depend:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/melina/dev/Geometry/vendor/CGAL-5.6/examples /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Envelope_3 /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Envelope_3 /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Envelope_3/CMakeFiles/envelope_spheres.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/Envelope_3/CMakeFiles/envelope_spheres.dir/depend

