cmake_minimum_required(VERSION 3.18)
project(Entity)
set(THIS_LIB_NAME Entity)

add_library(${THIS_LIB_NAME} ${THIS_LIB_NAME}.cpp line.cpp)

set(ENTITY_LIBRARIES ${PROJECT_NAME} PARENT_SCOPE)
set(ENTITY_INCLUDE_DIRS ${INCLUDE_DIRS} PARENT_SCOPE)

target_include_directories(${THIS_LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${UTILS_INCLUDE_DIRS} ${ANGEM_INCLUDE_DIRS} ${TWO_D_ENTITY_INCLUDE_DIRS})
target_link_libraries(${THIS_LIB_NAME} LINK_PUBLIC Utils Angem TwoDEntity)

