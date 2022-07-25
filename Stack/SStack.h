#ifndef STEPANSTACK_H
#define STEPANSTACK_H

#include <iostream>

struct component_stack {
    int data;
    component_stack *next;
};

class StepanStack {
private:
    component_stack* first;
public:
    StepanStack() {
        first = NULL;
    }
    bool empty() {
        return first == NULL;
    }
    void push(int data) {
        component_stack *newstack = new component_stack;
        newstack->data = data;
        newstack->next = first;
        first = newstack;
    }
    int top() {
        if(!empty()){
            return first->data;
        }
        return 0;
    }
    void pop() {
        if (!empty()){
            component_stack *newfirst = first->next;
            delete first;
            first = newfirst;
        }
    }
    size_t size() {
        std::size_t size = 0;
        if(!empty()){
            component_stack *current = first;
            while (current) {
                size++;
                current = current->next;
            }
        }
        return size;
    }
    ~StepanStack() {
        while (!empty()) {
            pop();
        }
    }
};

#endif // STEPANSTACK_H
