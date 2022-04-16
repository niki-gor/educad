cmake_minimum_required(VERSION 3.14)
project(test)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")

find_package(GTest REQUIRED)

add_executable(testRender testRender.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${RENDER_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE Render GTest::GTest GTest::Main)