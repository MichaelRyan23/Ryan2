/********************************************************************
*** NAME       : Michael Ryan
*** CLASS      : CSc 300
*** ASSIGNMENT : 2
*** DUE DATE   : 10 - 6 - s2023
*** INSTRUCTOR : GAMRADT
*********************************************************************
*** DESCRIPTION : This program implements a ADT called Stack which replicates
*** the real-world stack concept where items are placed (pushed) on top
*** and removed (popped) from the top. First in last out idea.
********************************************************************/             
#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
    
    Stack stack1(3);
    stack1.view();

    Element peek;
    Element pop;
    
    pop = stack1.pop();
    cout << pop << endl;

    stack1.push("Mike");
    stack1.view();
    stack1.pop();

    stack1.push("Class");
    stack1.push("This");
    stack1.push("I love");
    stack1.view();

    stack1.push("Guy");

    stack1.view();

    Stack cStack(stack1);
    cStack.view();

    stack1.view();

    peek = stack1.peek();
    cout << peek << endl;

    stack1.view();

    return 0;
}