#include "scene.h"
#include "camera.h"
#include "model3D.h"
#include "consts.h"
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

        if(IsKeyDown(KEY_A))  {
            player->turn_left();
            player->add_velocity((Vector2){0.0f, -PLAYER_SPEED});
        }

        if(IsKeyDown(KEY_D))  {
            player->turn_right();
            player->add_velocity((Vector2){0.0f, PLAYER_SPEED});
        }


        if(IsKeyDown(KEY_W))  {
            player->turn_forward();
            player->add_velocity((Vector2){PLAYER_SPEED , 0.0f});
        }


        if(IsKeyDown(KEY_S))  {
            player->turn_backward();
            player->add_velocity((Vector2){-PLAYER_SPEED , 0.0f});
        }

        bool key_release = IsKeyReleased(KEY_A) || 
             IsKeyReleased(KEY_D) ||
             IsKeyReleased(KEY_W) ||
             IsKeyReleased(KEY_S);


        if(key_release) 
            player->reset_velocity();




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







