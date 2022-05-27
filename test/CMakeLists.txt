cmake_minimum_required(VERSION 3.0.0)
project(test)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS "-std=c++11")

find_package(GTest REQUIRED)

add_executable(testRender testRender.cpp)
add_executable(testController testController.cpp)

target_include_directories(testRender PUBLIC ${RENDER_INCLUDE_DIRS} )
target_link_libraries(testRender PUBLIC ${RENDER_LIBRARIES} GTest::GTest GTest::Main)

add_executable(testAngem testAngem.cpp)

#SET(CMAKE_CXX_FLAGS  ${CMAKE_CXX_FLAGS} "-fprofile-arcs -ftest-coverage -fPIC -O0")

add_executable(testProjection testProjection.cpp)

target_include_directories(testAngem PUBLIC ${ANGEM_INCLUDE_DIRS} ${ENTITY_INCLUDE_DIRS} )
target_link_libraries(testAngem PUBLIC ${ANGEM_LIBRARIES} ${ENTITY_LIBRARIES} "-lgcov" GTest::GTest GTest::Main)

target_include_directories(testController PUBLIC ${CONTROLLER_INCLUDE_DIRS})
target_link_libraries(testController PUBLIC ${CONTROLLER_LIBRARIES} GTest::GTest GTest::Main)

target_include_directories(testProjection PUBLIC ${ENTITY_INCLUDE_DIRS})
target_link_libraries(testProjection PUBLIC ${ENTITY_LIBRARIES} GTest::GTest GTest::Main)
