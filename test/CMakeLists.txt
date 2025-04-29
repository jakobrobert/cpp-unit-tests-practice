include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.16.0
)

FetchContent_MakeAvailable(googletest)

file(GLOB TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
add_executable(test ${TEST_SOURCES})
target_link_libraries(test PRIVATE gtest_main lib)

enable_testing()
include(GoogleTest)
gtest_discover_tests(test)
