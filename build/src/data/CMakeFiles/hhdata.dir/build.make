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
CMAKE_SOURCE_DIR = /mnt/hgfs/CPP/hhuo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/hgfs/CPP/hhuo/build

# Include any dependencies generated for this target.
include src/data/CMakeFiles/hhdata.dir/depend.make

# Include the progress variables for this target.
include src/data/CMakeFiles/hhdata.dir/progress.make

# Include the compile flags for this target's objects.
include src/data/CMakeFiles/hhdata.dir/flags.make

src/data/CMakeFiles/hhdata.dir/HH_Json.cpp.o: src/data/CMakeFiles/hhdata.dir/flags.make
src/data/CMakeFiles/hhdata.dir/HH_Json.cpp.o: ../src/data/HH_Json.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/CPP/hhuo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/data/CMakeFiles/hhdata.dir/HH_Json.cpp.o"
	cd /mnt/hgfs/CPP/hhuo/build/src/data && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hhdata.dir/HH_Json.cpp.o -c /mnt/hgfs/CPP/hhuo/src/data/HH_Json.cpp

src/data/CMakeFiles/hhdata.dir/HH_Json.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hhdata.dir/HH_Json.cpp.i"
	cd /mnt/hgfs/CPP/hhuo/build/src/data && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/CPP/hhuo/src/data/HH_Json.cpp > CMakeFiles/hhdata.dir/HH_Json.cpp.i

src/data/CMakeFiles/hhdata.dir/HH_Json.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hhdata.dir/HH_Json.cpp.s"
	cd /mnt/hgfs/CPP/hhuo/build/src/data && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/CPP/hhuo/src/data/HH_Json.cpp -o CMakeFiles/hhdata.dir/HH_Json.cpp.s

src/data/CMakeFiles/hhdata.dir/HH_Json.cpp.o.requires:

.PHONY : src/data/CMakeFiles/hhdata.dir/HH_Json.cpp.o.requires

src/data/CMakeFiles/hhdata.dir/HH_Json.cpp.o.provides: src/data/CMakeFiles/hhdata.dir/HH_Json.cpp.o.requires
	$(MAKE) -f src/data/CMakeFiles/hhdata.dir/build.make src/data/CMakeFiles/hhdata.dir/HH_Json.cpp.o.provides.build
.PHONY : src/data/CMakeFiles/hhdata.dir/HH_Json.cpp.o.provides

src/data/CMakeFiles/hhdata.dir/HH_Json.cpp.o.provides.build: src/data/CMakeFiles/hhdata.dir/HH_Json.cpp.o


src/data/CMakeFiles/hhdata.dir/HH_Mysql.cpp.o: src/data/CMakeFiles/hhdata.dir/flags.make
src/data/CMakeFiles/hhdata.dir/HH_Mysql.cpp.o: ../src/data/HH_Mysql.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/CPP/hhuo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/data/CMakeFiles/hhdata.dir/HH_Mysql.cpp.o"
	cd /mnt/hgfs/CPP/hhuo/build/src/data && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hhdata.dir/HH_Mysql.cpp.o -c /mnt/hgfs/CPP/hhuo/src/data/HH_Mysql.cpp

src/data/CMakeFiles/hhdata.dir/HH_Mysql.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hhdata.dir/HH_Mysql.cpp.i"
	cd /mnt/hgfs/CPP/hhuo/build/src/data && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/CPP/hhuo/src/data/HH_Mysql.cpp > CMakeFiles/hhdata.dir/HH_Mysql.cpp.i

src/data/CMakeFiles/hhdata.dir/HH_Mysql.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hhdata.dir/HH_Mysql.cpp.s"
	cd /mnt/hgfs/CPP/hhuo/build/src/data && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/CPP/hhuo/src/data/HH_Mysql.cpp -o CMakeFiles/hhdata.dir/HH_Mysql.cpp.s

src/data/CMakeFiles/hhdata.dir/HH_Mysql.cpp.o.requires:

.PHONY : src/data/CMakeFiles/hhdata.dir/HH_Mysql.cpp.o.requires

src/data/CMakeFiles/hhdata.dir/HH_Mysql.cpp.o.provides: src/data/CMakeFiles/hhdata.dir/HH_Mysql.cpp.o.requires
	$(MAKE) -f src/data/CMakeFiles/hhdata.dir/build.make src/data/CMakeFiles/hhdata.dir/HH_Mysql.cpp.o.provides.build
.PHONY : src/data/CMakeFiles/hhdata.dir/HH_Mysql.cpp.o.provides

src/data/CMakeFiles/hhdata.dir/HH_Mysql.cpp.o.provides.build: src/data/CMakeFiles/hhdata.dir/HH_Mysql.cpp.o


