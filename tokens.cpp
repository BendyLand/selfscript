#include "tokens.hpp"

Name Token::get_name() const
{
    return this->token.first;
}

std::string Token::get_name_str() const
{
    return this->name_to_str(this->token.first);
}

std::vector<std::string> Token::get_args() const
{
    return this->token.second;
}
