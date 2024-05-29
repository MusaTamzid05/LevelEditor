#include "level.h"
#include "consts.h"
#include "level_editor.h"
#include "scene.h"
#include "cube.h"
#include "property.h"
#include "camera_property.h"
#include "cube_property.h"
#include <iostream>
#include <raylib.h>


Level::Level() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Level Editor");
    SetTargetFPS(60);




    editor = new Editor::LevelEditor();
    editor->property = new Editor::Property();
    editor->property->widget_objects.push_back(new Editor::CameraProperty());

    scene = new Editor::Scene();

    Game::Cube* cube = new Game::Cube();
    editor->property->widget_objects.push_back(new Editor::CubeProperty(cube));


    scene->game_objects.push_back(cube);

    editor->init();
    scene->init();




}


Level::~Level() {
    delete scene;
    delete editor;
    CloseWindow();

}

void Level::start() {
    std::cout << "level start\n";

    while(!WindowShouldClose() && !editor->is_menu_closed()) {
        update();
        render();

    }

}

void Level::render() {
    BeginDrawing();

        ClearBackground(DARKGRAY);
        editor->render(scene);

    EndDrawing();
    

}


void Level::update() {
    scene->update();

}