src/data/CMakeFiles/hhdata.dir/HH_Redis.cpp.o: src/data/CMakeFiles/hhdata.dir/flags.make
src/data/CMakeFiles/hhdata.dir/HH_Redis.cpp.o: ../src/data/HH_Redis.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/CPP/hhuo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/data/CMakeFiles/hhdata.dir/HH_Redis.cpp.o"
	cd /mnt/hgfs/CPP/hhuo/build/src/data && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hhdata.dir/HH_Redis.cpp.o -c /mnt/hgfs/CPP/hhuo/src/data/HH_Redis.cpp

src/data/CMakeFiles/hhdata.dir/HH_Redis.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hhdata.dir/HH_Redis.cpp.i"
	cd /mnt/hgfs/CPP/hhuo/build/src/data && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/CPP/hhuo/src/data/HH_Redis.cpp > CMakeFiles/hhdata.dir/HH_Redis.cpp.i

src/data/CMakeFiles/hhdata.dir/HH_Redis.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hhdata.dir/HH_Redis.cpp.s"
	cd /mnt/hgfs/CPP/hhuo/build/src/data && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/CPP/hhuo/src/data/HH_Redis.cpp -o CMakeFiles/hhdata.dir/HH_Redis.cpp.s

src/data/CMakeFiles/hhdata.dir/HH_Redis.cpp.o.requires:

.PHONY : src/data/CMakeFiles/hhdata.dir/HH_Redis.cpp.o.requires

src/data/CMakeFiles/hhdata.dir/HH_Redis.cpp.o.provides: src/data/CMakeFiles/hhdata.dir/HH_Redis.cpp.o.requires
	$(MAKE) -f src/data/CMakeFiles/hhdata.dir/build.make src/data/CMakeFiles/hhdata.dir/HH_Redis.cpp.o.provides.build
.PHONY : src/data/CMakeFiles/hhdata.dir/HH_Redis.cpp.o.provides

src/data/CMakeFiles/hhdata.dir/HH_Redis.cpp.o.provides.build: src/data/CMakeFiles/hhdata.dir/HH_Redis.cpp.o


# Object files for target hhdata
hhdata_OBJECTS = \
"CMakeFiles/hhdata.dir/HH_Json.cpp.o" \
"CMakeFiles/hhdata.dir/HH_Mysql.cpp.o" \
"CMakeFiles/hhdata.dir/HH_Redis.cpp.o"

# External object files for target hhdata
hhdata_EXTERNAL_OBJECTS =

lib/libhhdata.a: src/data/CMakeFiles/hhdata.dir/HH_Json.cpp.o
lib/libhhdata.a: src/data/CMakeFiles/hhdata.dir/HH_Mysql.cpp.o
lib/libhhdata.a: src/data/CMakeFiles/hhdata.dir/HH_Redis.cpp.o
lib/libhhdata.a: src/data/CMakeFiles/hhdata.dir/build.make
lib/libhhdata.a: src/data/CMakeFiles/hhdata.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/hgfs/CPP/hhuo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library ../../lib/libhhdata.a"
	cd /mnt/hgfs/CPP/hhuo/build/src/data && $(CMAKE_COMMAND) -P CMakeFiles/hhdata.dir/cmake_clean_target.cmake
	cd /mnt/hgfs/CPP/hhuo/build/src/data && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hhdata.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/data/CMakeFiles/hhdata.dir/build: lib/libhhdata.a

.PHONY : src/data/CMakeFiles/hhdata.dir/build

src/data/CMakeFiles/hhdata.dir/requires: src/data/CMakeFiles/hhdata.dir/HH_Json.cpp.o.requires
src/data/CMakeFiles/hhdata.dir/requires: src/data/CMakeFiles/hhdata.dir/HH_Mysql.cpp.o.requires
src/data/CMakeFiles/hhdata.dir/requires: src/data/CMakeFiles/hhdata.dir/HH_Redis.cpp.o.requires

.PHONY : src/data/CMakeFiles/hhdata.dir/requires

src/data/CMakeFiles/hhdata.dir/clean:
	cd /mnt/hgfs/CPP/hhuo/build/src/data && $(CMAKE_COMMAND) -P CMakeFiles/hhdata.dir/cmake_clean.cmake
.PHONY : src/data/CMakeFiles/hhdata.dir/clean

src/data/CMakeFiles/hhdata.dir/depend:
	cd /mnt/hgfs/CPP/hhuo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/hgfs/CPP/hhuo /mnt/hgfs/CPP/hhuo/src/data /mnt/hgfs/CPP/hhuo/build /mnt/hgfs/CPP/hhuo/build/src/data /mnt/hgfs/CPP/hhuo/build/src/data/CMakeFiles/hhdata.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/data/CMakeFiles/hhdata.dir/depend

