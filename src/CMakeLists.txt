set(icon ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/static/favicon.rc)
add_executable(snake Main.cpp Game.cpp Snake.cpp ${icon})
target_link_libraries(snake easyx winmm)
add_custom_command(TARGET snake POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/lib/libeasyx.a ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/lib/libwinmm.a ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/static ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)
