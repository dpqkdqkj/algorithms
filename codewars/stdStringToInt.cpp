#include <string>
#include <cstdio>

int string_to_number(const std::string& s) { return std::stoi(s); }


int main()
{
    std::string test = "-123";
    int res = string_to_number(test);
    printf("%d\n", res - 1);
    return 0;
}

