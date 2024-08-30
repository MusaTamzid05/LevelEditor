#ifndef SCENE_H
#define SCENE_H


#include "object.h"
#include <raylib.h>
#include <vector>
#include <string>

namespace Game {
    struct GameObject;
    struct Model3D;
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
        std::vector<Game::GameObject*> game_objects;

        Game::Model3D* player;

    };

}


#endif
