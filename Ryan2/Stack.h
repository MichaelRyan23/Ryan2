/********************************************************************
*** NAME : Michael Ryan
*** CLASS : CSc 300
*** ASSIGNMENT : 2
*** DUE DATE : 10 - 6 - 2023
*** INSTRUCTOR : GAMRADT
*********************************************************************
*** DESCRIPTION : <general english description of the abstract data type> 
*** <including supporting operations>
********************************************************************/

#ifndef _STACK_H
#define _STACK_H

#include <iostream>
using namespace std;

typedef std::string Element;     // making element a string data type
typedef Element * ElementPtr;

class Stack {
    public:

        explicit Stack(int size = 2);
        Stack(Stack &old);
        ~Stack();

        void push(const Element &item);
        Element pop();
        Element peek();
        void view();

    private:

        const int STACK_SIZE;
        ElementPtr stackArray;
        int top;

};

#endif