#include "view_object.h"
#include "imgui.h"
#include "rlImGui.h"

namespace Editor {
    ViewObject::ViewObject() {

    }

    ViewObject::~ViewObject() {

    }

    void ViewObject::init() {
        render_texture = LoadRenderTexture(
                GetScreenWidth(),
                GetScreenHeight()
                );

    }


    void ViewObject::render() {
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0,0));

            ImGui::SetNextWindowSizeConstraints(
                    ImVec2((float)GetScreenWidth() / 2.0f, (float)GetScreenHeight()),
                    ImVec2((float)GetScreenWidth(), (float)GetScreenHeight())
                    );

            if(ImGui::Begin("3D View", nullptr, ImGuiWindowFlags_NoScrollbar)) {
                rlImGuiImageRenderTextureFit(
                        &render_texture,
                        true
                        );

                ImGui::End();
            }

        ImGui::PopStyleVar();
        

    }
    void ViewObject::update() {

    }

    void ViewObject::activate() {
        BeginTextureMode(render_texture);

    }

    void ViewObject::deactivate() {
        EndTextureMode();

    }

}
