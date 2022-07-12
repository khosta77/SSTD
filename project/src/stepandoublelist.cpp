#include "../include/stepandoublelist.h"

StepanDoubleList::StepanDoubleList(){
    first = last = NULL;
    count = 0;
}

int StepanDoubleList::get_count(){
    return count;
}

bool StepanDoubleList::empty(){
    return first == NULL;
}

component_doublelist *StepanDoubleList::push(int data, component_doublelist *node = NULL){
    count++;
    if (node == NULL) {
      push_first(data);
      return first;
    }
    component_doublelist *newnode = new component_doublelist;
    newnode->data = data;
    newnode->next = node;
    newnode->preveus = node->preveus;
    node->preveus->next = newnode;
    node->preveus = newnode;
    return newnode;
}

int StepanDoubleList::get_value(component_doublelist *node){
    return node->data;
}

component_doublelist *StepanDoubleList::clear_node(component_doublelist *node){
    if (node == NULL) {
        return NULL;
    }
    count--;
    if (node == first) {
      node->preveus = NULL;
      first = node->next;
      delete node;
      return first;
    }
    if (node == last) {
      node->next = NULL;
      last = node->preveus;
      delete node;
      return last;
    }
    component_doublelist* prev = node->preveus;
    prev->next = node->next;
    delete node;
    return prev;
}

component_doublelist *StepanDoubleList::next(component_doublelist *node){
    if (empty()){
        return NULL;
    }
    return node->next;
}

component_doublelist *StepanDoubleList::previous(component_doublelist *node){
    if (empty()){
        return NULL;
    }
    return node->preveus;
}

component_doublelist *StepanDoubleList::get_first(){
    return first;
}

component_doublelist *StepanDoubleList::get_last(){
    return last;
}

void StepanDoubleList::push_first(int data){
    component_doublelist *current = new component_doublelist;
    current->data = data;
    current->preveus = NULL;
    current->next = first;
    if(first != 0){
        first->preveus = current;
    }
    if(count == 0){
        first = last = current;
    }
    else {
        first = current;
    }
    count++;
}

void StepanDoubleList::push_last(int data){
    component_doublelist *current = new component_doublelist;
    current->data = data;
    current->preveus = last;
    current->next = NULL;
    if(last != 0){
        last->next = current;
    }
    if(count == 0){
        first = last = current;
    }
    else {
        last = current;
    }
    count++;
}

void StepanDoubleList::print(bool tail){
    if (empty()) {
        std::cout << "The stepandoublelist is empty" << std::endl;
        return;
    }
    component_doublelist *current;
    if(tail){
        current = first;
        do {
            std::cout << get_value(current) << " ";
            current = next(current);
        } while (current != NULL);
    }
    else {
        current = last;
        do {
            std::cout << get_value(current) << " ";
            current = previous(current);
        } while (current != NULL);
    }
    std::cout << std::endl;
}

void StepanDoubleList::clear(){
    while (first) {
        component_doublelist *newfirst = first->next;
        delete first;
        first = newfirst;
    }
    count = 0;
    first = last = NULL;
}

StepanDoubleList::~StepanDoubleList(){
    clear();
}
