project(Engine)

set(SOURCES
src/application.cpp)

set(CMAKE_CXX_VISIBILITY_PRESET hidden)

add_library(Engine SHARED ${SOURCES})

target_include_directories(Engine PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_compile_definitions(Engine PRIVATE ENGINE)

add_custom_command(TARGET Engine POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:Engine> ${CMAKE_BINARY_DIR}/bin/
)

set_target_properties(Engine PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)
