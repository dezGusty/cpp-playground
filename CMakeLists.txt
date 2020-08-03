# set minimum required cmake version 
cmake_minimum_required(VERSION 3.0)

# 
# Specify some user configurable options
# 
OPTION(BUILD_SAMPLES_1_5 "Build the first set of samples" ON)
OPTION(BUILD_SAMPLES_6_10 "Build the second set samples" ON)

PROJECT(cpp-playground)

IF (BUILD_SAMPLES_1_5)
    ADD_SUBDIRECTORY(01_hello_world)
    ADD_SUBDIRECTORY(02_odd_even)
    ADD_SUBDIRECTORY(03_armstrong)
    ADD_SUBDIRECTORY(04_display_book)
ENDIF ()

IF (BUILD_SAMPLES_6_10)
    ADD_SUBDIRECTORY(10_oop_func_args_book)
ENDIF ()
