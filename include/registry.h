#ifndef REGISTRY_H
#define REGISTRY_H

#include <vector>

namespace Game {
    struct MLight;
    struct GameData;

    class Registry {
        public:
            int cube_count;
            static Registry* get_instance();

            MLight* light;
            GameData* game_data;

        private:
            Registry();
            static Registry* instance;


    };

}

#endif
