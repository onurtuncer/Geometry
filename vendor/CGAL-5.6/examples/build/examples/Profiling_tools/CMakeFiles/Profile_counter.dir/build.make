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
include examples/Profiling_tools/CMakeFiles/Profile_counter.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/Profiling_tools/CMakeFiles/Profile_counter.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/Profiling_tools/CMakeFiles/Profile_counter.dir/progress.make

# Include the compile flags for this target's objects.
include examples/Profiling_tools/CMakeFiles/Profile_counter.dir/flags.make

examples/Profiling_tools/CMakeFiles/Profile_counter.dir/Profile_counter.cpp.o: examples/Profiling_tools/CMakeFiles/Profile_counter.dir/flags.make
examples/Profiling_tools/CMakeFiles/Profile_counter.dir/Profile_counter.cpp.o: ../Profiling_tools/Profile_counter.cpp
examples/Profiling_tools/CMakeFiles/Profile_counter.dir/Profile_counter.cpp.o: examples/Profiling_tools/CMakeFiles/Profile_counter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/Profiling_tools/CMakeFiles/Profile_counter.dir/Profile_counter.cpp.o"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Profiling_tools && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/Profiling_tools/CMakeFiles/Profile_counter.dir/Profile_counter.cpp.o -MF CMakeFiles/Profile_counter.dir/Profile_counter.cpp.o.d -o CMakeFiles/Profile_counter.dir/Profile_counter.cpp.o -c /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Profiling_tools/Profile_counter.cpp

examples/Profiling_tools/CMakeFiles/Profile_counter.dir/Profile_counter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Profile_counter.dir/Profile_counter.cpp.i"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Profiling_tools && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Profiling_tools/Profile_counter.cpp > CMakeFiles/Profile_counter.dir/Profile_counter.cpp.i

examples/Profiling_tools/CMakeFiles/Profile_counter.dir/Profile_counter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Profile_counter.dir/Profile_counter.cpp.s"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Profiling_tools && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Profiling_tools/Profile_counter.cpp -o CMakeFiles/Profile_counter.dir/Profile_counter.cpp.s

# Object files for target Profile_counter
Profile_counter_OBJECTS = \
"CMakeFiles/Profile_counter.dir/Profile_counter.cpp.o"

# External object files for target Profile_counter
Profile_counter_EXTERNAL_OBJECTS =

examples/Profiling_tools/Profile_counter: examples/Profiling_tools/CMakeFiles/Profile_counter.dir/Profile_counter.cpp.o
examples/Profiling_tools/Profile_counter: examples/Profiling_tools/CMakeFiles/Profile_counter.dir/build.make
examples/Profiling_tools/Profile_counter: /usr/lib/x86_64-linux-gnu/libgmpxx.so
examples/Profiling_tools/Profile_counter: /usr/lib/x86_64-linux-gnu/libmpfr.so
examples/Profiling_tools/Profile_counter: /usr/lib/x86_64-linux-gnu/libgmp.so
examples/Profiling_tools/Profile_counter: examples/Profiling_tools/CMakeFiles/Profile_counter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Profile_counter"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Profiling_tools && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Profile_counter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/Profiling_tools/CMakeFiles/Profile_counter.dir/build: examples/Profiling_tools/Profile_counter
.PHONY : examples/Profiling_tools/CMakeFiles/Profile_counter.dir/build

examples/Profiling_tools/CMakeFiles/Profile_counter.dir/clean:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Profiling_tools && $(CMAKE_COMMAND) -P CMakeFiles/Profile_counter.dir/cmake_clean.cmake
.PHONY : examples/Profiling_tools/CMakeFiles/Profile_counter.dir/clean

examples/Profiling_tools/CMakeFiles/Profile_counter.dir/depend:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/melina/dev/Geometry/vendor/CGAL-5.6/examples /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Profiling_tools /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Profiling_tools /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Profiling_tools/CMakeFiles/Profile_counter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/Profiling_tools/CMakeFiles/Profile_counter.dir/depend

