#include "level_editor.h"
#include "rlImGui.h"
#include "widget_object.h"
#include "menu_bar.h"


namespace Editor {
    LevelEditor::LevelEditor() {

    }

    LevelEditor::~LevelEditor() {
        for(WidgetObject* widget_object : widget_objects)
            delete widget_object;

    }

    void LevelEditor::init() {
        rlImGuiSetup(true);

        menu_bar = new MenuBar();;
        widget_objects.push_back(menu_bar);


        for(WidgetObject* widget_object : widget_objects)
            widget_object->init();
    }

    void LevelEditor::render() {
        rlImGuiBegin();
            for(WidgetObject* widget_object : widget_objects)
                widget_object->render();
        rlImGuiEnd();
    }


    void LevelEditor::update() {
    }

    bool LevelEditor::is_menu_closed() const {
        return menu_bar->quit;
    }

}
