#include "camera.h"
#include <math.h>
#include "utils.h"

namespace Game {
    Camera* Camera::instance = nullptr;


    Camera::Camera() {

    }

    Camera::~Camera() {

    }


    Camera* Camera::get_instance() {
        if(instance == nullptr) 
            instance = new Camera();

        return instance;
    }


    void Camera::init() {

        position = (Vector3){-6.0f, 1.0f, 0.0f};
        rotation = {0};
        up = (Vector3){0.0f, 1.0f, 0.0f};

        init_defaults();


    }

    void Camera::update() {

        main_camera.target.x = position.x + cosf(rotation.x * DEG2RAD) * cosf(rotation.y * DEG2RAD);
        main_camera.target.y = position.y + sinf(rotation.y * DEG2RAD);
        main_camera.target.z = position.z + sinf(rotation.x * DEG2RAD) * cosf(rotation.y * DEG2RAD);
        main_camera.position = position;



    }


    Camera3D Camera::get_camera() const {
        return main_camera;

    }


    std::string Camera::get_data() const {
        std::string data;
        data += "camera|" + std::to_string(position.x) + ",";
        data +=  std::to_string(position.y) + ",";
        data +=  std::to_string(position.z) + "|";
        data +=  std::to_string(rotation.x) + ",";
        data +=  std::to_string(rotation.y) + ",";
        data +=  std::to_string(rotation.z);

        return data;

    }


    void Camera::load(const std::vector<std::string>& data) {
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

    void Camera::init_defaults() {
        up = (Vector3){0.0f, 1.0f, 0.0f};

        fovy = 60.0f;
        main_camera.projection = CAMERA_PERSPECTIVE;

        main_camera.position = position;
        main_camera.up = up;
        main_camera.fovy = fovy;

    }


}

