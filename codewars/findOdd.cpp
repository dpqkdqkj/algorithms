#include <vector>
#include <cstdio>
#include <unordered_map>


int findOdd(const std::vector<int> &numbers)
{
    std::unordered_map<int, int> map_numbers;
    for (auto number : numbers) {
        map_numbers[number]++;
    }
    for (auto it : map_numbers) {
        if (it.second % 2) return it.first;
    }
    return 0;
}

