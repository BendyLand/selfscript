#pragma once

#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>

std::string read_file(std::string path);
inline std::ostream& operator<<(std::ostream& os, std::vector<std::string> vec)
{
    size_t size = vec.size();
    for (size_t i = 0; i < size; i++) {
        std::cout << vec[i]; 
        if (i < size-1) std::cout << ", ";
    }
    return os;
}

