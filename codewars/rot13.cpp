#include <string>
#include <cstdio>


inline bool isLowercase(char ch) { return (97 <= ch && ch <= 122); }
inline bool isUppercase(char ch) { return (65 <= ch && ch <= 90); }

std::string rot13(std::string msg)
{
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    char ALPHABET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string res = "";

    for (char ch: msg) 
    {
        if (isLowercase(ch)) 
        {
            res += alphabet[(ch - 'a' + 13) % 26];
        }
        else if (isUppercase(ch)) 
        {
            res += ALPHABET[(ch - 'A' + 13) % 26];
        }
        else
        {
            res += ch;
        }
    }
    return res;
}


int main()
{
    
    std::string test = "AbCd";
    printf("%s\n", rot13(test).c_str());

    return 1;
}

/* Unused useless */
int getCharNumber(char ch)
{
    if (isLowercase(ch)) {
        return ch - 'a';
    }

    if (isUppercase(ch)) {
        return ch - 'A';
    }

    return -1;
}
