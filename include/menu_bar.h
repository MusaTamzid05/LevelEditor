#ifndef MENU_BAR_H
#define MENU_BAR_H

#include "widget_object.h"

namespace Editor {
    struct MenuBar : WidgetObject {
        MenuBar();
        virtual ~MenuBar();


        void init();
        void render();
        void update();

        bool quit;
        bool play;

    };


};

#endif
