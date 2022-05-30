#include <iostream>
#include <vector>


std::vector<int> snail(const std::vector<std::vector<int>>& snail_map)
{
    int n = snail_map[0].size();
    if (n == 0) return {};
    std::vector<int> res;
    int max_x = n;
    int max_y = n;
    int min_x = 0;
    int min_y = 0;

    for (int k = 0; min_x <= n; ++k, ++min_x, ++min_y, --max_x, --max_y)
    {
        /* -------------- top -------------- */
        for (int x = min_x; x < max_x; ++x)
        {
            res.push_back(snail_map[k][x]);
        }
        /* ------------- right ------------- */
        for (int y = min_y+1; y < max_y; ++y)
        {
            res.push_back(snail_map[y][max_x-1]);
        }
        /* -------------- bot -------------- */
        for (int x = max_x-1-1; x >= min_x; --x)
        {
            res.push_back(snail_map[max_y-1][x]);
        }
        /* ------------- left -------------- */
        for (int y = max_y-1-1; y > min_y; --y)
        {
            res.push_back(snail_map[y][k]);
        }
    }
    return res;
}

void printVec(std::vector<int> vec)
{
    for (int x: vec)
    {
        std::cout << x << " ";
    }
    std::cout << "\n";
}

int main()
{
    printVec(snail({

      {1,  2,  3,  4,  5,},
      {6,  7,  8,  9,  10},
      {11, 12, 13, 14, 15},
      {16, 17, 18, 19, 20},
      {21, 22, 23, 24, 25}

    }));

    snail({
      {}});

    return 0;
}

