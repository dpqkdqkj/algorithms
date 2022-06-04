#include <algorithm>  // max
#include "Array.hpp"

template <class T>
class ArrayStack {
    Array<T> a;
    int n;
public:
    int size() { return n; };

    T get(int i) { return a[i]; };

    T set(int i, T x)
    {
        T y = a[i];
        a[i] = x;
        return y;
    };

    void add(int i, T x)
    {
        if (n + 1 > a.length) resize();
        // right shift
        for (int j = n; j > i; --j)
            a[j] = a[j - 1];
        a[i] = x;
        ++n;
    };

    T remove(int i)
    {
        T x = a[i];
        // left shift
        for (int j = i; j < n - 1; ++j)
            a[j] = a[j + 1];
        --n;
        if (a.length >= 3 * n) resize();
        return x;
    };

    void resize()
    {
        Array<T> b(std::max<int>(2 * n, 1));
        for (int i = 0; i < n; ++i)
            b[i] = a[i];
        a = b;
    };
};

