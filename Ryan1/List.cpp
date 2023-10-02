/********************************************************************
*** NAME       : Michael Ryan
*** CLASS      : CSc 300
*** ASSIGNMENT : 1
*** DUE DATE   : 9-25-2023
*** INSTRUCTOR : GAMRADT
*********************************************************************
*** DESCRIPTION : ADT being implemented is a single-linked-list object that
*** has a pointer value(front) being initialized to null (empty list)
*** this list can then be manipulated through the add method which adds
*** an element to the list, or the remove method which removes an element from
*** said list. The ADT can also be implemented by the view method to see
*** what elements are in the list.
********************************************************************/ 
#include <iostream>
#include "List.h"
using namespace std;

/********************************************************************
*** FUNCTION destructor (List)
*********************************************************************
*** DESCRIPTION : Creates a placeholder for the current list selected (holding element)
*** along with a placeholder for the 'next' field. Initializing both to the front value,
*** it traverses along the list while there are still values that can be removed, and
*** individualy removes each one. When every value is removed from said list, front is 
*** set back to null (empty list).
*** INPUT ARGS  : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN      :
********************************************************************/
List::~List()
{
    Node *nodePtr;             // Node has element and next in it
    Node *nextNode;

    // move through the list, deleting each node
    nodePtr = nextNode = front;
    while(nodePtr)              // while there are values other than nullptr...
    {
        // move nextNode forward
        nextNode = nodePtr->next;   // next should have value from add function

        // delete off of nodePtr
        delete nodePtr;

        // tag nodePtr up with nextNode
        nodePtr = nextNode;
    }
    front = nullptr;           // Setting now the only value, front, to null
}

/********************************************************************
*** FUNCTION copy constructor (List)
*********************************************************************
*** DESCRIPTION : Declares an 'old' placeholder object that is the original list,
*** it then checks to see if the front value of the list is null. If not, the add
*** method is implemented to 'copy' an element from the old list into the new one.
*** this goes on until the value of oldNodePtr is null, meaning that the new list object
*** has been completely copied from the old one.
*** INPUT ARGS  : when called, original list is passed through
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN      : 
********************************************************************/
List::List(const List &old)    
{
    Node *oldNodePtr;

    front = nullptr;

    oldNodePtr = old.front;

    while(oldNodePtr != nullptr)
    {
        add(oldNodePtr->element);
        oldNodePtr = oldNodePtr->next;
    }
    return;
}

/********************************************************************
*** FUNCTION add
*********************************************************************
*** DESCRIPTION : Creates placeholders(structure pointers) for a new node, nodePtr, and 
*** previous node. The new node then dynamically allocates space, and the method checks
*** if the list is empty or not. If it's not, front points at Newnode which creates a new node 
*** to the list. If it is, the list traverses using logic to find the correct position
*** INPUT ARGS  : const Element num
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN      : void
********************************************************************/
void List::add(const Element num)
{
    Node *newNode;
    Node *nodePtr;
    Node *previousNode = nullptr;

    newNode = new Node;
    // newNode = new (std::nothrow) Node;

    if(newNode == nullptr) {
        cout << "Memory allocation error" << endl;
        return;
    }
    // supposed to have an else here that carries everything else

    newNode->element = num;

    if(!front)
    {
        front = newNode;
        newNode->next = nullptr;
    }
    else
    {
        nodePtr = front;
        previousNode = nullptr;

        while(nodePtr != nullptr && nodePtr->element > num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        if(previousNode == nullptr)
        {
            front = newNode;
            newNode->next = nodePtr;
        }
        else
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}

/********************************************************************
*** FUNCTION remove
*********************************************************************
*** DESCRIPTION : Removes a node with a specified value from the linked list
*** Takes an input parameter and basically checks each node until it finds 
*** the desired element, in which case if it DOES find it, removes it from the list
*** and if it DOESN't find it provides user feedback
*** INPUT ARGS  : const Element num
*** OUTPUT ARGS : 
*** IN/OUT ARGS :
*** RETURN      : void
********************************************************************/
void List::remove(const Element num)
{
    Node *nodePtr;
    Node *previousNode;

    if(!front)
        return;

    if(front->element == num)
    {
        nodePtr = front->next;
        delete front;
        front = nodePtr;
    }
    else
    {
        nodePtr = front;

        while(nodePtr != nullptr && nodePtr->element != num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        if(nodePtr)
        {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
        else
        {
            cout << "\nThe value " << num << " does not exist in the list\n\n";
        }
    }
}

/********************************************************************
*** FUNCTION view
*********************************************************************
*** DESCRIPTION : Displays all elements of a linked list from the FRONT
*** (beginning) to the END. A pointer traverses the list, and a cout
*** operation carries out and prints the current element value of the node,
*** then it moves forward and continues until the pointer is pointing at null
*** INPUT ARGS  : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN      : void
********************************************************************/
void List::view() const
{
    Node *nodePtr;

    nodePtr = front;

    cout << "FRONT -> ";

    
    // cout << fixed << setprecision(2);

    while(nodePtr != nullptr)
    {
        cout << nodePtr->element << " -> ";

        nodePtr = nodePtr->next;
    }
    cout << "END" << endl;
}