#ifndef STEPANDOUBLELIST_H
#define STEPANDOUBLELIST_H

#include <iostream>

using namespace std;

template<typename T>
struct list_node {
    T _M_data;
    list_node<T> *_next = NULL;
    list_node<T> *_prev = NULL;

    void next() {
        this = this->_next;
    }

    void prev() {
        this = this->_prev;
    }
};

template<typename T>
class SList {
private:
    list_node<T> *_first;
    list_node<T> *_last;
    size_t _size;
public:
    SList() {
        _first = _last = NULL;
        _size = 0;
    }

    void print() {
        list_node<T> *_buf_node = _first;
        while (_buf_node != NULL) {
            cout << _buf_node->_M_data << " ";
            _buf_node = _buf_node->_next;
        }
        cout << endl;
    }

    void rprint() {
        list_node<T> *_buf_node = _last;
        while (_buf_node != NULL) {
            cout << _buf_node->_M_data << " ";
            _buf_node = _buf_node->_prev;
        }
        cout << endl;
    }

    SList<T> &operator=(const SList<T> &other) {
        clear();
        this->_size = other._size;
        this->_first = other._first;
        this->_last = other._last;
    }

    //  Modifiers
    void clear() {
        size_t i = 0;
        while (_first != NULL ) {
            pop_back();
            pop_front();
            cout << ++i << endl;
        }
        _size = 0;
        _first = _last = NULL;
    }

//    void insert();

    void push_back(const T &value) {
        list_node<T> *new_node = new list_node<T>;
        new_node->_M_data = value;
        new_node->_prev = _last;
        new_node->_next = NULL;
        if (_last != NULL) {
            _last->_next = new_node;
        }

        if (_size == 0) {
            _first = _last = new_node;
        } else {
            _last = new_node;
        }

        _size++;
    }

    void pop_back() {
        if (_last == NULL && _first == NULL) {
            return;
        }

        if (_last == _first) {
            delete _first;
            _first = _last = NULL;
            return;
        }

        list_node<T> *del_node = _last;
        _last = del_node->_prev;
        _last->_next = NULL;
        delete del_node;

        _size--;
    }

    void push_front(const T &value) {
        list_node<T> *new_node = new list_node<T>;
        new_node->_M_data = value;
        new_node->_prev = NULL;
        new_node->_next = _first;
        if (_first != NULL) {
            _first->_prev = new_node;
        }

        if (_size == 0) {
            _first = _last = new_node;
        } else {
            _first = new_node;
        }

        _size++;
    }

    void pop_front() {
        if (_last == NULL && _first == NULL) {
            return;
        }

        if (_last == _first) {
            delete _first;
            _first = _last = NULL;
            return;
        }

        list_node<T> *del_node = _first;
        _first = del_node->_next;
        _first->_prev = NULL;
        delete del_node;

        _size--;
    }
};
//template<typename T>
//class StepanDoubleList {
//private:
//    component_doublelist<T> *first;
//    component_doublelist<T> *last;
//    int count;
//public:
//    StepanDoubleList() {
//        first = last = NULL;
//        count = 0;
//    }
//
//    int get_value(component_doublelist<T> *node) {
//        return node->data;
//    }
//
//    int get_count() {
//        return count;
//    }
//
//    bool empty() {
//        return first == NULL;
//    }
//    component_doublelist<T> *push(int data, component_doublelist<T> *node) {
//        count++;
//        if (node == NULL) {
//            push_first(data);
//            return first;
//        }
//        component_doublelist<T> *newnode = new component_doublelist<T>;
//        newnode->data = data;
//        newnode->next = node;
//        newnode->preveus = node->preveus;
//        node->preveus->next = newnode;
//        node->preveus = newnode;
//        return newnode;
//    }
//
//    component_doublelist *clear_node(component_doublelist *node) {
//        if (node == NULL) {
//            return NULL;
//        }
//        count--;
//        if (node == first) {
//            node->preveus = NULL;
//            first = node->next;
//            delete node;
//            return first;
//        }
//        if (node == last) {
//            node->next = NULL;
//            last = node->preveus;
//            delete node;
//            return last;
//        }
//        component_doublelist* prev = node->preveus;
//        prev->next = node->next;
//        delete node;
//        return prev;
//    }
//
//    component_doublelist *previous(component_doublelist *node) {
//        if (empty()){
//            return NULL;
//        }
//        return node->preveus;
//    }
//
//    component_doublelist *next(component_doublelist *node) {
//        if (empty()){
//            return NULL;
//        }
//        return node->next;
//    }
//
//    component_doublelist *get_first() {
//        return first;
//    }
//
//    component_doublelist *get_last() {
//        return last;
//    }
//
//    void print(bool tail = true) {
//        if (empty()) {
//            std::cout << "The stepandoublelist is empty" << std::endl;
//            return;
//        }
//        component_doublelist *current;
//        if(tail){
//            current = first;
//            do {
//                std::cout << get_value(current) << " ";
//                current = next(current);
//            } while (current != NULL);
//        }
//        else {
//            current = last;
//            do {
//                std::cout << get_value(current) << " ";
//                current = previous(current);
//            } while (current != NULL);
//        }
//        std::cout << std::endl;
//    }
//
//    void push_first(int data) {
//        component_doublelist *current = new component_doublelist;
//        current->data = data;
//        current->preveus = NULL;
//        current->next = first;
//        if(first != 0){
//            first->preveus = current;
//        }
//        if(count == 0){
//            first = last = current;
//        }
//        else {
//            first = current;
//        }
//        count++;
//    }
//
//    void push_last(int data) {
//        component_doublelist *current = new component_doublelist;
//        current->data = data;
//        current->preveus = last;
//        current->next = NULL;
//        if(last != 0){
//            last->next = current;
//        }
//        if(count == 0){
//            first = last = current;
//        }
//        else {
//            last = current;
//        }
//        count++;
//    }
//
//    void clear() {
//        while (first) {
//            component_doublelist *newfirst = first->next;
//            delete first;
//            first = newfirst;
//        }
//        count = 0;
//        first = last = NULL;
//    }
//
//    ~StepanDoubleList() {
//        clear();
//    }
//};

#endif // STEPANDOUBLELIST_H
