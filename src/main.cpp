#include <iostream>
#include "level.h"

int main(int argc, char** argv) {
    Level level;
    level.load();
    level.start();
    level.save();
    return 0;
}
