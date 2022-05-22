cmake_minimum_required(VERSION 3.5)

project(UI VERSION 0.1 LANGUAGES CXX)

set(THIS_LIB_NAME UI)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

#set(QT_DIR "/mnt/c/Qt/6.2.4/mingw_64/lib/cmake/Qt6")
#set(Qt6_DIR "/mnt/c/Qt/6.2.4/mingw_64/lib/cmake/Qt6")
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_PREFIX_PATH "/mnt/c/Qt/6.2.4/mingw_64/lib/cmake")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(QT_VERSION_MAJOR 6)
#find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        canvas.h
        contextedit.h
        projectstructurelist.h
        guiobjects.h
        guistorage.h
        iguiobserver.h
        toolbar.h
        canvas.cpp
        toolbar.cpp
        contextedit.cpp
        projectstructurelist.cpp
        mainwindow.ui
)

#if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
#    qt_add_executable(educadui
#        MANUAL_FINALIZATION
#        ${PROJECT_SOURCES}
#    )
## Define target properties for Android with Qt 6 as:
##    set_property(TARGET educadui APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
##                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
## For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
#else()
#    if(ANDROID)
#        add_library(educadui SHARED
#            ${PROJECT_SOURCES}
#        )
## Define properties for Android with Qt 5 after find_package() calls as:
##    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    else()
#        add_executable(educadui
#            ${PROJECT_SOURCES}
#        )
#    endif()
#endif()

set(UI_LIBRARIES ${PROJECT_NAME} PARENT_SCOPE)
set(UI_DIRS ${INCLUDE_DIRS} PARENT_SCOPE)

add_library(${THIS_LIB_NAME}  ${PROJECT_SOURCES})

target_link_libraries(UI PRIVATE Qt${QT_VERSION_MAJOR}::Widgets ${ENTITY_LIBRARIES})
target_include_directories(${THIS_LIB_NAME} PUBLIC ${ENTITY_INCLUDE_DIRS})

set_target_properties(UI PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(UI)
endif()
