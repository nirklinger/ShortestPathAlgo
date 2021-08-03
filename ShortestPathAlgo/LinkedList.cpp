#include "LinkedList.h"

void LinkedList::addToTail(Node* newTail) {
	if (isEmptyList()) {
		head = tail = newTail;
	}
	else {
		tail->next = newTail;
		tail = newTail;
	}
}

bool LinkedList::isEmptyList() {
	return head == nullptr;
}