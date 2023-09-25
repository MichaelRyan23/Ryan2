/********************************************************************
*** NAME       : Michael Ryan
*** CLASS      : CSc 300
*** ASSIGNMENT : 1
*** DUE DATE   : 9-25-2023
*** INSTRUCTOR : GAMRADT
*********************************************************************
*** DESCRIPTION : ADT being implemented is a single-linked-list that
*** can be manipulated through the 'add' or 'remove' methods
********************************************************************/ 
#ifndef _LIST_H
#define _LIST_H
using namespace std;

typedef float Element;          // turning Element into float data type

class List {
    public:

/********************************************************************
*** FUNCTION constructor (List)
*********************************************************************
*** DESCRIPTION : Creates an initialized empty list, front being put at null
*** INPUT ARGS  : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN      : 
********************************************************************/
        List() {
            front = nullptr;    // first pointer value going to null
        }

/********************************************************************
*** FUNCTION copy constructor (List)
*********************************************************************
*** DESCRIPTION : Creates a duplicate of an existing list using the add method
*** INPUT ARGS  : Original list
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN      : 
********************************************************************/
        List( const List & );

/********************************************************************
*** FUNCTION destructor (List)
*********************************************************************
*** DESCRIPTION : Moves through list, deleting each node as it goes
*** INPUT ARGS  : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN      : 
********************************************************************/
        ~List();

/********************************************************************
*** FUNCTION add
*********************************************************************
*** DESCRIPTION : Adds a user-provided element into a List object
*** INPUT ARGS  : const Element num
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN      : void
********************************************************************/
        void add(const Element);

/********************************************************************
*** FUNCTION remove
*********************************************************************
*** DESCRIPTION : Removes a user-provided element into a List object
*** INPUT ARGS  : const Element num
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN      : void
********************************************************************/
        void remove(const Element);

/********************************************************************
*** FUNCTION view
*********************************************************************
*** DESCRIPTION : Displays all nodes in a list object
*** INPUT ARGS  : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS :
*** RETURN      : void
********************************************************************/
        void view() const;

    private:

        struct Node;            // declaring so I can use typedef
        typedef Node * NodePtr; // turning NodePtr into a struct pointer
        struct Node {
            Element element;    // float element
            NodePtr next;       // struct Node *next
        };
        NodePtr front;          // Node *front
};

#endif