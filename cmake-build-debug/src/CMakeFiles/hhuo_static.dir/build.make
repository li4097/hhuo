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
include src/CMakeFiles/hhuo_static.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/hhuo_static.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/hhuo_static.dir/flags.make

src/CMakeFiles/hhuo_static.dir/HH_FDEvent.obj: src/CMakeFiles/hhuo_static.dir/flags.make
src/CMakeFiles/hhuo_static.dir/HH_FDEvent.obj: src/CMakeFiles/hhuo_static.dir/includes_CXX.rsp
src/CMakeFiles/hhuo_static.dir/HH_FDEvent.obj: ../src/HH_FDEvent.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mao.liu\CLionProjects\hhuo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/hhuo_static.dir/HH_FDEvent.obj"
	cd /d C:\Users\mao.liu\CLionProjects\hhuo\cmake-build-debug\src && C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\hhuo_static.dir\HH_FDEvent.obj -c C:\Users\mao.liu\CLionProjects\hhuo\src\HH_FDEvent.cpp

src/CMakeFiles/hhuo_static.dir/HH_FDEvent.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hhuo_static.dir/HH_FDEvent.i"
	cd /d C:\Users\mao.liu\CLionProjects\hhuo\cmake-build-debug\src && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mao.liu\CLionProjects\hhuo\src\HH_FDEvent.cpp > CMakeFiles\hhuo_static.dir\HH_FDEvent.i

src/CMakeFiles/hhuo_static.dir/HH_FDEvent.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hhuo_static.dir/HH_FDEvent.s"
	cd /d C:\Users\mao.liu\CLionProjects\hhuo\cmake-build-debug\src && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mao.liu\CLionProjects\hhuo\src\HH_FDEvent.cpp -o CMakeFiles\hhuo_static.dir\HH_FDEvent.s

src/CMakeFiles/hhuo_static.dir/HH_FDEvent.obj.requires:

.PHONY : src/CMakeFiles/hhuo_static.dir/HH_FDEvent.obj.requires

src/CMakeFiles/hhuo_static.dir/HH_FDEvent.obj.provides: src/CMakeFiles/hhuo_static.dir/HH_FDEvent.obj.requires
	$(MAKE) -f src\CMakeFiles\hhuo_static.dir\build.make src/CMakeFiles/hhuo_static.dir/HH_FDEvent.obj.provides.build
.PHONY : src/CMakeFiles/hhuo_static.dir/HH_FDEvent.obj.provides

src/CMakeFiles/hhuo_static.dir/HH_FDEvent.obj.provides.build: src/CMakeFiles/hhuo_static.dir/HH_FDEvent.obj


src/CMakeFiles/hhuo_static.dir/HH_EventLoop.obj: src/CMakeFiles/hhuo_static.dir/flags.make
src/CMakeFiles/hhuo_static.dir/HH_EventLoop.obj: src/CMakeFiles/hhuo_static.dir/includes_CXX.rsp
src/CMakeFiles/hhuo_static.dir/HH_EventLoop.obj: ../src/HH_EventLoop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mao.liu\CLionProjects\hhuo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/hhuo_static.dir/HH_EventLoop.obj"
	cd /d C:\Users\mao.liu\CLionProjects\hhuo\cmake-build-debug\src && C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\hhuo_static.dir\HH_EventLoop.obj -c C:\Users\mao.liu\CLionProjects\hhuo\src\HH_EventLoop.cpp

src/CMakeFiles/hhuo_static.dir/HH_EventLoop.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hhuo_static.dir/HH_EventLoop.i"
	cd /d C:\Users\mao.liu\CLionProjects\hhuo\cmake-build-debug\src && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mao.liu\CLionProjects\hhuo\src\HH_EventLoop.cpp > CMakeFiles\hhuo_static.dir\HH_EventLoop.i

src/CMakeFiles/hhuo_static.dir/HH_EventLoop.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hhuo_static.dir/HH_EventLoop.s"
	cd /d C:\Users\mao.liu\CLionProjects\hhuo\cmake-build-debug\src && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mao.liu\CLionProjects\hhuo\src\HH_EventLoop.cpp -o CMakeFiles\hhuo_static.dir\HH_EventLoop.s

src/CMakeFiles/hhuo_static.dir/HH_EventLoop.obj.requires:

