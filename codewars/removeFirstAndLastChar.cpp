#include <cstdio>
#include <string>


std::string sliceString(std::string str)
{
    return std::string(str.begin() + 1, str.end() - 1);
}


int main (int argc, char *argv[])
{
    printf("%s\n", sliceString("test").c_str());   // es
    printf("%s\n", sliceString("place").c_str());  // lac
    return 0;
}

