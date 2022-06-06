#ifndef ARRAY_H_
#define ARRAY_H_

#include <cstddef>  // size_t
#include <assert.h>  // assert
#include <algorithm>  // max, copy, copy_backward

namespace myds {
using std::size_t;

template<class T>
class Array {
protected:
    T *data;
    size_t length;
public:
    Array();
    Array(size_t len);
    Array(size_t len, T init);
    Array(const Array<T>& other);
    virtual ~Array();

    inline size_t size() const { return length; }

    const Array<T>& operator=(const Array<T>& other);
    inline T& operator[](size_t i) const;
    inline T* operator+(size_t i) const;
};

template<class T>
Array<T>::Array()
{
    length = 0;
    data = nullptr;
}

template<class T>
Array<T>::Array(size_t len)
{
    length = len;
    data = new T[length];
}

template<class T>
Array<T>::Array(size_t len, T init)
{
    length = len;
    data = new T[length];
    std::fill_n(data, length, init);
}
    
template<class T>
Array<T>::Array(const Array<T>& other)
{
    *this = other;
}

template<class T>
Array<T>::~Array()
{
    if (data != nullptr)
        delete [] data;
}

template<class T>
const Array<T>& Array<T>::operator=(const Array<T>& other)
{
    /* If we don't care about semantic traditions
     * we can type void return function:
    void operator=(const Array<T>& other) */
    if (data != nullptr)
        delete [] data;
    length = other.length;
    data = new T[length];
    std::copy(other.data, other.data + length, data);
    return *this;
}

template<class T> inline
T& Array<T>::operator[](size_t i) const
{
    assert(i >= 0 && i < length);
    return data[i];
}

template<class T> inline
T* Array<T>::operator+(size_t i) const
{
    /* Operator `+` is necessary to apply the function 
     * `std::copy` and similar. Pointer arithmetic. */
    return data + i;
}


} /* namespace myds */
#endif /* ARRAY_H_ */

