#include <vector>
#include <iostream> // cout
#include <cmath>    // pow
#include <cstddef>  // size_t

int square_sum(const std::vector<int>& numbers)
{
    if (numbers.size() == 0) return 0;

    int res = 0;
    for (size_t i = 0; i < numbers.size(); ++i)
        res += std::pow(numbers[i], 2);

    return res;
}

int main()
{
    std::cout << square_sum({0, 3, 4, 5}) << "\n";

    return 0;
}

