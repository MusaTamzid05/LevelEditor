#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "object.h"
#include <string>

namespace Game {
    struct GameObject : Object{
        GameObject();
        ~GameObject();

        virtual std::string get_data() const;

    };

};


#endif
