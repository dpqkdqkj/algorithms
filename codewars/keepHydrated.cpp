#include <cstdio>


int litres(double time)
{
    return (int)time * 0.5;
}


int main()
{
    printf("%d\n", litres(0));
    return 1;
}

