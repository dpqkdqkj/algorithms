#ifndef DUALARRAYDEQUE_HPP_
#define DUALARRAYDEQUE_HPP_
#include "ArrayStack.hpp"

namespace myds {

template<class T>
class DualArrayDeque {
protected:
	ArrayStack<T> front;
	ArrayStack<T> back;
	void balance();
public:
	DualArrayDeque();
	virtual ~DualArrayDeque();
	int size();
	T get(int i);
	T set(int i, T x);
	virtual void add(int i, T x);
	virtual T remove(int i);
	virtual void clear();
};

template<class T> inline
T DualArrayDeque<T>::get(int i) {
	if (i < front.size()) {
		return front.get(front.size() - i - 1);
	} else {
		return back.get(i - front.size());
	}
}

template<class T> inline
T DualArrayDeque<T>::set(int i, T x) {
	if (i < front.size()) {
		return front.set(front.size() - i - 1, x);

	} else {
		return back.set(i - front.size(), x);
	}
}

template<class T>
DualArrayDeque<T>::DualArrayDeque() {
}

template<class T>
DualArrayDeque<T>::~DualArrayDeque() {
}

template<class T>
int DualArrayDeque<T>::size() {
	return front.size() + back.size();
}

template<class T>
void DualArrayDeque<T>::add(int i, T x) {
	if (i < front.size()) {
		front.add(front.size() - i, x);
	} else {
		back.add(i - front.size(), x);
	}
	balance();
}

template<class T>
T DualArrayDeque<T>::remove(int i) {
    T x;
    if (i < front.size()) {
            x = front.remove(front.size()-i-1);
    } else {
            x = back.remove(i-front.size());
    }
    balance();
    return x;
}

template<class T>
void DualArrayDeque<T>::balance() {
	if (3*front.size() < back.size()
			|| 3*back.size() < front.size()) {
		int n = front.size() + back.size();
		int nf = n/2;
		Array<T> af(std::max(2*nf, 1));
		for (int i = 0; i < nf; i++) {
			af[nf-i-1] = get(i);
		}
		int nb = n - nf;
		Array<T> ab(std::max(2*nb, 1));
		for (int i = 0; i < nb; i++) {
			ab[i] = get(nf+i);
		}
		front.a = af;
		front.n = nf;
		back.a = ab;
		back.n = nb;
	}
}

template<class T>
void DualArrayDeque<T>::clear() {
	front.clear();
	back.clear();
}


} /* namespace myds */
#endif /* DUALARRAYDEQUE_HPP_ */

