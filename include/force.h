#ifndef FORCE_H
#define FORCE_H

#include <raylib.h>

namespace Game {
    struct GameObject;

    struct Force {
        virtual void update(GameObject* game_object) = 0;
        virtual void apply(const Vector3& force) = 0;

    };

}

#endif
