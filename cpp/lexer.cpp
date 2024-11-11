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

Token line_to_token(std::string& line)
{
    trim_start(line);
    std::vector<std::string> words = split(line, " ");
    if (contains(line, "\"")) {
        return str_line_to_token(line, words);
    }
    if (words.size() > 0) {
        std::string name = words[0];
        if (str_to_name(name) == Name::UNKNOWN) name = "variable";
        else {
            name = words[0];
            words.erase(words.begin());
        }
        return Token(name, words);
    }
    else {
        return Token("", {});
    }
}

Token str_line_to_token(std::string& line, std::vector<std::string>& words)
{
    std::string name = "";
    if (count(line, "\"") > 2) {
        std::vector<std::string> strs = extract_multiple_strings(line);
        name = words[0];
        words.erase(words.begin());
        words.insert(words.end(), strs.begin(), strs.end());
    }
    else {
        std::string inner_str = extract_string(line);
        name = words[0];
        words.erase(words.begin());
        words.emplace_back(inner_str);
    }
    words = dedup(words);
    if (str_to_name(name) == Name::UNKNOWN && words.size() > 0) name = "variable";
    return Token(name, words);
}