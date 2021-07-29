#include "LinkedList.h"

LinkedList::LinkedList() {
	head = nullptr;
}

LinkedList::LinkedList(const LinkedList& rhs) {
	if (rhs.head == nullptr) {
		head = nullptr;
		return;
	}
	else {
		head = new Node;
		Node* newNode = head;
		Node* rhsHead = rhs.head;
		while (rhsHead->next != nullptr) {
			newNode->next = new Node;
			newNode->next->value = rhsHead->value;
			rhsHead = rhsHead->next;
			newNode = newNode->next;
		}
	}
	
}

LinkedList::~LinkedList() {
	Node* p;
	Node* n;
	p = head;
	while (p != nullptr) {
		n = p->next;
		delete p;
		p = n;
	}
	delete p;
}
