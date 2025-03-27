cmake_minimum_required(VERSION 3.27)
project(SnakeProject)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output)
file(COPY ${CMAKE_SOURCE_DIR}/static DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
link_directories(${CMAKE_SOURCE_DIR}/lib)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(snake src/Main.cpp src/Game.cpp ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/static/favicon.rc)
target_link_libraries(snake -static easyx winmm)
