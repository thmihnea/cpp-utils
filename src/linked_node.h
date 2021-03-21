//
// Created by Mihnea on 3/21/2021.
//

#ifndef UNTITLED_LINKED_NODE_H
#define UNTITLED_LINKED_NODE_H


template <typename T>
class linked_node {
private:
    T data;
    linked_node<T>* previous;
    linked_node<T>* next;
public:
    explicit linked_node() {
        this->data = nullptr;
        this->previous = nullptr;
        this->next = nullptr;
    }

    explicit linked_node(T data) {
        this->data = data;
        this->previous = nullptr;
        this->next = nullptr;
    }

    explicit linked_node(T data, linked_node<T>* next) {
        this->data = data;
        this->previous = nullptr;
        this->next = next;
    }

    explicit linked_node(T data, linked_node<T>* next, linked_node<T>* previous) {
        this->data = data;
        this->next = next;
        this->previous = previous;
    }

    T get_data() {
        return this->data;
    }

    void set_data(T t) {
        this->data = t;
    }

    linked_node<T>* get_next() {
        return this->next;
    }

    void set_next(linked_node<T>* next_node) {
        this->next = next_node;
    }

    linked_node<T>* get_previous() {
        return this->previous;
    }

    void set_previous(linked_node<T>* previous_node) {
        this->previous = previous_node;
    }
};


#endif //UNTITLED_LINKED_NODE_H
