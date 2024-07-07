#include "model3D.h"
#include <raymath.h>

namespace Game {
    Model3D::Model3D() {

    }


    Model3D::~Model3D() {

    }

    void Model3D::init() {
        position = (Vector3) { 8.0f, 0.0f, 0.0f};
        rotation = {0};

        model = LoadModel("../resources/timmy5.glb");
        animation = LoadModelAnimations("../resources/timmy5.glb", &anime_count);
        anime_frame_count = 0;



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
        anime_frame_count += 1;
        UpdateModelAnimation(model, animation[0], anime_frame_count);
        
        if(anime_frame_count >= animation[0].frameCount)
            anime_frame_count = 0;



    }

}
