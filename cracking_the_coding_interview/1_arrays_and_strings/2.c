#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>  /* type bool */
#include <stdlib.h>  /* qsort */


bool isPermutation_1(const char *first, const char *second)
{
    size_t len_first, len_second;
    len_first = strlen(first);
    len_second = strlen(second);

    if (len_first != len_second) return false;

    int letter_counts[128];
    for (size_t i = 0; i < len_first; ++i) {
        letter_counts[first[i]]++;
    }
    for (size_t i = 0; i < len_second; ++i) {
        letter_counts[second[i]]--;
        if (letter_counts[second[i]] < 0) return false;
    }
    return true;
}

int cmpfunc(const void *left, const void *right);
char *sortedString(const char *str);

bool isPermutation_2(const char *first, const char *second)
{
    if (strlen(first) != strlen(second)) return false;

    char *first_sorted = sortedString(first);
    char *second_sorted = sortedString(second);

    int res_strcmp = strcmp(first_sorted, second_sorted);

    free(first_sorted);
    free(second_sorted);

    return res_strcmp ? false : true;
}

int main()
{
    char first[] = "aabc";
    char second[] = "cab";

    if (isPermutation_1(first, second)) {
        printf("First solution: YES!\n");
    } else {
        printf("First solution: NO.\n");
    }

    if (isPermutation_2(first, second)) {
        printf("Second solution: YES!\n");
    } else {
        printf("Second solution: NO..\n");
    }

    return 0;
}

int cmpfunc(const void *left, const void *right)
{
    return *(char *)left - *(char *)right;
}

char *sortedString(const char *str)
{
    /* ALLOCATES MEMORY! */
    char *sorted_str = strdup(str);
    qsort(sorted_str, strlen(str), sizeof(char), cmpfunc);
    return sorted_str;
}

