/********************************************************************
*** NAME        : Michael Ryan
*** CLASS       : CSc 300
*** ASSIGNMENT  : 2
*** DUE DATE    : 10 - 6 - 2023
*** INSTRUCTOR  : GAMRADT
*********************************************************************
*** DESCRIPTION : A stack is a collection of elements that implements
*** the First-in-last-out idea where the most recent element added(pushed)
*** is the first one to be removed (popped). 
********************************************************************/

#ifndef _STACK_H
#define _STACK_H

#include <iostream>
using namespace std;

typedef std::string Element;     // making element a string data type
typedef Element * ElementPtr;

class Stack {
    public:

/********************************************************************
*** FUNCTION constructor
*********************************************************************
*** DESCRIPTION : Initializes a new stack with a given or default size 
*** INPUT ARGS : size
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : 
********************************************************************/
        explicit Stack(int size = 2);

/********************************************************************
*** FUNCTION copy constructor
*********************************************************************
*** DESCRIPTION : Creates a copy of an existing stack
*** INPUT ARGS : old
*** OUTPUT ARGS : 
*** IN/OUT ARGS : old
*** RETURN : 
********************************************************************/
        Stack(Stack &old);

/********************************************************************
*** FUNCTION destructor
*********************************************************************
*** DESCRIPTION : Cleans up the stack by going popping each element out
*** and deletes (release) memory.
*** INPUT ARGS : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : 
********************************************************************/
        ~Stack();

/********************************************************************
*** FUNCTION push
*********************************************************************
*** DESCRIPTION : Adds an element to the top of the stack
*** INPUT ARGS : item
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : void
********************************************************************/
        void push(const Element item);

/********************************************************************
*** FUNCTION pop
*********************************************************************
*** DESCRIPTION : Removes and returns the top element of the stack.
*** INPUT ARGS : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : Element
********************************************************************/
        Element pop();

/********************************************************************
*** FUNCTION peek
*********************************************************************
*** DESCRIPTION : Retrieves top element from stack and pushes it back in
*** effectively returning top element.
*** INPUT ARGS : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : Element
********************************************************************/
        Element peek();

/********************************************************************
*** FUNCTION view
*********************************************************************
*** DESCRIPTION : Displays the content of the stack from top to bottom.
*** INPUT ARGS : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : void
********************************************************************/
        void view();

    private:

        const int STACK_SIZE;
        ElementPtr stackArray;
        int top;

};

#endif
