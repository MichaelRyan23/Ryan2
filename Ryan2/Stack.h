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

/********************************************************************
*** FUNCTION <name of function> 
*********************************************************************
*** DESCRIPTION : <general english description of the function> 
*** INPUT ARGS : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : 
********************************************************************/
        explicit Stack(int size = 2);

/********************************************************************
*** FUNCTION <name of function> 
*********************************************************************
*** DESCRIPTION : <general english description of the function> 
*** INPUT ARGS : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : 
********************************************************************/
        Stack(Stack &old);

/********************************************************************
*** FUNCTION <name of function> 
*********************************************************************
*** DESCRIPTION : <general english description of the function> 
*** INPUT ARGS : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : 
********************************************************************/
        ~Stack();

/********************************************************************
*** FUNCTION <name of function> 
*********************************************************************
*** DESCRIPTION : <general english description of the function> 
*** INPUT ARGS : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : 
********************************************************************/
        void push(const Element item);

/********************************************************************
*** FUNCTION <name of function> 
*********************************************************************
*** DESCRIPTION : <general english description of the function> 
*** INPUT ARGS : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : 
********************************************************************/
        Element pop();

/********************************************************************
*** FUNCTION <name of function> 
*********************************************************************
*** DESCRIPTION : <general english description of the function> 
*** INPUT ARGS : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : 
********************************************************************/
        Element peek();

/********************************************************************
*** FUNCTION <name of function> 
*********************************************************************
*** DESCRIPTION : <general english description of the function> 
*** INPUT ARGS : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : 
********************************************************************/
        void view();

    private:

        const int STACK_SIZE;
        ElementPtr stackArray;
        int top;

};

#endif