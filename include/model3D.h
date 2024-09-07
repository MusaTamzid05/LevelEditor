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

        void turn_left();
        void turn_right();
        void turn_forward();
        void turn_backward();

        void add_velocity(const Vector2& velocity);
        void reset_velocity();

        Vector3 position;
        Vector3 rotation;

        Model model;

        // animation

        int anim_count;
        int anim_frame_count;
        int anim_index;
        ModelAnimation* animation;

        const float LEFT_DIRECTION = 180.0f;
        const float RIGHT_DIRECTION = 0.0f;
        const float FORWARD_DIRECTION = 270.0f;
        const float BACKWARD_DIRECTION = 90.0f;

        Vector2 velocity;



    };


}

#endif
