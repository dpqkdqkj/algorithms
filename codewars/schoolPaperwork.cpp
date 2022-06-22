#include <cstdio>


int paperwork(int n, int m)
{
    if (n < 0 || m < 0) return 0;

    return n * m;
}

int paperwork2(int n, int m)
{
    return (n < 0 || m < 0) ? 0 : n * m;
}


int main()
{
    printf("%d\n", paperwork(5, 5));
    printf("%d\n", paperwork(-5, 5));

    printf("%d\n", paperwork2(-5, 5));
    printf("%d\n", paperwork2(-5, 5));
    return 0;
}

