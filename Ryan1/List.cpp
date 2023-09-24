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

// destructor
List::~List()
{
    Node *nodePtr;
    Node *nextNode;

    // move through the list, deleting each node
    nodePtr = nextNode = front;
    while(nodePtr)
    {
        // move nextNode forward
        nextNode = nodePtr->next;

        // delete off of nodePtr
        delete nodePtr;

        // tag nodePtr up with nextNode
        nodePtr = nextNode;
    }
    front = nullptr;
}

//copy constructor
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

// insert/add function
void List::add(Element num)
{
    Node *newNode;
    Node *nodePtr;
    Node *previousNode = nullptr;

    newNode = new Node;
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

        while(nodePtr != nullptr && nodePtr->element < num)
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

// Remove Element function
void List::remove(Element num)
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
    }
}

// display nodes
void List::view() const
{
    Node *nodePtr;

    nodePtr = front;

    while(nodePtr != nullptr)
    {
        cout << nodePtr->element << endl;

        nodePtr = nodePtr->next;
    }
}