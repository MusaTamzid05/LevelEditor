#ifndef LEVEL_H
#define LEVEL_H

namespace Editor {
    struct LevelEditor;
    struct Scene;
};



struct Level {
    Level();
    virtual ~Level();

    void init();
    void load();
    void start();
    void update();
    void render();

    void remove_inactive_objects();

    void save() const;

    Editor::LevelEditor* editor;
    Editor::Scene* scene;

};


#endif
