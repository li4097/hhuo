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
include src/net/CMakeFiles/hhnet.dir/depend.make

# Include the progress variables for this target.
include src/net/CMakeFiles/hhnet.dir/progress.make

# Include the compile flags for this target's objects.
include src/net/CMakeFiles/hhnet.dir/flags.make

src/net/CMakeFiles/hhnet.dir/HH_EventLoop.cpp.o: src/net/CMakeFiles/hhnet.dir/flags.make
src/net/CMakeFiles/hhnet.dir/HH_EventLoop.cpp.o: ../src/net/HH_EventLoop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hhou/CLionProjects/hhuo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/net/CMakeFiles/hhnet.dir/HH_EventLoop.cpp.o"
	cd /home/hhou/CLionProjects/hhuo/build/src/net && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hhnet.dir/HH_EventLoop.cpp.o -c /home/hhou/CLionProjects/hhuo/src/net/HH_EventLoop.cpp

src/net/CMakeFiles/hhnet.dir/HH_EventLoop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hhnet.dir/HH_EventLoop.cpp.i"
	cd /home/hhou/CLionProjects/hhuo/build/src/net && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hhou/CLionProjects/hhuo/src/net/HH_EventLoop.cpp > CMakeFiles/hhnet.dir/HH_EventLoop.cpp.i

src/net/CMakeFiles/hhnet.dir/HH_EventLoop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hhnet.dir/HH_EventLoop.cpp.s"
	cd /home/hhou/CLionProjects/hhuo/build/src/net && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hhou/CLionProjects/hhuo/src/net/HH_EventLoop.cpp -o CMakeFiles/hhnet.dir/HH_EventLoop.cpp.s

src/net/CMakeFiles/hhnet.dir/HH_EventLoop.cpp.o.requires:

.PHONY : src/net/CMakeFiles/hhnet.dir/HH_EventLoop.cpp.o.requires

src/net/CMakeFiles/hhnet.dir/HH_EventLoop.cpp.o.provides: src/net/CMakeFiles/hhnet.dir/HH_EventLoop.cpp.o.requires
	$(MAKE) -f src/net/CMakeFiles/hhnet.dir/build.make src/net/CMakeFiles/hhnet.dir/HH_EventLoop.cpp.o.provides.build
.PHONY : src/net/CMakeFiles/hhnet.dir/HH_EventLoop.cpp.o.provides

src/net/CMakeFiles/hhnet.dir/HH_EventLoop.cpp.o.provides.build: src/net/CMakeFiles/hhnet.dir/HH_EventLoop.cpp.o


src/net/CMakeFiles/hhnet.dir/HH_FDEvent.cpp.o: src/net/CMakeFiles/hhnet.dir/flags.make
src/net/CMakeFiles/hhnet.dir/HH_FDEvent.cpp.o: ../src/net/HH_FDEvent.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hhou/CLionProjects/hhuo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/net/CMakeFiles/hhnet.dir/HH_FDEvent.cpp.o"
	cd /home/hhou/CLionProjects/hhuo/build/src/net && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hhnet.dir/HH_FDEvent.cpp.o -c /home/hhou/CLionProjects/hhuo/src/net/HH_FDEvent.cpp

src/net/CMakeFiles/hhnet.dir/HH_FDEvent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hhnet.dir/HH_FDEvent.cpp.i"
	cd /home/hhou/CLionProjects/hhuo/build/src/net && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hhou/CLionProjects/hhuo/src/net/HH_FDEvent.cpp > CMakeFiles/hhnet.dir/HH_FDEvent.cpp.i

src/net/CMakeFiles/hhnet.dir/HH_FDEvent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hhnet.dir/HH_FDEvent.cpp.s"
	cd /home/hhou/CLionProjects/hhuo/build/src/net && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hhou/CLionProjects/hhuo/src/net/HH_FDEvent.cpp -o CMakeFiles/hhnet.dir/HH_FDEvent.cpp.s

src/net/CMakeFiles/hhnet.dir/HH_FDEvent.cpp.o.requires:

.PHONY : src/net/CMakeFiles/hhnet.dir/HH_FDEvent.cpp.o.requires

