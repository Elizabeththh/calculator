cmake_minimum_required(VERSION 3.5)

project(calculator)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(
    -Wall
    -pedantic
    -Wconversion
    -O3
)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/lib)

set(SOURCES
    ${SOURCE_DIR}/addition.cpp
    ${SOURCE_DIR}/calculation.cpp
    ${SOURCE_DIR}/calculator.cpp
    ${SOURCE_DIR}/division.cpp
    ${SOURCE_DIR}/multiplication.cpp
    ${SOURCE_DIR}/subtraction.cpp
    ${SOURCE_DIR}/helper.cpp
)

#  生成一个静态库 calculator_lib
add_library(calculator_lib STATIC ${SOURCES})
target_include_directories(calculator_lib PUBLIC ${INCLUDE_DIRECTORIES})

#  生成可执行文件 calculator（主程序）
add_executable(calculator ${SOURCE_DIR}/main.cpp)
target_link_libraries(calculator PRIVATE calculator_lib)

# ------------- 添加 Catch2 测试 -------------
enable_testing()  # 启用 CMake 测试功能

set(TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_calculator.cpp)

#  生成测试可执行文件 test_calculator
add_executable(test_calculator ${TEST_SOURCES})
target_include_directories(test_calculator PRIVATE ${INCLUDE_DIRECTORIES})
target_link_libraries(test_calculator PRIVATE calculator_lib) # 这里链接 calculator_lib

add_test(NAME CalculatorTests COMMAND test_calculator) # 添加测试命令
