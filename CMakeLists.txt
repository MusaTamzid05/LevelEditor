cmake_minimum_required(VERSION 3.0)

project(game)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


SET(SOURCE_FILES
    src/imgui.cpp
    src/rlImGui.cpp
    src/imgui_demo.cpp
    src/imgui_draw.cpp
    src/imgui_tables.cpp
    src/imgui_widgets.cpp

    src/main.cpp
    src/level.cpp
    src/object.cpp
    src/level_editor.cpp
    src/widget_object.cpp
    src/menu_bar.cpp
    src/camera.cpp
    src/scene.cpp
    )



add_executable(game ${SOURCE_FILES})

include_directories(include)
target_link_libraries(game raylib GL dl)
