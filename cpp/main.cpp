#include "tokens.hpp"
#include "utils.hpp"

int main()
{
    Token test("cp", {"ex1.txt", "ex2.txt"});
    std::cout << "name: " << test.get_name_str() << std::endl;
    std::cout << "args: " << test.get_args() << std::endl;

    return 0;
}
