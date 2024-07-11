#include <iostream>
#include "level.h"
#include "utils.h"
#include "consts.h"

int main(int argc, char** argv) {
    Level level;
    std::string level_path = LEVEL_NAME + ".level";

    if(Engine::file_exists(level_path)) {
        std::cout << "Loadng " << level_path << "\n";
        level.load();
    }
    else {
        std::cout << "Creating " << level_path << "\n";
        level.init();

    }

    level.start();
    level.save();
    
    return 0;
}
