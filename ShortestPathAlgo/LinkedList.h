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
    void addToTail(int newTail);
    bool deleteNode(int nodeToDelete);
    void printList();
    bool isEmptyList();
    bool search(int nodeToLookFor);
};

#endif