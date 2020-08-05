# set minimum required cmake version 
cmake_minimum_required(VERSION 3.0)

# 
# Specify some user configurable options
# 
OPTION(BUILD_SAMPLES_1_5 "Build the first set of samples" ON)
OPTION(BUILD_SAMPLES_6_9 "Build the second set of samples" ON)
OPTION(BUILD_SAMPLES_10_14 "Build the third set of samples" ON)
OPTION(BUILD_SAMPLES_EXTERNAL_DEPS "Build the external lib samples" OFF)

PROJECT(cpp-playground)

IF (BUILD_SAMPLES_1_5)
    ADD_SUBDIRECTORY(01_hello_world)
    ADD_SUBDIRECTORY(02_odd_even)
    ADD_SUBDIRECTORY(03_armstrong)
    ADD_SUBDIRECTORY(04_display_book)
ENDIF ()

IF (BUILD_SAMPLES_6_9)
    ADD_SUBDIRECTORY(06_read_file)
    ADD_SUBDIRECTORY(07_matrix_to_console)
    ADD_SUBDIRECTORY(08_lib_ini_read_book)
ENDIF ()
    
IF (BUILD_SAMPLES_10_14)
    ADD_SUBDIRECTORY(10_oop_func_args_book)
    ADD_SUBDIRECTORY(11_oop_book_auth)
ENDIF ()
