#include "property.h"
#include "imgui.h"

namespace Editor {
    Property::Property() {

    }

    Property::~Property() {
        for(WidgetObject* widget_object : widget_objects)
            delete widget_object;

    }

    void Property::init() {

        for(WidgetObject* widget_object : widget_objects)
            widget_object->init();

    }

    void Property::render() {
        ImGui::SetNextWindowSize(
                ImVec2(430 , 450),
                ImGuiCond_FirstUseEver
                );

        if(!ImGui::Begin("Property", nullptr)) {
            ImGui::End();
            return;
        }

            ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(2, 2));

                if(ImGui::BeginTable("##split",
                            2,
                            ImGuiTableFlags_BordersOuter  |
                            ImGuiTableFlags_Resizable | 
                            ImGuiTableFlags_ScrollY
                            )) {

                    ImGui::TableSetupScrollFreeze(0, 1);
                    ImGui::TableSetupColumn("Objects");
                    ImGui::TableSetupColumn("Attributes");
                    ImGui::TableHeadersRow();

                    for(int obj_i = 0; obj_i < widget_objects.size(); obj_i += 1) {
                        ImGui::PushID(obj_i);

                            WidgetObject* widget_object = widget_objects[obj_i] ;

                            ImGui::TableNextRow();
                            ImGui::TableSetColumnIndex(0);
                            ImGui::AlignTextToFramePadding();
                            bool node_open = ImGui::TreeNode(widget_object->name.c_str());

                            ImGui::TableSetColumnIndex(1);
                            ImGui::SetNextItemWidth(-FLT_MIN);

                            if(node_open) {
                                widget_object->render();
                                ImGui::TreePop();
                            }

                        ImGui::PopID();

                    }


                    ImGui::EndTable();

                }

            ImGui::PopStyleVar();

        ImGui::End();

    }

    void Property::update() {

    }

}

