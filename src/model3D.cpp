#include "model3D.h"
#include <raymath.h>
#include <raylib.h>
#include <iostream>
#include "utils.h"
#include "game_data.h"
#include "collision.h"

namespace Game {
    Model3D::Model3D():GameObject("Model") {
        type = GameObject::MODEL;
        collider_scale = (Vector3) { 2.0f,  2.0f,  2.0f};
        collided = false;

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
                0.01f,
                WHITE
                );

        collider_position = position;
        collider_position.y += 1.5f;

        // @TODO: Fix the render of the wire cube
        

        if(!collided)
            DrawCubeWires(
                    collider_position,
                    collider_scale.x,
                    collider_scale.y,
                    collider_scale.z,
                    GREEN
                    );
        else
            DrawCubeWires(
                    collider_position,
                    collider_scale.x,
                    collider_scale.y,
                    collider_scale.z,
                    RED 
                    );


    }

    void Model3D::update() {
        anim_frame_count += 1;
        UpdateModelAnimation(model, animation[anim_index], anim_frame_count);
        
        if(anim_frame_count >= animation[anim_index].frameCount)
            anim_frame_count = 0;





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
        anim_index = IDLE;


    }

    void Model3D::next_animation() {
        anim_index = (anim_index + 1) % anim_count;

    }

    void Model3D::turn_left() {
        anim_index = RUN;
        rotation.z = LEFT_DIRECTION;
    }

    void Model3D::turn_right() {
        anim_index = RUN;
        rotation.z = RIGHT_DIRECTION;
    }


    void Model3D::turn_forward() {
        anim_index = RUN;
        rotation.z = FORWARD_DIRECTION;
    }

    void Model3D::turn_backward() {
        anim_index = RUN;
        rotation.z = BACKWARD_DIRECTION;
    }


    void Model3D::add_position(const Vector2& add_vector, const  GameData* game_data) {
        Vector3 temp_collider_pos = game_data->player->collider_position;

        temp_collider_pos.x  += add_vector.x * GetFrameTime();
        temp_collider_pos.z  += add_vector.y * GetFrameTime();

        collided = false;

        for(GameObject* game_object : game_data->game_objects) {
            if(game_object->type == GameObject::MODEL)
                continue;

            collided = Collsion::check_box_collision(
                    temp_collider_pos,
                    collider_scale,
                    game_object->position,
                    game_object->scale
                    );

            if(collided) 
                return;

        }


        position.x += add_vector.x * GetFrameTime();
        position.z += add_vector.y * GetFrameTime();
    }

    void Model3D::set_idle() {
        anim_index = IDLE;
    }


}
