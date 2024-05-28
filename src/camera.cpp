#include "camera.h"

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

        position = (Vector3){0.0f, 10.0f, 10.0f};
        target = (Vector3){0.0f, 0.0f, 0.0f};
        up = (Vector3){0.0f, 1.0f, 0.0f};

        fovy = 45.0f;
        main_camera.projection = CAMERA_PERSPECTIVE;
    }

    void Camera::update() {
        main_camera.position = position;
        main_camera.target = position;
        main_camera.up = position;
        main_camera.fovy = fovy;
    }


}
