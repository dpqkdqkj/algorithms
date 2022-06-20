
#include <cstdio>


int get_sum(int a, int b)
{
    int min = a;
    int max = b;
    if (a > b) { min = b; max = a; }

    int sum = 0;
    for (; min <= max; sum += min, ++min) { }
    return sum;
}

int main()
{
    printf("%d\n", get_sum(1, 1));
    //get_sum(5,-4);
    return 0;
}
