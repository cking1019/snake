cmake_minimum_required(VERSION 3.27)

project(snake)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
# 添加编译参数
add_compile_options(-std=c++11)

set(CMAKE_BUILD_TYPE Debug)
# 将静态资源复制到构建目录， CMAKE_SOURCE_DIR指向工程顶层目录，CMAKE_BINARY_DIR指向编译输出层目录
# PROJECT_SOURCE_DIR等价于CMAKE_SOURCE_DIR
file(COPY ${CMAKE_SOURCE_DIR}/static DESTINATION ${CMAKE_BINARY_DIR})

# CMAKE_SOURCE_DIR与PROJECT_SOURCE_DIR等价
# 添加头文件寻找路径， 默认是全局包含，即向下传递。
include_directories(
    ${CMAKE_SOURCE_DIR}/include 
    ${CMAKE_SOURCE_DIR}/include/easyx 
    ${CMAKE_SOURCE_DIR}/include/snake
)
# 与include_directories命令是同一个功能
# target_include_directories()

# 设置可执行文件的输出目录
# set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# 设置程序图标
set(icon ${CMAKE_BINARY_DIR}/static/favicon.rc)

# 添加源文件到SRC列表变量中
aux_source_directory(${CMAKE_SOURCE_DIR}/src SRC)
aux_source_directory(${CMAKE_SOURCE_DIR}/src/snake SRC)

# 添加库路径，必须在add_executable之前
link_directories(${CMAKE_SOURCE_DIR}/lib)
# 链接库，将库链接到稍后添加的所有目标，用于add_executable之前
# link_libraries(easyx winmm)
# 等价于link_libraries
# find_library()

# 设置库文件生成路径
# set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
# 生成动态库
# add_library(snake2 SHARED ${SRC})

# 生成可执行文件
add_executable(${PROJECT_NAME} ${SRC} ${icon})
# 链接库文件，默认优先链接动态库，也可以显式指定。用于add_executable之后
target_link_libraries(${PROJECT_NAME} PUBLIC easyx winmm)

# PUBLIC:在public之后的库会被链接到你的目标中，并且其中的符号也会被导出，提供第三方使用。
# PRIVATE: 仅被链接到你的目标，并且终结掉，第三方不能感知你调用的库。
# INTERFACE: 不会链接到你的目标，只会导出符号。