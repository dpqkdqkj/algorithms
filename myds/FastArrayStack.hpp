#ifndef FASTARRAYSTACK_HPP_
#define FASTARRAYSTACK_HPP_

#include "ArrayStack.hpp"

namespace myds {

template<class T>
class FastArrayStack : public ArrayStack<T> {
protected:
    using ArrayStack<T>::array;
    using ArrayStack<T>::as_N;
    virtual void resize();
public:
    FastArrayStack();
    virtual ~FastArrayStack() {};

    virtual void add(size_t i, T x);
    virtual void add(T x) { add(ArrayStack<T>::size(), x); }
    virtual T remove(size_t i);
};

template<class T>
FastArrayStack<T>::FastArrayStack() : ArrayStack<T>() {}

template<class T>
void FastArrayStack<T>::resize()
{
    Array<T> new_array(std::max(static_cast<size_t>(1), 2 * as_N));
    std::copy(array + 0, array + as_N, new_array + 0);
    array = new_array;
}

template<class T>
void FastArrayStack<T>::add(size_t i, T x)
{
    if (as_N + 1 > array.size()) resize();
    std::copy_backward(array + i, array + as_N, array + as_N + 1);
    array[i] = x;
    ++as_N;
}

template<class T>
T FastArrayStack<T>::remove(size_t i)
{
    T x = array[i];
    std::copy(array + i + 1, array + as_N, array + i);
    --as_N;
    if (array.size() >= 3 * as_N) resize();
    return x;
}


} /* namespace ods */
#endif /* FASTARRAYSTACK_HPP_ */

