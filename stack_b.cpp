#include "stack_b.h"
#include <stdexcept>
#include <iostream>

using namespace std;

Stack_B::Stack_B() {
    capacity = 1024;
    size = 0;
    stk = new int[capacity];
}

Stack_B::~Stack_B() {
    delete[] stk;
}

void Stack_B::push(int data) {
    if (size >= capacity) {
        int newCapacity = 2 * capacity;
        if (newCapacity < 1024) {
            newCapacity = 1024;
        }

        int* newStk = new int[newCapacity];
        for (int i = 0; i < size; i++) {
            newStk[i] = stk[i];
        }

        delete[] stk;
        stk = newStk;
        capacity = newCapacity;
        }
    stk[size] = data;
    size++;
}

int Stack_B::pop() {
    if (size == 0) {
        throw std::runtime_error("Empty Stack");
    }

    int poppedValue = stk[size - 1];
    size--;

    if (size <= capacity / 4 && capacity > 1024) {
        int newCapacity = capacity / 2;
        if (newCapacity < 1024) {
            newCapacity = 1024; // Ensure the minimum size is 1024
        }
        int* newStk = new int[newCapacity];
        for (int i = 0; i < size; i++) {
            newStk[i] = stk[i];
        }

        delete[] stk;
        stk = newStk;
        capacity = newCapacity;
    }
    return poppedValue;
}

int Stack_B::add() {
    if(size < 2){
        throw std::runtime_error("Not Enough Arguments");
    }
    else{
        int sum = stk[size - 1] + stk[size - 2];
        size = size - 1;
        stk[size- 1] = sum;
        return(sum);

    }

}

int Stack_B::subtract() {
    if(size < 2){
        throw std::runtime_error("Not Enough Arguments");
    }
    else{
        int diff = stk[size - 2] - stk[size - 1];
        size = size - 1;
        stk[size- 1] = diff;
        return(diff);
    }
}

int Stack_B::multiply() {
    if(size < 2){
        throw std::runtime_error("Not Enough Arguments");
    }
    else{
        int prodc = stk[size - 1] * stk[size - 2];
        size = size - 1;
        stk[size- 1] = prodc;
        return(prodc);
    }
}

int Stack_B::divide() {
    if(size < 2){
        throw std::runtime_error("Not Enough Arguments");
    }
    else if(stk[size - 1] == 0){
        throw std::runtime_error("Divide by Zero Error");
    }
    else{
        int divd;
        if(stk[size - 1] * stk[size - 2] >= 0){
            divd = stk[size - 2] / stk[size - 1];
        }
        else if(stk[size - 2] % stk[size - 1] == 0){
            divd = stk[size - 2] / stk[size - 1];
        }
        else{
            divd = stk[size - 2] / stk[size - 1] - 1;
        }
        size = size - 1;
        stk[size- 1] = divd;
        return(divd);
    }
}

int Stack_B::get_element_from_bottom(int idx){
    if(idx > size - 1){
        throw std::runtime_error("Index out of range");
    }
    else{
        return(stk[idx]);
    }
}

int Stack_B::get_element_from_top(int idx){
    if(idx > size - 1){
        throw std::runtime_error("Index out of range");
    }
    else{
        return(stk[size - 1 - idx]);
    }
}

int* Stack_B::get_stack() {
    return stk;
}

int Stack_B::get_size() {
    return size;
}


void Stack_B::print_stack(bool top){
    if(top == 0){
        for(int i = 0; i < size; i++){
            cout<<stk[i]<<endl;
        }
    }
    else{
        for(int i = 0; i < size; i++){
            cout<<stk[size - 1 - i]<<endl;
        }
    }
}
