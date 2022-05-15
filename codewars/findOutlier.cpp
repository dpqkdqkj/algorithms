/*
 * You are given an array (which will have a length of at least 3, but could be 
 * very large) containing integers. The array is either entirely comprised of 
 * odd integers or entirely comprised of even integers except for a single 
 * integer N. Write a method that takes the array as an argument and returns 
 * this "outlier" N.
 */
#include <stdio.h>
#include <vector>


inline bool isOdd(int num);
inline bool isEven(int num);

int FindOutlier(std::vector<int> arr)
{
    int count_odds = 0;
    for (int i = 0; i < 3; ++i) {
        if (arr[i] % 2) count_odds++;
    }

    bool (*outlier)(int);
    if (count_odds > 1) {
        outlier = isEven;
    } else {
        outlier = isOdd;
    }

    for (int x : arr) {
        if (outlier(x)) return x;
    }
}

inline bool isOdd(int num)
{
    return (num % 2) ? true : false;
}
inline bool isEven(int num)
{
    return !isOdd(num);
}

