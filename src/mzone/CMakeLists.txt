cmake_minimum_required(VERSION 3.10)
# 设置当前项目名称
project(mzone)

# 定义宏函数，用于查找指定目录下的含头文件
macro(FIND_INCLUDE_DIR result curdir)
    file(GLOB_RECURSE children "${curdir}/*.hpp" "${curdir}/*.h")  # 查找 .hpp 和 .h 文件
    message("Found headers: ${children}")                        # 输出找到的头文件
    set(dirlist "")                                              # 初始化目录列表

    foreach(child ${children})                                  # 遍历找到的文件
        string(REGEX REPLACE "(.*)/.*" "\\1" LIB_NAME ${child})  # 获取目录名
        if(IS_DIRECTORY ${LIB_NAME})                            # 判断是否为路径
            list(FIND dirlist ${LIB_NAME} list_index)         # 查找 dirlist 是否已有该路径
            if(${list_index} LESS 0)                           # 若未找到
                LIST(APPEND dirlist ${LIB_NAME})               # 将路径添加到 dirlist
            endif()                                            # 结束检查
        endif()
    endforeach()                                                 # 结束遍历
    set(${result} ${dirlist})                                  # 将结果赋值给 result 变量
endmacro()

# 调用宏函数查找头文件路径
FIND_INCLUDE_DIR(HEADER_DIRS "${PROJECT_SOURCE_DIR}")  # 指定需要查找的路径

# 查找源文件和头文件
file(GLOB_RECURSE SOURCES "**/*.cpp")  # 查找所有的 .cpp 文件
# 添加包含目录
include_directories(
    ${HEADER_DIRS}
    ${THIRED_PATH}/spdlog/include
    ${THIRED_PATH}/workflow/_include 
    ${THIRED_PATH}/nlohmann

)

# 创建可执行文件
add_executable(zoneexe ${SOURCES})  # 创建可执行文件，包含所有源文件

# 链接库
target_link_libraries(zoneexe -lpthread)
target_link_libraries(zoneexe ${THIRED_PATH}/spdlog/lib/libspdlog.a)
target_link_libraries(zoneexe ${THIRED_PATH}/workflow/_lib/libworkflow.so)
