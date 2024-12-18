#include "pause_state.h"
#include "mlight.h"
#include "registry.h"


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
        Registry::get_instance()->light->update();
    }



    void PauseState::exit(GameData* game_data) {

    }

}

