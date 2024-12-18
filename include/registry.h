#ifndef REGISTRY_H
#define REGISTRY_H

namespace Game {
    struct MLight;

    class Registry {
        public:
            int cube_count;
            static Registry* get_instance();

            MLight* light;

        private:
            Registry();
            static Registry* instance;


    };

}

#endif
