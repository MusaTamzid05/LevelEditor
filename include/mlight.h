#ifndef MLIGHT_H
#define MLIGHT_H

#include "cube.h"
#include "rlight.h"

namespace Game {
    struct MLight : Cube {
        MLight();
        virtual ~MLight();

        void render();
        void update();

        Shader shader;
        Light light;




    };
}



#endif
