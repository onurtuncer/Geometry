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
include examples/Point_set_processing_3/CMakeFiles/normal_estimation.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/Point_set_processing_3/CMakeFiles/normal_estimation.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/Point_set_processing_3/CMakeFiles/normal_estimation.dir/progress.make

# Include the compile flags for this target's objects.
include examples/Point_set_processing_3/CMakeFiles/normal_estimation.dir/flags.make

examples/Point_set_processing_3/CMakeFiles/normal_estimation.dir/normal_estimation.cpp.o: examples/Point_set_processing_3/CMakeFiles/normal_estimation.dir/flags.make
examples/Point_set_processing_3/CMakeFiles/normal_estimation.dir/normal_estimation.cpp.o: ../Point_set_processing_3/normal_estimation.cpp
examples/Point_set_processing_3/CMakeFiles/normal_estimation.dir/normal_estimation.cpp.o: examples/Point_set_processing_3/CMakeFiles/normal_estimation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/Point_set_processing_3/CMakeFiles/normal_estimation.dir/normal_estimation.cpp.o"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Point_set_processing_3 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/Point_set_processing_3/CMakeFiles/normal_estimation.dir/normal_estimation.cpp.o -MF CMakeFiles/normal_estimation.dir/normal_estimation.cpp.o.d -o CMakeFiles/normal_estimation.dir/normal_estimation.cpp.o -c /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Point_set_processing_3/normal_estimation.cpp

examples/Point_set_processing_3/CMakeFiles/normal_estimation.dir/normal_estimation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/normal_estimation.dir/normal_estimation.cpp.i"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Point_set_processing_3 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Point_set_processing_3/normal_estimation.cpp > CMakeFiles/normal_estimation.dir/normal_estimation.cpp.i

examples/Point_set_processing_3/CMakeFiles/normal_estimation.dir/normal_estimation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/normal_estimation.dir/normal_estimation.cpp.s"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Point_set_processing_3 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Point_set_processing_3/normal_estimation.cpp -o CMakeFiles/normal_estimation.dir/normal_estimation.cpp.s

# Object files for target normal_estimation
normal_estimation_OBJECTS = \
"CMakeFiles/normal_estimation.dir/normal_estimation.cpp.o"

# External object files for target normal_estimation
normal_estimation_EXTERNAL_OBJECTS =

examples/Point_set_processing_3/normal_estimation: examples/Point_set_processing_3/CMakeFiles/normal_estimation.dir/normal_estimation.cpp.o
examples/Point_set_processing_3/normal_estimation: examples/Point_set_processing_3/CMakeFiles/normal_estimation.dir/build.make
examples/Point_set_processing_3/normal_estimation: /usr/lib/x86_64-linux-gnu/libgmpxx.so
examples/Point_set_processing_3/normal_estimation: /usr/lib/x86_64-linux-gnu/libmpfr.so
examples/Point_set_processing_3/normal_estimation: /usr/lib/x86_64-linux-gnu/libgmp.so
examples/Point_set_processing_3/normal_estimation: examples/Point_set_processing_3/CMakeFiles/normal_estimation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable normal_estimation"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Point_set_processing_3 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/normal_estimation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/Point_set_processing_3/CMakeFiles/normal_estimation.dir/build: examples/Point_set_processing_3/normal_estimation
.PHONY : examples/Point_set_processing_3/CMakeFiles/normal_estimation.dir/build

examples/Point_set_processing_3/CMakeFiles/normal_estimation.dir/clean:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Point_set_processing_3 && $(CMAKE_COMMAND) -P CMakeFiles/normal_estimation.dir/cmake_clean.cmake
.PHONY : examples/Point_set_processing_3/CMakeFiles/normal_estimation.dir/clean

examples/Point_set_processing_3/CMakeFiles/normal_estimation.dir/depend:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/melina/dev/Geometry/vendor/CGAL-5.6/examples /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Point_set_processing_3 /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Point_set_processing_3 /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Point_set_processing_3/CMakeFiles/normal_estimation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/Point_set_processing_3/CMakeFiles/normal_estimation.dir/depend

