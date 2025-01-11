project(Demo)

set(SOURCES src/game.cpp)
add_executable(Demo ${SOURCES})

target_link_libraries(Demo Engine)
