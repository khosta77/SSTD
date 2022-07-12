#ifndef STEPANVECTOR_H
#define STEPANVECTOR_H

#include <iostream>

struct component_vector {
    int data;
    component_vector *next;
    component_vector *preveus;
};

class StepanVector {
private:
    component_vector *first;
    component_vector *last;
    int count;
protected:
    component_vector *previous(component_vector *node);
    component_vector *next(component_vector *node);
    component_vector *get_first();
    component_vector *get_last();
public:
    StepanVector();
    int get_value(component_vector *node);
    int get_count();
    bool empty();
    component_vector *push(int data, component_vector *node);
    component_vector *clear_node(component_vector *node);
    component_vector *at(int i);
    void print(bool tail = true);
    void push_first(int data);
    void push_last(int data);
    void clear();
    ~StepanVector();
};


#endif // STEPANVECTOR_H
