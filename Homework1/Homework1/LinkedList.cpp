#include "LinkedList.h"

#include <iostream>


using namespace std;

LinkedList::LinkedList() {
	// create a new empty list
	head = nullptr;
	m_size = 0;
}

LinkedList::LinkedList(const LinkedList& rhs) {
	// if list empty, set new list to emtpy as well
	if (rhs.head == nullptr) {
		head = nullptr;
		m_size = 0;
		return;
	}
	else {
		// allocate head to nullptr (create empty list) and pointer to old list head
		head = nullptr;
		Node* rhsHead = rhs.head;

		// if new list is empty, insert value to front
			// and move old lists traversing pointer to next node
		if (head == nullptr) {
			insertToFront(rhsHead->value);
			rhsHead = rhsHead->next;
		}


		// create new pointer set to head
		Node* p = head;

		// while not reaching the end of the old object and new list is not empty
		while (rhsHead != nullptr && head != nullptr) {
			// create a new next node
			Node* n = new Node;

			// set next node's value to old lists value
			n->value = rhsHead->value;

			// set current last pointer to n
			// and set new pointer's next to nullptr
			p->next = n;
			n->next = nullptr;

			// point the pointers to the next node of the old and new list
			rhsHead = rhsHead->next;
			p = p->next;
			
		}
		m_size = rhs.size();
	}


}

const LinkedList& LinkedList::operator=(const LinkedList& rhs) {
	// if assigning to itself, do nothing
	if (&rhs == this) {
		return *this;
	}

	// create traversing pointers
	Node* old = rhs.head;
	Node* r = head;

	// deallocate old list
	while (r != nullptr) {
		Node* del = r->next;
		delete r;
		r = del;
	}
	delete r;
	head = nullptr;

	// loop until old list end
	while (old != nullptr) {
		// insert value to front of new list
		insertToFront(old->value);
		old = old->next;
	}
	// reverse list since items were added to the front
	reverseList();

	// set size of new list to old list size
	m_size = rhs.size();
	return *this;
}

LinkedList::~LinkedList() {
	// create pointers to traverse the linked list
	Node* p;
	Node* n;
	p = head;

	// while the traversing pointer, p, is not nullptr (end of list)
	while (p != nullptr) {
		// allocate n to hold the next node and delete p, then reallocate p with n
		n = p->next;
		delete p;
		p = n;
	}
	delete p;
}

void LinkedList::insertToFront(const ItemType& val) {
	// allocate memory for new node
	Node* p = new Node;
	//set new node's value to val
	p->value = val;
	// set the next node for p to be the head
	p->next = head;
	// set the head pointer to the new item in the front
	head = p;
	// increment size
	m_size++;
}

void LinkedList::printList() const {
	// set traversing pointer to head of list
	Node* p = head;

	// traverse until the end of the list (p = nullptr)
	while (p != nullptr) {
		// print out the value at each node and set p to the next node
		cout << p->value << " ";
		p = p->next;
	}
	cout << endl;
}

bool LinkedList::get(int i, ItemType& item) const {
	// allocate new traversing pointer and integrator
	Node* p = head;
	int j = 0;
	
	if (i < 0) {
		return false;
	}
	// keep traversing while j < position and p != nullptr
	while (j < i && p != nullptr) {
		p = p->next;
		j++;
	}
	if (p != nullptr) {
		// if p is not nullptr, set item equal to that value
		item = p->value;
		return true;
	}
	return false;
}

void LinkedList::reverseList() {
	// if list empty, return 
	if (head == nullptr) {
		return;
	}

	Node* p = head;
	Node* prev = nullptr;
	Node* next = nullptr;

	// traverse list
	while (p != nullptr) {
		// if reach the second last value, set head equal to tha node
		next = p->next;

		// set current node to previous node
		p->next = prev;

		// set previous and current node to point to next item on list
		prev = p;
		p = next;
	}
	head = prev;

}

void LinkedList::printReverse() const {
	// if empty list, return
	if (head == nullptr) {
		return;
	}

	// create a traversing pointer and find number of elements in list
	Node* p = head;
	// to set s equal to size
	int s = size();

	// set p back to head and create integrator i
	p = head;
	int i = 0;
	// create dynamic array to hold the values of the nodes
	string* x = new string[s];
	while (p != nullptr) {
		// traverse list and set x at i to the value of p
		x[i] = p->value;

		// integrate both p and i to point to the next position
		p = p->next;
		i++;
	}


	// set integrator, i, to the size - 1 to start from end of the x array
	i = s - 1;
	// for loop backwards through array x
	for (i; i >= 0; i--) {
		cout << x[i] << " ";
	}
	cout << endl;

	// deallocate x
	delete[] x;
	x = nullptr;
}

void LinkedList::append(const LinkedList& other) {
	Node* p = head;
	Node* otherList = other.head;
	
	// if no list to append to, return 
	if (head == nullptr) {
		return;
	}
	// or no list to append, return
	else if (other.head == nullptr) {
		return;
	}
	else {
		// traverse p to point at end of current list
		while (p->next != nullptr) {
			p = p->next;
		}
		while (otherList != nullptr) {
			// allocate new pointer for new node
			Node* n = new Node;

			// set new nodes value to other lists value
			n->value = otherList->value;

			// set this lists last pointer's next to n,
			// then set n to nullptr
			p->next = n;
			n->next = nullptr;

			// move traversing pointer to the last pointer of the current
			// list
			p = n;
			otherList = otherList->next;

		}
	}
	// add other size to this size since we are appending
	m_size += other.size();
}

int LinkedList::size() const {
	return m_size;
}

void LinkedList::swap(LinkedList& other) {
	LinkedList temp = other;
	other = *this;
	*this = temp;
}

