#include <stdio.h>

unsigned int lenString(const char *string)
{
    if (string == NULL) {
        return 0;
    }
    unsigned int res = 0;
    while (string[res]) {
        res += 1;
    }
    return res;
}

int isUniqueString(const char *string)
{
    /* Find lenght of the string */
    unsigned int len_str = 0;
    len_str = lenString(string);

    unsigned int i, j;
    for(i = 0; i < len_str; ++i) {
        for(j = i + 1; j < len_str; ++j) {
            if (string[i] == string[j]) {
                return 0;
            }
        }
    }
    return 1;
}


int printRawString(const char *string)
{
    for (int i = 0; i < lenString(string); ++i) {
        printf("i: %d | char: %d\n", i, string[i]);
    }
}


int main(int argc, char **argv)
{
    char test_string[] = "tesr camg";
    printf("test unique of string %s = %d\n", test_string, isUniqueString(test_string));
    printRawString(test_string);
    return 1;

}
