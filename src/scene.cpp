#include "scene.h"
#include "camera.h"
#include "model3D.h"
#include "consts.h"
#include "game_object.h"
#include "game_data.h"
#include "pause_state.h"
#include "state_machine.h"
#include <iostream>
#include "play_state.h"

namespace Editor {
    Scene::Scene() {
        game_data = new Game::GameData();
    }

    Scene::~Scene() {
        for(Game::GameObject* game_object : game_data->game_objects)
            delete game_object;

        delete game_data;

    }

    void Scene::init() {
        background_color = (Color){ 51, 77, 77, 255};

        for(Game::GameObject* game_object : game_data->game_objects)
            game_object->init();

        Game::StateMachine::get_instance()->change(
                new Game::PauseState(),
                game_data
                );
    }

    void Scene::load() {
        background_color = (Color){ 51, 77, 77, 255};

        Game::StateMachine::get_instance()->change(
                new Game::PauseState(),
                game_data
                );
    }

    void Scene::render() {
        ClearBackground(background_color);
        BeginMode3D(
                Game::Camera::get_instance()->get_camera()
                );
            Game::StateMachine::get_instance()->current_state->render(game_data);


        EndMode3D();



    }

    void Scene::update() {
        // @TODO: At delta time
        Game::StateMachine::get_instance()->current_state->update(game_data);

    }

    std::string Scene::get_data() const {
        std::string data = "";

        for(Game::GameObject* game_object : game_data->game_objects) 
            data += game_object->get_data() + "\n";

        return data;


    }
}







