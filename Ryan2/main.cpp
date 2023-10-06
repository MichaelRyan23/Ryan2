/********************************************************************
*** NAME       : Michael Ryan
*** CLASS      : CSc 300
*** ASSIGNMENT : 2
*** DUE DATE   : 10-5-2023
*** INSTRUCTOR : GAMRADT
*********************************************************************
*** DESCRIPTION : This program 
*** 
********************************************************************/             
#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
    
    Stack stack1(3);
    stack1.view();

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

    Stack copiedStack(stack1);
    copiedStack.view();

    return 0;
}
