cmake_minimum_required(VERSION 3.10)
project(FyreFawkes)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(fyrefish ${SOURCES})

target_include_directories(fyrefish PRIVATE src)
