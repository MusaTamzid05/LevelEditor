#include "registry.h"
#include "mlight.h"

namespace Game {
    Registry* Registry::instance = nullptr;

    Registry::Registry():cube_count(0), light(nullptr) {
    }


    Registry* Registry::get_instance() {
        if(instance == nullptr)
            instance = new Registry();

        return instance;

    }

}
