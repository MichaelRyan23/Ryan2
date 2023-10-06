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

/********************************************************************
*** FUNCTION <name of function> ***
*********************************************************************
*** DESCRIPTION : <detailed english description of the function> ***
*** INPUT ARGS : <list of all input argument names> ***
*** OUTPUT ARGS : <list of all output argument names> ***
*** IN/OUT ARGS : <list of all input/output argument names> ***
*** RETURN : <return type and return value name> ***
********************************************************************/
Stack::Stack(const int size): STACK_SIZE(size), top(-1) {

    stackArray = new (std::nothrow) Element[STACK_SIZE];

    if(stackArray == nullptr) {
        cout << "Memory allocation error" << endl;
        return;
    }
    
}

/********************************************************************
*** FUNCTION <name of function> ***
*********************************************************************
*** DESCRIPTION : <detailed english description of the function> ***
*** INPUT ARGS : <list of all input argument names> ***
*** OUTPUT ARGS : <list of all output argument names> ***
*** IN/OUT ARGS : <list of all input/output argument names> ***
*** RETURN : <return type and return value name> ***
********************************************************************/
Stack::Stack(Stack &old): STACK_SIZE(old.STACK_SIZE), top(-1) {

    Stack tempArray(STACK_SIZE);
    stackArray = new (std::nothrow) Element[STACK_SIZE];
    
    if(stackArray == nullptr) {
        cout << "Memory allocation error" << endl;
        return;
    }

    Element tempElement;

    while(old.top != -1) {
        tempElement = old.pop();
        tempArray.push(tempElement);
    }

    while(tempArray.top != -1) {
        tempElement = tempArray.pop();
        push(tempElement);
        old.push(tempElement);
    }
    
}

/********************************************************************
*** FUNCTION <name of function> ***
*********************************************************************
*** DESCRIPTION : <detailed english description of the function> ***
*** INPUT ARGS : <list of all input argument names> ***
*** OUTPUT ARGS : <list of all output argument names> ***
*** IN/OUT ARGS : <list of all input/output argument names> ***
*** RETURN : <return type and return value name> ***
********************************************************************/
Stack::~Stack() {
    while(top != -1) {
        pop();
    }
    delete[] stackArray;
}

/********************************************************************
*** FUNCTION <name of function> ***
*********************************************************************
*** DESCRIPTION : <detailed english description of the function> ***
*** INPUT ARGS : <list of all input argument names> ***
*** OUTPUT ARGS : <list of all output argument names> ***
*** IN/OUT ARGS : <list of all input/output argument names> ***
*** RETURN : <return type and return value name> ***
********************************************************************/
void Stack::push(const Element item) {
    if(top == STACK_SIZE - 1) {
        cout << "Stack Overflow! Too many values in Stack!" << endl;
        return;
    }
    else
        stackArray[++top] = item;
}

/********************************************************************
*** FUNCTION <name of function> ***
*********************************************************************
*** DESCRIPTION : <detailed english description of the function> ***
*** INPUT ARGS : <list of all input argument names> ***
*** OUTPUT ARGS : <list of all output argument names> ***
*** IN/OUT ARGS : <list of all input/output argument names> ***
*** RETURN : <return type and return value name> ***
********************************************************************/
Element Stack::pop() {
    if (top == -1) {
        cout << "Stack Underflow! Nothing to pop!" << endl;
        return "";
    }
    else
        return stackArray[top--];
}

/********************************************************************
*** FUNCTION <name of function> ***
*********************************************************************
*** DESCRIPTION : <detailed english description of the function> ***
*** INPUT ARGS : <list of all input argument names> ***
*** OUTPUT ARGS : <list of all output argument names> ***
*** IN/OUT ARGS : <list of all input/output argument names> ***
*** RETURN : <return type and return value name> ***
********************************************************************/
Element Stack::peek() {

    if (top == -1) {
        cout << "Stack Underflow! Nothing to peek at!" << endl;
        return "";
    }
    Element temp = pop();
    push(temp);
    return temp;
}

/********************************************************************
*** FUNCTION <name of function> ***
*********************************************************************
*** DESCRIPTION : <detailed english description of the function> ***
*** INPUT ARGS : <list of all input argument names> ***
*** OUTPUT ARGS : <list of all output argument names> ***
*** IN/OUT ARGS : <list of all input/output argument names> ***
*** RETURN : <return type and return value name> ***
********************************************************************/
void Stack::view() {

    if(top == -1) {
        cout << "TOP -> BOTTOM" << endl;
        return;
    }

    Stack tempStack(STACK_SIZE);

    Element tempElement;

    cout << "TOP -> ";

    while(top != -1) {
        tempElement = pop();
        cout << tempElement << " -> ";
        tempStack.push(tempElement);
    }

    cout << "BOTTOM" << endl;

    while(tempStack.top != -1) {
        tempElement = tempStack.pop();
        push(tempElement);
    }

}

