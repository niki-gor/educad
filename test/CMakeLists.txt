cmake_minimum_required(VERSION 3.14)
project(test)

set(CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)

add_executable(testRender testRender.cpp)

target_include_directories(testRender PUBLIC ${RENDER_INCLUDE_DIRS})
target_link_libraries(testRender PUBLIC ${RENDER_LIBRARIES} GTest::GTest GTest::Main)

add_executable(testAngem testAngem.cpp)
SET(CMAKE_CXX_FLAGS  ${CMAKE_CXX_FLAGS} "-fprofile-arcs -ftest-coverage -fPIC -O0")
target_include_directories(testAngem PUBLIC ${ANGEM_INCLUDE_DIRS} ${ENTITY_INCLUDE_DIRS} )
target_link_libraries(testAngem PUBLIC ${ANGEM_LIBRARIES} ${ENTITY_LIBRARIES} "-lgcov" GTest::GTest GTest::Main)