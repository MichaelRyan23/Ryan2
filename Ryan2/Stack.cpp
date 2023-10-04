/********************************************************************
*** NAME : Michael Ryan
*** CLASS : CSc 300
*** ASSIGNMENT : 2
*** DUE DATE : 10 - 6 - 2023
*** INSTRUCTOR : GAMRADT
*********************************************************************
*** DESCRIPTION : <detailed english description of the abstract data type> 
*** <including supporting operations> 
********************************************************************/

#include <iostream>
#include "Stack.h"
using namespace std;

// default and parameterized constructor
Stack::Stack(const int size): STACK_SIZE(size) {
    stackArray = new (std::nothrow) Element[STACK_SIZE];
    
}

// Copy constructor
Stack::Stack(Stack &old): STACK_SIZE(old.STACK_SIZE), top(-1) {
    stackArray = new Element[STACK_SIZE];
    
    Stack tempStack(STACK_SIZE);
}

// Destructor
Stack::~Stack() {
    while(top != -1) {
        pop();
    }
    delete[] stackArray;
}

void Stack::push(const Element &item) {
    if(top == STACK_SIZE - 1) {
        cout << "Stack full!" << endl;
        return;
    }
    else
        stackArray[++top] = item;
}

Element Stack::pop() {
    if (top == -1) {
        cout << "Stack is empty!" << endl;
        return "";
    }
    return stackArray[top--];
}

Element Stack::peek() {

}

void Stack::view() {
    
}

