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
include examples/Kernel_23/CMakeFiles/intersection_get.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/Kernel_23/CMakeFiles/intersection_get.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/Kernel_23/CMakeFiles/intersection_get.dir/progress.make

# Include the compile flags for this target's objects.
include examples/Kernel_23/CMakeFiles/intersection_get.dir/flags.make

examples/Kernel_23/CMakeFiles/intersection_get.dir/intersection_get.cpp.o: examples/Kernel_23/CMakeFiles/intersection_get.dir/flags.make
examples/Kernel_23/CMakeFiles/intersection_get.dir/intersection_get.cpp.o: ../Kernel_23/intersection_get.cpp
examples/Kernel_23/CMakeFiles/intersection_get.dir/intersection_get.cpp.o: examples/Kernel_23/CMakeFiles/intersection_get.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/Kernel_23/CMakeFiles/intersection_get.dir/intersection_get.cpp.o"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Kernel_23 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/Kernel_23/CMakeFiles/intersection_get.dir/intersection_get.cpp.o -MF CMakeFiles/intersection_get.dir/intersection_get.cpp.o.d -o CMakeFiles/intersection_get.dir/intersection_get.cpp.o -c /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Kernel_23/intersection_get.cpp

examples/Kernel_23/CMakeFiles/intersection_get.dir/intersection_get.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/intersection_get.dir/intersection_get.cpp.i"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Kernel_23 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Kernel_23/intersection_get.cpp > CMakeFiles/intersection_get.dir/intersection_get.cpp.i

examples/Kernel_23/CMakeFiles/intersection_get.dir/intersection_get.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/intersection_get.dir/intersection_get.cpp.s"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Kernel_23 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Kernel_23/intersection_get.cpp -o CMakeFiles/intersection_get.dir/intersection_get.cpp.s

# Object files for target intersection_get
intersection_get_OBJECTS = \
"CMakeFiles/intersection_get.dir/intersection_get.cpp.o"

# External object files for target intersection_get
intersection_get_EXTERNAL_OBJECTS =

examples/Kernel_23/intersection_get: examples/Kernel_23/CMakeFiles/intersection_get.dir/intersection_get.cpp.o
examples/Kernel_23/intersection_get: examples/Kernel_23/CMakeFiles/intersection_get.dir/build.make
examples/Kernel_23/intersection_get: /usr/lib/x86_64-linux-gnu/libgmpxx.so
examples/Kernel_23/intersection_get: /usr/lib/x86_64-linux-gnu/libmpfr.so
examples/Kernel_23/intersection_get: /usr/lib/x86_64-linux-gnu/libgmp.so
examples/Kernel_23/intersection_get: examples/Kernel_23/CMakeFiles/intersection_get.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable intersection_get"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Kernel_23 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/intersection_get.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/Kernel_23/CMakeFiles/intersection_get.dir/build: examples/Kernel_23/intersection_get
.PHONY : examples/Kernel_23/CMakeFiles/intersection_get.dir/build

examples/Kernel_23/CMakeFiles/intersection_get.dir/clean:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Kernel_23 && $(CMAKE_COMMAND) -P CMakeFiles/intersection_get.dir/cmake_clean.cmake
.PHONY : examples/Kernel_23/CMakeFiles/intersection_get.dir/clean

examples/Kernel_23/CMakeFiles/intersection_get.dir/depend:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/melina/dev/Geometry/vendor/CGAL-5.6/examples /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Kernel_23 /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Kernel_23 /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Kernel_23/CMakeFiles/intersection_get.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/Kernel_23/CMakeFiles/intersection_get.dir/depend

