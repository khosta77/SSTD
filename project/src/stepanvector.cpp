#include "../include/stepanvector.h"

StepanVector::StepanVector(){
    first = last = NULL;
    count = 0;
}

int StepanVector::get_count(){
    return count;
}

bool StepanVector::empty(){
    return first == NULL;
}

component_vector *StepanVector::push(int data, component_vector *node = NULL){
    count++;
    if (node == NULL) {
      push_first(data);
      return first;
    }
    component_vector *newnode = new component_vector;
    newnode->data = data;
    newnode->next = node;
    newnode->preveus = node->preveus;
    node->preveus->next = newnode;
    node->preveus = newnode;
    return newnode;
}

int StepanVector::get_value(component_vector *node){
    return node->data;
}

component_vector *StepanVector::clear_node(component_vector *node){
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
    component_vector* prev = node->preveus;
    prev->next = node->next;
    delete node;
    return prev;
}

component_vector *StepanVector::at(int i){
    if (i == 0){
        return first;
    }
    if (i == count - 1){
//        std::cout << count / 2;
        return last;
    }
//    return first;
    component_vector *current;
    int current_i;
    if(i <= count/2){
        current = first;
        current_i = 0;
        for(; current_i < i; current_i++){
            current = current->next;
        }
    }
    else {
        current = last;
        current_i = count - 1;
        for(; current_i > i; current_i--){
            current = current->preveus;
        }
    }
    return current;
}

component_vector *StepanVector::next(component_vector *node){
    if (empty()){
        return NULL;
    }
    return node->next;
}

component_vector *StepanVector::previous(component_vector *node){
    if (empty()){
        return NULL;
    }
    return node->preveus;
}

component_vector *StepanVector::get_first(){
    return first;
}

component_vector *StepanVector::get_last(){
    return last;
}

void StepanVector::push_first(int data){
    component_vector *current = new component_vector;
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

void StepanVector::push_last(int data){
    component_vector *current = new component_vector;
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

void StepanVector::print(bool tail){
    if (empty()) {
        std::cout << "The stepandoublelist is empty" << std::endl;
        return;
    }
    component_vector *current;
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

void StepanVector::clear(){
    while (first) {
        component_vector *newfirst = first->next;
        delete first;
        first = newfirst;
    }
    count = 0;
    first = last = NULL;
}

StepanVector::~StepanVector(){
    clear();
}
