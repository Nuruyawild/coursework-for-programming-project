cmake_minimum_required(VERSION 2.8)

project(restaurant)

set( CMAKE_BUILD_TYPE Debug)

set(CMAKE_C_FLAGS "-fdump-rtl-expand")


add_executable(restaurant book_management.c Count_Entries.c)


install(TARGETS restaurant RUNTIME DESTINATION bin)
