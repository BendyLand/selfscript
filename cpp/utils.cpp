#include "utils.hpp"

std::string read_file(const std::string& path)
{
    std::ifstream t(path);
    std::stringstream buffer;
    buffer << t.rdbuf();
    return buffer.str();
}

std::vector<std::string> split(std::string str, const std::string& delim)
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

bool contains(const std::string& haystack, const std::string& needle)
{
    return haystack.find(needle) != std::string::npos;
}

size_t count(std::string haystack, const std::string& needle)
{
    size_t result = 0;
    while (haystack.find(needle) != std::string::npos) {
        result++;
        haystack.erase(haystack.find(needle), needle.size());
    }
    return result;
}

std::string extract_string(const std::string& str)
{
    size_t str_start = str.find("\"");
    size_t i = str_start+1;
    while (i < str.size()) {
        if (str[i] == '\"' && str[i-1] != '\\') break;
        i++;
    }
    return str.substr(str_start, i-str_start+1);
}

std::vector<std::string> extract_multiple_strings(std::string str)
{
    std::vector<std::string> result;
    size_t i = 0;
    while (true) {
        std::string temp = extract_string(str);
        result.emplace_back(temp);
        size_t first_quote = str.find("\"");
        size_t second_quote = str.find("\"", first_quote+1);
        str = str.substr(second_quote+1, str.size()-second_quote);
        i++;
        if (!contains(str, "\"")) break;
    }
    return result;
}

void trim_start(std::string& str)
{
    while (isspace(str[0])) {
        str.erase(str.begin());
    }
}