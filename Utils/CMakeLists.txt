set(THIS_LIB_NAME Utils)

add_library(${THIS_LIB_NAME} ${THIS_LIB_NAME}.cpp)
target_include_directories(${THIS_LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})