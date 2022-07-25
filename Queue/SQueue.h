#ifndef STEPANQUEUE_H
#define STEPANQUEUE_H

#include <iostream>

struct component_queue {
    int data;
    component_queue *next;
};

class StepanQueue {
private:
    component_queue *first;
public:
    StepanQueue() {
        first = NULL;
    }
    bool empty() {
        return first == NULL;
    }
    void push(int data) {
        component_queue *newqueue = first;
        if(newqueue){
            while (newqueue->next) {
                newqueue = newqueue->next;
            }
            newqueue->next = new component_queue;
            newqueue = newqueue->next;
            newqueue->data = data;
            newqueue->next = NULL;
        }
        else {
            first = new component_queue;
            first->data = data;
            first->next = NULL;
        }
    }
    int top() {
        if(!empty()){
            return first->data;
        }
        return 0;
    }
    void pop() {
        if (!empty()){
            component_queue* newfirst = first->next;
            delete first;
            first = newfirst;
        }
    }
    size_t size() {
        std::size_t size = 0;
        if(!empty()){
            component_queue *current = first;
            while (current) {
                size++;
                current = current->next;
            }
        }
        return size;
    }
    ~StepanQueue() {
        while (!empty()) {
            pop();
        }
    }
};

#endif // STEPANQUEUE_H
