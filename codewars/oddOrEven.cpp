#include <string>
#include <vector>
#include <cstdio>


std::string odd_or_even(const std::vector<int> &arr)
{
    size_t arr_len = arr.size();

    if (arr_len == 0) return "even";

    int sum = 0;
    for (size_t i = 0; i < arr_len; ++i)
        sum += arr[i];

    return (sum % 2 == 0) ? "even" : "odd";
}

int main (int argc, char *argv[])
{
    printf("%s\n", odd_or_even({0,-1,-5}).c_str());
    return 0;
}

