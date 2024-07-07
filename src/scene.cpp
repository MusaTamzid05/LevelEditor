#include "scene.h"
#include "camera.h"
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
        Game::Camera::get_instance()->init();

        for(Game::GameObject* game_object : game_objects)
            game_object->init();




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

    }
}
