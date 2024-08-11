cmake_minimum_required(VERSION 3.27)

project(snake)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
set(CMAKE_BUILD_TYPE Debug)
# 将静态资源复制到构建目录, CMAKE_SOURCE_DIR指向工程顶层目录，CMAKE_BINARY_DIR指向编译输出层目录
file(COPY ${CMAKE_SOURCE_DIR}/static DESTINATION ${CMAKE_BINARY_DIR})

# 头文件的路径
include_directories(
    ${CMAKE_SOURCE_DIR}/include 
    ${CMAKE_SOURCE_DIR}/include/easyx 
    ${CMAKE_SOURCE_DIR}/include/snake
)

# 设置可执行文件的输出目录
# set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# 设置程序图标
set(icon ${CMAKE_BINARY_DIR}/static/favicon.rc)

# 所有源文件
# file(GLOB SRC 
#     ${CMAKE_SOURCE_DIR}/src/*.cpp
#     ${CMAKE_SOURCE_DIR}/src/snake/*.cpp)
aux_source_directory(src SRC)
aux_source_directory(src/snake SRC)

# 库文件的路径
link_directories(${CMAKE_SOURCE_DIR}/lib)

# 添加编译参数
add_compile_options(-std=c++11)

# 生成可执行文件
add_executable(${PROJECT_NAME} ${SRC} ${icon})
target_link_libraries(${PROJECT_NAME} easyx winmm)
