#include "level_editor.h"
#include "rlImGui.h"


namespace Editor {
    LevelEditor::LevelEditor() {

    }

    LevelEditor::~LevelEditor() {

    }

    void LevelEditor::init() {
        rlImGuiSetup(true);
    }

    void LevelEditor::render() {
        rlImGuiBegin();
            // render editor code
        rlImGuiEnd();
    }


    void LevelEditor::update() {
    }

}
