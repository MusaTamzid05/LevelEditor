#include <iostream>
#include "level.h"
#include "utils.h"
#include "consts.h"

int main(int argc, char** argv) {
    /*
    Level level;
    level.start();
    level.save();
    */

    for(std::string line : Engine::get_lines(LEVEL_NAME + ".level")) 
        std::cout << line << "\n";
    return 0;
}
