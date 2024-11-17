#ifndef CUBE_PROPERTY_H
#define CUBE_PROPERTY_H

#include "widget_object.h"


namespace Game {
    struct Cube;
}

namespace Editor {

    struct CubeProperty : WidgetObject {
        CubeProperty(Game::Cube* Cube);
        virtual ~CubeProperty();

        void init();
        void render();
        void update();

        Game::Cube* cube;


    };

}


#endif
