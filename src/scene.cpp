#include "scene.h"
#include "camera.h"
#include "model3D.h"
#include "game_object.h"
#include <iostream>

namespace Editor {
    Scene::Scene() {

    }

    Scene::~Scene() {
        for(Game::GameObject* game_object : game_objects)
            delete game_object;

    }

    void Scene::init() {
        background_color = (Color){ 51, 77, 77, 255};

        for(Game::GameObject* game_object : game_objects)
            game_object->init();
    }

    void Scene::load() {
        background_color = (Color){ 51, 77, 77, 255};
    }

    void Scene::render() {
        ClearBackground(background_color);
        BeginMode3D(
                Game::Camera::get_instance()->get_camera()
                );

                for(Game::GameObject* game_object : game_objects)
                    game_object->render();

            // render code

        EndMode3D();



    }

    void Scene::update() {

        if(IsKeyPressed(KEY_P)) 
            player->next_animation();


        for(Game::GameObject* game_object : game_objects)
            game_object->update();

    }

    std::string Scene::get_data() const {
        std::string data = "";

        for(Game::GameObject* game_object : game_objects) 
            data += game_object->get_data() + "\n";

        return data;


    }
}







