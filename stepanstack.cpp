#include "stepanstack.h"
#include <iostream>

StepanStack::StepanStack(){
    first = NULL;
}

bool StepanStack::empty(){
    return first == NULL;
}

void StepanStack::push(int data){
    component_stack *newstack = new component_stack;
    newstack->data = data;
    newstack->next = first;
    first = newstack;
}

int StepanStack::top(){
    if(!empty()){
        return first->data;
    }
    return NULL;
}

void StepanStack::pop(){
    if (!empty()){
        component_stack *newfirst = first->next;
        delete first;
        first = newfirst;
    }
}

std::size_t StepanStack::size(){
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

StepanStack::~StepanStack(){
    while (!empty()) {
        pop();
    }
}
