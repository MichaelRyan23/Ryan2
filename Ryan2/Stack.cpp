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
Stack::Stack(const int size): STACK_SIZE(size), top(-1) {

    stackArray = new (std::nothrow) Element[STACK_SIZE];

    if(stackArray == nullptr) {
        cout << "Memory allocation error" << endl;
        return;
    }
    
}

// Copy constructor
Stack::Stack(Stack &old): STACK_SIZE(old.STACK_SIZE), top(-1) {

    stackArray = new (std::nothrow) Element[STACK_SIZE];
    
    if(stackArray == nullptr) {
        cout << "Memory allocation error" << endl;
        return;
    }
    
    ElementPtr tempArray = new (std::nothrow) Element[STACK_SIZE];
    int tempTop = 0;

    while(old.top != 1) {
        tempArray[tempTop++] = old.pop();
    }

    for(int i = 0; i < tempTop; i++) {
        old.push(tempArray[i]);
        push(tempArray[i]);
    }

    delete[] tempArray;
}

// Destructor
Stack::~Stack() {
    while(top != -1) {
        pop();
    }
    delete[] stackArray;
}

void Stack::push(const Element item) {
    if(top == STACK_SIZE - 1) {
        cout << "Stack Overflow!" << endl;
        return;
    }
    else
        stackArray[++top] = item;
}

Element Stack::pop() {
    if (top == -1) {
        cout << "Stack Underflow! Nothing to pop!" << endl;
        return "";
    }
    else
        return stackArray[top--];
}

Element Stack::peek() {

    if (top == -1) {
        cout << "Stack Underflow!" << endl;
        return "";
    }
    Element temp = pop();
    push(temp);
    return temp;

}

void Stack::view() {

    if(top == -1) {
        cout << "TOP -> BOTTOM" << endl;
        return;
    }

    ElementPtr tempArray = new (std::nothrow) Element[STACK_SIZE];
    int tempTop = 0;

    while(top != -1) {
        tempArray[tempTop++] = pop();
    }

    cout << "TOP -> ";

    for(int i = 0; i < tempTop; i++) {
        cout << tempArray[i] << " -> ";
        push(tempArray[i]);
    }

    cout << "BOTTOM" << endl;

    delete[] tempArray;

}

