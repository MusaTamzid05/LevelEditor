#ifndef GRAVITY_FORCE_H
#define GRAVITY_FORCE_H

#include "force.h"
#include <raymath.h>

namespace Game {
    struct GravityForce : Force {
        GravityForce();
        virtual ~GravityForce();

        void update(GameObject* src_object);
        void apply(const Vector3& force);

        Vector3 velocity;
        Vector3 acceleration;


    };

}

#endif
