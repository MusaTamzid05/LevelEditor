#include "model3D_property.h"
#include "model3D.h"
#include "imgui.h"

namespace Editor {
    Model3DProperty::Model3DProperty(Game::Model3D* model):model(model) {

    }

    Model3DProperty::~Model3DProperty() {

    }

    void Model3DProperty::init() {
        name = "model";

    }

    void Model3DProperty::render() {

        ImGui::PushID(0);

            ImGui::Text("Position");
            ImGui::DragFloat3("##pos",
                    &model->position.x
                    );

            ImGui::Text("Rotation");
            ImGui::DragFloat3("##rot",
                    &model->rotation.x
                    );


        ImGui::PopID();

    }
    void Model3DProperty::update() {

    }
}





