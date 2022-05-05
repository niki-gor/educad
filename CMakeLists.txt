cmake_minimum_required(VERSION 3.0.0)

project(educad)

set(CMAKE_CXX_FLAGS "-std=c++2a -Wall -Wpedantic -Wextra -lsfml-graphics -lsfml-window -lsfml-system")
add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(angem)
add_subdirectory(hash)
add_subdirectory(line)
add_subdirectory(point)
add_subdirectory(utility)
add_subdirectory(vec2)
add_subdirectory(vec3)

target_link_libraries(${PROJECT_NAME} LINK_PUBLIC angem hash line point utility vec2 vec3 sfml-graphics sfml-window sfml-system)