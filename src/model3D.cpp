#include "model3D.h"
#include <raymath.h>
#include <raylib.h>
#include <iostream>
#include "utils.h"

namespace Game {
    Model3D::Model3D() {

    }


    Model3D::~Model3D() {

    }

    void Model3D::init() {
        position = (Vector3) { 8.0f, 0.0f, 0.0f};
        rotation = {0};

        init_defaults();




    }


    void Model3D::render() {
        model.transform = MatrixRotateXYZ(
                (Vector3) {
                DEG2RAD * rotation.x,
                DEG2RAD * rotation.y,
                DEG2RAD * rotation.z
                }
                );

        DrawModel(model,
                position,
                1.0f,
                WHITE
                );

    }

    void Model3D::update() {
        anim_frame_count += 1;
        UpdateModelAnimation(model, animation[anim_index], anim_frame_count);
        
        if(anim_frame_count >= animation[anim_index].frameCount)
            anim_frame_count = 0;


        position.x += velocity.x * GetFrameTime();
        position.z += velocity.y * GetFrameTime();



    }


    std::string Model3D::get_data() const {
        std::string data;
        data += "model|" + std::to_string(position.x) + ",";
        data +=  std::to_string(position.y) + ",";
        data +=  std::to_string(position.z) + "|";
        data +=  std::to_string(rotation.x) + ",";
        data +=  std::to_string(rotation.y) + ",";
        data +=  std::to_string(rotation.z);

        return data;

    }

    void Model3D::load(const std::vector<std::string>& data) {
        std::vector<std::string> position_data = Engine::split(data[1], ',');

        position.x =  std::stof(position_data[0]);
        position.y =  std::stof(position_data[1]);
        position.z =  std::stof(position_data[2]);


        std::vector<std::string> rotation_data = Engine::split(data[2], ',');


        rotation.x =  std::stof(rotation_data[0]);
        rotation.y =  std::stof(rotation_data[1]);
        rotation.z =  std::stof(rotation_data[2]);

        init_defaults();




    }

    void Model3D::init_defaults() {
        model = LoadModel("../resources/anim3.glb");
        animation = LoadModelAnimations("../resources/anim3.glb", &anim_count);
        anim_frame_count = 0;
        anim_index = 0;

        velocity = (Vector2) { 0.0f, 0.0f};

    }

    void Model3D::next_animation() {
        anim_index = (anim_index + 1) % anim_count;

    }

    void Model3D::turn_left() {
        rotation.z = LEFT_DIRECTION;
    }

    void Model3D::turn_right() {
        rotation.z = RIGHT_DIRECTION;
    }


    void Model3D::turn_forward() {
        rotation.z = FORWARD_DIRECTION;
    }

    void Model3D::turn_backward() {
        rotation.z = BACKWARD_DIRECTION;
    }


    void Model3D::add_velocity(const Vector2& velocity) {
        this->velocity.x += velocity.x;
        this->velocity.y += velocity.y;
    }

    void Model3D::reset_velocity() {
        velocity = (Vector2) { 0.0f, 0.0f};
    }


}
