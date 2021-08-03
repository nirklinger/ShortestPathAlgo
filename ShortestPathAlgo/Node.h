#ifndef NodeH
#define NodeH

class Node {
public:
    Node();
    Node(int _val, Node* _next = nullptr) : val(_val), next(_next) {};
    Node(const Node& node);    
    Node* next;
    int val;
};

#endif