#pragma once

#include <iostream>

template<typename T>
class Array {
public:
    Array() {
        arr = NULL;
        size = 0;
    }

    Array( const size_t n ) {
        try {
            arr = new T[n];
            size = n;
        } catch( std::bad_alloc &e ) {
            std::cout << "coudn't allocate memory " << e.what() << std::endl;
            size = 0;
        }
    }

    Array( const Array& obj ) {
        try {
            arr = new T[obj.getSize()];
            for (size_t i = 0; i < obj.getSize(); i++) {
                arr[i] = obj.arr[i];
            }
            this->size = obj.getSize();
        } catch( std::bad_alloc &e ) {
            std::cout << "coudn't allocate memory " << e.what() << std::endl;
            this->size = 0;
        }
    }

    Array& operator =( const Array& obj ) {
        if (this != &obj) {
            try {
                T* newArr = new T[obj.getSize()];
                if (arr) delete[] arr;
                arr = newArr;
                for (size_t i = 0; i < obj.getSize(); i++ ){
                    arr[i] = obj.arr[i];
                }
                this->size = obj.getSize();
            } catch( std::bad_alloc &e ) {
                std::cout << "coudn't allocate memory " << e.what() << std::endl;
            }
        }
        return *this;
    }

    T& operator[]( const size_t idx ) const {
        if (idx >= this->size) {
            throw std::out_of_range("index out of bound");
        }
        return arr[idx];
    }

    size_t getSize( ) const {
        return this->size;
    }

    ~Array() {
        delete[] arr;
    }
private:
    T *arr;
    size_t size;
};