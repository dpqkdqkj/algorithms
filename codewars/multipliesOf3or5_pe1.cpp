#include <cstdio>
#include <vector>
#include <numeric>


//               getNumbers(10)                              accumulate is O(n)
// solution(10) -> [ 3 5 6 (6/3=2) 9 (9/3=3) ] -> [ 3 + 5 + 6 + 9 ] -> 23
// O(n)

std::vector<int> getNumbers(int number);

/* Return sum of arithmetic progression Sn = (a1 + an) * n/2. */
int S_n(int a1, int an, int n);


/* O(n) */
int solution1(int number) 
{
    if (number <= 2) return 0;
    std::vector<int> numbers = getNumbers(number);
    return accumulate(numbers.begin(), numbers.end(), 0);
}

/* O(1) */
int solution2(int number) 
{
    int n_3  = (number - 1) / 3;
    int n_5  = (number - 1) / 5;
    int n_15 = (number - 1) / 15;
    return S_n(3, 3*n_3, n_3) + S_n(5, 5*n_5, n_5) - S_n(15, 15*n_15, n_15);
}


int main()
{
    int testNumber = 1000;
    std::vector<int> test = getNumbers(testNumber);
    if (testNumber < 1001) {
        printf("[ ");
        for (int x: test) {
            printf("%d ", x);
        }
        printf("]\n");
    }

    printf("sum %d\n", solution1(testNumber));
    printf("sum2 %d\n", solution2(testNumber));

    return 0;
}


std::vector<int> getNumbers(int number)
{
    std::vector<int> numbers;
    int maxFrom3 = (number - 1) / 3;
    int maxFrom5 = (number - 1) / 5;

    for (int i = 1; i <= maxFrom3; ++i)
    {
        numbers.push_back(i * 3);
        if (i % 3 == 0 || i > maxFrom5) continue;
        numbers.push_back(i * 5);
    }

    return numbers;
}

int S_n(int a1, int an, int n)
{
    return (a1 + an) * n/2;
}
