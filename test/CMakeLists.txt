cmake_minimum_required(VERSION 3.14)
project(test)

set(CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)

add_executable(testRender testRender.cpp)

target_include_directories(testRender PUBLIC ${RENDER_INCLUDE_DIRS})
target_link_libraries(testRender PUBLIC ${RENDER_LIBRARIES} GTest::GTest GTest::Main)
