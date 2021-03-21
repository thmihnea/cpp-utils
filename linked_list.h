//
// Created by Mihnea on 3/21/2021.
//

#ifndef UNTITLED_LINKED_LIST_H
#define UNTITLED_LINKED_LIST_H

#include "linked_node.h"

template <typename T>
class linked_list {
private:
    linked_node<T>* front_node;
    linked_node<T>* last_node;
    size_t size = 0;
public:
    explicit linked_list() {
        this->last_node = nullptr;
        this->front_node = nullptr;
    }

    size_t get_size() {
        return this->size;
    }

    linked_node<T>* get_front() {
        return this->front_node;
    }

    linked_node<T>* get_last() {
        return this->last_node;
    }

    void add_back(T t) {
        auto* node = new linked_node<T>;
        node->set_data(t);
        if (this->last_node == nullptr) {
            this->last_node = node;
            this->front_node = node;
        } else {
            node->set_previous(this->last_node);
            this->last_node->set_next(node);
            this->last_node = node;
        }
        this->size++;
    }

    void add_front(T t) {
        auto* node = new linked_node<T>;
        node->set_data(t);
        if (this->front_node == nullptr) {
            this->last_node = node;
            this->front_node = node;
        } else {
            node->set_next(this->front_node);
            this->front_node->set_previous(node);
            this->front_node = node;
        }
        this->size++;
    }

    void add(T t, int index) {
        auto* node = new linked_node<T>;
        node->set_data(t);
        linked_node<T>* current = this->get(index);
        linked_node<T>* before = current->get_previous();
        if (current != nullptr) {
            node->set_next(current);
            current->set_previous(node);
        }
        if (before != nullptr) {
            node->set_previous(before);
            before->set_next(node);
        }
        if (index == 0) {
            this->front_node = node;
        }
        this->size++;
    }

    void remove_back() {
        if (this->size == 0) {
            throw exception("the linked list is empty, make sure there are elements inside of it first!");
        }
        linked_node<T>* last = this->last_node;
        if (this->last_node->get_previous() != nullptr) {
            this->last_node->get_previous()->set_next(nullptr);
        }
        this->last_node = this->last_node->get_previous();
        this->size--;
        delete last;
    }

    void remove_front() {
        if (this->size <= 0) {
            throw exception("the linked list is empty, make sure there are elements inside of it first!");
        }
        linked_node<T>* front = this->front_node;
        if (this->front_node->get_next() != nullptr) {
            this->front_node->get_next()->set_previous(nullptr);
        }
        this->front_node = this->front_node->get_next();
        this->size--;
        delete front;
    }

    void remove(int index) {
        linked_node<T>* node = this->get(index);
        auto* after = node->get_next();
        auto* before = node->get_previous();
        if (index == 0) {
            this->front_node = this->front_node->get_next();
        }
        if (index == this->size - 1) {
            this->last_node = this->last_node->get_previous();
        }
        if (before != nullptr) {
            before->set_next(after);
        }
        if (after != nullptr) {
            after->set_previous(before);
        }
        delete node;
        this->size--;
    }

    bool has_next() {
        return this->size != 0;
    }

    linked_node<T>* get(int index) {
        if (index > this->size - 1) {
            throw exception(&"there's no element at index " [ index]);
        }
        linked_node<T>* current = this->front_node;
        for (int i = 0; i < index; i++) {
            current = current->get_next();
        }
        return current;
    }

    T get_data(int index) {
        return this->get(index)->get_data();
    }


};


#endif //UNTITLED_LINKED_LIST_H
