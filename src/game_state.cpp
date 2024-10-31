#include "game_state.h"
#include "game_object.h"
#include "game_data.h"

namespace Game {
    GameState::GameState() {
        type = NONE;
    }

    GameState::~GameState() {

    }

    void GameState::render(GameData* game_data) {
        for(Game::GameObject* game_object : game_data->game_objects)
            game_object->render();


    }


    void GameState::update(GameData* game_data) {
        for(Game::GameObject* game_object : game_data->game_objects)
            game_object->update();

    }

}

