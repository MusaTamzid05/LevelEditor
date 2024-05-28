#include "level.h"
#include "consts.h"
#include "level_editor.h"
#include <iostream>
#include <raylib.h>


Level::Level() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Level Editor");
    SetTargetFPS(60);

    editor = new Editor::LevelEditor();
    editor->init();


}


Level::~Level() {
    delete editor;
    CloseWindow();

}

void Level::start() {
    std::cout << "level start\n";

    while(!WindowShouldClose()) {
        update();
        render();

    }

}

void Level::render() {
    BeginDrawing();
        editor->render();
    EndDrawing();
    

}


void Level::update() {

}
