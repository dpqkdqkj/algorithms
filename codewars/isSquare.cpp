#include <cmath>
#include <cstdio>


bool is_square(int n)
{
    float square_n = std::sqrt(n);
    int whole_square_n = square_n;

    return (square_n - whole_square_n == 0) ? true : false;
}


int main (int argc, char *argv[])
{

    float a = 12.3;
    int c = (int)a;
    int b = (a - c)*10;
    printf("%d\n", b);

    printf("%d\n", is_square(64));
    
    return 0;
}

