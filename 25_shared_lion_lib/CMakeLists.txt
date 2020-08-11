# set minimum required cmake version 
cmake_minimum_required(VERSION 3.0)

# create variable containing project name
SET(PROJECT_NAME "25_shared_lion_lib")

# set project name
PROJECT(${PROJECT_NAME})
MESSAGE(STATUS "building ${PROJECT_NAME} ...")
ADD_DEFINITIONS(-DUNICODE -D_UNICODE)
# TODO: consider adding the following definition
ADD_DEFINITIONS(-DLION_DLL)

SET(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake_modules/;${CMAKE_MODULE_PATH}")

SET(CMAKE_CXX_STANDARD 11)

# specify the folder(s) where the compiler should look for include files
include_directories(
	include #in our case the 'include' folder present in the root folder
	../24_shared_feline_lib/include # Use this library
)

# or we can use file(GLOB ...) for wildcard additon (add any file ending with '.h')
FILE(GLOB HEADER_FILES "include/*.h")

FILE(GLOB SRC_FILES "src/*.cpp")

# specify where to generate the executable file
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin)

# specify that we are building an executable, and what sources to use 
ADD_LIBRARY(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SRC_FILES})

# ----------------------------------------
# Link to dependencies
# This library depends on functionality contained in the other classes E.g. feline class.
# We don't have access to the feline class in this library, so import the binary code
# from another lib. 
TARGET_LINK_LIBRARIES(${PROJECT_NAME} 24_shared_feline_lib)
