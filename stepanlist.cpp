#include "stepanlist.h"

component_list *StepanList::previous(component_list *node){
    if (empty()) {
        return NULL;
    }
    if (node == first) {
        return NULL;
    }
    component_list *current = first;
    while (current->next != node) {
        current = current->next;
    }
    return current;
}

StepanList::StepanList(){
    first = NULL;
    count = 0;
}

int StepanList::get_count(){
    return count;
}

bool StepanList::empty(){
    return first == NULL;
}

int StepanList::get_value(component_list *node){
    return node->data;
}

component_list *StepanList::get_first(){
    return first;
}

component_list *StepanList::get_last(){
    component_list *current = first;
    while (current) {
        current = current->next;
    }
    return current;
}

void StepanList::clear(){
    while (first) {
        component_list *newfirst = first->next;
        delete first;
        first = newfirst;
    }
    count = 0;
    first = NULL;
}

component_list *StepanList::next(component_list *node){
    if (empty()){
        return NULL;
    }
    return node->next;
}

component_list *StepanList::push(int data, component_list *node){
    component_list *newnode = new component_list;
    newnode->data = data;
    count++;
    if (node == NULL) {
      if (first == NULL) {
        newnode->next = NULL;
        first = newnode;
      }
      else {
        newnode->next = first;
        first = newnode;
      }
      return newnode;
    }
    newnode->next = node->next;
    node->next = newnode;
    return newnode;
}

void StepanList::push_first(int data){
    component_list *newstack = new component_list;
    newstack->data = data;
    newstack->next = first;
    first = newstack;
}

void StepanList::push_last(int data){
    component_list *newnode = first;
    if(newnode){
        while (newnode->next) {
            newnode = newnode->next;
        }
        newnode->next = new component_list;
        newnode = newnode->next;
        newnode->data = data;
        newnode->next = NULL;
    }
    else {
        first = new component_list;
        first->data = data;
        first->next = NULL;
    }
}

component_list *StepanList::clear_node(component_list *node){
    if (node == NULL) {
        return NULL;
    }
    count--;
    if (node == first) {
      first = node->next;
      delete node;
      return first;
    }
    component_list* prev = previous(node);
    prev->next = node->next;
    delete node;
    return prev;
}

void StepanList::swap(component_list *node_1, component_list *node_2){
    if (node_1 == NULL || node_2 == NULL) {
        return;
    }
    if (node_1 == node_2) {
        return;
    }
    if (node_2->next == node_1) {
        component_list *buffer = node_1;
        node_1 = node_2;
        node_2 = buffer;
    }
    component_list *prev1 = previous(node_1);
    component_list *prev2 = previous(node_2);
    component_list *next1 = next(node_1);
    component_list *next2 = next(node_2);
    if (next1 == node_2) {
        if (prev1 != NULL) {
            prev1->next = node_2;
        }
        else {
            first = node_2;
        }
        node_2->next = node_1;
        node_1->next = next2;
        return;
    }
    if (prev1 != NULL) {
        prev1->next = node_2;
    }
    else {
        first = node_2;
    }
    if (prev2 != NULL) {
        prev2->next = node_1;
    }
    else {
        first = node_1;
    }
    node_2->next = next1;
    node_1->next = next2;
}

void StepanList::print(){
    if (empty()) {
        std::cout << "The stepanList is empty" << std::endl;
        return;
    }
    component_list *current = first;
    do {
      std::cout << get_value(current) << " ";
      current = next(current);
    } while (current != NULL);
    std::cout << std::endl;
}

StepanList::~StepanList(){
    clear();
}
