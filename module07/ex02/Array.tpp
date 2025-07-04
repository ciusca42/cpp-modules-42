#pragma once

#include "Array.hpp"
#include <cstdlib>
#include <iostream>

template <typename T>
Array<T>::Array() : len(0), arr(NULL) {
}

template <typename T>
Array<T>::Array(uint len) : len(len) {
    if (len == 0) {
        arr = NULL;
        return ;
    }
    arr = new T[len];
}

template <typename T>
Array<T>::~Array() {
    delete[] this->arr;
}


template <typename T>
unsigned int Array<T>::size() const {
    return this->len; // Return the size
}

template <typename T>
Array<T>::Array(const Array<T> &obj): len(obj.size()){
    if (len == 0) {
        arr = NULL;
    } else {
        arr = new T[obj.size()];
        for (uint i = 0; i < len; ++i) {
            arr[i] = obj.arr[i];
        }
    }
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &obj) {
    delete[] this->arr;
    this->arr = new T(obj.size());
    if (!this->arr)
        return *this;
    this->len = obj.size();
    for (int i = 0; i < (int)this->len; i++) {
        this->arr[i] = obj[i];
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](int i) {
    if (i >= (int)this->len) {
        throw OutOfBounds();
    }
    return this->arr[i];
}

template <typename T>
T Array<T>::operator[](int i) const {
      if (i >= (int)this->len) {
        throw OutOfBounds();
    }
    return this->arr[i];
}

template <typename T>
const char *Array<T>::OutOfBounds::what() const throw() {
    return "index is out of bound\n";
}



