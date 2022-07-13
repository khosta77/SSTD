#ifndef STEPANVECTOR_H
#define STEPANVECTOR_H

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <utility>

template<typename T>
class StepanVector {
private:
    T *_arr;
    size_t _size{};
    size_t _capacity;

public:
    // Constructor & destructor
    StepanVector() {

    }

    StepanVector (const StepanVector<T> &SV) {

    }

    StepanVector<T> &operator= (const StepanVector<T> &SV) {

    }

    ~StepanVector() {

    }

    // Iterators


    // Capacity
    size_t size() const {
        return count;
    }

    // Element access
    T &operator[] (const size_t i) {
        return at(i);
    }

    T &operator[] (const size_t i) const {
        return at(i);
    }

    T &at (const size_t i) {
        if (i == 0){
            return first->data;
        }

        if (i == count - 1){
            return last->data;
        }

        component_vector<T> *current;
        size_t current_i;
        if(i <= count/2){
            current = first;
            current_i = 0;

            for(; current_i < i; current_i++){
                current = current->next;
            }
        } else {
            current = last;
            current_i = count - 1;

            for(; current_i > i; current_i--){
                current = current->preveus;
            }
        }

        return current->data;
    }

    T &at (const size_t i) const {
        if (i == 0){
            return first->data;
        }

        if (i == count - 1){
            return last->data;
        }

        component_vector<T> *current;
        size_t current_i;
        if(i <= count/2){
            current = first;
            current_i = 0;

            for(; current_i < i; current_i++){
                current = current->next;
            }
        } else {
            current = last;
            current_i = count - 1;

            for(; current_i > i; current_i--){
                current = current->preveus;
            }
        }

        return current->data;
    }

    // Modifiers
//    void assign()

    void push_back(const T& val) {
        component_vector<T> *current = new component_vector<T>;
        current->data{val};
        current->preveus = last;
        current->next = nullptr;

        if (last != 0){
            last->next = current;
        }

        if (count == 0){
            first = last = current;
        } else {
            last = current;
        }

        count++;
    }

//    void pop_back();
//    void insert();
//    void erase();
//    void swap();

    void clear() {
        while (first) {
            component_vector<T> *newfirst = first->next;
            delete first;
            first = newfirst;
        }

        count = 0;
        first = last = NULL;
    }

//    void emplace();
//    void emplace_back();


    // Allocator

    // Non-member function overloads

};


#endif // STEPANVECTOR_H
