#include "collision.h"

namespace Game {

    bool Collsion::check_box_collision(
            const Vector3& pos1,
            const Vector3& scale1,
            const Vector3& pos2,
            const Vector3& scale2
            ) {

        BoundingBox box1;

        box1.min = (Vector3) {
            pos1.x - scale1.x / 2.0f,
            pos1.y - scale1.y / 2.0f,
            pos1.z - scale1.z / 2.0f

        };

        box1.max= (Vector3) {
            pos1.x + scale1.x / 2.0f,
            pos1.y + scale1.y / 2.0f,
            pos1.z + scale1.z / 2.0f,

        };

        BoundingBox box2;

        box2.min = (Vector3) {
            pos2.x - scale2.x / 2.0f,
            pos2.y - scale2.y / 2.0f,
            pos2.z - scale2.z / 2.0f

        };

        box2.max= (Vector3) {
            pos2.x + scale2.x / 2.0f,
            pos2.y + scale2.y / 2.0f,
            pos2.z + scale2.z / 2.0f,

        };

        return CheckCollisionBoxes(box1, box2);



    }

}
