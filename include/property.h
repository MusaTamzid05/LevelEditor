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

        void remove_inactive_objects();

        std::vector<WidgetObject*> widget_objects;

    };

}

#endif
