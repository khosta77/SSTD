#ifndef STEPANVECTOR_H
#define STEPANVECTOR_H

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <utility>
#include <exception>
#include <execution>

template<typename T>
class StepanVector {
private:
    T *_arr;
    size_t _size;

public:
    class iterator {
    private:
        T* _cur;
    public:

        iterator(T* elem) : _cur(elem) {}

        iterator& operator=(const iterator& IT) { _cur = *IT; }

        iterator operator++(int n) { return *_cur++; }
        iterator operator--(int n) { return *_cur--; }
        iterator& operator++() { return *++_cur; }
        iterator& operator--() { return *--_cur; }


        reference operator*() const { return *_cur; }

        bool operator==(iterator other) const { return _cur != other._cur; }
        bool operator!=(iterator other) const { return _cur != other._cur; }

        // Your code goes here?..

    private:
        // Your code hoes here...
    };

    // Constructor & destructor
    StepanVector() {}
//    StepanVector (const StepanVector<T> &SV) {}
//    StepanVector<T> &operator= (const StepanVector<T> &SV) {}
//    ~StepanVector() {}

    // Iterators
    iterator begin() { return _arr; }
    iterator end() { return _arr + _size; }

    // Capacity
    size_t size() const { return _size; }

    // Element access
    T &operator[] (const size_t i) noexcept { return _arr[i]; }

    T &operator[] (const size_t i) const noexcept { return _arr[i]; }

    T &at (const size_t i) {
        if (i < 0 && i > _size) {
            throw std::out_of_range("in at");
        }
        return _arr[i];
    }

    T &at (const size_t i) const {
        if (i < 0 && i > _size) {
            throw std::out_of_range("in at");
        }
        return _arr[i];
    }

    // Modifiers
//    void assign()

    void push_back(const T& val) {}

//    void pop_back();
//    void insert();
//    void erase();
//    void swap();

    void clear() {}

//    void emplace();
//    void emplace_back();


    // Allocator

    // Non-member function overloads

};


#endif // STEPANVECTOR_H
