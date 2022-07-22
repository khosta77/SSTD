#ifndef STEPANDOUBLELIST_H
#define STEPANDOUBLELIST_H

#include <iostream>

struct component_doublelist {
    int data;
    component_doublelist *next;
    component_doublelist *preveus;
};

class StepanDoubleList {
private:
    component_doublelist *first;
    component_doublelist *last; // fayry tail :D
    int count;
public:
    StepanDoubleList();
    int get_value(component_doublelist *node);
    int get_count();
    bool empty();
    component_doublelist *push(int data, component_doublelist *node);
    component_doublelist *clear_node(component_doublelist *node);
    component_doublelist *previous(component_doublelist *node);
    component_doublelist *next(component_doublelist *node);
    component_doublelist *get_first();
    component_doublelist *get_last();
    void print(bool tail = true);
    void push_first(int data);
    void push_last(int data);
    void clear();
    ~StepanDoubleList();
};

#endif // STEPANDOUBLELIST_H
