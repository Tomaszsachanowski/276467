# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tomeczek/Pulpit/Mapy

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tomeczek/Pulpit/Mapy/Release

# Include any dependencies generated for this target.
include tests/CMakeFiles/aisdiMapsTests.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/aisdiMapsTests.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/aisdiMapsTests.dir/flags.make

tests/CMakeFiles/aisdiMapsTests.dir/test_main.cpp.o: tests/CMakeFiles/aisdiMapsTests.dir/flags.make
tests/CMakeFiles/aisdiMapsTests.dir/test_main.cpp.o: ../tests/test_main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tomeczek/Pulpit/Mapy/Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/aisdiMapsTests.dir/test_main.cpp.o"
	cd /home/tomeczek/Pulpit/Mapy/Release/tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/aisdiMapsTests.dir/test_main.cpp.o -c /home/tomeczek/Pulpit/Mapy/tests/test_main.cpp

tests/CMakeFiles/aisdiMapsTests.dir/test_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aisdiMapsTests.dir/test_main.cpp.i"
	cd /home/tomeczek/Pulpit/Mapy/Release/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tomeczek/Pulpit/Mapy/tests/test_main.cpp > CMakeFiles/aisdiMapsTests.dir/test_main.cpp.i

tests/CMakeFiles/aisdiMapsTests.dir/test_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aisdiMapsTests.dir/test_main.cpp.s"
	cd /home/tomeczek/Pulpit/Mapy/Release/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tomeczek/Pulpit/Mapy/tests/test_main.cpp -o CMakeFiles/aisdiMapsTests.dir/test_main.cpp.s

tests/CMakeFiles/aisdiMapsTests.dir/test_main.cpp.o.requires:

.PHONY : tests/CMakeFiles/aisdiMapsTests.dir/test_main.cpp.o.requires

tests/CMakeFiles/aisdiMapsTests.dir/test_main.cpp.o.provides: tests/CMakeFiles/aisdiMapsTests.dir/test_main.cpp.o.requires
	$(MAKE) -f tests/CMakeFiles/aisdiMapsTests.dir/build.make tests/CMakeFiles/aisdiMapsTests.dir/test_main.cpp.o.provides.build
.PHONY : tests/CMakeFiles/aisdiMapsTests.dir/test_main.cpp.o.provides

tests/CMakeFiles/aisdiMapsTests.dir/test_main.cpp.o.provides.build: tests/CMakeFiles/aisdiMapsTests.dir/test_main.cpp.o


tests/CMakeFiles/aisdiMapsTests.dir/TreeMapTests.cpp.o: tests/CMakeFiles/aisdiMapsTests.dir/flags.make
tests/CMakeFiles/aisdiMapsTests.dir/TreeMapTests.cpp.o: ../tests/TreeMapTests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tomeczek/Pulpit/Mapy/Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/CMakeFiles/aisdiMapsTests.dir/TreeMapTests.cpp.o"
	cd /home/tomeczek/Pulpit/Mapy/Release/tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/aisdiMapsTests.dir/TreeMapTests.cpp.o -c /home/tomeczek/Pulpit/Mapy/tests/TreeMapTests.cpp

tests/CMakeFiles/aisdiMapsTests.dir/TreeMapTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aisdiMapsTests.dir/TreeMapTests.cpp.i"
	cd /home/tomeczek/Pulpit/Mapy/Release/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tomeczek/Pulpit/Mapy/tests/TreeMapTests.cpp > CMakeFiles/aisdiMapsTests.dir/TreeMapTests.cpp.i

tests/CMakeFiles/aisdiMapsTests.dir/TreeMapTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aisdiMapsTests.dir/TreeMapTests.cpp.s"
	cd /home/tomeczek/Pulpit/Mapy/Release/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tomeczek/Pulpit/Mapy/tests/TreeMapTests.cpp -o CMakeFiles/aisdiMapsTests.dir/TreeMapTests.cpp.s

tests/CMakeFiles/aisdiMapsTests.dir/TreeMapTests.cpp.o.requires:

.PHONY : tests/CMakeFiles/aisdiMapsTests.dir/TreeMapTests.cpp.o.requires

tests/CMakeFiles/aisdiMapsTests.dir/TreeMapTests.cpp.o.provides: tests/CMakeFiles/aisdiMapsTests.dir/TreeMapTests.cpp.o.requires
	$(MAKE) -f tests/CMakeFiles/aisdiMapsTests.dir/build.make tests/CMakeFiles/aisdiMapsTests.dir/TreeMapTests.cpp.o.provides.build
.PHONY : tests/CMakeFiles/aisdiMapsTests.dir/TreeMapTests.cpp.o.provides

tests/CMakeFiles/aisdiMapsTests.dir/TreeMapTests.cpp.o.provides.build: tests/CMakeFiles/aisdiMapsTests.dir/TreeMapTests.cpp.o


