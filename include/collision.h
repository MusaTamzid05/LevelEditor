#ifndef COLLSION_H
#define COLLSION_H

#include <raylib.h>

namespace Game {
    struct Collsion {
        static bool check_box_collision(
                const Vector3& pos1,
                const Vector3& scale1,
                const Vector3& pos2,
                const Vector3& scale2
                );

    };

}

#endif
