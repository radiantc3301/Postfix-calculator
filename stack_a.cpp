#include "stack_a.h"
#include <stdexcept>
#include <iostream>

using namespace std;
// Constructor
Stack_A::Stack_A() {
    size = 0;
}

void Stack_A::push(int data) {
    if(size >= 1024){
        throw std::runtime_error("Stack Full");
    }
    else{
        stk[size] = data;
        size = size + 1;
    }
}

int Stack_A::pop(){
    if(size == 0){
        throw std::runtime_error("Empty Stack");
    }else{
        size = size - 1;
        return(stk[size]);
    }
}

void Stack_A::print_stack(bool top){
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

int Stack_A::get_element_from_bottom(int idx){
    if(idx > size - 1){
        throw std::runtime_error("Index out of range");
    }
    else{
        return(stk[idx]);
    }
}

int Stack_A::get_element_from_top(int idx){
    if(idx > size - 1){
        throw std::runtime_error("Index out of range");
    }
    else{
        return(stk[size - 1 - idx]);
    }
}

int Stack_A::add() {
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

int Stack_A::subtract() {
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

int Stack_A::multiply() {
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

int Stack_A::divide() {
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

int* Stack_A::get_stack() {
    return stk;
}

int Stack_A::get_size() {
    return size;
}
