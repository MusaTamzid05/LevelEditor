#ifndef PROPERTY_H
#define PROPERTY_H

#include "widget_object.h"
#include <vector>

namespace Editor {
    struct Property : WidgetObject {
        Property();
        virtual ~Property();

        void init();
        void render();
        void update();

        std::vector<WidgetObject*> widget_objects;

    };

}

#endif
