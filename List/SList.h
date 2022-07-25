#ifndef STEPANDOUBLELIST_H
#define STEPANDOUBLELIST_H

#include <iostream>

using namespace std;

namespace sstd {

    template<typename T>
    struct list_node {
        T _M_data;
        list_node<T> *_next = NULL;
        list_node<T> *_prev = NULL;
    };

    template<typename T>
    class SList {
    protected:
        list_node<T> *_first;
        list_node<T> *_last;
        size_t _size;
    public:
//------------------------------------------------------------------------------------------------------------
        //  Member functions
        SList() {
            _first = _last = NULL;
            _size = 0;
        }

        SList(const SList<T> &other) {
            list_node<T> *_buf_node = other._first;
            _first = _last = NULL;
            _size = 0;
            for (size_t i = 0; i < other.size(); i++) {
                push_back(T(_buf_node->_M_data));
                _buf_node = _buf_node->_next;
            }
        }

        ~SList() {
            clear();
            delete _first;
            delete _last;
        }

        SList<T> &operator=(const SList<T> &other) {
            clear();
            list_node<T> *_buf_node = other._first;
            for (size_t i = 0; i < other.size(); i++) {
                push_back(T(_buf_node->_M_data));
                _buf_node = _buf_node->_next;
            };
        }

//------------------------------------------------------------------------------------------------------------
        //  Element access
        T front() {
            if (_first != NULL) {
                return _first->_M_data;
            }
            return NULL;
        }

        T front() const {
            if (_first != NULL) {
                return _first->_M_data;
            }
            return NULL;
        }

        T back() {
            if (_last != NULL) {
                return _last->_M_data;
            }
            return NULL;
        }

        T back() const {
            if (_last != NULL) {
                return _last->_M_data;
            }
            return NULL;
        }
//------------------------------------------------------------------------------------------------------------
        //  Capacity
        bool empty() const { return _first != NULL; }

        size_t size() const { return _size; }
//------------------------------------------------------------------------------------------------------------
        //  Modifiers
        void clear() {
            while (_first != NULL) {
                pop_back();
                pop_front();
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

};  // Stepan Standart Template Data

#endif // STEPANDOUBLELIST_H
