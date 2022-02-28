#ifndef STEPANLIST_H
#define STEPANLIST_H

#include <iostream>

struct component_list {
    int data;
    component_list *next;
};

class StepanList {
private:
    component_list *first;
    int count;
    component_list *previous(component_list *node);
public:
    StepanList();
    int get_count();
    bool empty();
    int get_value(component_list *node);
    component_list *get_first();
    component_list *get_last();
    void clear();
    component_list *next(component_list *node);
    component_list *push(int data, component_list *node = NULL);
    void push_first(int data);
    void push_last(int data);
    component_list *clear_node(component_list *node);
    void swap(component_list *node_1, component_list* node_2);
    void print();
    ~StepanList();
};


#endif // STEPANLIST_H
