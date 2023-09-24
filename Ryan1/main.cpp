/********************************************************************
*** NAME       : Michael Ryan
*** CLASS      : CSc 300
*** ASSIGNMENT : 1
*** DUE DATE   : 9-25-2023
*** INSTRUCTOR : GAMRADT
*********************************************************************
*** DESCRIPTION : <detailed english description of the current assignment>
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

    return 0;
}
