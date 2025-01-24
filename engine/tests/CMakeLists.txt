include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(UNIT_TEST EngineTests)
add_custom_target(run_unit_test ALL
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS ${UNIT_TEST})

enable_testing()

add_executable(
  EngineTests
  vector.cc
)

target_link_libraries(
  EngineTests
  GTest::gtest_main
  Engine
)

include(GoogleTest)
gtest_discover_tests(EngineTests)
