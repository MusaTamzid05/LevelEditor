#ifndef CAMERA_H
#define CAMERA_H

#include <raylib.h>
#include <string>

namespace Game {
    class Camera {

        public:

            virtual ~Camera();

            void init();
            void update();

            static Camera* get_instance();
            Camera3D get_camera() const;

            std::string get_data() const;

            Vector3 position;
            //Vector3 target;
            Vector3 up;
            float fovy;


            Vector3 rotation;

        private:
            Camera();
            static Camera* instance;
            Camera3D main_camera;











    };

}

#endif
