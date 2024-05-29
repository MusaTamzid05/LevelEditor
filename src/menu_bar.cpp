#include "menu_bar.h"
#include "imgui.h"
#include "message.h"

namespace Editor {
    MenuBar::MenuBar() {

    }

    MenuBar::~MenuBar() {

    }

    void MenuBar::init() {
        WidgetObject::init();
        name = "Menu Bar";
        quit = false;

    }


    void MenuBar::render() {
        if(ImGui::BeginMainMenuBar())  {
            if(ImGui::BeginMenu("File")) {
                if(ImGui::MenuItem("Exit")) 
                    quit = true;

                ImGui::EndMenu();
            }

            if(ImGui::BeginMenu("Create")) {
                if(ImGui::MenuItem("Cube"))  {
                    Game::Message::get_instance()->push(Game::Message::Type::CREATE_CUBE);

                }

                ImGui::EndMenu();
            }

            ImGui::EndMainMenuBar();

        }

    }

    void MenuBar::update() {

    }

}



