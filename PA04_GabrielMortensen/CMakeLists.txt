cmake_minimum_required(VERSION 2.8.9)

project(Project4)
set (CMAKE_CXX_STANDARD11)	


# considered for header files in include file
include_directories(include)

# Create a variable from file in source files as taught in CS202 
set(LEFTLEANINGREDBLACK_SOURCES src/LeftLeaningRedBlack.cpp)
add_library(LeftLeaningRedBlack ${LEFTLEANINGREDBLACK_SOURCES}) 
 
# Rule for creating an executable (by compiling the project source main)
add_executable(proj4 src/Proj4.cpp)


# Got help on this part by TA
target_link_libraries(proj4 LeftLeaningRedBlack  )


# Install targets as taught in CS202
install(TARGETS proj4 LeftLeaningRedBlack 
	RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/devel/bin
	LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib
	ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib/static)


#cheks include file for .h files to put in source Dir
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
	DESTINATION ${PROJECT_SOURCE_DIR}/devel/include
	FILES_MATCHING PATTERN "*.h")
