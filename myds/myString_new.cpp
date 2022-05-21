#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <cstddef>
#include <vector>
#include <iostream>
#include <algorithm>


class String {
    size_t len;
    char *data;

public:
    String(const char *c_string) {
        len = strlen(c_string);
        data = new char[len + 1];
        memcpy(data, c_string, len);
        data[len] = '\0';
    }

    String(const String& a) {
        len = strlen(a.data);
        data = new char[len + 1];
        memcpy(data, a.data, len);
        data[len] = '\0';
    }

    size_t size() { return len; }

    void print() { printf("%s\n", data); }

    ~String() { delete [] data; }
};

void testF(const String& s) {
    String tmp = s;
    tmp.print();
}

int *foo(int countt)
{
    int *p = new int[countt];
    for (int i = 0; i < countt; ++i) {
        p[i] = i;
    }
    return p;
}

int main(int argc, char **argv)
{
    String test("Test me");
    String test2 = test;
    testF(test2);
    int *tp = foo(argc);
    tp = foo(argc);
    printf("argc %d tp %d\n", argc, tp[argc-1]);
    std::vector<bool> ships = {true, true, true,true, false};
    int res = 0;
    res = std::count(ships.begin(), ships.end(), true);
    printf("%d\n", res); 
    return 0;
}

