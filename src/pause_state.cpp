#include "pause_state.h"


namespace Game {
    PauseState::PauseState() {
        type = PAUSE;
    }

    PauseState::~PauseState() {

    }

    void PauseState::enter(GameData* game_data) {

    }

    void PauseState::render(GameData* game_data) {
        GameState::render(game_data);

    }


    void PauseState::update(GameData* game_data) {
    }



    void PauseState::exit(GameData* game_data) {

    }

}

