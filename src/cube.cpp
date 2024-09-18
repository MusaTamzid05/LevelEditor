#include "cube.h"
#include <iostream>
#include "utils.h"

namespace Game {

    Cube::Cube() {

    }

    
    Cube::~Cube() {

    }


    void Cube::init() {
        position = (Vector3) {1.0f, 1.0f, 0.0f};
        color = (Vector3) {0.0f, 0.0f, 0.0f};

    }

    void Cube::render() {

        Color cube_color;
        cube_color.r = color.x * 255.0f;
        cube_color.g = color.y * 255.0f;
        cube_color.b  = color.z * 255.0f;
        cube_color.a  = 255.0f;

        DrawCube(
                position,
                2.0f,
                2.0f,
                2.0f,
                cube_color
                );


    }


    void Cube::update() {

    }

    std::string Cube::get_data() const {
        std::string data;
        data += "cube|" + std::to_string(position.x) + ",";
        data +=  std::to_string(position.y) + ",";
        data +=  std::to_string(position.z) + "|";


        data +=  std::to_string(color.x) + ",";
        data +=  std::to_string(color.y) + ",";
        data +=  std::to_string(color.z);

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




    }

};
