#include <iostream>
#include <cstring>


bool isEqual(const char *first, const char *second, int n);
bool isSubstring(const char *first, const char *second);
char *concatStr(const char *s1, const char *s2);

bool isRotation(const char *s1, const char *s2)
{
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    if (len_s1 != len_s2) return false;

    char *s1s1 = concatStr(s1, s1);

    bool is_rotation = isSubstring(s1s1, s2);
    free(s1s1);

    if (is_rotation) return true;

    return false;
}


int main()
{
    char test_a[] = "abcdef";
    char test_b[] = "de";

    char test_rot1[] = "abcdef";
    char test_rot2[] = "defabc";

    //std::cout << isSubstring(test_a, test_b) << '\n';
    std::cout << isRotation(test_rot1, test_rot2) << '\n';

    return 0;
}


bool isEqual(const char *first, const char *second, int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (first[i] != second[i]) return false;
    }
    return true;
}

bool isSubstring(const char *first, const char *second)
{
    const char *long_str = first;
    const char *short_str = second;
    int len_long = strlen(long_str);
    int len_short = strlen(short_str);

    if (len_short > len_long) {
        long_str = second;
        short_str = first;
        int tmp = len_long;
        len_long = len_short;
        len_short = tmp;
    }
    for (int i = 0; i < len_long; ++i) {
        if (isEqual(long_str + i, short_str, len_short)) {
            return true;
        }
    }
    return false;
}

char *concatStr(const char *s1, const char *s2)
{
    /* ALLOCATE MEM ! */
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    char *s1s2 = static_cast<char *>(malloc((len_s1 + len_s2) * sizeof(char) + 1));

    memcpy(s1s2, s1, len_s1);
    memcpy(s1s2 + len_s1, s1, len_s2);
    s1s2[len_s1 + len_s2] = '\0';

    return s1s2;
}

