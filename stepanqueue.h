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
    StepanQueue();
    bool empty();
    void push(int data);
    int top();
    void pop();
    std::size_t size();
    ~StepanQueue();
};

#endif // STEPANQUEUE_H
