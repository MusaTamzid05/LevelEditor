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

    }

    void Cube::render() {
        DrawCube(
                position,
                2.0f,
                2.0f,
                2.0f,
                RED
                );


    }


    void Cube::update() {

    }

    std::string Cube::get_data() const {
        std::string data;
        data += "cube|" + std::to_string(position.x) + ",";
        data +=  std::to_string(position.y) + ",";
        data +=  std::to_string(position.z);

        return data;

    }

    void Cube::load(const std::vector<std::string>& data) {
        std::vector<std::string> position_data = Engine::split(data[1], ',');

        position.x =  std::stof(position_data[0]);
        position.y =  std::stof(position_data[1]);
        position.z =  std::stof(position_data[2]);

    }

};
