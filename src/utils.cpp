#include "utils.h"
#include <fstream>
#include <iostream>



namespace Engine {
    std::vector<std::string> get_lines(const std::string& path) {
        std::vector<std::string> lines;

        std::ifstream input(path);

        if(!input.is_open()) {
            std::cerr << path << "\n";
            return lines;
        }

        std::string line;

        while(std::getline(input, line)) 
            lines.push_back(line);


        return lines;

    }
}
