# 指定最低的CMake版本
cmake_minimum_required(VERSION 3.10)

# 设置当前项目名称
project(mzone)

# 设置源文件和头文件的变量
file(GLOB_RECURSE SOURCES "./*.cpp")  # 查找当前目录及其子目录下的所有 .cpp 文件
file(GLOB_RECURSE HEADERS "./*.h")      # 查找当前目录及其子目录下的所有 .h 文件

# 创建可执行文件
add_executable(zoneexe ${SOURCES} ${HEADERS})  # 将头文件也加入可执行文件

# 链接其他库（如果需要）
# target_link_libraries(zoneexe PRIVATE ${OTHER_LIBRARIES})  # 如果有其他依赖库，可以在这里链接
