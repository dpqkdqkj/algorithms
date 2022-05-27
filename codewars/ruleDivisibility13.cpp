#include <iostream>
#include <cmath>

class Thirteen
{
public:
    static long long thirt(long long n)
    {
        long long last_res = 0;
        long long res = n;
        
        while (res != last_res)
        {
            last_res = res;
            res = 0;
            int dig_count = static_cast<int>(log10(last_res) + 1);
            int last_n = last_res;
            for (int i = 0; i < dig_count; ++i)
            {
                int digit = static_cast<int>(last_n % 10);
                last_n /= 10;
                res += digit * (static_cast<int>(pow(10, i)) % 13);
            }
        };
        return res;
    };
};


int main()
{
    Thirteen::thirt(8529);

    // 123 / 10 = 12.3
    // 123 % 10 = 3
    //
    // TODO: 
    // 1. use while (res >= 100)
    // 2. use pattern (array with pow 10 % 13)

    return 0;
}

