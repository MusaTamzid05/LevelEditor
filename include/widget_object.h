#ifndef WIDGET_OBJECT_H
#define WIDGET_OBJECT_H

#include "object.h"
#include <string>

namespace Editor {
    struct WidgetObject : Object {
        WidgetObject();
        virtual ~WidgetObject();

        void init();
        virtual void render() = 0;
        virtual void update() = 0;

        std::string name;


    };

}

#endif
