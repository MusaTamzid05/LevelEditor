#ifndef GAME_DATA_H
#define GAME_DATA_H

#include <vector>
#include "game_object.h"
#include "model3D.h"

namespace Game {

    struct GameData {
        std::vector<Game::GameObject*> game_objects;
        Game::Model3D* player;

        void remove_inactive_objects();
    };
}

#endif
