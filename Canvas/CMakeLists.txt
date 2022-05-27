cmake_minimum_required(VERSION 3.5)

project(CANVAS VERSION 0.1 LANGUAGES CXX)

set(THIS_LIB_NAME CANVAS)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_PREFIX_PATH "C:/Qt/6.2.4/mingw_64/lib/cmake")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES *.cpp *.ui)
file(GLOB INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})

set(QT_VERSION_MAJOR 6)
find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

set(CANVAS_LIBRARIES ${PROJECT_NAME} PARENT_SCOPE)
set(CANVAS_INCLUDE_DIRS ${INCLUDE_DIRS} PARENT_SCOPE)

add_library(${THIS_LIB_NAME}  ${SOURCES} canvasMoveMouse.cpp canvasPaint.cpp canvasPressMouse.cpp)

target_link_libraries(CANVAS PUBLIC ${ENTITY_LIBRARIES} ${RENDERABLE_ENTITY_LIBRARIES} Qt6::Core Qt6::Gui Qt6::Widgets)
target_include_directories(CANVAS PUBLIC ${ENTITY_INCLUDE_DIRS} ${RENDERABLE_ENTITY_INCLUDE_DIRS})
#if(QT_VERSION_MAJOR EQUAL 6)
#    qt_finalize_executable(UI)
#endif()
