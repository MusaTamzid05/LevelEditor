#ifndef REGISTRY_H
#define REGISTRY_H

namespace Game {
    class Registry {
        public:
            int cube_count;
            static Registry* get_instance();

        private:
            Registry();
            static Registry* instance;


    };

}

#endif
