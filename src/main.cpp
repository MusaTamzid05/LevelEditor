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

    for(std::string word : Engine::split("data1|data2|data3", '|')) 
        std::cout << word << "\n";
    return 0;
}
