#include "lexer.hpp"

std::string Lexer::file()
{
    return this->m_file;
}

std::vector<std::string> Lexer::lines()
{
    return split(this->m_file, "\n");
}

void Lexer::tokenize()
{
    std::vector<Token> result;
    std::vector<std::string> lines = this->lines();
    result.reserve(lines.size());
    
    for (std::string line : lines) {
        Token lineTok = line_to_token(line);
        std::cout << "Line token: " << lineTok << std::endl;
    }

    this->m_tokens = result;
}

Token line_to_token(std::string line)
{
    std::vector<std::string> words = split(line, " ");
    if (words.size() > 0) {
        std::string name = words[0];
        words.erase(words.begin());
        return Token(name, words);
    }
    else {
        return Token("", {});
    }
}