project(Demo)

set(SOURCES src/game.cpp)
add_executable(Demo ${SOURCES})

target_link_libraries(Demo Engine)

set_target_properties(Demo PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
