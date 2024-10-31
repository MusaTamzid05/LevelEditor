#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include "game_state.h"

namespace Game {

    struct GameData;


    struct PlayState : GameState {

        PlayState();
        ~PlayState();

        void enter(GameData* game_data);
        void render(GameData* game_data);
        void update(GameData* game_data);
        void exit(GameData* game_data);



    };

};


#endif
