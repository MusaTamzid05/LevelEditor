#include "level.h"
#include "consts.h"
#include "level_editor.h"
#include "scene.h"
#include "cube.h"
#include "property.h"
#include "camera_property.h"
#include "cube_property.h"
#include "message.h"
#include "model3D.h"
#include "model3D_property.h"
#include "camera.h"
#include <iostream>
#include <raylib.h>


Level::Level() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Level Editor");
    SetTargetFPS(60);




    editor = new Editor::LevelEditor();
    editor->property = new Editor::Property();
    editor->property->widget_objects.push_back(new Editor::CameraProperty());

    scene = new Editor::Scene();

    Game::Model3D* model = new Game::Model3D();
    editor->property->widget_objects.push_back(new Editor::Model3DProperty(model));
    scene->game_objects.push_back(model);

    /*
    Game::Cube* cube = new Game::Cube();
    editor->property->widget_objects.push_back(new Editor::CubeProperty(cube));


    scene->game_objects.push_back(cube);
    */

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

    Game::Camera::get_instance()->update();

    if(editor->is_play())
        scene->update();

    while(!Game::Message::get_instance()->is_empty()) {
        Game::Message::Type message_type = Game::Message::get_instance()->pop();

        switch(message_type) {
            case Game::Message::Type::CREATE_CUBE:
                Game::Cube* cube = new Game::Cube();
                Editor::CubeProperty* property = new Editor::CubeProperty(cube);

                cube->init();
                property->init();

                scene->game_objects.push_back(cube);
                editor->property->widget_objects.push_back(property);


                break;
        }

    }
}






