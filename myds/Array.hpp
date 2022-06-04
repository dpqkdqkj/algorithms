#include <cassert>  // assert

template <class T>
class Array {
    T *data;
    int length;
public:
    /* Init construction */
    Array(int len)
    {
        length = len;
        data = new T[length];
    };

    T& operator[](int i)
    {
        assert(i >= 0 && i < length);
        return data[i];
    };

    Array<T>& operator=(Array<T> &b)
    {
        if (this->data != nullptr) delete[] this->data;

        this->data = b.data;
        b.data = nullptr;
        this->length = b.length;

        return *this;
    };
};

