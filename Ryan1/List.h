#ifndef LIST_H
#define LIST_H
using namespace std;

class List {
    public:

        List();
        List( const List & );
        ~List();
        void add (const /*Element*/int x);
        void view() const;

    private:

        struct Node;
        typedef Node * NodePtr;
        struct Node {
            //Element element;
            NodePtr next;
        };
        NodePtr front;

};

#endif