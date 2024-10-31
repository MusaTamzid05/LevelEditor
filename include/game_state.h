#ifndef GAME_STATE_H
#define GAME_STATE_H

namespace Game {

    struct GameData;

    enum State {
        NONE,
        PAUSE,
        PLAY
    };

    struct GameState {

        GameState();
        ~GameState();

        virtual void enter(GameData* game_data) = 0;
        virtual void render(GameData* game_data);
        virtual void update(GameData* game_data);
        virtual void exit(GameData* game_data) = 0;

        State type;


    };

};

#endif
