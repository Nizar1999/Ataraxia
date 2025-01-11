project(Engine)
add_library(Engine src/main.cpp)
target_include_directories(Engine PUBLIC "${PROJECT_SOURCE_DIR}/include")
