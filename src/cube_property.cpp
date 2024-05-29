#include "cube_property.h"
#include "cube.h"
#include "imgui.h"

namespace Editor {


    CubeProperty::CubeProperty(Game::Cube* cube):cube(cube) {

    }

    CubeProperty::~CubeProperty() {

    }



    void CubeProperty::init() {
        name = "Cube";

    }
    void CubeProperty::render() {
        ImGui::PushID(0);

            ImGui::Text("Position");
            ImGui::DragFloat3("##pos",
                    &cube->position.x
                    );


        ImGui::PopID();


    }

    void CubeProperty::update() {

    }

}


