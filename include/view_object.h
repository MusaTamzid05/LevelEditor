#ifndef VIEW_OBJECT_H
#define VIEW_OBJECT_H

#include "widget_object.h"
#include <raylib.h>

namespace Editor {
    struct ViewObject : WidgetObject {
        ViewObject();
        virtual ~ViewObject();

        void init();
        void render();
        void update();

        void activate();
        void deactivate();

        RenderTexture render_texture;

    };


}


#endif
