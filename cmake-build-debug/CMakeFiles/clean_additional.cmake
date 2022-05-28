# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "Canvas\\CANVAS_autogen"
  "Canvas\\CMakeFiles\\CANVAS_autogen.dir\\AutogenUsed.txt"
  "Canvas\\CMakeFiles\\CANVAS_autogen.dir\\ParseCache.txt"
  "UI\\CMakeFiles\\UI_autogen.dir\\AutogenUsed.txt"
  "UI\\CMakeFiles\\UI_autogen.dir\\ParseCache.txt"
  "UI\\UI_autogen"
  )
endif()
