#ifndef STEPANSTACK_H
#define STEPANSTACK_H

#include <iostream>

namespace sstd {

    template<typename T>
    struct stack_node {
        T data;
        stack_node<T> *next;
    };

    template<typename T>
    class SStack {
    private:
        stack_node<T> *first;

    protected:
        void clear() {
            while (!empty()) {
                pop();
            }
        }

        void push_end(T data) {
            stack_node<T> *new_stack = first;
            if(new_stack){
                while (new_stack->next) {
                    new_stack = new_stack->next;
                }
                new_stack->next = new stack_node<T>;
                new_stack = new_stack->next;
                new_stack->data = data;
                new_stack->next = NULL;
            }
            else {
                first = new stack_node<T>;
                first->data = data;
                first->next = NULL;
            }
        }
    public:
//------------------------------------------------------------------------------------------------------------
        //  Member functions
        SStack() {
            first = NULL;
        }

        SStack(const SStack<T> &other) {
            first = NULL;
            this = other;
        }

        ~SStack() {
            clear();
            delete first;
        }

        SStack<T> &operator=(const SStack<T> &other) {
            clear();
            stack_node<T> *_buf_stack_node = other.first;
            for (size_t i = 0; i < other.size(); i++) {
                push_end(_buf_stack_node->data);
                _buf_stack_node = _buf_stack_node->next;
            }

            return *this;
        }
//------------------------------------------------------------------------------------------------------------
        //  Element access
        T top() {
            if (!empty()) {
                return first->data;
            }
            return 0;
        }
//------------------------------------------------------------------------------------------------------------
        //  Capacity
        bool empty() const {
            return first == NULL;
        }

        size_t size() const {
            size_t size = 0;
            if (!empty()) {
                stack_node<T> *current = first;
                while (current) {
                    size++;
                    current = current->next;
                }
            }
            return size;
        }
//------------------------------------------------------------------------------------------------------------
        //  Modifiers
        void push(T data) {
            stack_node<T> *new_stack = new stack_node<T>;
            new_stack->data = data;
            new_stack->next = first;
            first = new_stack;
        }

        void pop() {
            if (!empty()) {
                stack_node<T> *new_first = first->next;
                delete first;
                first = new_first;
            }
        }
    };

};  // Stepan Standart Template Data

#endif // STEPANSTACK_H
