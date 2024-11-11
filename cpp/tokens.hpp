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
    UNKNOWN,
};

class Token 
{
public:
    Name get_name() const;
    std::string get_name_str() const;
    std::vector<std::string> get_args() const;
    Token(std::string name, std::vector<std::string> args) :
        token(str_to_name(name), args)
    {}
    std::string name_to_str(Name name) const
    {
        std::string result;
        switch (name) {
            case Name::CP:         result = "cp";        break;
            case Name::MV:         result = "mv";        break;
            case Name::RM:         result = "rm";        break;
            case Name::MKDIR:      result = "mkdir";     break;
            case Name::CHECK_ENV:  result = "check_env"; break;
            case Name::SET_ENV:    result = "set_env";   break;
            case Name::UNSET_ENV:  result = "unset_env"; break;
            case Name::EXEC:       result = "exec";      break;
            case Name::PUTS:       result = "puts";      break;
            case Name::PROMPT:     result = "prompt";    break;
            case Name::CONFIRM:    result = "confirm";   break;
            case Name::IF:         result = "if";        break;
            case Name::THEN:       result = "then";      break;
            case Name::ELSE:       result = "else";      break;
            case Name::END:        result = "end";       break;
            case Name::COND:       result = "cond";      break;
            case Name::FOR:        result = "for";       break;
            case Name::DO:         result = "do";        break;
            case Name::LABEL:      result = "label";     break;
            case Name::GOTO:       result = "goto";      break;
            case Name::DOWNLOAD:   result = "download";  break;
            case Name::UPLOAD:     result = "upload";    break;
            case Name::UNKNOWN:    result = "unknown";   break;
            default:               result = "ERROR";     break;
        }
        return result;
    }

private:
    std::pair<Name, std::vector<std::string>> token;
    Name str_to_name(std::string name)
    {
        static const std::unordered_map<std::string, Name> name_map = {
            {"cp", Name::CP}, {"mv", Name::MV}, {"rm", Name::RM}, 
            {"mkdir", Name::MKDIR}, {"check_env", Name::CHECK_ENV}, 
            {"set_env", Name::SET_ENV}, {"unset_env", Name::UNSET_ENV}, 
            {"exec", Name::EXEC}, {"puts", Name::PUTS}, {"prompt", Name::PROMPT}, 
            {"confirm", Name::CONFIRM}, {"if", Name::IF}, {"then", Name::THEN}, 
            {"else", Name::ELSE}, {"end", Name::END}, {"cond", Name::COND}, 
            {"for", Name::FOR}, {"do", Name::DO}, {"label", Name::LABEL}, 
            {"goto", Name::GOTO}, {"download", Name::DOWNLOAD}, 
            {"upload", Name::UPLOAD}
        };
        auto it = name_map.find(name);
        return it != name_map.end() ? it->second : Name::UNKNOWN;
    }
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
