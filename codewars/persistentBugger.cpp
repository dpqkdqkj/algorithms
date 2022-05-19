#include <cstdio>


long long foo(long long n)
{
    long long tmp = n;
    long long res = 1;
    while (tmp > 0) {
        res = res * (tmp % 10);
        tmp = tmp / 10;
    }
    return res;
}

int persistence(long long n)
{
    if (n < 10) return 0;

    long long tmp = n;
    int res = 0;
    while (tmp > 9) {
        tmp = foo(tmp);
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
