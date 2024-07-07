#ifndef LEVEL_EDITOR_H
#define LEVEL_EDITOR_H

#include <vector>

namespace Editor {
    struct WidgetObject;
    struct MenuBar;
    struct Scene;
    struct Editor;
    struct ViewObject;
    struct Property;

    struct LevelEditor {
        LevelEditor();
        virtual ~LevelEditor();

        void init();



        void render(Scene* scene);
        void update();

        bool is_menu_closed() const;
        bool is_play() const;

        std::vector<WidgetObject*> widget_objects;

        MenuBar* menu_bar;
        Scene* scene;
        ViewObject* view ;
        Property* property ;




    };

};

#endif
