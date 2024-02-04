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
include examples/Kernel_23/CMakeFiles/cartesian_converter.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/Kernel_23/CMakeFiles/cartesian_converter.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/Kernel_23/CMakeFiles/cartesian_converter.dir/progress.make

# Include the compile flags for this target's objects.
include examples/Kernel_23/CMakeFiles/cartesian_converter.dir/flags.make

examples/Kernel_23/CMakeFiles/cartesian_converter.dir/cartesian_converter.cpp.o: examples/Kernel_23/CMakeFiles/cartesian_converter.dir/flags.make
examples/Kernel_23/CMakeFiles/cartesian_converter.dir/cartesian_converter.cpp.o: ../Kernel_23/cartesian_converter.cpp
examples/Kernel_23/CMakeFiles/cartesian_converter.dir/cartesian_converter.cpp.o: examples/Kernel_23/CMakeFiles/cartesian_converter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/Kernel_23/CMakeFiles/cartesian_converter.dir/cartesian_converter.cpp.o"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Kernel_23 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/Kernel_23/CMakeFiles/cartesian_converter.dir/cartesian_converter.cpp.o -MF CMakeFiles/cartesian_converter.dir/cartesian_converter.cpp.o.d -o CMakeFiles/cartesian_converter.dir/cartesian_converter.cpp.o -c /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Kernel_23/cartesian_converter.cpp

examples/Kernel_23/CMakeFiles/cartesian_converter.dir/cartesian_converter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cartesian_converter.dir/cartesian_converter.cpp.i"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Kernel_23 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Kernel_23/cartesian_converter.cpp > CMakeFiles/cartesian_converter.dir/cartesian_converter.cpp.i

examples/Kernel_23/CMakeFiles/cartesian_converter.dir/cartesian_converter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cartesian_converter.dir/cartesian_converter.cpp.s"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Kernel_23 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Kernel_23/cartesian_converter.cpp -o CMakeFiles/cartesian_converter.dir/cartesian_converter.cpp.s

# Object files for target cartesian_converter
cartesian_converter_OBJECTS = \
"CMakeFiles/cartesian_converter.dir/cartesian_converter.cpp.o"

# External object files for target cartesian_converter
cartesian_converter_EXTERNAL_OBJECTS =

examples/Kernel_23/cartesian_converter: examples/Kernel_23/CMakeFiles/cartesian_converter.dir/cartesian_converter.cpp.o
examples/Kernel_23/cartesian_converter: examples/Kernel_23/CMakeFiles/cartesian_converter.dir/build.make
examples/Kernel_23/cartesian_converter: /usr/lib/x86_64-linux-gnu/libgmpxx.so
examples/Kernel_23/cartesian_converter: /usr/lib/x86_64-linux-gnu/libmpfr.so
examples/Kernel_23/cartesian_converter: /usr/lib/x86_64-linux-gnu/libgmp.so
examples/Kernel_23/cartesian_converter: examples/Kernel_23/CMakeFiles/cartesian_converter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cartesian_converter"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Kernel_23 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cartesian_converter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/Kernel_23/CMakeFiles/cartesian_converter.dir/build: examples/Kernel_23/cartesian_converter
.PHONY : examples/Kernel_23/CMakeFiles/cartesian_converter.dir/build

examples/Kernel_23/CMakeFiles/cartesian_converter.dir/clean:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Kernel_23 && $(CMAKE_COMMAND) -P CMakeFiles/cartesian_converter.dir/cmake_clean.cmake
.PHONY : examples/Kernel_23/CMakeFiles/cartesian_converter.dir/clean

examples/Kernel_23/CMakeFiles/cartesian_converter.dir/depend:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/melina/dev/Geometry/vendor/CGAL-5.6/examples /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Kernel_23 /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Kernel_23 /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Kernel_23/CMakeFiles/cartesian_converter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/Kernel_23/CMakeFiles/cartesian_converter.dir/depend

