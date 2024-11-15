#include "cube_property.h"
#include "cube.h"
#include "imgui.h"
#include <iostream>

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

            ImGui::SeparatorText("Transform");

            ImGui::Text("Position");
            ImGui::DragFloat3("##pos",
                    &cube->position.x
                    );


            ImGui::Text("Scale");
            ImGui::DragFloat3("##scale",
                    &cube->scale.x
                    );


            ImGui::Text("Color");
            ImGui::ColorEdit3(
                    "#color",
                    (float*)&cube->color
                    );


            ImGui::SeparatorText("-");

            if(ImGui::Button("Delete"))  {
                active = false;
                cube->active = false;
            }


        ImGui::PopID();


    }

    void CubeProperty::update() {

    }

}


