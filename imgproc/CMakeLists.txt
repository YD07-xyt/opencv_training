cmake_minimum_required(VERSION 3.22)

project(test)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_LIBS})
message(STATUS "OpenCV 版本: ${OpenCV_VERSION}")
message(STATUS "OpenCV 头文件路径: ${OpenCV_INCLUDE_DIRS}")
message(STATUS "OpenCV 库文件: ${OpenCV_LIBS}")

add_executable(test test.cpp)

target_link_libraries(test ${OpenCV_LIBS})

add_executable(test01 imgproc_sum.cpp)

target_link_libraries(test01 ${OpenCV_LIBS})


add_executable(test02 hsv.cpp)

target_link_libraries(test02 ${OpenCV_LIBS})


add_executable(test03 hsv_one.cpp)

target_link_libraries(test03 ${OpenCV_LIBS})

