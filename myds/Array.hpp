#ifndef ARRAY_H_
#define ARRAY_H_

#include <assert.h>  // assert

namespace myds {

template<class T>
class Array {
protected:
	T *data;
public:
	int length;
	Array();
	Array(int len);
	Array(int len, T init);
    Array(const Array<T>& a);

	const Array<T>& operator=(const Array<T>& other) {
		if (data != nullptr) delete [] data;
        length = other.length;
        data = new T[length];

        for (int i = 0; i < length; ++i)
            data[i] = other.data[i];

		return *this;
	}
    /* If we don't care about semantic traditions
     * we can type the following:
     *
	void operator=(const Array<T>& other) {
		if (data != nullptr) delete [] data;

        length = other.length;
        data = new T[length];
        for (int i = 0; i < length; ++i)
            data[i] = other.data[i];
	}
    */

	T& operator[](int i) {
		assert(i >= 0 && i < length);
		return data[i];
	}

	virtual ~Array();
};

template<class T>
Array<T>::Array() {
	length = 0;
	data = nullptr;
}

template<class T>
Array<T>::Array(int len) {
	length = len;
	data = new T[length];
}

template<class T>
Array<T>::Array(int len, T init) {
	length = len;
	data = new T[length];
	for (int i = 0; i < length; ++i)
		data[i] = init;
}
    
template<class T>
Array<T>::Array(const Array<T>& a) {
    *this = a;
}

template<class T>
Array<T>::~Array() {
	if (data != nullptr) delete[] data;
}

} /* namespace ods */
#endif /* ARRAY_H_ */

