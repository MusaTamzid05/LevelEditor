#ifndef CAMERA_H
#define CAMERA_H

#include <raylib.h>
#include <string>
#include <vector>

namespace Game {
    class Camera {

        public:

            virtual ~Camera();

            void init();
            void update();

            static Camera* get_instance();
            Camera3D get_camera() const;

            std::string get_data() const;
            void load(const std::vector<std::string>& data);

            void init_defaults();


            void init_camera_offset(const Vector3& player_pos);
            bool did_player_move(const Vector3& player_pos) const;
            void follow(const Vector3& player_pos);

            Vector3 position;
            //Vector3 target;
            Vector3 up;
            float fovy;


            Vector3 rotation;


            // For following
            //
            Vector3 offset;
            Vector3 last_player_pos;


        private:
            Camera();
            static Camera* instance;
            Camera3D main_camera;











    };

}

#endif
