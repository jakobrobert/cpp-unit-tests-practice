file(GLOB LIB_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
add_library(lib STATIC ${LIB_SOURCES})
target_include_directories(lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
