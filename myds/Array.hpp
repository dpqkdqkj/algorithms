#ifndef ARRAY_H_
#define ARRAY_H_

#include <cstddef>  // size_t
#include <assert.h>  // assert

namespace myds {
using std::size_t;

template<class T>
class Array {
protected:
    T *data;
public:
    size_t length;

    Array();
    Array(size_t len);
    Array(size_t len, T init);
    Array(const Array<T>& other);

    const Array<T>& operator=(const Array<T>& other) {
        if (data != nullptr) delete [] data;

        length = other.length;
        data = new T[length];
        for (size_t i = 0; i < length; ++i)
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
    T& operator[](size_t i) const {
        //assert(i >= static_cast<size_t>(0) && i < length);
        assert(i >= 0 && i < length);
        return data[i];
    }

    /* Operator `+` is necessary to apply the function `std::copy` and similar. 
     */
    T* operator+(size_t i) const {
        return &data[i];
    }

    virtual ~Array();
};

template<class T>
Array<T>::Array() {
    length = 0;
    data = nullptr;
}

template<class T>
Array<T>::Array(size_t len) {
    length = len;
    data = new T[length];
}

template<class T>
Array<T>::Array(size_t len, T init) {
    length = len;
    data = new T[length];
    for (size_t i = 0; i < length; ++i)
        data[i] = init;
}
    
template<class T>
Array<T>::Array(const Array<T>& other) {
    *this = other;
}

template<class T>
Array<T>::~Array() {
    if (data != nullptr) delete [] data;
}


} /* namespace myds */
#endif /* ARRAY_H_ */

