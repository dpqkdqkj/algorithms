#include <string>
#include <cstring>  // memset
#include <algorithm>  // count_if

using std::string;

int getCharNumber(char ch);
bool is_vowel(char c);


/* Solution #1 with hash table O(n) */
int getCount1(const string& inputStr)
{
    int num_vowels = 0;
    const char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
    int hashChar[23];
    memset(hashChar, 0, 23 * sizeof(int));  // Initialize array by zeroes.

    /* O(n) */
    for (char ch: inputStr) {
        int idx = getCharNumber(ch);
        if (idx >= 0) {
            hashChar[idx]++;
        }
    }
    for (char ch: vowels) {
        num_vowels += hashChar[getCharNumber(ch)];
    }
    return num_vowels;
}

/* Solution #2 with count_if O(n) */
int getCount2(const string& inputStr) 
{
    return count_if(inputStr.begin(), inputStr.end(), is_vowel);
}


int getCharNumber(char ch)
{
    if (('a' <= ch) && (ch <= 'z')) {
        return ch - 'a';
    }
    return -1;
}

bool is_vowel(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main()
{
    const string testStr = "abcei";  // 3
    printf("count vowels in string \"%s\" = %d\n", 
            testStr.c_str(), getCount1(testStr));

    printf("count vowels in string \"%s\" = %d\n", 
            testStr.c_str(), getCount2(testStr));
    return 0;
}

