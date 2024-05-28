#ifndef LEVEL_EDITOR_H
#define LEVEL_EDITOR_H

#include "object.h"

namespace Editor {

    struct LevelEditor : Object {
        LevelEditor();
        virtual ~LevelEditor();

        void init();



        void render();
        void update();



    };

};

#endif
