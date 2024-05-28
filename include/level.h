#ifndef LEVEL_H
#define LEVEL_H

namespace Editor {
    struct LevelEditor;
};


struct Level {
    Level();
    virtual ~Level();

    void start();
    void update();
    void render();

    Editor::LevelEditor* editor;

};


#endif
