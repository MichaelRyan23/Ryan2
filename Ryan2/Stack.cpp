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
*** FUNCTION constructor
*********************************************************************
*** DESCRIPTION : Default and parameterized constructor. It initializes
*** an array of elements of the given size (default size 2) and sets the
*** top value to -1 which indicates an empty stack
*** INPUT ARGS : size
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN :
********************************************************************/
Stack::Stack(const int size): STACK_SIZE(size), top(-1) {

    stackArray = new (std::nothrow) Element[STACK_SIZE];

    if(stackArray == nullptr) {
        cout << "Memory allocation error" << endl;
        return;
    }
    
}

/********************************************************************
*** FUNCTION copy constructor
*********************************************************************
*** DESCRIPTION : Copy constructor creates a new stack object from an
*** already existing one. Through push and pull manipulation, the new 
*** stack will have the same order of elements as the old one.
*** INPUT ARGS : old
*** OUTPUT ARGS : 
*** IN/OUT ARGS : old (technically because it's modified?)
*** RETURN :
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
*** FUNCTION destructor
*********************************************************************
*** DESCRIPTION : Destructor de-allocates memory and ensures proper 
*** data clean up by popping all the elements from the stack and deleting
*** the allocated memory.
*** INPUT ARGS : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : 
********************************************************************/
Stack::~Stack() {
    while(top != -1) {
        pop();
    }
    delete[] stackArray;
}

/********************************************************************
*** FUNCTION push
*********************************************************************
*** DESCRIPTION : Push's job is to push a new element into the stack.
*** It checks if the stack is full, if not then the element is added
*** to the top of the stack and 'top' is incremented.
*** INPUT ARGS : item
*** OUTPUT ARGS : 
*** IN/OUT ARGS :
*** RETURN : void
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
*** FUNCTION pop
*********************************************************************
*** DESCRIPTION : Pop's job is to remove the top element from the stack.
*** It checks if the stack is empty, if not then the function returns
*** the top-most element of the stack and decrements 'top' in stack.
*** INPUT ARGS : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : Element
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
*** FUNCTION peek
*********************************************************************
*** DESCRIPTION : Peek's job is to check if the stack is empty and if it's
*** not, it pops the top element into a temporary Element value, pushes
*** it back into the stack, and returns the topmost element.
*** INPUT ARGS : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : Element
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
*** FUNCTION view
*********************************************************************
*** DESCRIPTION : View's job is to display the stack's contents from top
*** to bottom. It has a special case check to see if it's empty, then it
*** pops each element from the original stack, displaying them, and pushes
*** them into a temporary stack. The process is repeated for the temporary
*** stack back into the original stack to ensure the order stays correct.
*** INPUT ARGS : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : void
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

