# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.7

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.1.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.1.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\mao.liu\CLionProjects\hhuo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\mao.liu\CLionProjects\hhuo\cmake-build-debug

# Include any dependencies generated for this target.
include tests/CMakeFiles/bind.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/bind.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/bind.dir/flags.make

tests/CMakeFiles/bind.dir/bind.obj: tests/CMakeFiles/bind.dir/flags.make
tests/CMakeFiles/bind.dir/bind.obj: tests/CMakeFiles/bind.dir/includes_CXX.rsp
tests/CMakeFiles/bind.dir/bind.obj: ../tests/bind.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mao.liu\CLionProjects\hhuo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/bind.dir/bind.obj"
	cd /d C:\Users\mao.liu\CLionProjects\hhuo\cmake-build-debug\tests && C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\bind.dir\bind.obj -c C:\Users\mao.liu\CLionProjects\hhuo\tests\bind.cpp

tests/CMakeFiles/bind.dir/bind.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bind.dir/bind.i"
	cd /d C:\Users\mao.liu\CLionProjects\hhuo\cmake-build-debug\tests && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mao.liu\CLionProjects\hhuo\tests\bind.cpp > CMakeFiles\bind.dir\bind.i

tests/CMakeFiles/bind.dir/bind.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bind.dir/bind.s"
	cd /d C:\Users\mao.liu\CLionProjects\hhuo\cmake-build-debug\tests && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mao.liu\CLionProjects\hhuo\tests\bind.cpp -o CMakeFiles\bind.dir\bind.s

tests/CMakeFiles/bind.dir/bind.obj.requires:

.PHONY : tests/CMakeFiles/bind.dir/bind.obj.requires

tests/CMakeFiles/bind.dir/bind.obj.provides: tests/CMakeFiles/bind.dir/bind.obj.requires
	$(MAKE) -f tests\CMakeFiles\bind.dir\build.make tests/CMakeFiles/bind.dir/bind.obj.provides.build
.PHONY : tests/CMakeFiles/bind.dir/bind.obj.provides

tests/CMakeFiles/bind.dir/bind.obj.provides.build: tests/CMakeFiles/bind.dir/bind.obj


# Object files for target bind
bind_OBJECTS = \
"CMakeFiles/bind.dir/bind.obj"

# External object files for target bind
bind_EXTERNAL_OBJECTS =

bin/bind.exe: tests/CMakeFiles/bind.dir/bind.obj
bin/bind.exe: tests/CMakeFiles/bind.dir/build.make
bin/bind.exe: lib/libhhuo.dll.a
bin/bind.exe: tests/CMakeFiles/bind.dir/linklibs.rsp
bin/bind.exe: tests/CMakeFiles/bind.dir/objects1.rsp
bin/bind.exe: tests/CMakeFiles/bind.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\mao.liu\CLionProjects\hhuo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ..\bin\bind.exe"
	cd /d C:\Users\mao.liu\CLionProjects\hhuo\cmake-build-debug\tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\bind.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/bind.dir/build: bin/bind.exe

.PHONY : tests/CMakeFiles/bind.dir/build

tests/CMakeFiles/bind.dir/requires: tests/CMakeFiles/bind.dir/bind.obj.requires

.PHONY : tests/CMakeFiles/bind.dir/requires

tests/CMakeFiles/bind.dir/clean:
	cd /d C:\Users\mao.liu\CLionProjects\hhuo\cmake-build-debug\tests && $(CMAKE_COMMAND) -P CMakeFiles\bind.dir\cmake_clean.cmake
.PHONY : tests/CMakeFiles/bind.dir/clean

tests/CMakeFiles/bind.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\mao.liu\CLionProjects\hhuo C:\Users\mao.liu\CLionProjects\hhuo\tests C:\Users\mao.liu\CLionProjects\hhuo\cmake-build-debug C:\Users\mao.liu\CLionProjects\hhuo\cmake-build-debug\tests C:\Users\mao.liu\CLionProjects\hhuo\cmake-build-debug\tests\CMakeFiles\bind.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/bind.dir/depend

