# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.4

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
CMAKE_COMMAND = /home/glutolik/cmake-3.4.1-Linux-x86_64/bin/cmake

# The command to remove a file.
RM = /home/glutolik/cmake-3.4.1-Linux-x86_64/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/glutolik/mipt

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/glutolik/mipt

# Include any dependencies generated for this target.
include agraph/CMakeFiles/agraph.dir/depend.make

# Include the progress variables for this target.
include agraph/CMakeFiles/agraph.dir/progress.make

# Include the compile flags for this target's objects.
include agraph/CMakeFiles/agraph.dir/flags.make

agraph/CMakeFiles/agraph.dir/agraph.cpp.o: agraph/CMakeFiles/agraph.dir/flags.make
agraph/CMakeFiles/agraph.dir/agraph.cpp.o: agraph/agraph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/glutolik/mipt/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object agraph/CMakeFiles/agraph.dir/agraph.cpp.o"
	cd /home/glutolik/mipt/agraph && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/agraph.dir/agraph.cpp.o -c /home/glutolik/mipt/agraph/agraph.cpp

agraph/CMakeFiles/agraph.dir/agraph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/agraph.dir/agraph.cpp.i"
	cd /home/glutolik/mipt/agraph && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/glutolik/mipt/agraph/agraph.cpp > CMakeFiles/agraph.dir/agraph.cpp.i

agraph/CMakeFiles/agraph.dir/agraph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/agraph.dir/agraph.cpp.s"
	cd /home/glutolik/mipt/agraph && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/glutolik/mipt/agraph/agraph.cpp -o CMakeFiles/agraph.dir/agraph.cpp.s

agraph/CMakeFiles/agraph.dir/agraph.cpp.o.requires:

.PHONY : agraph/CMakeFiles/agraph.dir/agraph.cpp.o.requires

agraph/CMakeFiles/agraph.dir/agraph.cpp.o.provides: agraph/CMakeFiles/agraph.dir/agraph.cpp.o.requires
	$(MAKE) -f agraph/CMakeFiles/agraph.dir/build.make agraph/CMakeFiles/agraph.dir/agraph.cpp.o.provides.build
.PHONY : agraph/CMakeFiles/agraph.dir/agraph.cpp.o.provides

agraph/CMakeFiles/agraph.dir/agraph.cpp.o.provides.build: agraph/CMakeFiles/agraph.dir/agraph.cpp.o


# Object files for target agraph
agraph_OBJECTS = \
"CMakeFiles/agraph.dir/agraph.cpp.o"

# External object files for target agraph
agraph_EXTERNAL_OBJECTS =

bin/libagraph.so: agraph/CMakeFiles/agraph.dir/agraph.cpp.o
bin/libagraph.so: agraph/CMakeFiles/agraph.dir/build.make
bin/libagraph.so: agraph/CMakeFiles/agraph.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/glutolik/mipt/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ../bin/libagraph.so"
	cd /home/glutolik/mipt/agraph && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/agraph.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
agraph/CMakeFiles/agraph.dir/build: bin/libagraph.so

.PHONY : agraph/CMakeFiles/agraph.dir/build

agraph/CMakeFiles/agraph.dir/requires: agraph/CMakeFiles/agraph.dir/agraph.cpp.o.requires

.PHONY : agraph/CMakeFiles/agraph.dir/requires

agraph/CMakeFiles/agraph.dir/clean:
	cd /home/glutolik/mipt/agraph && $(CMAKE_COMMAND) -P CMakeFiles/agraph.dir/cmake_clean.cmake
.PHONY : agraph/CMakeFiles/agraph.dir/clean

agraph/CMakeFiles/agraph.dir/depend:
	cd /home/glutolik/mipt && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/glutolik/mipt /home/glutolik/mipt/agraph /home/glutolik/mipt /home/glutolik/mipt/agraph /home/glutolik/mipt/agraph/CMakeFiles/agraph.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : agraph/CMakeFiles/agraph.dir/depend
