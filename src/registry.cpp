#include "registry.h"

namespace Game {
    Registry* Registry::instance = nullptr;

    Registry::Registry():cube_count(0) {
    }


    Registry* Registry::get_instance() {
        if(instance == nullptr)
            instance = new Registry();

        return instance;

    }

}
