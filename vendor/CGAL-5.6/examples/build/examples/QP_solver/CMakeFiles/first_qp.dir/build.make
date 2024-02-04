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
include examples/QP_solver/CMakeFiles/first_qp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/QP_solver/CMakeFiles/first_qp.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/QP_solver/CMakeFiles/first_qp.dir/progress.make

# Include the compile flags for this target's objects.
include examples/QP_solver/CMakeFiles/first_qp.dir/flags.make

examples/QP_solver/CMakeFiles/first_qp.dir/first_qp.cpp.o: examples/QP_solver/CMakeFiles/first_qp.dir/flags.make
examples/QP_solver/CMakeFiles/first_qp.dir/first_qp.cpp.o: ../QP_solver/first_qp.cpp
examples/QP_solver/CMakeFiles/first_qp.dir/first_qp.cpp.o: examples/QP_solver/CMakeFiles/first_qp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/QP_solver/CMakeFiles/first_qp.dir/first_qp.cpp.o"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/QP_solver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/QP_solver/CMakeFiles/first_qp.dir/first_qp.cpp.o -MF CMakeFiles/first_qp.dir/first_qp.cpp.o.d -o CMakeFiles/first_qp.dir/first_qp.cpp.o -c /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/QP_solver/first_qp.cpp

examples/QP_solver/CMakeFiles/first_qp.dir/first_qp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/first_qp.dir/first_qp.cpp.i"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/QP_solver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/QP_solver/first_qp.cpp > CMakeFiles/first_qp.dir/first_qp.cpp.i

examples/QP_solver/CMakeFiles/first_qp.dir/first_qp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/first_qp.dir/first_qp.cpp.s"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/QP_solver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/QP_solver/first_qp.cpp -o CMakeFiles/first_qp.dir/first_qp.cpp.s

# Object files for target first_qp
first_qp_OBJECTS = \
"CMakeFiles/first_qp.dir/first_qp.cpp.o"

# External object files for target first_qp
first_qp_EXTERNAL_OBJECTS =

examples/QP_solver/first_qp: examples/QP_solver/CMakeFiles/first_qp.dir/first_qp.cpp.o
examples/QP_solver/first_qp: examples/QP_solver/CMakeFiles/first_qp.dir/build.make
examples/QP_solver/first_qp: /usr/lib/x86_64-linux-gnu/libgmpxx.so
examples/QP_solver/first_qp: /usr/lib/x86_64-linux-gnu/libmpfr.so
examples/QP_solver/first_qp: /usr/lib/x86_64-linux-gnu/libgmp.so
examples/QP_solver/first_qp: examples/QP_solver/CMakeFiles/first_qp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable first_qp"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/QP_solver && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/first_qp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/QP_solver/CMakeFiles/first_qp.dir/build: examples/QP_solver/first_qp
.PHONY : examples/QP_solver/CMakeFiles/first_qp.dir/build

examples/QP_solver/CMakeFiles/first_qp.dir/clean:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/QP_solver && $(CMAKE_COMMAND) -P CMakeFiles/first_qp.dir/cmake_clean.cmake
.PHONY : examples/QP_solver/CMakeFiles/first_qp.dir/clean

examples/QP_solver/CMakeFiles/first_qp.dir/depend:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/melina/dev/Geometry/vendor/CGAL-5.6/examples /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/QP_solver /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/QP_solver /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/QP_solver/CMakeFiles/first_qp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/QP_solver/CMakeFiles/first_qp.dir/depend

