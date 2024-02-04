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
include examples/Skin_surface_3/CMakeFiles/skin_surface_subdiv.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/Skin_surface_3/CMakeFiles/skin_surface_subdiv.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/Skin_surface_3/CMakeFiles/skin_surface_subdiv.dir/progress.make

# Include the compile flags for this target's objects.
include examples/Skin_surface_3/CMakeFiles/skin_surface_subdiv.dir/flags.make

examples/Skin_surface_3/CMakeFiles/skin_surface_subdiv.dir/skin_surface_subdiv.cpp.o: examples/Skin_surface_3/CMakeFiles/skin_surface_subdiv.dir/flags.make
examples/Skin_surface_3/CMakeFiles/skin_surface_subdiv.dir/skin_surface_subdiv.cpp.o: ../Skin_surface_3/skin_surface_subdiv.cpp
examples/Skin_surface_3/CMakeFiles/skin_surface_subdiv.dir/skin_surface_subdiv.cpp.o: examples/Skin_surface_3/CMakeFiles/skin_surface_subdiv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/Skin_surface_3/CMakeFiles/skin_surface_subdiv.dir/skin_surface_subdiv.cpp.o"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Skin_surface_3 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/Skin_surface_3/CMakeFiles/skin_surface_subdiv.dir/skin_surface_subdiv.cpp.o -MF CMakeFiles/skin_surface_subdiv.dir/skin_surface_subdiv.cpp.o.d -o CMakeFiles/skin_surface_subdiv.dir/skin_surface_subdiv.cpp.o -c /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Skin_surface_3/skin_surface_subdiv.cpp

examples/Skin_surface_3/CMakeFiles/skin_surface_subdiv.dir/skin_surface_subdiv.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/skin_surface_subdiv.dir/skin_surface_subdiv.cpp.i"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Skin_surface_3 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Skin_surface_3/skin_surface_subdiv.cpp > CMakeFiles/skin_surface_subdiv.dir/skin_surface_subdiv.cpp.i

examples/Skin_surface_3/CMakeFiles/skin_surface_subdiv.dir/skin_surface_subdiv.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/skin_surface_subdiv.dir/skin_surface_subdiv.cpp.s"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Skin_surface_3 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Skin_surface_3/skin_surface_subdiv.cpp -o CMakeFiles/skin_surface_subdiv.dir/skin_surface_subdiv.cpp.s

# Object files for target skin_surface_subdiv
skin_surface_subdiv_OBJECTS = \
"CMakeFiles/skin_surface_subdiv.dir/skin_surface_subdiv.cpp.o"

# External object files for target skin_surface_subdiv
skin_surface_subdiv_EXTERNAL_OBJECTS =

examples/Skin_surface_3/skin_surface_subdiv: examples/Skin_surface_3/CMakeFiles/skin_surface_subdiv.dir/skin_surface_subdiv.cpp.o
examples/Skin_surface_3/skin_surface_subdiv: examples/Skin_surface_3/CMakeFiles/skin_surface_subdiv.dir/build.make
examples/Skin_surface_3/skin_surface_subdiv: /usr/lib/x86_64-linux-gnu/libgmpxx.so
examples/Skin_surface_3/skin_surface_subdiv: /usr/lib/x86_64-linux-gnu/libmpfr.so
examples/Skin_surface_3/skin_surface_subdiv: /usr/lib/x86_64-linux-gnu/libgmp.so
examples/Skin_surface_3/skin_surface_subdiv: examples/Skin_surface_3/CMakeFiles/skin_surface_subdiv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable skin_surface_subdiv"
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Skin_surface_3 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/skin_surface_subdiv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/Skin_surface_3/CMakeFiles/skin_surface_subdiv.dir/build: examples/Skin_surface_3/skin_surface_subdiv
.PHONY : examples/Skin_surface_3/CMakeFiles/skin_surface_subdiv.dir/build

examples/Skin_surface_3/CMakeFiles/skin_surface_subdiv.dir/clean:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Skin_surface_3 && $(CMAKE_COMMAND) -P CMakeFiles/skin_surface_subdiv.dir/cmake_clean.cmake
.PHONY : examples/Skin_surface_3/CMakeFiles/skin_surface_subdiv.dir/clean

examples/Skin_surface_3/CMakeFiles/skin_surface_subdiv.dir/depend:
	cd /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/melina/dev/Geometry/vendor/CGAL-5.6/examples /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/Skin_surface_3 /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Skin_surface_3 /home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Skin_surface_3/CMakeFiles/skin_surface_subdiv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/Skin_surface_3/CMakeFiles/skin_surface_subdiv.dir/depend

