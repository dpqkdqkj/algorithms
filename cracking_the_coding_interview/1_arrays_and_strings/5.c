#include <stdio.h>
#include <string.h>


int isTrue(char *source, char *dest)
{
    char *longest;
    char *shortest;

    int len_longest = strlen(source);
    int len_shortest = strlen(dest);

    if (len_longest >= len_shortest) {
        longest = source;
        shortest = dest;
    } else {
        longest = dest;
        shortest = source;
        int tmp = len_longest;
        len_longest = len_shortest;
        len_shortest = tmp;
    }

    if ((len_longest - len_shortest) > 1) return 0;

    int changed = 0;
    for (int i = 0, j = 0; i < (len_shortest - 1); ++i, ++j) {
        if (shortest[i] == longest[j]) continue;
        if (changed) return 0;
        if (shortest[i+1] == longest[j+1]) {
            changed = 1;
            continue;
        }
        if (shortest[i] == longest[j+1]) {
            changed = 1;
            j += 1;
        } else return 0;
    }
    return 1;
}


int main() {
    char test_source[] = "pale";
    char test_dest[] = "palse";
    printf("%d\n", isTrue(test_source, test_dest));
    return 0;
}
