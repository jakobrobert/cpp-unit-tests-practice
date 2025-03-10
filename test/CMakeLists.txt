add_executable(test main.cpp)

target_link_libraries(test PRIVATE lib)

# TODO Link google test library (can get it from github in CMake with FetchContent)
