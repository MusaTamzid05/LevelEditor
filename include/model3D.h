#ifndef MODEL3D_H
#define MODEL3D_H

#include "game_object.h"
#include <raylib.h>

namespace Game {

    struct Model3D : GameObject {
        Model3D();
        virtual ~Model3D();

        void init();
        void render();
        void update();

        Vector3 position;
        Vector3 rotation;

        Model model;


    };


}

#endif
