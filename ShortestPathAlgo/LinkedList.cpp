#include "LinkedList.h"

void LinkedList::addToTail(int intToAdd) {
	Node* newTail = new Node(intToAdd);
	if (isEmptyList()) {
		head = tail = newTail;
	}
	else {
		tail->next = newTail;
		tail = newTail;
	}
}

bool LinkedList::deleteNode(int nodeToDelete)
{
	Node* index = head;
	if (head->val == nodeToDelete)
	{
		if (head->next == nullptr)
		{
			tail = nullptr;
			head = nullptr;
		}
		else
		{
			head = head->next;
		}
		delete index;
		return true;
	}
	else 
	{
		Node* prev = head;
		while ((index != nullptr) && (index->val != nodeToDelete))
		{
			prev = index;
			index = index->next;
		}
		if (index != nullptr)
		{
			prev->next = index->next;
			if (index->next == nullptr)
			{
				tail = prev;
			}
			delete index;
			return true;
		}
	}
	return false;
}

void LinkedList::printList()
{
	Node* currentNode = head;
	while (currentNode != nullptr)
	{
		cout << " " << currentNode->val;
		currentNode = currentNode->next;
	}
}

bool LinkedList::isEmptyList() 
{
	return head == nullptr;
}

bool LinkedList::search(int nodeToLookFor)
{
	Node *index = head;
	while (index != nullptr)
	{
		if (index->val == nodeToLookFor)
		{
			return true;
		}

		index = index->next;
	}
	return false;
}

void LinkedList::removeAllNodes()
{
	Node* index = head, *tmp;
	while (index != nullptr)
	{
		tmp = index;
		index = index->next;
		delete tmp;
	}
	head = tail = nullptr;
}