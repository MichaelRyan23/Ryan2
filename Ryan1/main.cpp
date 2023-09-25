/********************************************************************
*** NAME       : Michael Ryan
*** CLASS      : CSc 300
*** ASSIGNMENT : 1
*** DUE DATE   : 9-25-2023
*** INSTRUCTOR : GAMRADT
*********************************************************************
*** DESCRIPTION : This program lets you create a user-defined single-linked-list
*** that can be manipulated by: an add method, which adds an element
*** to a linked list object. A remove method, which removes whatever user-defined
*** element from the linked list object.
*** You are also able to view every element in the list using the view method,
*** and you can make copies of list
********************************************************************/             
#include <iostream>
#include "List.h"
using namespace std;

int main() {

    List list1;

    cout << "List 1 before adding anything: \n";
    list1.view();

    cout << "\nAdding -2, 5, and 18.3 to list1...\n\n";
    list1.add(-2.0);
    list1.add(5.0);
    list1.add(18.3);

    cout << "List 1: \n";
    list1.view();

    cout << "\nAdding 17.38 to list1...\n\n";
    list1.add(17.38);

    cout << "List 1: \n";
    list1.view();

    cout << "\nRemoving 5 and 12 from the list\n\n";
    list1.remove(5.0);
    list1.remove(12.0);

    cout << "List 1: \n";
    list1.view();

    // Creating the copy constructor
    List list2(list1);

    cout << "\nList 1: \n";
    list1.view();

    cout << "\nList 2: \n";
    list2.view();

    return 0;
}