#include <stdio.h>
#include <string.h>


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

int isTrue(const char *str)
{
    int bit_vector = createBitVector(str);
    return bit_vector == 0 || isOnlyOneBitSet(bit_vector);
}

int main()
{
    char test_str[] = "abc cba";
    printf("%d\n", isTrue(test_str));
    return 0;
}

