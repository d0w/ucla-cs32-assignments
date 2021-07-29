#include "OnlineDating.h"

#include <iostream>
using namespace std;

//
//PRIVATE FUNCTIONS
//
//
int OnlineDating::size() const {
	return m_size;
}

void OnlineDating::add(const std::string firstName, const std::string lastName,
	const OnlineType& val) {
	if (head == nullptr) {
		addFront(firstName, lastName, val);
		return;
	}
	else {
		// allocate memory for new node
		Node* p = tail;
		Node* n = new Node;
		//set new node's value to val
		n->value = val;
		n->f_name = firstName;
		n->l_name = lastName;
		// set the next node for p to be n
		n->prev = p;
		p->next = n;
		n->next = nullptr;
		// set the tail pointer to the new item in the rear
		tail = p;
		// increment size
		m_size++;
	}
}

void OnlineDating::addFront(const std::string firstName, const std::string lastName,
	const OnlineType& val) {
	//allocate new node
	Node* p = new Node;
	// put values in the node
	p->value = val;
	p->f_name = firstName;
	p->l_name = lastName;
	// link the new node to old top node
	p->next = head;
	p->prev = nullptr;
	// link the head pointer to our new top node
	head = p;

}

//
//
// PUBLIC FUNCTIONS
//
//
//
OnlineDating::OnlineDating() {
	head = nullptr;
	tail = nullptr;
	m_size = 0;
}

OnlineDating::OnlineDating(const OnlineDating& rhs) {
	if (rhs.head == nullptr) {
		head = nullptr;
		tail = nullptr;
		m_size = 0;
		return;
	}
	else {
		// allocate head to nullptr (create empty list) and pointer to old list head
		head = nullptr;
		tail = nullptr;
		Node* rhsHead = rhs.head;

		// if new list is empty, insert value to front
			// and move old lists traversing pointer to next node
		if (head == nullptr) {
			add(rhsHead->f_name, rhsHead->l_name, rhsHead->value);
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
			n->f_name = rhsHead->f_name;
			n->l_name = rhsHead->l_name;

			// set current last pointer to n
			// and set new pointer's next to nullptr
			p->next = n;
			n->next = nullptr;
			n->prev = p;

			// point the pointers to the next node of the old and new list
			rhsHead = rhsHead->next;
			p = p->next;

		}
		tail = p;
		m_size = rhs.size();
	}

}

OnlineDating& OnlineDating::operator=(const OnlineDating& rhs) {
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
	tail = nullptr;

	// add first element
	if (old != nullptr) {
		addFront(old->f_name, old->l_name, old->value);
		old = old->next;
	}
	// loop until old list end
	while (old != nullptr) {
		// insert value to front of new list
		makeMatch(old->f_name, old->l_name, old->value);
		old = old->next;
	}

	// set size of new list to old list size
	m_size = rhs.size();
	return *this;
}

OnlineDating::~OnlineDating() {
	Node* p;
	Node* n;
	p = head;

	// while the traversing pointer, p, is not nullptr (end of list)
	while (p != nullptr) {
		// allocate n to hold the next node and delete p, then reallocate p with n
		n = p->next;
		//cerr << p->f_name << " destroyed" << endl;
		delete p;
		p = n;
	}
	delete p;
}

bool OnlineDating::noMatches() const {
	if (head == nullptr) {
		return true;
	}
	return false;
}

void OnlineDating::dump() const {

	// set traversing pointer to head of list
	Node* p = head;
	cerr << "------------------" << endl;
	cerr << howManyMatches() << endl;
	// traverse until the end of the list (p = nullptr)
	while (p != nullptr) {
		// print out the value at each node and set p to the next node
		cerr << p->f_name << " " << p->l_name << "(" << p->value << ")" << " ";
		p = p->next;
	}
	cerr << endl;
	p = nullptr;

	// set traversing pointer to head of list
	Node* x = tail;

	while (x != nullptr) {
		// print out the value at each node and set p to the next node
		cerr << x->f_name << " " << x->l_name << "(" << x->value << ")" << " ";
		x = x->prev;
	}
	cerr << endl;
	cerr << "------------------" << endl;
	x = nullptr;
}

