#ifndef ARRAYDEQUE_HPP_
#define ARRAYDEQUE_HPP_

#include "Array.hpp"

namespace myds {

template<class T>
class ArrayDeque {
protected:
    size_t first_idx;
    size_t ad_N;
    virtual void resize();
    void shift_left(size_t start_idx, size_t end_idx);
    void shift_right(size_t start_idx, size_t end_idx);
public:
    Array<T> array;
    ArrayDeque();
    virtual ~ArrayDeque() {};

    size_t array_size() const { return array.size(); }
    inline T get(size_t i) const { return array[ (first_idx + i) % array.size() ]; };
    T set(size_t i, T x);
    virtual void add(size_t i, T x);
    virtual T remove(size_t i);

    inline size_t size() const { return ad_N; };
    inline size_t get_first_idx() const { return first_idx; };
};

template<class T>
inline T ArrayDeque<T>::set(size_t i, T x)
{
    T y = array[ (first_idx + i) % array.size() ];
    array[ (first_idx + i) % array.size() ] = x;
    return y;
}

template<class T>
ArrayDeque<T>::ArrayDeque() : array(12)
{
    ad_N = 0;
    first_idx = 0;
}

template<class T>
void ArrayDeque<T>::resize()
{
    Array<T> resized_array(std::max(static_cast<size_t>(1), 2 * ad_N));

    for (size_t k = 0; k < ad_N; ++k)
        resized_array[ k ] = array[ (first_idx + k) % array.size() ];

    array = resized_array;
    first_idx = 0;
}


template<class T>
void ArrayDeque<T>::shift_left(size_t start_idx, size_t end_idx)
{
    for (size_t k = start_idx; k <= end_idx; ++k)
        array[ (first_idx + k) % array.size() ] = array[ (first_idx + k + 1) % array.size() ];
}

template<class T>
void ArrayDeque<T>::shift_right(size_t start_idx, size_t end_idx)
{
    for (size_t k = end_idx; k > start_idx; --k)
        array[ (first_idx + k) % array.size() ] = array[ (first_idx + k - 1) % array.size() ];
}

template<class T>
void ArrayDeque<T>::add(size_t i, T x)
{
    if (ad_N + 1 > array.size()) resize();

    if (i < ad_N / 2) // shift a[0],..,a[i-1] left one position
    {
        first_idx = (first_idx == 0) ? array.size() - 1 : first_idx - 1;
        /*
        for (size_t k = 0; k <= i - 1; ++k)
            array[ (first_idx + k) % array.size() ] = array[ (first_idx + k + 1) % array.size() ];
            */
        //if (i != 0)
        shift_left(0, i - 1);
    }
    else // shift a[i],..,a[n-1] right one position
    {
        /*
        for (size_t k = ad_N; k > i; --k)
            array[ (first_idx + k) % array.size() ] = array[ (first_idx + k - 1) % array.size() ];
            */
        shift_right(i, ad_N);
    }

    array[ (first_idx + i) % array.size() ] = x;
    ++ad_N;
}

template<class T>
T ArrayDeque<T>::remove(size_t i)
{
    T x = array[ (first_idx + i) % array.size() ];

    if (i < ad_N / 2) // shift a[0],..,[i-1] right one position
    {
        /*
        for (size_t k = i; k > 0; --k)
            array[ (first_idx + k) % array.size() ] = array[ (first_idx + k - 1) % array.size() ];
        */

        shift_right(0, i);
        first_idx = (first_idx + 1) % array.size();
    }
    else // shift a[i+1],..,a[n-1] left one position
    {
        /*
        for (size_t k = i; k < ad_N - 1; ++k)
            array[ (first_idx + k) % array.size() ] = array[ (first_idx + k + 1) % array.size() ];
        */
        if (ad_N != 0)
            shift_left(i, ad_N - 1);
            //shift_left(i, ad_N);
    }

    --ad_N;
    //if (3 * ad_N < array.size()) resize();

    return x;
}


} /* namespace myds */

#endif /* ARRAYDEQUE_HPP_ */

