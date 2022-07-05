#include <string>
#include <vector>
#include <cstdio>


std::string odd_or_even(const std::vector<int> &arr)
{
    int sum = 0;
    for (size_t i = 0; i < arr.size(); ++i)
        sum += arr[i];

    return (sum % 2 == 0) ? "even" : "odd";
}

int main (int argc, char *argv[])
{
    printf("%s\n", odd_or_even({}).c_str());
    return 0;
}

