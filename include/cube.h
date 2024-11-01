#ifndef CUBE_H
#define CUBE_H

#include "game_object.h"
#include <raylib.h>
#include <vector>

namespace Game {

    struct Cube : GameObject {
        Cube();
        virtual ~Cube();

        void init();
        void render();
        void update();

        std::string get_data() const;
        void load(const std::vector<std::string>& data);

        Vector3 position;
        Vector3 color;
        Vector3 scale;


    };

}

#endif
