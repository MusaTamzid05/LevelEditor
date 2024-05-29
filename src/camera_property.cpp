#include "camera_property.h"
#include "camera.h"
#include "imgui.h"

namespace Editor {


    CameraProperty::CameraProperty() {

    }

    CameraProperty::~CameraProperty() {

    }

    void CameraProperty::init()  {
        WidgetObject::init();
        name = "Camera";
    }

    void CameraProperty::render() {
        ImGui::PushID(0);

            ImGui::Text("Position");
            ImGui::DragFloat3("##pos",
                    &Game::Camera::get_instance()->position.x
                    );

            ImGui::Text("Target");
            ImGui::DragFloat3("##target",
                    &Game::Camera::get_instance()->target.x
                    );

            ImGui::Text("Up");
            ImGui::DragFloat3("##up",
                    &Game::Camera::get_instance()->up.x
                    );


            ImGui::Text("FOV y");
            ImGui::DragFloat("##fovt",
                    &Game::Camera::get_instance()->fovy
                    );

        ImGui::PopID();



    }
    void CameraProperty::update() {

    }
}
