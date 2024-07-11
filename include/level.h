#ifndef LEVEL_H
#define LEVEL_H

namespace Editor {
    struct LevelEditor;
    struct Scene;
};



struct Level {
    Level();
    virtual ~Level();

    void start();
    void update();
    void render();

    void save() const;

    Editor::LevelEditor* editor;
    Editor::Scene* scene;

};


#endif