.PHONY : src/CMakeFiles/hhuo_static.dir/HH_EventLoop.obj.requires

src/CMakeFiles/hhuo_static.dir/HH_EventLoop.obj.provides: src/CMakeFiles/hhuo_static.dir/HH_EventLoop.obj.requires
	$(MAKE) -f src\CMakeFiles\hhuo_static.dir\build.make src/CMakeFiles/hhuo_static.dir/HH_EventLoop.obj.provides.build
.PHONY : src/CMakeFiles/hhuo_static.dir/HH_EventLoop.obj.provides

src/CMakeFiles/hhuo_static.dir/HH_EventLoop.obj.provides.build: src/CMakeFiles/hhuo_static.dir/HH_EventLoop.obj


src/CMakeFiles/hhuo_static.dir/HH_ListenEvent.obj: src/CMakeFiles/hhuo_static.dir/flags.make
src/CMakeFiles/hhuo_static.dir/HH_ListenEvent.obj: src/CMakeFiles/hhuo_static.dir/includes_CXX.rsp
src/CMakeFiles/hhuo_static.dir/HH_ListenEvent.obj: ../src/HH_ListenEvent.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mao.liu\CLionProjects\hhuo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/hhuo_static.dir/HH_ListenEvent.obj"
	cd /d C:\Users\mao.liu\CLionProjects\hhuo\cmake-build-debug\src && C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\hhuo_static.dir\HH_ListenEvent.obj -c C:\Users\mao.liu\CLionProjects\hhuo\src\HH_ListenEvent.cpp

src/CMakeFiles/hhuo_static.dir/HH_ListenEvent.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hhuo_static.dir/HH_ListenEvent.i"
	cd /d C:\Users\mao.liu\CLionProjects\hhuo\cmake-build-debug\src && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mao.liu\CLionProjects\hhuo\src\HH_ListenEvent.cpp > CMakeFiles\hhuo_static.dir\HH_ListenEvent.i

src/CMakeFiles/hhuo_static.dir/HH_ListenEvent.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hhuo_static.dir/HH_ListenEvent.s"
	cd /d C:\Users\mao.liu\CLionProjects\hhuo\cmake-build-debug\src && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mao.liu\CLionProjects\hhuo\src\HH_ListenEvent.cpp -o CMakeFiles\hhuo_static.dir\HH_ListenEvent.s

src/CMakeFiles/hhuo_static.dir/HH_ListenEvent.obj.requires:

.PHONY : src/CMakeFiles/hhuo_static.dir/HH_ListenEvent.obj.requires

src/CMakeFiles/hhuo_static.dir/HH_ListenEvent.obj.provides: src/CMakeFiles/hhuo_static.dir/HH_ListenEvent.obj.requires
	$(MAKE) -f src\CMakeFiles\hhuo_static.dir\build.make src/CMakeFiles/hhuo_static.dir/HH_ListenEvent.obj.provides.build
.PHONY : src/CMakeFiles/hhuo_static.dir/HH_ListenEvent.obj.provides

src/CMakeFiles/hhuo_static.dir/HH_ListenEvent.obj.provides.build: src/CMakeFiles/hhuo_static.dir/HH_ListenEvent.obj


src/CMakeFiles/hhuo_static.dir/HH_Poller.obj: src/CMakeFiles/hhuo_static.dir/flags.make
src/CMakeFiles/hhuo_static.dir/HH_Poller.obj: src/CMakeFiles/hhuo_static.dir/includes_CXX.rsp
src/CMakeFiles/hhuo_static.dir/HH_Poller.obj: ../src/HH_Poller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mao.liu\CLionProjects\hhuo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/hhuo_static.dir/HH_Poller.obj"
	cd /d C:\Users\mao.liu\CLionProjects\hhuo\cmake-build-debug\src && C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\hhuo_static.dir\HH_Poller.obj -c C:\Users\mao.liu\CLionProjects\hhuo\src\HH_Poller.cpp

src/CMakeFiles/hhuo_static.dir/HH_Poller.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hhuo_static.dir/HH_Poller.i"
	cd /d C:\Users\mao.liu\CLionProjects\hhuo\cmake-build-debug\src && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mao.liu\CLionProjects\hhuo\src\HH_Poller.cpp > CMakeFiles\hhuo_static.dir\HH_Poller.i

