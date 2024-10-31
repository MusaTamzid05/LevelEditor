#ifndef SCENE_H
#define SCENE_H


#include "object.h"
#include <raylib.h>
#include <string>

namespace Game {
    struct GameData;
    struct GameState;
}

namespace Editor {
    struct Scene : Object {
        Scene();
        virtual ~Scene();

        void init();
        void load();
        void render();
        void update();
        std::string get_data() const;

        Color background_color;
        Game::GameData* game_data;
        Game::GameState* pause_state;

    };

}


#endif
