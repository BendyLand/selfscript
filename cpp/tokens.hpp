#pragma once

#include <string>
#include <vector>
#include <utility>
#include <unordered_map>
#include "utils.hpp"

enum class Name
{
    CP, MV, RM, MKDIR, CHECK_ENV, SET_ENV, UNSET_ENV, EXEC, PUTS, PROMPT,
    CONFIRM, IF, THEN, ELSE, END, COND, FOR, DO, LABEL, GOTO, DOWNLOAD, UPLOAD,
    VARIABLE, UNKNOWN,
};

Name str_to_name(std::string name);
std::string name_to_str(Name name);

class Token 
{
public:
    Name get_name() const;
    std::string get_name_str() const;
    std::vector<std::string> get_args() const;
    Token(std::string name, std::vector<std::string> args) :
        token(str_to_name(name), args)
    {}

private:
    std::pair<Name, std::vector<std::string>> token;
    void set_args(const std::vector<std::string>& args)
    {
        this->token.second = args;
    }
    void set_name(const std::string& name)
    {
        this->token.first = str_to_name(name);
    }
};

inline std::ostream& operator<<(std::ostream& os, Token token)
{
    std::cout << "\nName: " << token.get_name_str() << std::endl;
    std::cout <<   "Args: " << token.get_args() << std::endl;
    return os;
}
