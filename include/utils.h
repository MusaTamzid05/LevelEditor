#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

namespace Engine {
    std::vector<std::string> get_lines(const std::string& path);
    std::vector<std::string> split(const std::string& str, char target);
    bool file_exists(const std::string& path);
}

#endif
