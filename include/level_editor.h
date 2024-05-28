#ifndef LEVEL_EDITOR_H
#define LEVEL_EDITOR_H

#include "object.h"
#include <vector>

namespace Editor {
    struct WidgetObject;
    struct MenuBar;

    struct LevelEditor : Object {
        LevelEditor();
        virtual ~LevelEditor();

        void init();



        void render();
        void update();

        bool is_menu_closed() const;

        std::vector<WidgetObject*> widget_objects;

        MenuBar* menu_bar;




    };

};

#endif
