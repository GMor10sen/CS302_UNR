# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/build"

# Include any dependencies generated for this target.
include CMakeFiles/StackArray.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/StackArray.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/StackArray.dir/flags.make

CMakeFiles/StackArray.dir/src/StackArray.cpp.o: CMakeFiles/StackArray.dir/flags.make
CMakeFiles/StackArray.dir/src/StackArray.cpp.o: ../src/StackArray.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/StackArray.dir/src/StackArray.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/StackArray.dir/src/StackArray.cpp.o -c "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/src/StackArray.cpp"

CMakeFiles/StackArray.dir/src/StackArray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StackArray.dir/src/StackArray.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/src/StackArray.cpp" > CMakeFiles/StackArray.dir/src/StackArray.cpp.i

CMakeFiles/StackArray.dir/src/StackArray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StackArray.dir/src/StackArray.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/src/StackArray.cpp" -o CMakeFiles/StackArray.dir/src/StackArray.cpp.s

CMakeFiles/StackArray.dir/src/StackArray.cpp.o.requires:

.PHONY : CMakeFiles/StackArray.dir/src/StackArray.cpp.o.requires

CMakeFiles/StackArray.dir/src/StackArray.cpp.o.provides: CMakeFiles/StackArray.dir/src/StackArray.cpp.o.requires
	$(MAKE) -f CMakeFiles/StackArray.dir/build.make CMakeFiles/StackArray.dir/src/StackArray.cpp.o.provides.build
.PHONY : CMakeFiles/StackArray.dir/src/StackArray.cpp.o.provides

CMakeFiles/StackArray.dir/src/StackArray.cpp.o.provides.build: CMakeFiles/StackArray.dir/src/StackArray.cpp.o


# Object files for target StackArray
StackArray_OBJECTS = \
"CMakeFiles/StackArray.dir/src/StackArray.cpp.o"

# External object files for target StackArray
StackArray_EXTERNAL_OBJECTS =

libStackArray.a: CMakeFiles/StackArray.dir/src/StackArray.cpp.o
libStackArray.a: CMakeFiles/StackArray.dir/build.make
libStackArray.a: CMakeFiles/StackArray.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libStackArray.a"
	$(CMAKE_COMMAND) -P CMakeFiles/StackArray.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/StackArray.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/StackArray.dir/build: libStackArray.a

.PHONY : CMakeFiles/StackArray.dir/build

CMakeFiles/StackArray.dir/requires: CMakeFiles/StackArray.dir/src/StackArray.cpp.o.requires

.PHONY : CMakeFiles/StackArray.dir/requires

CMakeFiles/StackArray.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/StackArray.dir/cmake_clean.cmake
.PHONY : CMakeFiles/StackArray.dir/clean

CMakeFiles/StackArray.dir/depend:
	cd "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)" "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)" "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/build" "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/build" "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/build/CMakeFiles/StackArray.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/StackArray.dir/depend
