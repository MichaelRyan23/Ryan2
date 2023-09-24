/********************************************************************
*** NAME       : Michael Ryan
*** CLASS      : CSc 300
*** ASSIGNMENT : 1
*** DUE DATE   : 9-25-2023
*** INSTRUCTOR : GAMRADT
*********************************************************************
*** DESCRIPTION : <general english description of the abstract data type>
***               <including supporting operations>
********************************************************************/ 
#ifndef _LIST_H
#define _LIST_H
using namespace std;

typedef float Element;

class List {
    public:

        List() {
            front = nullptr;
        }

        List( const List & );

        ~List();

        void add(const Element);
        void remove(const Element);
        void view() const;

    private:

        struct Node;
        typedef Node * NodePtr;
        struct Node {
            Element element;
            NodePtr next;
        };
        NodePtr front;

};

#endif