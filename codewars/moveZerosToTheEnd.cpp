#include <vector>
#include <iostream>


std::vector<int> move_zeroes(const std::vector<int>& input)
{
    int n = input.size();
    std::vector<int> res(n);

    for (int i = 0, j = 0, zeroes = 0; i < n; ++i)
    {
        if (input[i] != 0)
        {
            res[j] = input[i];
            ++j;
        }
        else
        {
            res[n - 1 - zeroes] = 0;
            ++zeroes;
        }
    }
    return res;
}


int main()
{
    std::vector<int> test = {1, 0, 2, 0, 3, 5};
    std::vector<int> res = move_zeroes(test);

    for (int x: res) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}

