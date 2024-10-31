#ifndef PAUSE_STATE_H
#define PAUSE_STATE_H

#include "game_state.h"

namespace Game {

    struct GameData;


    struct PauseState : GameState {

        PauseState();
        ~PauseState();

        void enter(GameData* game_data);
        void render(GameData* game_data);
        void update(GameData* game_data);
        void exit(GameData* game_data);

    };

};


#endif
