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
include CMakeFiles/SortingParent.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SortingParent.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SortingParent.dir/flags.make

CMakeFiles/SortingParent.dir/src/SortingParent.cpp.o: CMakeFiles/SortingParent.dir/flags.make
CMakeFiles/SortingParent.dir/src/SortingParent.cpp.o: ../src/SortingParent.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/gabriel/Desktop/PA02_(Extra)/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SortingParent.dir/src/SortingParent.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SortingParent.dir/src/SortingParent.cpp.o -c "/home/gabriel/Desktop/PA02_(Extra)/src/SortingParent.cpp"

CMakeFiles/SortingParent.dir/src/SortingParent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SortingParent.dir/src/SortingParent.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/gabriel/Desktop/PA02_(Extra)/src/SortingParent.cpp" > CMakeFiles/SortingParent.dir/src/SortingParent.cpp.i

CMakeFiles/SortingParent.dir/src/SortingParent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SortingParent.dir/src/SortingParent.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/gabriel/Desktop/PA02_(Extra)/src/SortingParent.cpp" -o CMakeFiles/SortingParent.dir/src/SortingParent.cpp.s

CMakeFiles/SortingParent.dir/src/SortingParent.cpp.o.requires:

.PHONY : CMakeFiles/SortingParent.dir/src/SortingParent.cpp.o.requires

CMakeFiles/SortingParent.dir/src/SortingParent.cpp.o.provides: CMakeFiles/SortingParent.dir/src/SortingParent.cpp.o.requires
	$(MAKE) -f CMakeFiles/SortingParent.dir/build.make CMakeFiles/SortingParent.dir/src/SortingParent.cpp.o.provides.build
.PHONY : CMakeFiles/SortingParent.dir/src/SortingParent.cpp.o.provides

CMakeFiles/SortingParent.dir/src/SortingParent.cpp.o.provides.build: CMakeFiles/SortingParent.dir/src/SortingParent.cpp.o


# Object files for target SortingParent
SortingParent_OBJECTS = \
"CMakeFiles/SortingParent.dir/src/SortingParent.cpp.o"

# External object files for target SortingParent
SortingParent_EXTERNAL_OBJECTS =

libSortingParent.a: CMakeFiles/SortingParent.dir/src/SortingParent.cpp.o
libSortingParent.a: CMakeFiles/SortingParent.dir/build.make
libSortingParent.a: CMakeFiles/SortingParent.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/gabriel/Desktop/PA02_(Extra)/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libSortingParent.a"
	$(CMAKE_COMMAND) -P CMakeFiles/SortingParent.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SortingParent.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SortingParent.dir/build: libSortingParent.a

.PHONY : CMakeFiles/SortingParent.dir/build

CMakeFiles/SortingParent.dir/requires: CMakeFiles/SortingParent.dir/src/SortingParent.cpp.o.requires

.PHONY : CMakeFiles/SortingParent.dir/requires

CMakeFiles/SortingParent.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SortingParent.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SortingParent.dir/clean

CMakeFiles/SortingParent.dir/depend:
	cd "/home/gabriel/Desktop/PA02_(Extra)/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/gabriel/Desktop/PA02_(Extra)" "/home/gabriel/Desktop/PA02_(Extra)" "/home/gabriel/Desktop/PA02_(Extra)/build" "/home/gabriel/Desktop/PA02_(Extra)/build" "/home/gabriel/Desktop/PA02_(Extra)/build/CMakeFiles/SortingParent.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/SortingParent.dir/depend

