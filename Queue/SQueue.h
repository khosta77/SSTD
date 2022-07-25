#ifndef STEPANQUEUE_H
#define STEPANQUEUE_H

#include <iostream>

namespace sstd {

    template<typename T>
    struct queue_node {
        T data;
        queue_node<T> *next;
    };

    template<typename T>
    class SQueue {
    private:
        queue_node<T> *first;
    protected:

        void clear() {
            while (!empty()) {
                pop();
            }
        }

    public:
        SQueue() {
            first = NULL;
        }

        SQueue(const SQueue<T> &other) {
            clear();
            this = other;
        }

        ~SQueue() {
            clear();
            delete first;
        }

        SStack<T> &operator=(const SStack<T> &other) {
            clear();
            stack_node<T> *_buf_stack_node = other.first;
            for (size_t i = 0; i < other.size(); i++) {
                push(_buf_stack_node->data);
                _buf_stack_node = _buf_stack_node->next;
            }

            return *this;
        }

        bool empty() {
            return first == NULL;
        }

        void push(T data) {
            queue_node<T> *newqueue = first;
            if (newqueue) {
                while (newqueue->next) {
                    newqueue = newqueue->next;
                }
                newqueue->next = new queue_node<T>;
                newqueue = newqueue->next;
                newqueue->data = data;
                newqueue->next = NULL;
            } else {
                first = new queue_node<T>;
                first->data = data;
                first->next = NULL;
            }
        }

        int top() {
            if (!empty()) {
                return first->data;
            }
            return 0;
        }

        void pop() {
            if (!empty()) {
                queue_node<T> *newfirst = first->next;
                delete first;
                first = newfirst;
            }
        }

        size_t size() {
            size_t size = 0;
            if (!empty()) {
                queue_node<T> *current = first;
                while (current) {
                    size++;
                    current = current->next;
                }
            }
            return size;
        }
    };

};  // Stepan Standart Template Data

#endif // STEPANQUEUE_H
