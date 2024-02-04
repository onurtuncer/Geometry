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
include examples/Circulator/CMakeFiles/circulator_prog3.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/Circulator/CMakeFiles/circulator_prog3.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/Circulator/CMakeFiles/circulator_prog3.dir/progress.make

# Include the compile flags for this target's objects.
include examples/Circulator/CMakeFiles/circulator_prog3.dir/flags.make

examples/Circulator/CMakeFiles/circulator_prog3.dir/circulator_prog3.cpp.o: examples/Circulator/CMakeFiles/circulator_prog3.dir/flags.make
examples/Circulator/CMakeFiles/circulator_prog3.dir/circulator_prog3.cpp.o: ../Circulator/circulator_prog3.cpp
examples/Circulator/CMakeFiles/circulator_prog3.dir/circulator_prog3.cpp.o: examples/Circulator/CMakeFiles/circulator_prog3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/Circulator/CMakeFiles/circulator_prog3.dir/circulator_prog3.cpp.o"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Circulator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/Circulator/CMakeFiles/circulator_prog3.dir/circulator_prog3.cpp.o -MF CMakeFiles/circulator_prog3.dir/circulator_prog3.cpp.o.d -o CMakeFiles/circulator_prog3.dir/circulator_prog3.cpp.o -c /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Circulator/circulator_prog3.cpp

examples/Circulator/CMakeFiles/circulator_prog3.dir/circulator_prog3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/circulator_prog3.dir/circulator_prog3.cpp.i"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Circulator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Circulator/circulator_prog3.cpp > CMakeFiles/circulator_prog3.dir/circulator_prog3.cpp.i

examples/Circulator/CMakeFiles/circulator_prog3.dir/circulator_prog3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/circulator_prog3.dir/circulator_prog3.cpp.s"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Circulator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Circulator/circulator_prog3.cpp -o CMakeFiles/circulator_prog3.dir/circulator_prog3.cpp.s

# Object files for target circulator_prog3
circulator_prog3_OBJECTS = \
"CMakeFiles/circulator_prog3.dir/circulator_prog3.cpp.o"

# External object files for target circulator_prog3
circulator_prog3_EXTERNAL_OBJECTS =

examples/Circulator/circulator_prog3: examples/Circulator/CMakeFiles/circulator_prog3.dir/circulator_prog3.cpp.o
examples/Circulator/circulator_prog3: examples/Circulator/CMakeFiles/circulator_prog3.dir/build.make
examples/Circulator/circulator_prog3: /usr/lib/x86_64-linux-gnu/libgmpxx.so
examples/Circulator/circulator_prog3: /usr/lib/x86_64-linux-gnu/libmpfr.so
examples/Circulator/circulator_prog3: /usr/lib/x86_64-linux-gnu/libgmp.so
examples/Circulator/circulator_prog3: examples/Circulator/CMakeFiles/circulator_prog3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable circulator_prog3"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Circulator && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/circulator_prog3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/Circulator/CMakeFiles/circulator_prog3.dir/build: examples/Circulator/circulator_prog3
.PHONY : examples/Circulator/CMakeFiles/circulator_prog3.dir/build

examples/Circulator/CMakeFiles/circulator_prog3.dir/clean:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Circulator && $(CMAKE_COMMAND) -P CMakeFiles/circulator_prog3.dir/cmake_clean.cmake
.PHONY : examples/Circulator/CMakeFiles/circulator_prog3.dir/clean

examples/Circulator/CMakeFiles/circulator_prog3.dir/depend:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/melina/dev/Geometry/vendor/CGAL-5.6/examples /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Circulator /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Circulator /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Circulator/CMakeFiles/circulator_prog3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/Circulator/CMakeFiles/circulator_prog3.dir/depend

