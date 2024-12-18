#include "mlight.h"
#include <raymath.h>

#define RLIGHTS_IMPLEMENTATION
#include "rlight.h"


namespace Game {
    MLight::MLight():Cube("MLight") {
        save_name = "light";
        shader = LoadShader("../shaders/lighting.vs", "../shaders/lighting.fs");
        shader.locs[SHADER_LOC_VECTOR_VIEW] = GetShaderLocation(shader, "viewPos");

        int ambient_loc = GetShaderLocation(shader, "ambient");
        float ambient_val[4] = { 0.1f,  0.1f,  0.1f,  0.1f };
        SetShaderValue(shader, ambient_loc, ambient_val, SHADER_UNIFORM_VEC4);

        light = CreateLight(LIGHT_POINT, position, Vector3Zero(), YELLOW, shader);

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
        light.position = position;
        UpdateLightValues(shader, light);

    }
}
