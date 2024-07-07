#include "cube.h"
#include <iostream>

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

};
