#include <iostream>

bool isParenthesized()
{
  return true;
}

#define isParenthesized() false

int main()
{
    std::cout << isParenthesized() << "\n";
    std::cout << (isParenthesized)() << "\n";
    return 0;
}

