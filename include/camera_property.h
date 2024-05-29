#ifndef CAMERA_PROPERTY_H
#define CAMERA_PROPERTY_H

#include "widget_object.h"

namespace Editor {
    struct CameraProperty : WidgetObject {
        CameraProperty();
        virtual ~CameraProperty();

        void init();
        void render();
        void update();


    };
}


#endif
