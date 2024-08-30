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
#include <fstream>
#include "utils.h"


Level::Level() {


}


Level::~Level() {
    delete scene;
    delete editor;
    CloseWindow();

}


void Level::init() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, LEVEL_NAME.c_str());
    SetTargetFPS(60);




    editor = new Editor::LevelEditor();
    editor->property = new Editor::Property();
    editor->property->widget_objects.push_back(new Editor::CameraProperty());

    scene = new Editor::Scene();

    Game::Model3D* model = new Game::Model3D();
    editor->property->widget_objects.push_back(new Editor::Model3DProperty(model));
    scene->game_objects.push_back(model);
    scene->player = model;

    /*
    Game::Cube* cube = new Game::Cube();
    editor->property->widget_objects.push_back(new Editor::CubeProperty(cube));


    scene->game_objects.push_back(cube);
    */

    Game::Camera::get_instance()->init();
    editor->init();
    scene->init();




}

void Level::load() {

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, LEVEL_NAME.c_str());
    SetTargetFPS(60);
    std::vector<std::string> level_data = Engine::get_lines(LEVEL_NAME + ".level");

    editor = new Editor::LevelEditor();
    editor->property = new Editor::Property();
    scene = new Editor::Scene();


    for(std::string line : level_data) {
        std::vector<std::string> game_object_data = Engine::split(line, '|');

        if(game_object_data[0] == "camera") {
            Game::Camera::get_instance()->load(game_object_data);
            editor->property->widget_objects.push_back(new Editor::CameraProperty());

        }

        if(game_object_data[0] == "model") {
            Game::Model3D* model = new Game::Model3D();
            model->load(game_object_data);

            Editor::Model3DProperty* property = new Editor::Model3DProperty(model);
            property->init();

            editor->property->widget_objects.push_back(property);
            scene->game_objects.push_back(model);
            scene->player = model;
        }

        if(game_object_data[0] == "cube") {

            Game::Cube* cube = new Game::Cube();
            cube->load(game_object_data);

            Editor::CubeProperty* property = new Editor::CubeProperty(cube);
            property->init();

            editor->property->widget_objects.push_back(property);
            scene->game_objects.push_back(cube);
        }
    }

    editor->init();
    scene->load();
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

void Level::save() const {
    std::string data = Game::Camera::get_instance()->get_data() + "\n";
    data += scene->get_data();

    std::ofstream output(LEVEL_NAME + ".level");
    output << data;

    output.close();

}






