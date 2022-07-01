#include <string>
#include <cstdio>


std::string greet()
{
    return "hello world!";
}


int main (int argc, char *argv[])
{
    printf("%s\n", greet().c_str());
    return 0;
}

