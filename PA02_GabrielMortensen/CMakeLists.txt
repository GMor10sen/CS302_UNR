cmake_minimum_required(VERSION 2.8.9)

project(Project2)
set (CMAKE_CXX_STANDARD11)	


# considered for header files in include file
include_directories(include)

# Create a variable from file in source files as taught in CS202 
set(BUBBLE_SOURCES src/Bubble.cpp)
add_library(Bubble ${BUBBLE_SOURCES}) 

# Do the same 
set(MERGE_SOURCES src/Merge.cpp)
add_library(Merge ${MERGE_SOURCES}) 

# DO the same 
set(SORTINGPARENT_SOURCES src/SortingParent.cpp)
add_library(SortingParent ${SORTINGPARENT_SOURCES}) 

# Rule for creating an executable (by compiling the project source main)
add_executable(proj2 src/proj2.cpp)



# Got help on this part by TA
target_link_libraries(proj2 Bubble Merge SortingParent  )


# Install targets as taught in CS202
install(TARGETS proj2 SortingParent Bubble Merge 
	RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/devel/bin
	LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib
	ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib/static)


#cheks include file for .h files to put in source Dir
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
	DESTINATION ${PROJECT_SOURCE_DIR}/devel/include
	FILES_MATCHING PATTERN "*.h")
