#include "level_editor.h"
#include "rlImGui.h"
#include "widget_object.h"


namespace Editor {
    LevelEditor::LevelEditor() {

    }

    LevelEditor::~LevelEditor() {
        for(WidgetObject* widget_object : widget_objects)
            delete widget_object;

    }

    void LevelEditor::init() {
        rlImGuiSetup(true);

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

}
