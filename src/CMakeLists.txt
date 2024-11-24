set(icon ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/static/favicon.rc)
add_executable(snake Main.cpp Game.cpp Snake.cpp)
target_link_libraries(snake easyx winmm)