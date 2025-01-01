#include "gravity_force.h"
#include "game_object.h"
#include "game_data.h"
#include "registry.h"
#include "collision.h"
#include <iostream>

namespace Game {
    GravityForce::GravityForce() {
        velocity = (Vector3) { 0.0f,  0.0f, 0.0f};
        acceleration = (Vector3) { 0.0f,  0.0f, 0.0f};

    }

    GravityForce::~GravityForce() {

    }

    void GravityForce::update(GameObject* src_object) {

        // v = u + a * t , t = 1 

        Vector3 position = src_object->position;

        Vector3 new_velocity = (Vector3){
            velocity.x + acceleration.x,
            velocity.y + acceleration.y,
            velocity.z + acceleration.z
        };

        acceleration = (Vector3) { 0.0f, 0.0f, 0.0f};

        Vector3 new_position = (Vector3) {
            position.x + new_velocity.x,
            position.y + new_velocity.y,
            position.z + new_velocity.z
        };

        GameData* game_data = Registry::get_instance()->game_data;
        bool collided = false;

        for(GameObject* game_object : game_data->game_objects) {

            if(game_object->type != GameObject::CUBE)
                continue;

            if(game_object->name == src_object->name)
                continue;

            collided = Collsion::check_box_collision(
                    src_object->position,
                    src_object->scale,
                    game_object->position,
                    game_object->scale
                    );

            if(collided) 
                return;
        }

        velocity = new_velocity;
        src_object->position = new_position;

    }

    void GravityForce::apply(const Vector3& force) {
        acceleration = force;
    }
}
