project(Demo)

set(SOURCES
src/game.cpp
src/player.cpp
)
add_executable(Demo ${SOURCES})

target_link_libraries(Demo Engine)
target_include_directories(Demo PRIVATE "${PROJECT_SOURCE_DIR}/src")

add_custom_command(TARGET Demo POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory ${PROJECT_SOURCE_DIR}/data/ ${CMAKE_BINARY_DIR}/bin/
)

set_target_properties(Demo PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