bool OnlineDating::makeMatch(const std::string& firstName, const std::string&
	lastName, const OnlineType& value) {
	Node* n = new Node;
	Node* t = nullptr;

	n->value = value;
	n->f_name = firstName;
	n->l_name = lastName;

	// if list is empty add new node to front
	if (head == nullptr) {
		head = new Node;
		n->next = nullptr;
		n->prev = nullptr;
		head = n;
		tail = n;
		m_size++;

		return true;;
	}

	if (head != nullptr) {
		t = head;
		if (t->l_name == lastName && t->f_name == firstName)
			return false;
		// check if item belongs at front of the list
		if (t->l_name.compare(lastName) > 0) {
			n->next = t;
			t->prev = n;
			n->prev = nullptr;
			head = n;
			m_size++;
			return true;;
		}
		// compare first names
		// if item belongs at front of the list
		if (t->f_name.compare(firstName) > 0 && t->l_name == lastName) {
			n->next = t;
			t->prev = n;
			n->prev = nullptr;
			head = n;
			m_size++;
			return true;
		}
		// traverse through list with t
		while (t != nullptr) {
			// if name is the same
			if (t->l_name == lastName && t->f_name == firstName) {
				return false;
			}
			// if last names match
			if (t->l_name == lastName) {
				// if reach the end of the list and need to place item right before end
				if (t->next == nullptr && t->f_name.compare(firstName) > 0) {
					n->next = t;
					n->prev = t->prev;
					t->prev = n;
					tail = t;
					m_size++;
					return true;
				}
				// if reach the end of the list and need to place item at end
				else if (t->next == nullptr && t->f_name.compare(firstName) < 0) {
					n->prev = t;
					t->next = n;
					n->next = nullptr;
					tail = n;
					m_size++;
					return true;
				}
				// if firstName goes before t at this part of the list
				else if (t->f_name.compare(firstName) > 0) {
					t->prev->next = n;
					n->next = t;
					n->prev = t->prev;
					t->prev = n;
					m_size++;
					return true;
				}
			}
			// if last names dont match up, run the same test cases for
			// first names but with last names instead
			else {
				if (t->next == nullptr && t->l_name.compare(lastName) > 0) {
					t->prev->next = n;
					n->next = t;
					n->prev = t->prev;
					t->prev = n;
					tail = t;
					m_size++;
					return true;
				}
				else if (t->next == nullptr && t->l_name.compare(lastName) < 0) {
					t->next = n;
					n->prev = t;
					n->next = nullptr;
					tail = n;
					m_size++;
					return true;
				}
				// inserting value somewhere in the middle of the list
				else if (t->l_name.compare(lastName) > 0) {
					t->prev->next = n;
					n->next = t;
					n->prev = t->prev;
					t->prev = n;
					m_size++;
					return true;
				}
			}
			t = t->next;
		}

		return false;
	}
	return false;
}

int OnlineDating::howManyMatches() const {
	return m_size;
}

bool OnlineDating::transformMatch(const string& firstName, const
	string& lastName, const OnlineType& value) {
	Node* p = head;
	// traverse through linked list with p
	while (p != nullptr) {
		if (p->f_name == firstName && p->l_name == lastName) {
			p->value = value;
			// return true if first and last name match, then change the value
			return true;
		}
		p = p->next;
	}
	return false;
}


bool OnlineDating::someoneAmongMatches(const std::string& firstName, const
	std::string& lastName) const {
	Node* p = head;
	// traverse through list with p
	while (p != nullptr) {
		if (p->f_name == firstName && p->l_name == lastName) {
			// return true if first and last name match with a list item
			return true;
		}
		p = p->next;
	}
	return false;
}


bool OnlineDating::makeOrTransform(const std::string& firstName, const
	std::string& lastName, const OnlineType& value) {
	if (someoneAmongMatches(firstName, lastName)) {
		Node* p = head;
		// if first item is correct, then adjust head's value
		if (p->f_name == firstName && p->l_name == lastName) {
			p->value = value;
			return true;
		}
		else {
			// traverse through list with p and 'p=p->next'
			while (p != nullptr) {
				// if the first and last name match, set the value of that p
				// and then break the loop
				if (p->f_name == firstName && p->l_name == lastName) {
					p->value = value;
					break;
				}
				p = p->next;
			}
			return true;
		}
	}
	else {
		// create match and return the bool value
		return makeMatch(firstName, lastName, value);
	}
}

bool OnlineDating::blockPreviousMatch(const std::string& firstName, const
	std::string& lastName) {
	if (someoneAmongMatches(firstName, lastName)) {
		Node* p = head;
		if (p->f_name == firstName && p->l_name == lastName) {
			Node* kill = head;
			head = kill->next;
			m_size--;
			delete kill;
			return true;
		}
		else {
			// traverse through list with p and 'p=p->next'
			while (p != nullptr) {
				// if the first and last name match and next is not nullptr
				if (p->next != nullptr && p->next->f_name == firstName
					&& p->next->l_name == lastName)
					break;
				p = p->next;
			}
			// if there is a value
			if (p != nullptr) {
				// link node before and after kill together
				Node* kill = p->next;
				p->next = kill->next;
				// if killing the tail
				if (kill == tail) {
					tail = p; // set tail to p (value before kill)
				}
				else
					kill->next->prev = p; // else, just linke p and kills next
				
				delete kill; // delete kill
				m_size--;
				return true;
			}
			
		}
	}
	return false;
}

