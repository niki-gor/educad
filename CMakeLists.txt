cmake_minimum_required(VERSION 3.0.0)

project(educad)

add_executable(${PROJECT_NAME} main.cpp)

#set(GCC_COVERAGE_LINK_FLAGS "-lgcov")
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11")

add_subdirectory(RenderableEntity)
add_subdirectory(Utils)
add_subdirectory(Angem)
add_subdirectory(Entity)
add_subdirectory(Canvas)
add_subdirectory(render)
add_subdirectory(AngemWorker)
add_subdirectory(Controller)
add_subdirectory(UI)

target_include_directories(${PROJECT_NAME} PUBLIC ${CONTROLLER_INCLUDE_DIRS} ${UI_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PUBLIC ${CONTROLLER_LIBRARIES} ${UI_LIBRARIES})

#add_subdirectory(test)