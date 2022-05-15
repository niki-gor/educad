cmake_minimum_required(VERSION 3.0.0)

project(educad)

set(CMAKE_CXX_FLAGS "-std=c++2a -Wall -Wpedantic -Wextra -lsfml-graphics -lsfml-window -lsfml-system")
add_executable(${PROJECT_NAME} main.cpp)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

add_subdirectory(angem)
add_subdirectory(entity2d)
add_subdirectory(line2d)
add_subdirectory(line2d_base)
add_subdirectory(point2d)
add_subdirectory(point2d_base)
add_subdirectory(polyset)
add_subdirectory(utils)

target_link_libraries(${PROJECT_NAME} PUBLIC angem entity2d line2d line2d_base point2d point2d_base polyset utils 
Eigen3::Eigen
sfml-graphics sfml-window sfml-system)