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
CMAKE_SOURCE_DIR = /home/hhou/CLionProjects/hhuo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hhou/CLionProjects/hhuo/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/test4task.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/test4task.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/test4task.dir/flags.make

tests/CMakeFiles/test4task.dir/test4task.cpp.o: tests/CMakeFiles/test4task.dir/flags.make
tests/CMakeFiles/test4task.dir/test4task.cpp.o: ../tests/test4task.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hhou/CLionProjects/hhuo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/test4task.dir/test4task.cpp.o"
	cd /home/hhou/CLionProjects/hhuo/build/tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test4task.dir/test4task.cpp.o -c /home/hhou/CLionProjects/hhuo/tests/test4task.cpp

tests/CMakeFiles/test4task.dir/test4task.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test4task.dir/test4task.cpp.i"
	cd /home/hhou/CLionProjects/hhuo/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hhou/CLionProjects/hhuo/tests/test4task.cpp > CMakeFiles/test4task.dir/test4task.cpp.i

tests/CMakeFiles/test4task.dir/test4task.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test4task.dir/test4task.cpp.s"
	cd /home/hhou/CLionProjects/hhuo/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hhou/CLionProjects/hhuo/tests/test4task.cpp -o CMakeFiles/test4task.dir/test4task.cpp.s

tests/CMakeFiles/test4task.dir/test4task.cpp.o.requires:

.PHONY : tests/CMakeFiles/test4task.dir/test4task.cpp.o.requires

tests/CMakeFiles/test4task.dir/test4task.cpp.o.provides: tests/CMakeFiles/test4task.dir/test4task.cpp.o.requires
	$(MAKE) -f tests/CMakeFiles/test4task.dir/build.make tests/CMakeFiles/test4task.dir/test4task.cpp.o.provides.build
.PHONY : tests/CMakeFiles/test4task.dir/test4task.cpp.o.provides

tests/CMakeFiles/test4task.dir/test4task.cpp.o.provides.build: tests/CMakeFiles/test4task.dir/test4task.cpp.o


# Object files for target test4task
test4task_OBJECTS = \
"CMakeFiles/test4task.dir/test4task.cpp.o"

# External object files for target test4task
test4task_EXTERNAL_OBJECTS =

bin/test4task: tests/CMakeFiles/test4task.dir/test4task.cpp.o
bin/test4task: tests/CMakeFiles/test4task.dir/build.make
bin/test4task: lib/libhhnet.a
bin/test4task: lib/libhhparser.a
bin/test4task: lib/libhhutils.a
bin/test4task: tests/CMakeFiles/test4task.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hhou/CLionProjects/hhuo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/test4task"
	cd /home/hhou/CLionProjects/hhuo/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test4task.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/test4task.dir/build: bin/test4task

.PHONY : tests/CMakeFiles/test4task.dir/build

tests/CMakeFiles/test4task.dir/requires: tests/CMakeFiles/test4task.dir/test4task.cpp.o.requires

.PHONY : tests/CMakeFiles/test4task.dir/requires

tests/CMakeFiles/test4task.dir/clean:
	cd /home/hhou/CLionProjects/hhuo/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/test4task.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/test4task.dir/clean

tests/CMakeFiles/test4task.dir/depend:
	cd /home/hhou/CLionProjects/hhuo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hhou/CLionProjects/hhuo /home/hhou/CLionProjects/hhuo/tests /home/hhou/CLionProjects/hhuo/build /home/hhou/CLionProjects/hhuo/build/tests /home/hhou/CLionProjects/hhuo/build/tests/CMakeFiles/test4task.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/test4task.dir/depend

