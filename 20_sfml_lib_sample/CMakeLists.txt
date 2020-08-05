# set minimum required cmake version 
cmake_minimum_required(VERSION 3.0)

# create variable containing project name
set(PROJECT_NAME "20_sfml_lib_sample")

# set project name
project(${PROJECT_NAME})
MESSAGE(STATUS "building ${PROJECT_NAME} ...")
ADD_DEFINITIONS(-DUNICODE -D_UNICODE)

SET(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake_modules/;${CMAKE_MODULE_PATH}")


set(CMAKE_CXX_STANDARD 11)

# specify the folder(s) where the compiler should look for include files
include_directories(include) #in our case the 'include' folder present in the root folder

# or we can use file(GLOB ...) for wildcard additon (add any file ending with '.h')
file(GLOB HEADER_FILES "include/*.h")

file(GLOB SRC_FILES "src/*.cpp")

find_package(SFML 2.5 REQUIRED graphics window system)

# specify where to generate the executable file
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin)

# specify that we are building an executable, and what sources to use 
add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SRC_FILES})

# MESSAGE(STATUS "***SFML_LIBRARIES ${SFML_LIBRARIES}")
# MESSAGE(STATUS "***SFML_DEPENDENCIES ${SFML_DEPENDENCIES}")
# MESSAGE(STATUS "sfml-graphics sfml-audio")
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)
# target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})