src/net/CMakeFiles/hhnet.dir/HH_FDEvent.cpp.o.provides: src/net/CMakeFiles/hhnet.dir/HH_FDEvent.cpp.o.requires
	$(MAKE) -f src/net/CMakeFiles/hhnet.dir/build.make src/net/CMakeFiles/hhnet.dir/HH_FDEvent.cpp.o.provides.build
.PHONY : src/net/CMakeFiles/hhnet.dir/HH_FDEvent.cpp.o.provides

src/net/CMakeFiles/hhnet.dir/HH_FDEvent.cpp.o.provides.build: src/net/CMakeFiles/hhnet.dir/HH_FDEvent.cpp.o


src/net/CMakeFiles/hhnet.dir/HH_ListenEvent.cpp.o: src/net/CMakeFiles/hhnet.dir/flags.make
src/net/CMakeFiles/hhnet.dir/HH_ListenEvent.cpp.o: ../src/net/HH_ListenEvent.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hhou/CLionProjects/hhuo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/net/CMakeFiles/hhnet.dir/HH_ListenEvent.cpp.o"
	cd /home/hhou/CLionProjects/hhuo/build/src/net && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hhnet.dir/HH_ListenEvent.cpp.o -c /home/hhou/CLionProjects/hhuo/src/net/HH_ListenEvent.cpp

src/net/CMakeFiles/hhnet.dir/HH_ListenEvent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hhnet.dir/HH_ListenEvent.cpp.i"
	cd /home/hhou/CLionProjects/hhuo/build/src/net && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hhou/CLionProjects/hhuo/src/net/HH_ListenEvent.cpp > CMakeFiles/hhnet.dir/HH_ListenEvent.cpp.i

src/net/CMakeFiles/hhnet.dir/HH_ListenEvent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hhnet.dir/HH_ListenEvent.cpp.s"
	cd /home/hhou/CLionProjects/hhuo/build/src/net && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hhou/CLionProjects/hhuo/src/net/HH_ListenEvent.cpp -o CMakeFiles/hhnet.dir/HH_ListenEvent.cpp.s

src/net/CMakeFiles/hhnet.dir/HH_ListenEvent.cpp.o.requires:

.PHONY : src/net/CMakeFiles/hhnet.dir/HH_ListenEvent.cpp.o.requires

src/net/CMakeFiles/hhnet.dir/HH_ListenEvent.cpp.o.provides: src/net/CMakeFiles/hhnet.dir/HH_ListenEvent.cpp.o.requires
	$(MAKE) -f src/net/CMakeFiles/hhnet.dir/build.make src/net/CMakeFiles/hhnet.dir/HH_ListenEvent.cpp.o.provides.build
.PHONY : src/net/CMakeFiles/hhnet.dir/HH_ListenEvent.cpp.o.provides

src/net/CMakeFiles/hhnet.dir/HH_ListenEvent.cpp.o.provides.build: src/net/CMakeFiles/hhnet.dir/HH_ListenEvent.cpp.o


src/net/CMakeFiles/hhnet.dir/HH_Poller.cpp.o: src/net/CMakeFiles/hhnet.dir/flags.make
src/net/CMakeFiles/hhnet.dir/HH_Poller.cpp.o: ../src/net/HH_Poller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hhou/CLionProjects/hhuo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/net/CMakeFiles/hhnet.dir/HH_Poller.cpp.o"
	cd /home/hhou/CLionProjects/hhuo/build/src/net && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hhnet.dir/HH_Poller.cpp.o -c /home/hhou/CLionProjects/hhuo/src/net/HH_Poller.cpp

src/net/CMakeFiles/hhnet.dir/HH_Poller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hhnet.dir/HH_Poller.cpp.i"
	cd /home/hhou/CLionProjects/hhuo/build/src/net && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hhou/CLionProjects/hhuo/src/net/HH_Poller.cpp > CMakeFiles/hhnet.dir/HH_Poller.cpp.i

