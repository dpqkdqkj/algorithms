#include <stdio.h>


unsigned int countBits(unsigned long long n)
{
    unsigned int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}


int main()
{
    unsigned long long n = 392902058;
    printf("%d\n", countBits(n));
    return 0;
}

