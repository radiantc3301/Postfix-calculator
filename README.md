# Postfix-calculator
A postfix calculator made using dynamic arrays and linked list

#Stack A

this is a fixed sized array which gas a size of 1024 elements

#Stack B

This is a dynamic sized stack which rises and shrinks its size depending on number of elements it contains

#Stack C

This is a stack is implemented using linked lists.

These are the stack operations

void push(int data)                  - Push the argument on the stack

int pop()                            - Pop and return the top element of the stack

int get_element_from_top(int idx)    - Return the element at index idx from the top

int get_element_from_bottom(int idx) - Return the element at index idx from the bottom

void print_stack(bool top)           - Print the elements of the stack, one number per line. If top = 1, start printing from the top, else bottom.

int add()                            - Pop and add the top two elements of the stack and push the result back onto the stack

int subtract()                       - Pop the top two elements from the stack. Subtract the top element from the second element and push the results back onto the stack

int multiply()                       - Pop two elements from the stack and multiply them and push the result back onto the stack

int divide()                         - Pop two elements from the stack. Divide the second from the top element by the top element of the stack. Push the floor of the result, i.e. ⌊res⌋ back onto the stack.

int* get_stack()                     - Return a pointer to the array used for the stack 

List* get_stack()                    - Return a pointer to the Linked List used for the stack 

int get_size()                       - Return the size of the stack

