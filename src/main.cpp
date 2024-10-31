#include <iostream>
#include "level.h"
#include "utils.h"
#include "consts.h"

int main(int argc, char** argv) {
    Level level;

    if(Engine::file_exists(LEVEL_PATH)) {
        std::cout << "Loadng " << LEVEL_PATH << "\n";
        level.load();
    }
    else {
        std::cout << "Creating " << LEVEL_PATH << "\n";
        level.init();

    }

    level.start();
    level.save();
    
    return 0;
}
