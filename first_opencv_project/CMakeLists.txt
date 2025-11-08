cmake_minimum_required(VERSION 3.22)

project(test)
# 告诉 CMake 自动查找系统中安装的 OpenCV 库
find_package(OpenCV REQUIRED)
# 将 OpenCV 头文件的目录添加到项目的 include 路径中，确保代码中 #include <opencv2/...> 能正确找到头文件
include_directories(${OpenCV_INCLUDE_DIRS})

# 打印
message(STATUS "OpenCV 版本: ${OpenCV_VERSION}")
message(STATUS "OpenCV 头文件路径: ${OpenCV_INCLUDE_DIRS}")
message(STATUS "OpenCV 库文件: ${OpenCV_LIBS}")

add_executable(test first.cpp)
# 链接 OpenCV 库
target_link_libraries(test ${OpenCV_LIBS})

