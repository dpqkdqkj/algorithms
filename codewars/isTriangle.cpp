#include <cstdio>


void sortABC(int *a, int *b, int *c);

namespace Triangle
{
    bool isTriangle1(int a, int b, int c)
    {
        if (a <= 0 || b <= 0 || c <= 0) return false;

        if (a == b == c) return true;

        sortABC(&a, &b, &c);
        if (a == b) return true;

        return (a - b - c) < 0;
    }

    bool isTriangle2(int a, int b, int c)
    {
        /* Undefined with a negative values abc */
        sortABC(&a, &b, &c);
        return a > (b - c) && b > (a - c) && c > (a - b);
    }

    bool isTriangle3(int a, int b, int c)
    {
        /* Undefined with a negative values abc */
        return a - b < c && b - c < a && c - a < b;
    }

};


int main()
{
    int a = 5;
    int b = 4;
    int c = 3;
    printf("%d\n", Triangle::isTriangle3(696446245,1648564250,1206573244));
    printf("%d\n", Triangle::isTriangle3(3,2,1));
    return 0;
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sortABC(int *a, int *b, int *c)
{
    if (*a < *b) swap(a, b);
    if (*b < *c) swap(b, c);  // here c is smallest 
    if (*a < *b) swap(a, b);
}

