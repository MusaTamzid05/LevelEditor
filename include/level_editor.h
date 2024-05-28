#ifndef LEVEL_EDITOR_H
#define LEVEL_EDITOR_H

#include <vector>

namespace Editor {
    struct WidgetObject;
    struct MenuBar;
    struct Scene;
    struct Editor;
    struct ViewObject;

    struct LevelEditor {
        LevelEditor();
        virtual ~LevelEditor();

        void init();



        void render(Scene* scene);
        void update();

        bool is_menu_closed() const;

        std::vector<WidgetObject*> widget_objects;

        MenuBar* menu_bar;
        Scene* scene;
        ViewObject* view ;




    };

};

#endif