tests/CMakeFiles/aisdiMapsTests.dir/HashMapTests.cpp.o: tests/CMakeFiles/aisdiMapsTests.dir/flags.make
tests/CMakeFiles/aisdiMapsTests.dir/HashMapTests.cpp.o: ../tests/HashMapTests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tomeczek/Pulpit/Mapy/Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object tests/CMakeFiles/aisdiMapsTests.dir/HashMapTests.cpp.o"
	cd /home/tomeczek/Pulpit/Mapy/Release/tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/aisdiMapsTests.dir/HashMapTests.cpp.o -c /home/tomeczek/Pulpit/Mapy/tests/HashMapTests.cpp

tests/CMakeFiles/aisdiMapsTests.dir/HashMapTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aisdiMapsTests.dir/HashMapTests.cpp.i"
	cd /home/tomeczek/Pulpit/Mapy/Release/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tomeczek/Pulpit/Mapy/tests/HashMapTests.cpp > CMakeFiles/aisdiMapsTests.dir/HashMapTests.cpp.i

tests/CMakeFiles/aisdiMapsTests.dir/HashMapTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aisdiMapsTests.dir/HashMapTests.cpp.s"
	cd /home/tomeczek/Pulpit/Mapy/Release/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tomeczek/Pulpit/Mapy/tests/HashMapTests.cpp -o CMakeFiles/aisdiMapsTests.dir/HashMapTests.cpp.s

tests/CMakeFiles/aisdiMapsTests.dir/HashMapTests.cpp.o.requires:

.PHONY : tests/CMakeFiles/aisdiMapsTests.dir/HashMapTests.cpp.o.requires

tests/CMakeFiles/aisdiMapsTests.dir/HashMapTests.cpp.o.provides: tests/CMakeFiles/aisdiMapsTests.dir/HashMapTests.cpp.o.requires
	$(MAKE) -f tests/CMakeFiles/aisdiMapsTests.dir/build.make tests/CMakeFiles/aisdiMapsTests.dir/HashMapTests.cpp.o.provides.build
.PHONY : tests/CMakeFiles/aisdiMapsTests.dir/HashMapTests.cpp.o.provides

tests/CMakeFiles/aisdiMapsTests.dir/HashMapTests.cpp.o.provides.build: tests/CMakeFiles/aisdiMapsTests.dir/HashMapTests.cpp.o


# Object files for target aisdiMapsTests
aisdiMapsTests_OBJECTS = \
"CMakeFiles/aisdiMapsTests.dir/test_main.cpp.o" \
"CMakeFiles/aisdiMapsTests.dir/TreeMapTests.cpp.o" \
"CMakeFiles/aisdiMapsTests.dir/HashMapTests.cpp.o"

# External object files for target aisdiMapsTests
aisdiMapsTests_EXTERNAL_OBJECTS =

tests/aisdiMapsTests: tests/CMakeFiles/aisdiMapsTests.dir/test_main.cpp.o
tests/aisdiMapsTests: tests/CMakeFiles/aisdiMapsTests.dir/TreeMapTests.cpp.o
tests/aisdiMapsTests: tests/CMakeFiles/aisdiMapsTests.dir/HashMapTests.cpp.o
tests/aisdiMapsTests: tests/CMakeFiles/aisdiMapsTests.dir/build.make
tests/aisdiMapsTests: /usr/lib/i386-linux-gnu/libboost_unit_test_framework.so
tests/aisdiMapsTests: tests/CMakeFiles/aisdiMapsTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tomeczek/Pulpit/Mapy/Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable aisdiMapsTests"
	cd /home/tomeczek/Pulpit/Mapy/Release/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/aisdiMapsTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/aisdiMapsTests.dir/build: tests/aisdiMapsTests

.PHONY : tests/CMakeFiles/aisdiMapsTests.dir/build

tests/CMakeFiles/aisdiMapsTests.dir/requires: tests/CMakeFiles/aisdiMapsTests.dir/test_main.cpp.o.requires
tests/CMakeFiles/aisdiMapsTests.dir/requires: tests/CMakeFiles/aisdiMapsTests.dir/TreeMapTests.cpp.o.requires
tests/CMakeFiles/aisdiMapsTests.dir/requires: tests/CMakeFiles/aisdiMapsTests.dir/HashMapTests.cpp.o.requires

.PHONY : tests/CMakeFiles/aisdiMapsTests.dir/requires

tests/CMakeFiles/aisdiMapsTests.dir/clean:
	cd /home/tomeczek/Pulpit/Mapy/Release/tests && $(CMAKE_COMMAND) -P CMakeFiles/aisdiMapsTests.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/aisdiMapsTests.dir/clean

tests/CMakeFiles/aisdiMapsTests.dir/depend:
	cd /home/tomeczek/Pulpit/Mapy/Release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tomeczek/Pulpit/Mapy /home/tomeczek/Pulpit/Mapy/tests /home/tomeczek/Pulpit/Mapy/Release /home/tomeczek/Pulpit/Mapy/Release/tests /home/tomeczek/Pulpit/Mapy/Release/tests/CMakeFiles/aisdiMapsTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/aisdiMapsTests.dir/depend
