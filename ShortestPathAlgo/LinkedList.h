#ifndef ListH
#define ListH

#include "Node.h"

class LinkedList
{
private:
    Node* head, *tail;
public:
    LinkedList()
    {
        head = tail = nullptr;
    };
    void addToTail(Node* newTail);
    bool isEmptyList();
};

#endif