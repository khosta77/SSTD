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
    StepanStack();
    bool empty();
    void push(int data);
    int top();
    void pop();
    std::size_t size();
    ~StepanStack();
};

#endif // STEPANSTACK_H