bool OnlineDating::lookAtMatches(const std::string& firstName, const
	std::string& lastName, OnlineType& value) const {
	if (someoneAmongMatches(firstName, lastName)) {
		Node* p = head;
		// if first item is correct, then adjust head's value
		if (p->f_name == firstName && p->l_name == lastName) {
			value = p->value;
			return true;
		}
		else {
			// traverse through list with p and 'p=p->next'
			while (p != nullptr) {
				// if the first and last name match, set the value of that p
				// and then break the loop
				if (p->f_name == firstName && p->l_name == lastName) {
					value = p->value;
					return true;
					break;
				}
				p = p->next;
			}
			return false;
		}
	}
	else {
		// create match and return the bool value
		return false;
	}
}

bool OnlineDating::confirmMatch(int i, std::string& firstName, std::string&
	lastName, OnlineType& value) const {

	if (i >= 0 && i < howManyMatches()) {
		if (i == 0) {
			firstName = head->f_name;
			lastName = head->l_name;
			value = head->value;
			return true;
		}
		else {
			Node* p = head;
			for (int j = 0; j < i; j++) {
				p = p->next;
			}
			firstName = p->f_name;
			lastName = p->l_name;
			value = p->value;
			return true;
		}
		
	}
	return false;
}

void OnlineDating::tradeMatches(OnlineDating& other) {
	// exchanging heads
	Node* temp = other.head;
	other.head = head;
	head = temp;

	// exchanging tails
	temp = other.tail;
	other.tail = tail;
	tail = temp;

	// exchange sizes
	int t = other.m_size;
	other.m_size = m_size;
	m_size = t;
}

/*
/ NON-MEMBER FUNCTIONS
*/
bool mergeMatches(const OnlineDating& odOne, const OnlineDating& odTwo,
	OnlineDating& odJoined) {
	// create temp array, strings, and OnlineTypes
	// to hold values from odOne and odTwo
	OnlineDating temp;
	std::string one_first, one_last, two_first, two_last;
	OnlineType one_val, two_val;

	int unmatch = 0;
	// traverse odOne, take values from start to end,
	// and then make the match
	for (int i = 0; i < odOne.howManyMatches(); i++) {
		odOne.confirmMatch(i, one_first, one_last, one_val);
		temp.makeMatch(one_first, one_last, one_val);
	}
	// traverseOdTwo, take values from start to end,
	// for each element, attempt to make a match in temp
	for (int i = 0; i < odTwo.howManyMatches(); i++) {
		odTwo.confirmMatch(i, two_first, two_last, two_val);
		// if there is a duplicate nameg
		if (!temp.makeMatch(two_first, two_last, two_val)) {
			// take the value from odOne with matching name
			// taken from element i from odTwo
			odOne.lookAtMatches(two_first, two_last, one_val);
			// check if the values are the same
			// if not, remove that name from temp
			if (two_val != one_val) {
				temp.blockPreviousMatch(two_first, two_last);
				unmatch++;
			}
		}
	}


	//for (int i = 0; i < temp.howManyMatches(); i++) {
	//	temp.confirmMatch(i, one_first, one_last, one_val);
	//	for (int j = i + 1; j < temp.howManyMatches(); j++) {
	//		temp.confirmMatch(j, two_first, two_last, two_val);
	//		
	//	}
	//}
	odJoined = temp;

	if (unmatch > 0) {
		return false;
	}

	return true;

}

void authenticateMatches(const std::string& fsearch, const std::string& lsearch,
	const OnlineDating& odOne, OnlineDating& odResult) {
	// return if odOne is empty
	if (odOne.noMatches())
		return;
	else {
		OnlineDating temp;
		// create variables to store names temporarily
		string f, l;
		OnlineType val;
		// if first name input is a wildcard
		if (fsearch == "*") {
			// traverse odOne
			for (int i = 0; i < odOne.howManyMatches(); i++) {
				// set the name and value at i to 'f','l', and 'val'
				odOne.confirmMatch(i, f, l, val);
				
				// if last name at i matches lsearch, add name and values to temp
				if (lsearch == l)
					temp.makeMatch(f, l, val);
			}
		}
		// if last name input is a wildcad, search for all matching first names
		else if (lsearch == "*") {
			// traverse odOne
			for (int i = 0; i < odOne.howManyMatches(); i++) {
				// set the name and value at i to 'f','l', and 'val'
				odOne.confirmMatch(i, f, l, val);

				// if first name at i matches fsearch, add name and values to temp
				if (fsearch == f)
					temp.makeMatch(f, l, val);
			}
		}
		// if both inputs are wildcards, assign or copy construct odResult
		else if (lsearch == "*" && fsearch == "*") {
			temp = odOne;
		}
		else {
			// if looking for specific name without wildcard char
			if (odOne.someoneAmongMatches(fsearch, lsearch)) {
				for (int i = 0; i < odOne.howManyMatches(); i++) {
					// set the name and value at i to 'f','l', and 'val'
					odOne.confirmMatch(i, f, l, val);

					// if both first and last name match, add to temp
					if (fsearch == f && lsearch == l)
						temp.makeMatch(f, l, val);
				}
			}
		}
		// assign or copy odResult to be temp
		odResult = temp;
	}
}

