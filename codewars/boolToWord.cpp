#include <cstdio>
#include <string>


std::string bool_to_word(bool value)
{
    return value ? "Yes" : "No";
}


int main (int argc, char *argv[])
{
    printf("%s\n", bool_to_word(true).c_str());   // Yes
    printf("%s\n", bool_to_word(false).c_str());  // No
    return 0;
}

