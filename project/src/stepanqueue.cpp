#include "../include/stepanqueue.h"

StepanQueue::StepanQueue(){
    first = NULL;
}

bool StepanQueue::empty(){
    return first == NULL;
}

void StepanQueue::push(int data){
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

int StepanQueue::top(){
    if(!empty()){
        return first->data;
    }
    return 0;
}

void StepanQueue::pop(){
    if (!empty()){
        component_queue* newfirst = first->next;
        delete first;
        first = newfirst;
    }
}

std::size_t StepanQueue::size(){
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

StepanQueue::~StepanQueue(){
    while (!empty()) {
        pop();
    }
}
