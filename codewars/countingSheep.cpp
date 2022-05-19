#include <vector>
#include <algorithm>


int count_sheep(std::vector<bool> arr) 
{
    return std::count(arr.begin(), arr.end(), true);
}

