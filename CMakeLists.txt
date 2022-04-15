cmake_minimum_required(VERSION 3.0.0)

project(educad)

set(CMAKE_CXX_FLAGS "-Wall -Wpedantic -Wextra -lsfml-graphics -lsfml-window -lsfml-system")
add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(Utils)
add_subdirectory(Entity)

target_link_libraries(${PROJECT_NAME} LINK_PUBLIC Utils Entity sfml-graphics sfml-window sfml-system)