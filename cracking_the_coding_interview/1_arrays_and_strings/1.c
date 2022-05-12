#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>


/* 
 * ---- ---- ---- Solution 1 ---- ---- ----
 */
bool isUniqueString(const char *string)
{
    size_t len_str = strlen(string);
    for (size_t i = 0; i < len_str; ++i) {
        for (size_t j = i + 1; j < len_str; ++j) {
            if (string[i] == string[j]) return false;
        }
    }
    return true;
}

/* 
 * ---- ---- ---- Tests ---- ---- ----
 */
bool test(bool (*f)(const char *));

int main()
{
    printf("%s\n", test(isUniqueString) ? "OK." : "FAIL.");
    return 0;
}


bool test(bool (*f)(const char *))
{
    char test_true[] = "abc";
    char test_false[] = "abb";
    return (f(test_true) && ~f(test_false));
}

