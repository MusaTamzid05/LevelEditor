#ifndef LEVEL_EDITOR_H
#define LEVEL_EDITOR_H

#include "object.h"
#include <vector>

namespace Editor {
    struct WidgetObject;

    struct LevelEditor : Object {
        LevelEditor();
        virtual ~LevelEditor();

        void init();



        void render();
        void update();

        std::vector<WidgetObject*> widget_objects;



    };

};

#endif
