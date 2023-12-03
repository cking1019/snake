cmake_minimum_required(VERSION 3.27)

project(snake)

# 将静态资源复制到构建目录
file(COPY ${CMAKE_SOURCE_DIR}/static DESTINATION ${CMAKE_BINARY_DIR})

# 头文件的路径
include_directories(
    ${PROJECT_SOURCE_DIR}/include 
    ${PROJECT_SOURCE_DIR}/include/easyx 
    ${PROJECT_SOURCE_DIR}/include/snake
)

# 设置可执行文件的输出目录
# set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# 设置程序图标
set(icon ${CMAKE_BINARY_DIR}/static/favicon.rc)

# 所有源文件
file(GLOB SRC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/snake/*.cpp)

# 库文件的路径
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)

# 生成可执行文件
add_executable(${PROJECT_NAME} ${SRC} ${icon})
target_link_libraries(${PROJECT_NAME} easyx winmm)
