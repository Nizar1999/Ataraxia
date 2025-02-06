cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_COMPILE_WARNING_AS_ERROR ON)

project(Ataraxia)

add_subdirectory(engine)
add_subdirectory(engine/tests)
add_subdirectory(demo)
