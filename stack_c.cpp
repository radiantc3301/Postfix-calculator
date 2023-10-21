#include "stack_c.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Stack_C::Stack_C() {
    try {
        List* stk = new List(); // Try to allocate memory for a new List
    } catch (const std::bad_alloc&) {
        throw std::runtime_error("Out of Memory");
    }
}

Stack_C::~Stack_C() {
    delete stk;
}

void Stack_C::push(int data) {
    stk->insert(data);
}

int Stack_C::pop() {
    if (stk->get_size() == 0) {
        throw std::runtime_error("Empty Stack");
    }
    int poppedValue = stk->delete_tail();
    return poppedValue;
}

int Stack_C::get_element_from_top(int idx) {
    int adjustedIndex = stk->get_size() - idx - 1;

    if (adjustedIndex < 0 || adjustedIndex >= stk->get_size()) {
        throw std::runtime_error("Index out of range");
    }

    Node* nodeAtIndex = stk->get_head()->next;  // Skip the sentinel head
    for (int i = 0; i < adjustedIndex; ++i) {
        nodeAtIndex = nodeAtIndex->next;
    }

    return nodeAtIndex->get_value();
}

int Stack_C::get_element_from_bottom(int idx) {
    if (idx < 0 || idx >= stk->get_size()) {
        throw std::runtime_error("Index out of range");
    }

    Node* nodeAtIndex = stk->get_head()->next;  // Skip the sentinel head
    for (int i = 0; i < idx; ++i) {
        nodeAtIndex = nodeAtIndex->next;
    }

    return nodeAtIndex->get_value();
}

void Stack_C::print_stack(bool top_or_bottom) {
    Node* currNode = stk->get_head();
    for(int i = 0; i < stk->get_size(); i++){
        currNode->next;
    }

    Node* currentNode = top_or_bottom ? stk->get_head()->next : currNode->prev;
    Node* endNode = top_or_bottom ? currNode : stk->get_head();

    while (currentNode != endNode) {
        std::cout << currentNode->get_value() << " ";
        currentNode = top_or_bottom ? currentNode->next : currentNode->prev;
    }

    std::cout << std::endl;
}

int Stack_C::add() {
    if(stk->get_size() < 2){
        throw std::runtime_error("Not Enough Arguments");
    }
    else{
        int topValue = pop();
        int secondTopValue = pop();
        int result = secondTopValue + topValue;
        push(result);
        return result;
    }
}

int Stack_C::subtract() {
    if(stk->get_size() < 2){
        throw std::runtime_error("Not Enough Arguments");
    }
    else{
        int topValue = pop();
        int secondTopValue = pop();
        int result = secondTopValue - topValue;
        push(result);
        return result;
    }
}

int Stack_C::multiply() {
    if(stk->get_size() < 2){
        throw std::runtime_error("Not Enough Arguments");
    }
    else{
        int topValue = pop();
        int secondTopValue = pop();
        int result = secondTopValue * topValue;
        push(result);
        return result;
    }
}

int Stack_C::divide() {
    if(stk->get_size() < 2){
        throw std::runtime_error("Not Enough Arguments");
    }
    else{
        int topValue = pop();
        int secondTopValue = pop();
        if(topValue == 0){
            throw std::runtime_error("Divide by Zero Error");
        }
        else{
            int result;
            if(topValue * secondTopValue >= 0){
                result = secondTopValue / topValue;
            }
            else if(secondTopValue % topValue == 0){
                result = secondTopValue / topValue;
            }
            else{
                result = secondTopValue / topValue - 1;
            }
            push(result);
            return result;
        }
    }
}

List* Stack_C::get_stack() {
    return stk;
}

int Stack_C::get_size() {
    return stk->get_size();
}
