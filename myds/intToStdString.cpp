#include <string>


std::string number_to_string(int num) {
  return std::to_string(num);
}


int main()
{
    int num = 123;
    std::string test = number_to_string(num);
    printf("%s\n", test.c_str());
    return 0;
}

