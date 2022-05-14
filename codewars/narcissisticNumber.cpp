#include <cstdio>
#include <cmath>



std::size_t intlen(int i);

bool narcissistic(int value) 
{
    int tmp_value = value;
    size_t count_digits = intlen(value);
    int sum = 0;
    for (size_t i = 0; i < count_digits; ++i) {
        int last_digit = tmp_value % 10;
        tmp_value /= 10;

        sum += pow(last_digit, count_digits);
    }
    return (sum == value);
}


int main()
{
    printf("%d\n", narcissistic(7));
    return 0;
}


std::size_t intlen(int i) 
{
    if (i == 0) {
        return 1;
    }
    return 1 + log10(i);
}

