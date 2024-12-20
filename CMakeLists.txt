cmake_minimum_required(VERSION 3.10)

# 设置项目名称和版本
project(webServer VERSION 1.0)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# 添加子目录
add_subdirectory(./src/mzone/)

