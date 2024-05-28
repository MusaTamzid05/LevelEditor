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

    }
    void Scene::update() {
        Game::Camera::get_instance()->update();

    }
}
