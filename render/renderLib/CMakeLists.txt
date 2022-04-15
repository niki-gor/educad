cmake_minimum_required(VERSION 3.19)
project(render)

set(CMAKE_CXX_STANDARD 14)

add_library(render render.cpp render.h ProjectionPlane/ProjectionPlane.h ProjectionPlane/ProjectionPlane.cpp GUIObserver/GUIObserver.h TwoDObject/TwoDObject.h TwoDObject/TwoDPoint.h TwoDObject/TwoDPoint.cpp TwoDObject/TwoDLine.h TwoDObject/TwoDLine.cpp AngemEntity/AngemEntity.h)