#ifndef MODEL3D_H
#define MODEL3D_H

#include "game_object.h"
#include <raylib.h>
#include <vector>

namespace Game {

    struct Model3D : GameObject {
        Model3D();
        virtual ~Model3D();

        void init();
        void render();
        void update();

        std::string get_data() const;
        void load(const std::vector<std::string>& data);

        void init_defaults();
        void next_animation();

        Vector3 position;
        Vector3 rotation;

        Model model;

        // animation

        int anim_count;
        int anim_frame_count;
        int anim_index;
        ModelAnimation* animation;



    };


}

#endif
