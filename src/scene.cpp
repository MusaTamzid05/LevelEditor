#include "scene.h"
#include "camera.h"

namespace Editor {
    Scene::Scene() {

    }

    Scene::~Scene() {

    }

    void Scene::init() {
        background_color = (Color){ 51, 77, 77, 255};
        Game::Camera::get_instance()->init();
        


    }

    void Scene::render() {
        ClearBackground(background_color);
        BeginMode3D(
                Game::Camera::get_instance()->get_camera()
                );

            // render code

        EndMode3D();



    }
    void Scene::update() {
        Game::Camera::get_instance()->update();

    }
}
