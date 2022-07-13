#ifndef STEPANVECTOR_H
#define STEPANVECTOR_H

#include <iostream>

template<typename T>
struct component_vector {
    T data;
    component_vector<T> *next;
    component_vector<T> *preveus;
};

template<typename T>
class StepanVector {
private:
    component_vector<T> *first;
    component_vector<T> *last;
    size_t count{};

//protected:
//    component_vector<T> *previous(component_vector *node);
//    component_vector<T> *next(component_vector *node);
//    component_vector<T> *get_first();
//    component_vector<T> *get_last();

public:
    // Constructor & destructor
    StepanVector() {
        first = last = NULL;
        count = 0;
    }

    StepanVector (const StepanVector<T> &SV) {
        this->first = this->last = NULL;
        this->count = 0;


        for (size_t i = 0; i < SV.size(); i++) {
            this->push_back(SV[i]);
        }
    }

    StepanVector<T> &operator= (const StepanVector<T> &SV) {
        if (this == &SV) {
            return *this;
        }

        this->clear();

        for (size_t i = 0; i < SV.size(); i++) {
            this->push_back(SV[i]);
        }
        return *this;
    }

    ~StepanVector() {
        while (first) {
            component_vector<T> *newfirst = first->next;
            delete first;
            first = newfirst;
        }
        delete first;
    }

    // Iterators

    // Capacity
    size_t size() const {
        return this->count;
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
        current->data = val;
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



//    T &at(size_t i) {
//        if (i == 0){
//            return first->data;
//        }
//        if (i == count - 1){
//            return last->data;
//        }
//        component_vector<T> *current;
//        size_t current_i;
//        if(i <= count/2){
//            current = first;
//            current_i = 0;
//            for(; current_i < i; current_i++){
//                current = current->next;
//            }
//        }
//        else {
//            current = last;
//            current_i = count - 1;
//            for(; current_i > i; current_i--){
//                current = current->preveus;
//            }
//        }
//        return current->data;
//    }


//    ~StepanVector();
//    int get_value(component_vector *node);
//    int get_count();
//    bool empty();
//    component_vector *push(int data, component_vector *node);
//    component_vector *clear_node(component_vector *node);
//    component_vector *at(int i);
//    void print(bool tail = true);
//    void push_first(int data);
//    void push_last(int data);
//    void clear();
};


#endif // STEPANVECTOR_H
