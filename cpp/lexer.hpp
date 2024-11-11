#pragma once

#include "utils.hpp"
#include "tokens.hpp"

class Lexer 
{
public:
    Lexer(std::string file) : 
        m_file(file)
    {}
    std::string file();
    std::vector<std::string> lines();
    void tokenize();

private:
    std::string m_file;
    std::vector<Token> m_tokens;
};

Token line_to_token(std::string line);
