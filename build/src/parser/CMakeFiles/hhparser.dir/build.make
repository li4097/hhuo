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
include src/parser/CMakeFiles/hhparser.dir/depend.make

# Include the progress variables for this target.
include src/parser/CMakeFiles/hhparser.dir/progress.make

# Include the compile flags for this target's objects.
include src/parser/CMakeFiles/hhparser.dir/flags.make

src/parser/CMakeFiles/hhparser.dir/HH_HttpResponse.cpp.o: src/parser/CMakeFiles/hhparser.dir/flags.make
src/parser/CMakeFiles/hhparser.dir/HH_HttpResponse.cpp.o: ../src/parser/HH_HttpResponse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hhou/CLionProjects/hhuo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/parser/CMakeFiles/hhparser.dir/HH_HttpResponse.cpp.o"
	cd /home/hhou/CLionProjects/hhuo/build/src/parser && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hhparser.dir/HH_HttpResponse.cpp.o -c /home/hhou/CLionProjects/hhuo/src/parser/HH_HttpResponse.cpp

src/parser/CMakeFiles/hhparser.dir/HH_HttpResponse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hhparser.dir/HH_HttpResponse.cpp.i"
	cd /home/hhou/CLionProjects/hhuo/build/src/parser && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hhou/CLionProjects/hhuo/src/parser/HH_HttpResponse.cpp > CMakeFiles/hhparser.dir/HH_HttpResponse.cpp.i

src/parser/CMakeFiles/hhparser.dir/HH_HttpResponse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hhparser.dir/HH_HttpResponse.cpp.s"
	cd /home/hhou/CLionProjects/hhuo/build/src/parser && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hhou/CLionProjects/hhuo/src/parser/HH_HttpResponse.cpp -o CMakeFiles/hhparser.dir/HH_HttpResponse.cpp.s

src/parser/CMakeFiles/hhparser.dir/HH_HttpResponse.cpp.o.requires:

.PHONY : src/parser/CMakeFiles/hhparser.dir/HH_HttpResponse.cpp.o.requires

src/parser/CMakeFiles/hhparser.dir/HH_HttpResponse.cpp.o.provides: src/parser/CMakeFiles/hhparser.dir/HH_HttpResponse.cpp.o.requires
	$(MAKE) -f src/parser/CMakeFiles/hhparser.dir/build.make src/parser/CMakeFiles/hhparser.dir/HH_HttpResponse.cpp.o.provides.build
.PHONY : src/parser/CMakeFiles/hhparser.dir/HH_HttpResponse.cpp.o.provides

src/parser/CMakeFiles/hhparser.dir/HH_HttpResponse.cpp.o.provides.build: src/parser/CMakeFiles/hhparser.dir/HH_HttpResponse.cpp.o


src/parser/CMakeFiles/hhparser.dir/HH_HttpRequest.cpp.o: src/parser/CMakeFiles/hhparser.dir/flags.make
src/parser/CMakeFiles/hhparser.dir/HH_HttpRequest.cpp.o: ../src/parser/HH_HttpRequest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hhou/CLionProjects/hhuo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/parser/CMakeFiles/hhparser.dir/HH_HttpRequest.cpp.o"
	cd /home/hhou/CLionProjects/hhuo/build/src/parser && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hhparser.dir/HH_HttpRequest.cpp.o -c /home/hhou/CLionProjects/hhuo/src/parser/HH_HttpRequest.cpp

src/parser/CMakeFiles/hhparser.dir/HH_HttpRequest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hhparser.dir/HH_HttpRequest.cpp.i"
	cd /home/hhou/CLionProjects/hhuo/build/src/parser && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hhou/CLionProjects/hhuo/src/parser/HH_HttpRequest.cpp > CMakeFiles/hhparser.dir/HH_HttpRequest.cpp.i

src/parser/CMakeFiles/hhparser.dir/HH_HttpRequest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hhparser.dir/HH_HttpRequest.cpp.s"
	cd /home/hhou/CLionProjects/hhuo/build/src/parser && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hhou/CLionProjects/hhuo/src/parser/HH_HttpRequest.cpp -o CMakeFiles/hhparser.dir/HH_HttpRequest.cpp.s

src/parser/CMakeFiles/hhparser.dir/HH_HttpRequest.cpp.o.requires:

.PHONY : src/parser/CMakeFiles/hhparser.dir/HH_HttpRequest.cpp.o.requires

src/parser/CMakeFiles/hhparser.dir/HH_HttpRequest.cpp.o.provides: src/parser/CMakeFiles/hhparser.dir/HH_HttpRequest.cpp.o.requires
	$(MAKE) -f src/parser/CMakeFiles/hhparser.dir/build.make src/parser/CMakeFiles/hhparser.dir/HH_HttpRequest.cpp.o.provides.build
.PHONY : src/parser/CMakeFiles/hhparser.dir/HH_HttpRequest.cpp.o.provides

src/parser/CMakeFiles/hhparser.dir/HH_HttpRequest.cpp.o.provides.build: src/parser/CMakeFiles/hhparser.dir/HH_HttpRequest.cpp.o


