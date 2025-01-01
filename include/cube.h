#ifndef CUBE_H
#define CUBE_H

#include "game_object.h"
#include <raylib.h>
#include <vector>

namespace Game {

    struct Cube : GameObject {
        Cube(const std::string& name="Cube");
        virtual ~Cube();

        void init();
        virtual void render();
        virtual void update();

        std::string get_data() const;
        void load(const std::vector<std::string>& data);

        Vector3 color;
        std::string save_name;
        bool gravity;


    };

}

#endif
