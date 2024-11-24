cmake_minimum_required(VERSION 3.27)
project(SnakeProject)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/output)
file(COPY ${CMAKE_SOURCE_DIR}/static DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
link_directories(${PROJECT_SOURCE_DIR}/lib)
add_subdirectory(src)

add_custom_target(SnakeProject ALL DEPENDS snake)