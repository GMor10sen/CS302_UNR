cmake_minimum_required(VERSION 2.8.9)

project(Project3)
set (CMAKE_CXX_STANDARD11)	


# considered for header files in include file
include_directories(include)

# Create a variable from file in source files as taught in CS202 
set(BINARY_NODE_SOURCES src/BinaryNode.cpp)
add_library(BinaryNode ${BINARY_NODE_SOURCES}) 

# Do the same 
set(BINARY_NODE_TREE_SOURCES src/BinaryNodeTree.cpp)
add_library(BinaryNodeTree ${BINARY_NODE_TREE_SOURCES}) 

# Do the same 
set(BINARY_SEARCH_TREE_SOURCES src/BinarySearchTree.cpp)
add_library(BinarySearchTree ${BINARY_SEARCH_TREE_SOURCES}) 

# Rule for creating an executable (by compiling the project source main)
add_executable(proj3 src/Proj3.cpp)



# Got help on this part by TA
target_link_libraries(proj3 BinaryNode BinaryNode BinarySearchTree )


# Install targets as taught in CS202
install(TARGETS proj3 BinaryNode BinaryNode BinarySearchTree
	RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/devel/bin
	LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib
	ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib/static)


#cheks include file for .h files to put in source Dir
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
	DESTINATION ${PROJECT_SOURCE_DIR}/devel/include
	FILES_MATCHING PATTERN "*.h")
