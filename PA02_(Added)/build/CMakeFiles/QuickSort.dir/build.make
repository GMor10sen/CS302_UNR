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
CMAKE_SOURCE_DIR = "/home/gabriel/Desktop/PA02_(Extra)"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/gabriel/Desktop/PA02_(Extra)/build"

# Include any dependencies generated for this target.
include CMakeFiles/QuickSort.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/QuickSort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/QuickSort.dir/flags.make

CMakeFiles/QuickSort.dir/src/QuickSort.cpp.o: CMakeFiles/QuickSort.dir/flags.make
CMakeFiles/QuickSort.dir/src/QuickSort.cpp.o: ../src/QuickSort.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/gabriel/Desktop/PA02_(Extra)/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/QuickSort.dir/src/QuickSort.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QuickSort.dir/src/QuickSort.cpp.o -c "/home/gabriel/Desktop/PA02_(Extra)/src/QuickSort.cpp"

CMakeFiles/QuickSort.dir/src/QuickSort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QuickSort.dir/src/QuickSort.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/gabriel/Desktop/PA02_(Extra)/src/QuickSort.cpp" > CMakeFiles/QuickSort.dir/src/QuickSort.cpp.i

CMakeFiles/QuickSort.dir/src/QuickSort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QuickSort.dir/src/QuickSort.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/gabriel/Desktop/PA02_(Extra)/src/QuickSort.cpp" -o CMakeFiles/QuickSort.dir/src/QuickSort.cpp.s

CMakeFiles/QuickSort.dir/src/QuickSort.cpp.o.requires:

.PHONY : CMakeFiles/QuickSort.dir/src/QuickSort.cpp.o.requires

CMakeFiles/QuickSort.dir/src/QuickSort.cpp.o.provides: CMakeFiles/QuickSort.dir/src/QuickSort.cpp.o.requires
	$(MAKE) -f CMakeFiles/QuickSort.dir/build.make CMakeFiles/QuickSort.dir/src/QuickSort.cpp.o.provides.build
.PHONY : CMakeFiles/QuickSort.dir/src/QuickSort.cpp.o.provides

CMakeFiles/QuickSort.dir/src/QuickSort.cpp.o.provides.build: CMakeFiles/QuickSort.dir/src/QuickSort.cpp.o


# Object files for target QuickSort
QuickSort_OBJECTS = \
"CMakeFiles/QuickSort.dir/src/QuickSort.cpp.o"

# External object files for target QuickSort
QuickSort_EXTERNAL_OBJECTS =

libQuickSort.a: CMakeFiles/QuickSort.dir/src/QuickSort.cpp.o
libQuickSort.a: CMakeFiles/QuickSort.dir/build.make
libQuickSort.a: CMakeFiles/QuickSort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/gabriel/Desktop/PA02_(Extra)/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libQuickSort.a"
	$(CMAKE_COMMAND) -P CMakeFiles/QuickSort.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/QuickSort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/QuickSort.dir/build: libQuickSort.a

.PHONY : CMakeFiles/QuickSort.dir/build

CMakeFiles/QuickSort.dir/requires: CMakeFiles/QuickSort.dir/src/QuickSort.cpp.o.requires

.PHONY : CMakeFiles/QuickSort.dir/requires

CMakeFiles/QuickSort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/QuickSort.dir/cmake_clean.cmake
.PHONY : CMakeFiles/QuickSort.dir/clean

CMakeFiles/QuickSort.dir/depend:
	cd "/home/gabriel/Desktop/PA02_(Extra)/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/gabriel/Desktop/PA02_(Extra)" "/home/gabriel/Desktop/PA02_(Extra)" "/home/gabriel/Desktop/PA02_(Extra)/build" "/home/gabriel/Desktop/PA02_(Extra)/build" "/home/gabriel/Desktop/PA02_(Extra)/build/CMakeFiles/QuickSort.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/QuickSort.dir/depend

