# Install script for directory: /home/gabriel/Desktop/PA01_GabrielMortensen(Extra)

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/devel/bin/postfix" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/devel/bin/postfix")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/devel/bin/postfix"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/devel/bin/postfix")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/devel/bin" TYPE EXECUTABLE FILES "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/build/postfix")
  if(EXISTS "$ENV{DESTDIR}/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/devel/bin/postfix" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/devel/bin/postfix")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/devel/bin/postfix")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/devel/lib/static/libStackLinked.a")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/devel/lib/static" TYPE STATIC_LIBRARY FILES "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/build/libStackLinked.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/devel/lib/static/libStackArray.a")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/devel/lib/static" TYPE STATIC_LIBRARY FILES "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/build/libStackArray.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/devel/bin/delimiters" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/devel/bin/delimiters")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/devel/bin/delimiters"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/devel/bin/delimiters")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/devel/bin" TYPE EXECUTABLE FILES "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/build/delimiters")
  if(EXISTS "$ENV{DESTDIR}/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/devel/bin/delimiters" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/devel/bin/delimiters")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/devel/bin/delimiters")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/devel/lib/static/libStackLinked.a")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/devel/lib/static" TYPE STATIC_LIBRARY FILES "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/build/libStackLinked.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/devel/lib/static/libStackArray.a")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/devel/lib/static" TYPE STATIC_LIBRARY FILES "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/build/libStackArray.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/devel/bin/palindrome" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/devel/bin/palindrome")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/devel/bin/palindrome"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/devel/bin/palindrome")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/devel/bin" TYPE EXECUTABLE FILES "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/build/palindrome")
  if(EXISTS "$ENV{DESTDIR}/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/devel/bin/palindrome" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/devel/bin/palindrome")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/devel/bin/palindrome")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/devel/lib/static/libStackLinked.a")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/devel/lib/static" TYPE STATIC_LIBRARY FILES "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/build/libStackLinked.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/devel/lib/static/libStackArray.a")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/devel/lib/static" TYPE STATIC_LIBRARY FILES "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/build/libStackArray.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/devel/include/")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/devel/include" TYPE DIRECTORY FILES "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/include/" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/gabriel/Desktop/PA01_GabrielMortensen(Extra)/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
