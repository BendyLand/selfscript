#include "tokens.hpp"
#include "utils.hpp"
#include "lexer.hpp"

int main()
{
    std::string file = read_file("../test.ss");
    Lexer lexer(file);
    lexer.tokenize();

    return 0;
}
