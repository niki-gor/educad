set(THIS_LIB_NAME point)

add_library(${THIS_LIB_NAME} ${THIS_LIB_NAME}.cpp)
target_include_directories(${THIS_LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${THIS_LIB_NAME} LINK_PUBLIC vec3)