src/net/CMakeFiles/hhnet.dir/HH_Poller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hhnet.dir/HH_Poller.cpp.s"
	cd /home/hhou/CLionProjects/hhuo/build/src/net && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hhou/CLionProjects/hhuo/src/net/HH_Poller.cpp -o CMakeFiles/hhnet.dir/HH_Poller.cpp.s

src/net/CMakeFiles/hhnet.dir/HH_Poller.cpp.o.requires:

.PHONY : src/net/CMakeFiles/hhnet.dir/HH_Poller.cpp.o.requires

src/net/CMakeFiles/hhnet.dir/HH_Poller.cpp.o.provides: src/net/CMakeFiles/hhnet.dir/HH_Poller.cpp.o.requires
	$(MAKE) -f src/net/CMakeFiles/hhnet.dir/build.make src/net/CMakeFiles/hhnet.dir/HH_Poller.cpp.o.provides.build
.PHONY : src/net/CMakeFiles/hhnet.dir/HH_Poller.cpp.o.provides

src/net/CMakeFiles/hhnet.dir/HH_Poller.cpp.o.provides.build: src/net/CMakeFiles/hhnet.dir/HH_Poller.cpp.o


# Object files for target hhnet
hhnet_OBJECTS = \
"CMakeFiles/hhnet.dir/HH_EventLoop.cpp.o" \
"CMakeFiles/hhnet.dir/HH_FDEvent.cpp.o" \
"CMakeFiles/hhnet.dir/HH_ListenEvent.cpp.o" \
"CMakeFiles/hhnet.dir/HH_Poller.cpp.o"

# External object files for target hhnet
hhnet_EXTERNAL_OBJECTS =

lib/libhhnet.a: src/net/CMakeFiles/hhnet.dir/HH_EventLoop.cpp.o
lib/libhhnet.a: src/net/CMakeFiles/hhnet.dir/HH_FDEvent.cpp.o
lib/libhhnet.a: src/net/CMakeFiles/hhnet.dir/HH_ListenEvent.cpp.o
lib/libhhnet.a: src/net/CMakeFiles/hhnet.dir/HH_Poller.cpp.o
lib/libhhnet.a: src/net/CMakeFiles/hhnet.dir/build.make
lib/libhhnet.a: src/net/CMakeFiles/hhnet.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hhou/CLionProjects/hhuo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library ../../lib/libhhnet.a"
	cd /home/hhou/CLionProjects/hhuo/build/src/net && $(CMAKE_COMMAND) -P CMakeFiles/hhnet.dir/cmake_clean_target.cmake
	cd /home/hhou/CLionProjects/hhuo/build/src/net && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hhnet.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/net/CMakeFiles/hhnet.dir/build: lib/libhhnet.a

.PHONY : src/net/CMakeFiles/hhnet.dir/build

src/net/CMakeFiles/hhnet.dir/requires: src/net/CMakeFiles/hhnet.dir/HH_EventLoop.cpp.o.requires
src/net/CMakeFiles/hhnet.dir/requires: src/net/CMakeFiles/hhnet.dir/HH_FDEvent.cpp.o.requires
src/net/CMakeFiles/hhnet.dir/requires: src/net/CMakeFiles/hhnet.dir/HH_ListenEvent.cpp.o.requires
src/net/CMakeFiles/hhnet.dir/requires: src/net/CMakeFiles/hhnet.dir/HH_Poller.cpp.o.requires

.PHONY : src/net/CMakeFiles/hhnet.dir/requires

src/net/CMakeFiles/hhnet.dir/clean:
	cd /home/hhou/CLionProjects/hhuo/build/src/net && $(CMAKE_COMMAND) -P CMakeFiles/hhnet.dir/cmake_clean.cmake
.PHONY : src/net/CMakeFiles/hhnet.dir/clean

src/net/CMakeFiles/hhnet.dir/depend:
	cd /home/hhou/CLionProjects/hhuo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hhou/CLionProjects/hhuo /home/hhou/CLionProjects/hhuo/src/net /home/hhou/CLionProjects/hhuo/build /home/hhou/CLionProjects/hhuo/build/src/net /home/hhou/CLionProjects/hhuo/build/src/net/CMakeFiles/hhnet.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/net/CMakeFiles/hhnet.dir/depend
