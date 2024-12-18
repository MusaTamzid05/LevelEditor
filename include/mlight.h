#ifndef MLIGHT_H
#define MLIGHT_H

#include "cube.h"

namespace Game {
    struct MLight : Cube {
        MLight();
        virtual ~MLight();

        void render();
        void update();




    };
}



#endif
