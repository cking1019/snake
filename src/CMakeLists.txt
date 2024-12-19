add_executable(snake Main.cpp Game.cpp ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/static/favicon.rc)
target_link_libraries(snake easyx winmm)
