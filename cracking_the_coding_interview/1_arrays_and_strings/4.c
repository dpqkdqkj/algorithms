#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


/* 
 * ---- ---- ---- Solution 1 ---- ---- ----
 */
void initArray(size_t *array, size_t len_array);

bool isPermutationOfPalindrome_1(const char *str)
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

/* 
 * ---- ---- ---- Solution 2 ---- ---- ----
 */
int getCharNumber(char c);
int createBitVector(const char *str);
void toggleBitVector(int *bit_vector, int index);
int isOnlyOneBitSet(int bit_vector);

bool isPermutationOfPalindrome_2(const char *str)
{
    int bit_vector = createBitVector(str);
    return bit_vector == 0 || isOnlyOneBitSet(bit_vector);
}

/* 
 * ---- ---- ---- Tests ---- ---- ----
 */
bool test(bool (*f)(const char*));

int main()
{
    printf("%s\n", test(isPermutationOfPalindrome_1) ? "OK." : "FAIL.");
    printf("%s\n", test(isPermutationOfPalindrome_2) ? "OK." : "FAIL.");
    return 0;
}


bool test(bool (*f)(const char*)) 
{
    char test_true[] = "abab";
    char test_false[] = "abad";
    return (f(test_true) && ~f(test_false));
}

void initArray(size_t *array, size_t len_array)
{
    memset(array, 0, len_array * sizeof(size_t));
}

int getCharNumber(char c)
{
    if (('a' <= c) && (c <= 'z')) {
        return c - 'a';
    }
    return -1;
}

void toggleBitVector(int *bit_vector, int index)
{
    if (index < 0) return;

    int mask = 1 << index;

    if ((*bit_vector & mask) == 0) {
        *bit_vector |= mask;
    } else {
        *bit_vector &= ~mask;
    }
}

int createBitVector(const char *str) {
    int bit_vector = 0;
    int *ptr_bv = &bit_vector;
    
    for (int i = 0; i < strlen(str); ++i) {
        toggleBitVector(ptr_bv, getCharNumber(str[i]));
    }
    return bit_vector;
}

int isOnlyOneBitSet(int bit_vector)
{
    return ((bit_vector - 1) & bit_vector) == 0;
}

