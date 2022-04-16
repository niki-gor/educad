cmake_minimum_required(VERSION 3.0.0)

project(educad)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(TwoDEntity)
add_subdirectory(Utils)
add_subdirectory(Entity)
add_subdirectory(Angem)
add_subdirectory(render)
add_subdirectory(UI)


target_include_directories(${PROJECT_NAME} PUBLIC ${RENDER_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PUBLIC ${RENDER_LIBRARIES})

add_subdirectory(test)