#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "object.h"
#include <string>
#include <raylib.h>

namespace Game {
    struct GameObject : Object{
        GameObject();
        ~GameObject();

        virtual std::string get_data() const;

        Vector3 position;
        Vector3 scale;

    };

};


#endif
