#include "utils.hpp"

std::string read_file(std::string path)
{
    std::ifstream t(path);
    std::stringstream buffer;
    buffer << t.rdbuf();
    return buffer.str();
}

std::vector<std::string> split(std::string str, std::string delim)
{
    std::vector<std::string> result;
    while (str.find(delim) != std::string::npos) {
        size_t pos = str.find(delim);
        size_t len = str.size() - pos;
        std::string temp = str.substr(0, pos);
        result.emplace_back(temp);
        str = str.substr(pos+1, len);
    }
    if (str.size() > 0) result.emplace_back(str);
    return result;
}