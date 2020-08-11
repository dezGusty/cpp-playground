# set minimum required cmake version 
cmake_minimum_required(VERSION 3.0)

# Create variable containing project name. We'll be using this in several places and it helps with copy-pasting into a new project.
# For simplicity this should match the directory name.
SET(PROJECT_NAME "26_shared_cats")

# set project name
PROJECT(${PROJECT_NAME})
MESSAGE(STATUS "building ${PROJECT_NAME} ...")
ADD_DEFINITIONS(-DUNICODE -D_UNICODE)

SET(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake_modules/;${CMAKE_MODULE_PATH}")

SET(CMAKE_CXX_STANDARD 11)

# specify the folder(s) where the compiler should look for include files
include_directories(
	include #in our case the 'include' folder present in the root folder
	../24_shared_feline_lib/include # Use this library
	../25_shared_lion_lib/include # Use this library
)
# or we can use file(GLOB ...) for wildcard additon (add any file ending with '.h')
FILE(GLOB HEADER_FILES "include/*.h")
FILE(GLOB SRC_FILES "src/*.cpp")

# specify where to generate the executable file
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin)

# specify that we are building an executable, and what sources to use 
ADD_EXECUTABLE(${PROJECT_NAME} ${HEADER_FILES} ${SRC_FILES})

# ----------------------------------------
# Link to dependencies
# This library depends on functionality contained in the other classes E.g. feline class.
# We don't have access to the feline class in this library, so import the binary code
# from another lib. 
# Note the cats_lib project shall generate a "feline_lib.lib" and "feline_lib.dll" files.
# That's the name of the dependency we need to use.
# Using the same name (E.g. see cats_domestic_lib) makes it easier to handle.
TARGET_LINK_LIBRARIES(${PROJECT_NAME} 25_shared_lion_lib)
