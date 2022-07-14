#ifndef STEPANVECTOR_H
#define STEPANVECTOR_H

#include <iostream>
//#include <algorithm>
//#include <stdexcept>
//#include <utility>
//#include <exception>
//#include <execution>
#include <algorithm>
#include <iterator>

template<typename T>
class StepanVector {
private:
    T *_arr;
    size_t _size;

public:
//------------------------------------------------------------------------------------------------------------
    class iterator {
    private:
        T* _cur;
    public:
        iterator() {}
        iterator(T *elem) : _cur(elem) {}

        T& operator=(const iterator &IT) { _cur = IT._cur; }

        T& operator+ (size_t n) { return *(_cur + n); }
        T& operator- (size_t n) { return *(_cur - n); }

        T operator++(int n) { return *_cur++; }
        T operator--(int n) { return *_cur--; }
        T& operator++() { return *++_cur; }
        T& operator--() { return *--_cur; }


        T operator*() const { return *_cur; }

        bool operator==(iterator other) const { return _cur != other._cur; }
        bool operator!=(iterator other) const { return _cur != other._cur; }

        // Your code goes here?..

    private:
        // Your code hoes here...
    };
//------------------------------------------------------------------------------------------------------------
    // Constructor & destructor
    StepanVector() {}

    StepanVector(const size_t &n) {
        _arr = new T[n]{};
        _size = n;
    }

    StepanVector (const StepanVector<T> &SV) {
        _size = SV._size;
        _arr = new T[_size]{};

        for (size_t i = 0; i < _size; i++) {
            this->_arr[i] = *(SV._arr + i);
        }
    }

    StepanVector<T> &operator= (const StepanVector<T> &SV) {
        if (this == &SV) {
            return *this;
        }

        delete [] _arr;

        _size = SV._size;
        _arr = new T[_size]{};

        for (size_t i = 0; i < _size; i++) {
            this->_arr[i] = *(SV._arr + i);
        }

        return *this;
    }

    ~StepanVector() {
        delete [] _arr;
    }
//------------------------------------------------------------------------------------------------------------
    // Iterators
    iterator begin() { return _arr; }
    iterator end() { return _arr + _size; }
//------------------------------------------------------------------------------------------------------------
    // Capacity
    size_t size() const  noexcept { return _size; }

    size_t max_size() const noexcept { return (size_t)(-1) / sizeof(T); }  // Не могу утверждать на сколько \
    корректно это выражение

    void resize (size_t n) {
        if (n < 0) {
            throw std::out_of_range("in resize: n < 0");
        }

        StepanVector<T> new_vec(n);
        size_t const SIZE = (n < _size) ?  new_vec.size() : this->_size;

        for (size_t i = 0; i < SIZE; i++) {
            new_vec.begin() + i = *(_arr + i);
        }

        *this = new_vec;
    }

    void resize (size_t n, const T &val) {
        if (n < this->_size) {
            this->resize(this->_size + 1);
            return;
        }

        size_t i = this->_size;
        this->resize(n);
        for (;i < this->_size; i++) {
            this->_arr[i] = val;
        }
    }

//    size_t capacity() const {}  // ???

    bool empty() const noexcept { return this->_size == 0; }

//    void reserve(size_t n) { }  // ???

//    void shrink_to_fit() {}  // ???
//------------------------------------------------------------------------------------------------------------
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
//------------------------------------------------------------------------------------------------------------
    // Modifiers
//    void assign()

    void push_back(const T &val) noexcept {
        this->resize(this->_size + 1);
        this->_arr[this->_size - 1] = val;
    }

//    void pop_back();
//    void insert();
//    void erase();
//    void swap();

    void clear() noexcept { delete this->_arr; }

//    void emplace();
//    void emplace_back();

//------------------------------------------------------------------------------------------------------------
    // Allocator

//------------------------------------------------------------------------------------------------------------
    // Non-member function overloads

};


#endif // STEPANVECTOR_H
