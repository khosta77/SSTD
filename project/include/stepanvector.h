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

//    StepanVector (const StepanVector<T> &SV);
//    StepanVector<T> &operator= (const StepanVector<T> &SV);
//    ~StepanVector();

    // Iterators

    // Capacity

    // Element access
    T &operator[] (const size_t i) {
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
        }
        else {
            current = last;
            current_i = count - 1;
            for(; current_i > i; current_i--){
                current = current->preveus;
            }
        }
        return current->data;
    }
    // Modifiers
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
        }
        else {
            last = current;
        }

        count++;
    }
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
