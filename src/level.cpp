#include "level.h"
#include "consts.h"
#include "level_editor.h"
#include "scene.h"
#include <iostream>
#include <raylib.h>


Level::Level() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Level Editor");
    SetTargetFPS(60);

    editor = new Editor::LevelEditor();
    editor->init();

    scene = new Editor::Scene();
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
