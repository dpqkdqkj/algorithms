#ifndef ARRAYSTACK_HPP_
#define ARRAYSTACK_HPP_

#include "Array.hpp"

namespace myds {

template<class T>
class DualArrayDeque;

template<class T>
class ArrayStack {
    friend class DualArrayDeque<T>;
protected:
    Array<T> array;
    size_t as_N;
    virtual void resize();
public:
    ArrayStack();
    ArrayStack(size_t len);
    virtual ~ArrayStack() {};

    inline size_t size() const { return as_N; };
    inline T get(size_t i) const { return array[i]; };
    inline T set(size_t i, T x);
    virtual void add(size_t i, T x);
    virtual void add(T x) { add(size(), x); }
    virtual T remove(size_t i);
};

template <class T>
ArrayStack<T>::ArrayStack() : array()
{
    as_N = 0;
}

template <class T>
ArrayStack<T>::ArrayStack(size_t len) : array(len)
{
    as_N = 0;
}

template<class T>
inline T ArrayStack<T>::set(size_t i, T x)
{
    T y = array[i];
    array[i] = x;
    return y;
}

template<class T>
void ArrayStack<T>::resize()
{
    Array<T> new_array(std::max(2 * as_N, static_cast<size_t>(1)));
    for (size_t i = 0; i < as_N; ++i)
        new_array[i] = array[i];
    array = new_array;
}

template<class T>
void ArrayStack<T>::add(size_t i, T x)
{
    if (as_N + 1 > array.size()) resize();
    for (size_t j = as_N; j > i; --j)
        array[j] = array[j - 1];
    array[i] = x;
    ++as_N;
}

template<class T>
T ArrayStack<T>::remove(size_t i)
{
    T x = array[i];
    for (size_t j = i; j < as_N - 1; ++j)
        array[j] = array[j + 1];
    --as_N;
    if (array.size() >= 3 * as_N) resize();
    return x;
}


} /* namespace myds */
#endif /* ARRAYSTACK_HPP_ */

