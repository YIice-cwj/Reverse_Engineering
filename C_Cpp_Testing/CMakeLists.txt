# 设置 CMake 的最低版本要求
cmake_minimum_required(VERSION 3.10)

# 项目名称和版本
project(ReverseEngineering VERSION 1.0 LANGUAGES C)

# 设置头文件路径（如果有）
include_directories(${PROJECT_SOURCE_DIR}/include)

# 设置源文件路径
set(SOURCES
    src/main.c
)

# 设置测试代码路径
set(TEST_SOURCES
    tests/test01_main.c
)

# 添加主程序的可执行文件
add_executable(ReverseEngineering ${SOURCES})

# 添加测试程序的可执行文件
add_executable(test01 ${TEST_SOURCES})

# 设置输出目录
set_target_properties(ReverseEngineering PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set_target_properties(test01 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})