src/CMakeFiles/hhuo_static.dir/HH_Poller.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hhuo_static.dir/HH_Poller.s"
	cd /d C:\Users\mao.liu\CLionProjects\hhuo\cmake-build-debug\src && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mao.liu\CLionProjects\hhuo\src\HH_Poller.cpp -o CMakeFiles\hhuo_static.dir\HH_Poller.s

src/CMakeFiles/hhuo_static.dir/HH_Poller.obj.requires:

.PHONY : src/CMakeFiles/hhuo_static.dir/HH_Poller.obj.requires

src/CMakeFiles/hhuo_static.dir/HH_Poller.obj.provides: src/CMakeFiles/hhuo_static.dir/HH_Poller.obj.requires
	$(MAKE) -f src\CMakeFiles\hhuo_static.dir\build.make src/CMakeFiles/hhuo_static.dir/HH_Poller.obj.provides.build
.PHONY : src/CMakeFiles/hhuo_static.dir/HH_Poller.obj.provides

src/CMakeFiles/hhuo_static.dir/HH_Poller.obj.provides.build: src/CMakeFiles/hhuo_static.dir/HH_Poller.obj


# Object files for target hhuo_static
hhuo_static_OBJECTS = \
"CMakeFiles/hhuo_static.dir/HH_FDEvent.obj" \
"CMakeFiles/hhuo_static.dir/HH_EventLoop.obj" \
"CMakeFiles/hhuo_static.dir/HH_ListenEvent.obj" \
"CMakeFiles/hhuo_static.dir/HH_Poller.obj"

# External object files for target hhuo_static
hhuo_static_EXTERNAL_OBJECTS =

lib/libhhuo.a: src/CMakeFiles/hhuo_static.dir/HH_FDEvent.obj
lib/libhhuo.a: src/CMakeFiles/hhuo_static.dir/HH_EventLoop.obj
lib/libhhuo.a: src/CMakeFiles/hhuo_static.dir/HH_ListenEvent.obj
lib/libhhuo.a: src/CMakeFiles/hhuo_static.dir/HH_Poller.obj
lib/libhhuo.a: src/CMakeFiles/hhuo_static.dir/build.make
lib/libhhuo.a: src/CMakeFiles/hhuo_static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\mao.liu\CLionProjects\hhuo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library ..\lib\libhhuo.a"
	cd /d C:\Users\mao.liu\CLionProjects\hhuo\cmake-build-debug\src && $(CMAKE_COMMAND) -P CMakeFiles\hhuo_static.dir\cmake_clean_target.cmake
	cd /d C:\Users\mao.liu\CLionProjects\hhuo\cmake-build-debug\src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\hhuo_static.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/hhuo_static.dir/build: lib/libhhuo.a

.PHONY : src/CMakeFiles/hhuo_static.dir/build

src/CMakeFiles/hhuo_static.dir/requires: src/CMakeFiles/hhuo_static.dir/HH_FDEvent.obj.requires
src/CMakeFiles/hhuo_static.dir/requires: src/CMakeFiles/hhuo_static.dir/HH_EventLoop.obj.requires
src/CMakeFiles/hhuo_static.dir/requires: src/CMakeFiles/hhuo_static.dir/HH_ListenEvent.obj.requires
src/CMakeFiles/hhuo_static.dir/requires: src/CMakeFiles/hhuo_static.dir/HH_Poller.obj.requires

.PHONY : src/CMakeFiles/hhuo_static.dir/requires

src/CMakeFiles/hhuo_static.dir/clean:
	cd /d C:\Users\mao.liu\CLionProjects\hhuo\cmake-build-debug\src && $(CMAKE_COMMAND) -P CMakeFiles\hhuo_static.dir\cmake_clean.cmake
.PHONY : src/CMakeFiles/hhuo_static.dir/clean

src/CMakeFiles/hhuo_static.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\mao.liu\CLionProjects\hhuo C:\Users\mao.liu\CLionProjects\hhuo\src C:\Users\mao.liu\CLionProjects\hhuo\cmake-build-debug C:\Users\mao.liu\CLionProjects\hhuo\cmake-build-debug\src C:\Users\mao.liu\CLionProjects\hhuo\cmake-build-debug\src\CMakeFiles\hhuo_static.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/hhuo_static.dir/depend

