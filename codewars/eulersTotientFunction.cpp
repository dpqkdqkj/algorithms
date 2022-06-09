
/* O(sqrt(n)) */
int eulersTotientFunction (int n)
{
    int ans = n;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n = n / i;
            ans -= ans / i;
        }
    }
    if (n > 1)
        ans -= ans / n;
    return ans;
}

/* n = 5
 * 5 % 2 = 1;
 * 5 % 3 = 2;
 * 5 % 4 = 1;
 * 5 % 5 = 0;
 * 5 = 5 / 5 = 1;
 * ans = ans - ans / 5 === 5 - 5 / 5 = 4;
 * n = 1;
 * ans = 4;
 */

