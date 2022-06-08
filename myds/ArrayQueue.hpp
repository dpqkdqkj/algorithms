#ifndef ARRAYQUEUE_HPP_
#define ARRAYQUEUE_HPP_

#include "Array.hpp"

namespace myds {

template<class T>
class ArrayQueue {
protected:
	Array<T> array;
	size_t first_idx;
	size_t aq_N;
	void resize();
public:
	ArrayQueue();
	virtual ~ArrayQueue() {};

	virtual bool add(T x);
	virtual T remove();
	inline size_t size() { return aq_N; };
};

template<class T>
ArrayQueue<T>::ArrayQueue() : array(4)
{
	aq_N = 0;
	first_idx = 0;
}

template<class T>
void ArrayQueue<T>::resize()
{
	Array<T> resized_array(std::max(static_cast<size_t>(1), 2 * aq_N));

	for (size_t k = 0; k < aq_N; ++k)
		resized_array[ k ] = array[ (first_idx + k) % array.size() ];

	array = resized_array;
	first_idx = 0;
}

template<class T>
bool ArrayQueue<T>::add(T x)
{
	if (aq_N + 1 > array.size()) resize();

	array[ (first_idx + aq_N) % array.size() ] = x;
	++aq_N;

	return true;
}

template<class T>
T ArrayQueue<T>::remove()
{
	T x = array[first_idx];
	first_idx = (first_idx + 1) % array.size();
	--aq_N;

	if (array.size() >= 3 * aq_N) resize();

	return x;
}


} /* namespace myds */
#endif /* ARRAYQUEUE_HPP_ */

