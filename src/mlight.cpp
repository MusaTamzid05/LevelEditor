#include "mlight.h"


namespace Game {
    MLight::MLight():Cube("MLight") {
        save_name = "light";

    }

    MLight::~MLight() {

    }

    void MLight::render() {
        DrawCube(
                position,
                scale.x,
                scale.y,
                scale.z,
                WHITE
                );


    }


    void MLight::update() {

    }
}
