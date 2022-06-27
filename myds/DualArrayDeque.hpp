#ifndef DUALARRAYDEQUE_HPP_
#define DUALARRAYDEQUE_HPP_

#include "ArrayStack.hpp"
#include <cstddef>

namespace myds {

template<class T>
class DualArrayDeque {
protected:
    ArrayStack<T> front;
    ArrayStack<T> back;
    void balance();
public:
    DualArrayDeque() {};
    virtual ~DualArrayDeque() {};

    inline size_t size() const;
    T get(size_t i);
    T set(size_t i, T x);
    virtual void add(size_t i, T x);
    virtual T remove(size_t i);
    //virtual void clear();
};


template<class T>
inline size_t DualArrayDeque<T>::size() const
{
    return front.size() + back.size();
}

template<class T> inline
T DualArrayDeque<T>::get(size_t i)
{
    return (i < front.size()) ? front.get(front.size() - i - 1) : 
                                back.get(i - front.size());
}

template<class T> inline
T DualArrayDeque<T>::set(size_t i, T x)
{
    return (i < front.size()) ? front.set(front.size() - i - 1, x) : 
                                back.set(i - front.size(), x);
}

template<class T>
void DualArrayDeque<T>::add(size_t i, T x)
{
    /*     front | back
       4 3 2 1 0   0 1 2 3 4 
       _ _ _ a b | c d _ _ _
             0 1   2 3 

       add(1, 'x');

       _ _ _ a b | c d _ _ _
             0 1   2 3 
       
       _ _ a x b | c d _ _ _
           0 1 2   3 4

       add(4, 'y');

       _ _ a x b | c y d _ _
           0 1 2   3 4 5
    */

    if (i < front.size()) {
        front.add(front.size() - i, x);
    } else {
        back.add(i - front.size(), x);
    }

    balance();
}

template<class T>
T DualArrayDeque<T>::remove(size_t i)
{
    T x;
    if (i < front.size()) {
        x = front.remove(front.size() - i - 1);
    } else {
        x = back.remove(i - front.size());
    }

    balance();

    return x;
}

template<class T>
void DualArrayDeque<T>::balance()
{
    if (3 * front.size() < back.size() || 3 * back.size() < front.size()) {
        size_t n = front.size() + back.size();
        size_t nf = n/2;
        Array<T> af(std::max(2 * nf, static_cast<size_t>(1)));
        for (size_t i = 0; i < nf; ++i) {
            af[nf - i - 1] = get(i);
        }
        size_t nb = n - nf;
        Array<T> ab(std::max(2 * nb, static_cast<size_t>(1)));
        for (size_t i = 0; i < nb; ++i) {
            ab[i] = get(nf + i);
        }
        front.array = af;
        front.as_N = nf;
        back.array = ab;
        back.as_N = nb;
    }
}

/*
template<class T>
void DualArrayDeque<T>::clear()
{
    front.clear();
    back.clear();
}
*/


} /* namespace myds */
#endif /* DUALARRAYDEQUE_HPP_ */

