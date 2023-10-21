#include "list.h"  // Include the header file for the List class
#include <iostream>
#include <stdexcept>

List::List() {
    size = 0;

    try {
        Node* sentinel_head = new Node(true);
        Node* sentinel_tail = new Node(true);
    } catch (const std::bad_alloc&) {
        throw std::runtime_error("Out of Memory");
    }

    sentinel_head->next = sentinel_tail;
    sentinel_tail->prev = sentinel_head;
}

List::~List() {
    Node* current = sentinel_head->next;
    while (current != sentinel_tail) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    delete sentinel_head;
    delete sentinel_tail;
}

void List::insert(int v) {
    Node* newNode = new Node(v, sentinel_tail, sentinel_tail->prev);
    sentinel_tail->prev->next = newNode;
    sentinel_tail->prev = newNode;
    size++;
}

int List::delete_tail() {
    if (size == 0) {
        throw std::runtime_error("Empty Stack");
    }

    Node* tailNode = sentinel_tail->prev;
    int tailValue = tailNode->get_value();

    sentinel_tail->prev = tailNode->prev;
    tailNode->prev->next = sentinel_tail;

    delete tailNode;
    size--;

    return tailValue;
}

int List::get_size() {
    return size;
}

Node* List::get_head() {
    return sentinel_head;
}
