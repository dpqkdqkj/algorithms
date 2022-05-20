#include <cstdio>


long long foo(long long n)
{
    long long res = 1;
    while (n > 0) {
        res *= (n % 10);
        n /= 10;
    }
    return res;
}

int persistence(long long n)
{
    if (n < 10) return 0;

    int res = 0;
    while (n > 9) {
        n = foo(n);
        res++;
    }
    return res;
}


int main()
{
    printf("%ld\n", foo(10));
    printf("%d\n", persistence(25));
    return 1;
}
