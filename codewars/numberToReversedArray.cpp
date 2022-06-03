#include <cmath>
#include <vector>


std::vector<int> digitize(unsigned long n) 
{
    if (n == 0) return { 0 };

    int count_digits = static_cast<int>(log10(n) + 1);
    std::vector<int> res(count_digits);

    for (int i = 0; i < count_digits; n /= 10, ++i)
    {
        res[i] = n % 10;
    }
    return res;
}


int main()
{
    digitize(12345);  // { 5, 4, 3, 2, 1 }
    return 0;
}

