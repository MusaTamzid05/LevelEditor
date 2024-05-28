#ifndef CAMERA_H
#define CAMERA_H

#include <raylib.h>

namespace Game {
    class Camera {

        public:

            virtual ~Camera();

            void init();
            void update();

            static Camera* get_instance();

        private:
            Camera();
            static Camera* instance;
            Camera3D main_camera;

            Vector3 position;
            Vector3 target;
            Vector3 up;
            float fovy;










    };

}

#endif
