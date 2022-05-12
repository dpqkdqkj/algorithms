#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>


char *compressString(const char *source)
{
    if (strlen(source) == 0) return NULL;

    char *res = calloc(2 * strlen(source) + 1, 1);
    int pos_res = 0;

    char cur_symbol = source[0];
    int acc_symbol = 1;
    for (int i = 1; i < strlen(source); ++i) {
        if (cur_symbol == source[i]) {
            acc_symbol += 1;
            continue;
        }

        cur_symbol = source[i];
    }

}


int main()
{
    int num = 323125234;
    char *test = calloc(6 + 1, sizeof(char));
    sprintf(test, "%ld", num);
    printf("%s\n", test);

    return 1;
}

