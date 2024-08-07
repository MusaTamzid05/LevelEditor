#include "model3D.h"
#include <raymath.h>
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
        anime_frame_count += 1;
        UpdateModelAnimation(model, animation[0], anime_frame_count);
        
        if(anime_frame_count >= animation[0].frameCount)
            anime_frame_count = 0;



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
        model = LoadModel("../resources/timmy5.glb");
        animation = LoadModelAnimations("../resources/timmy5.glb", &anime_count);
        anime_frame_count = 0;

    }


}
