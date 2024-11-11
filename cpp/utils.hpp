#pragma once

#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>

std::string read_file(const std::string& path);
std::vector<std::string> split(std::string str, const std::string& delim);
bool contains(const std::string& haystack, const std::string& needle);
size_t count(std::string haystack, const std::string& needle);
std::string extract_string(const std::string& str);
std::vector<std::string> extract_multiple_strings(std::string str);
void trim_start(std::string& str);

template <typename T>
inline std::ostream& operator<<(std::ostream& os, std::vector<T> vec)
{
    size_t size = vec.size();
    for (size_t i = 0; i < size; i++) {
        std::cout << vec[i]; 
        if (i < size-1) std::cout << ", ";
    }
    return os;
}

template <typename T>
inline bool contains(std::vector<T> haystack, T needle)
{
    for (T item : haystack) {
        if (item == needle) return true;
    }
    return false;
}

template <typename T>
inline std::vector<T> dedup(std::vector<T> vec)
{
    std::vector<T> result;
    result.reserve(vec.size());
    for (T item : vec) {
        if (contains(result, item)) continue;
        result.emplace_back(item);
    }
    return result;
}