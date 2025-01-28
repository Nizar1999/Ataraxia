project(Engine)

set(SOURCES
src/logger.cpp
src/application.cpp
src/scene.cpp
src/actor.cpp
src/console_renderer.cpp
src/camera.cpp
src/input.cpp
src/input_handler.cpp
)

if(CMAKE_SYSTEM MATCHES Windows)
list(APPEND SOURCES
src/input_handler_windows.cpp
)
endif()

if(CMAKE_HOST_SYSTEM MATCHES Linux)
list(APPEND SOURCES
src/input_handler_linux.cpp
)
endif()

set(CMAKE_CXX_VISIBILITY_PRESET hidden)

add_library(Engine SHARED ${SOURCES})

target_include_directories(Engine PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_include_directories(Engine PUBLIC "${PROJECT_SOURCE_DIR}/src")
target_compile_definitions(Engine PRIVATE ENGINE)

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)

add_custom_command(TARGET Engine POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:Engine> ${CMAKE_BINARY_DIR}/bin/
)

set_target_properties(Engine PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)
