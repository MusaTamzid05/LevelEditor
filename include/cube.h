#ifndef CUBE_H
#define CUBE_H

#include "game_object.h"
#include <raylib.h>

namespace Game {

    struct Cube : GameObject {
        Cube();
        virtual ~Cube();

        void init();
        void render();
        void update();

        Vector3 position;


    };

}

#endif
