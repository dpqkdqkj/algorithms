#include <stdio.h>
#include <string.h>
#include <stdbool.h>


void initArray(size_t *array, size_t len_array);

bool isPermutationOfPalindrome(char *str)
{
    size_t count_letters[128];
    initArray(count_letters, 128);

    for (size_t i = 0; i < strlen(str); ++i) {
        if (str[i] == ' ') continue;
        count_letters[str[i]]++;
    }

    bool oddFound = 0;
    for (size_t i = 0; i < 128; ++i) {
        if (count_letters[i] == 0) continue;
        if (count_letters[i] % 2) {
            if (oddFound) return false;
            oddFound = 1;
        }
    }
    return true;
}


int main()
{
    char test[] = "bclcb";
    if (isPermutationOfPalindrome(test)) {
        printf("YES.\n");
    } else {
        printf("NO.\n");
    }
    return 0;
}

void initArray(size_t *array, size_t len_array)
{
    memset(array, 0, len_array * sizeof(size_t));  /* initialize array by zeroes */
}

