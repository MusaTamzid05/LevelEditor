#ifndef MODEL3D_PROPERTY_H
#define MODEL3D_PROPERTY_H

#include "widget_object.h"


namespace Game {
    struct Model3D;
}

namespace Editor {

    struct Model3DProperty : WidgetObject {

        Model3DProperty(Game::Model3D* model);
        virtual ~Model3DProperty();

        void init();
        void render();
        void update();

        Game::Model3D* model;

    };

}


#endif
