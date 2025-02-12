project(Engine)

set(SOURCES
src/logger.cpp
src/scene.cpp
src/scene_manager.cpp
src/actor.cpp
src/render_manager.cpp
src/camera.cpp
src/scene_parser.cpp
src/input_manager.cpp
src/input.cpp
src/console.cpp
src/frame_buffer.cpp
src/input_action.cpp
src/application.cpp
)

if(CMAKE_SYSTEM MATCHES Windows)
list(APPEND SOURCES
src/input_windows.cpp
)
endif()

if(CMAKE_HOST_SYSTEM MATCHES Linux)
list(APPEND SOURCES
src/input_linux.cpp
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
