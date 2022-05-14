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


int main()
{
    std::vector<int> numbers;
    numbers.push_back(5);
    numbers.push_back(5);
    numbers.push_back(1);
    numbers.push_back(1);
    numbers.push_back(1);
    numbers.push_back(1);
    numbers.push_back(3);
    numbers.push_back(3);
    numbers.push_back(2);
    numbers.push_back(2);
    numbers.push_back(12121);


    printf("%d\n", findOdd(numbers));
    printf("%X\n", 0x010101 ^ 0x100001);
    return 0;
}

