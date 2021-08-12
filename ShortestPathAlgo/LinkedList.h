/*
Thie class in charge of our linkedlist data structure used by the graph
*/

#ifndef ListH
#define ListH

#include "Node.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class LinkedList
{
private:
    Node *head, *tail;
public:
    LinkedList()
    {
        head = tail = nullptr;
    };
    ~LinkedList() { removeAllNodes(); }
    void addToTail(int newTail);
    bool deleteNode(int nodeToDelete);
    void printList();
    bool isEmptyList();
    bool search(int nodeToLookFor);
    Node* getHead() { return head; }
    void removeAllNodes();
};

#endif