src/parser/CMakeFiles/hhparser.dir/HH_Parse.cpp.o: src/parser/CMakeFiles/hhparser.dir/flags.make
src/parser/CMakeFiles/hhparser.dir/HH_Parse.cpp.o: ../src/parser/HH_Parse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hhou/CLionProjects/hhuo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/parser/CMakeFiles/hhparser.dir/HH_Parse.cpp.o"
	cd /home/hhou/CLionProjects/hhuo/build/src/parser && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hhparser.dir/HH_Parse.cpp.o -c /home/hhou/CLionProjects/hhuo/src/parser/HH_Parse.cpp

src/parser/CMakeFiles/hhparser.dir/HH_Parse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hhparser.dir/HH_Parse.cpp.i"
	cd /home/hhou/CLionProjects/hhuo/build/src/parser && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hhou/CLionProjects/hhuo/src/parser/HH_Parse.cpp > CMakeFiles/hhparser.dir/HH_Parse.cpp.i

src/parser/CMakeFiles/hhparser.dir/HH_Parse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hhparser.dir/HH_Parse.cpp.s"
	cd /home/hhou/CLionProjects/hhuo/build/src/parser && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hhou/CLionProjects/hhuo/src/parser/HH_Parse.cpp -o CMakeFiles/hhparser.dir/HH_Parse.cpp.s

src/parser/CMakeFiles/hhparser.dir/HH_Parse.cpp.o.requires:

.PHONY : src/parser/CMakeFiles/hhparser.dir/HH_Parse.cpp.o.requires

src/parser/CMakeFiles/hhparser.dir/HH_Parse.cpp.o.provides: src/parser/CMakeFiles/hhparser.dir/HH_Parse.cpp.o.requires
	$(MAKE) -f src/parser/CMakeFiles/hhparser.dir/build.make src/parser/CMakeFiles/hhparser.dir/HH_Parse.cpp.o.provides.build
.PHONY : src/parser/CMakeFiles/hhparser.dir/HH_Parse.cpp.o.provides

src/parser/CMakeFiles/hhparser.dir/HH_Parse.cpp.o.provides.build: src/parser/CMakeFiles/hhparser.dir/HH_Parse.cpp.o


# Object files for target hhparser
hhparser_OBJECTS = \
"CMakeFiles/hhparser.dir/HH_HttpResponse.cpp.o" \
"CMakeFiles/hhparser.dir/HH_HttpRequest.cpp.o" \
"CMakeFiles/hhparser.dir/HH_Parse.cpp.o"

# External object files for target hhparser
hhparser_EXTERNAL_OBJECTS =

lib/libhhparser.a: src/parser/CMakeFiles/hhparser.dir/HH_HttpResponse.cpp.o
lib/libhhparser.a: src/parser/CMakeFiles/hhparser.dir/HH_HttpRequest.cpp.o
lib/libhhparser.a: src/parser/CMakeFiles/hhparser.dir/HH_Parse.cpp.o
lib/libhhparser.a: src/parser/CMakeFiles/hhparser.dir/build.make
lib/libhhparser.a: src/parser/CMakeFiles/hhparser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hhou/CLionProjects/hhuo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library ../../lib/libhhparser.a"
	cd /home/hhou/CLionProjects/hhuo/build/src/parser && $(CMAKE_COMMAND) -P CMakeFiles/hhparser.dir/cmake_clean_target.cmake
	cd /home/hhou/CLionProjects/hhuo/build/src/parser && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hhparser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/parser/CMakeFiles/hhparser.dir/build: lib/libhhparser.a

.PHONY : src/parser/CMakeFiles/hhparser.dir/build

src/parser/CMakeFiles/hhparser.dir/requires: src/parser/CMakeFiles/hhparser.dir/HH_HttpResponse.cpp.o.requires
src/parser/CMakeFiles/hhparser.dir/requires: src/parser/CMakeFiles/hhparser.dir/HH_HttpRequest.cpp.o.requires
src/parser/CMakeFiles/hhparser.dir/requires: src/parser/CMakeFiles/hhparser.dir/HH_Parse.cpp.o.requires

.PHONY : src/parser/CMakeFiles/hhparser.dir/requires

src/parser/CMakeFiles/hhparser.dir/clean:
	cd /home/hhou/CLionProjects/hhuo/build/src/parser && $(CMAKE_COMMAND) -P CMakeFiles/hhparser.dir/cmake_clean.cmake
.PHONY : src/parser/CMakeFiles/hhparser.dir/clean

src/parser/CMakeFiles/hhparser.dir/depend:
	cd /home/hhou/CLionProjects/hhuo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hhou/CLionProjects/hhuo /home/hhou/CLionProjects/hhuo/src/parser /home/hhou/CLionProjects/hhuo/build /home/hhou/CLionProjects/hhuo/build/src/parser /home/hhou/CLionProjects/hhuo/build/src/parser/CMakeFiles/hhparser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/parser/CMakeFiles/hhparser.dir/depend
