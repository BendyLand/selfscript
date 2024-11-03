#pragma once

#include <string>
#include <vector>
#include <utility>
#include <unordered_map>

typedef enum 
{
    CP,
    MV,
    RM,
    MKDIR,
    CHECK_ENV,
    SET_ENV,
    UNSET_ENV,
    EXEC,
    PUTS,
    PROMPT,
    CONFIRM,
    IF,
    THEN,
    ELSE,
    END,
    COND,
    FOR,
    DO,
    LABEL,
    GOTO,
    DOWNLOAD,
    UPLOAD,
    UNKNOWN,
} Name;

class Token 
{
private:
    std::pair<Name, std::vector<std::string>> token;
    Name str_to_name(std::string name)
    {
        static const std::unordered_map<std::string, Name> name_map = {
            {"cp", CP}, {"mv", MV}, {"rm", RM}, {"mkdir", MKDIR},
            {"check_env", CHECK_ENV}, {"set_env", SET_ENV}, {"unset_env", UNSET_ENV},
            {"exec", EXEC}, {"puts", PUTS}, {"prompt", PROMPT},
            {"confirm", CONFIRM}, {"if", IF}, {"then", THEN}, {"else", ELSE},
            {"end", END}, {"cond", COND}, {"for", FOR}, {"do", DO},
            {"label", LABEL}, {"goto", GOTO}, {"download", DOWNLOAD},
            {"upload", UPLOAD}
        };
        auto it = name_map.find(name);
        return it != name_map.end() ? it->second : UNKNOWN;
    }
    void set_args(const std::vector<std::string>& args)
    {
        this->token.second = args;
    }
    void set_name(const std::string& name)
    {
        this->token.first = str_to_name(name);
    }

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
            case CP:         result = "cp";        break;
            case MV:         result = "mv";        break;
            case RM:         result = "rm";        break;
            case MKDIR:      result = "mkdir";     break;
            case CHECK_ENV:  result = "check_env"; break;
            case SET_ENV:    result = "set_env";   break;
            case UNSET_ENV:  result = "unset_env"; break;
            case EXEC:       result = "exec";      break;
            case PUTS:       result = "puts";      break;
            case PROMPT:     result = "prompt";    break;
            case CONFIRM:    result = "confirm";   break;
            case IF:         result = "if";        break;
            case THEN:       result = "then";      break;
            case ELSE:       result = "else";      break;
            case END:        result = "end";       break;
            case COND:       result = "cond";      break;
            case FOR:        result = "for";       break;
            case DO:         result = "do";        break;
            case LABEL:      result = "label";     break;
            case GOTO:       result = "goto";      break;
            case DOWNLOAD:   result = "download";  break;
            case UPLOAD:     result = "upload";    break;
            case UNKNOWN:    result = "unknown";   break;
            default:         result = "ERROR";     break;
        }
        return result;
    }
};
