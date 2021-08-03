#include "Node.h"

Node::Node(const Node& node) {
	val = node.val;
	next = node.next;
};

Node::Node() {
	val = 0;
	next = nullptr;
};
