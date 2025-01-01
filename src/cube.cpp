#include "cube.h"
#include <iostream>
#include "utils.h"
#include "mlight.h"
#include "registry.h"
#include "camera.h"

namespace Game {

    Cube::Cube(const std::string& name):GameObject(name),gravity(false) {
        save_name = "cube";
        type = GameObject::CUBE;

    }

    
    Cube::~Cube() {

    }


    void Cube::init() {
        position = (Vector3) {1.0f, 1.0f, 0.0f};
        color = (Vector3) {0.0f, 0.0f, 0.0f};
        scale = (Vector3) {2.0f, 2.0f, 2.0f};

    }

    void Cube::render() {

        Color cube_color;
        cube_color.r = color.x * 255.0f;
        cube_color.g = color.y * 255.0f;
        cube_color.b  = color.z * 255.0f;
        cube_color.a  = 255.0f;

        MLight* light = Registry::get_instance()->light;

        if(light == nullptr) {
            DrawCube(
                    position,
                    scale.x,
                    scale.y,
                    scale.z,
                    cube_color
                    );
            return;

        }

        Vector3 camera_pos = Camera::get_instance()->position;
        SetShaderValue(light->shader, light->shader.locs[SHADER_LOC_VECTOR_VIEW], &camera_pos, SHADER_UNIFORM_VEC3);

        BeginShaderMode(light->shader);
            DrawCube(
                    position,
                    scale.x,
                    scale.y,
                    scale.z,
                    cube_color
                    );
        EndShaderMode();





    }


    void Cube::update() {

        if(!gravity)
            return;
        gravity_force.apply((Vector3){ 0.0f, -0.1f, 0.0f});
        gravity_force.update(this);


    }

    std::string Cube::get_data() const {
        std::string data;
        data +=  save_name + "|" + std::to_string(position.x) + ",";
        data +=  std::to_string(position.y) + ",";
        data +=  std::to_string(position.z) + "|";


        data +=  std::to_string(color.x) + ",";
        data +=  std::to_string(color.y) + ",";
        data +=  std::to_string(color.z) + "|";


        data +=  std::to_string(scale.x) + ",";
        data +=  std::to_string(scale.y) + ",";
        data +=  std::to_string(scale.z) + "|";
        data +=  name;

        return data;

    }

    void Cube::load(const std::vector<std::string>& data) {
        std::vector<std::string> position_data = Engine::split(data[1], ',');

        position.x =  std::stof(position_data[0]);
        position.y =  std::stof(position_data[1]);
        position.z =  std::stof(position_data[2]);


        std::vector<std::string> color_data = Engine::split(data[2], ',');

        color.x =  std::stof(color_data[0]);
        color.y =  std::stof(color_data[1]);
        color.z =  std::stof(color_data[2]);


        std::vector<std::string> scale_data = Engine::split(data[3], ',');

        scale.x =  std::stof(scale_data[0]);
        scale.y =  std::stof(scale_data[1]);
        scale.z =  std::stof(scale_data[2]);

        name = data[4];




    }

};
