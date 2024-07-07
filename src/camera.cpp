#include "camera.h"
#include <math.h>

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

        fovy = 60.0f;
        main_camera.projection = CAMERA_PERSPECTIVE;

        main_camera.position = position;
        main_camera.up = up;
        main_camera.fovy = fovy;

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


}

