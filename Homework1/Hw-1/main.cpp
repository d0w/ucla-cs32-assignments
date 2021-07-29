#include <iostream>
#include "LinkedList.h"
#include <cassert>
using namespace std;


int main() {
	LinkedList e1;
	e1.insertToFront("A");
	e1.insertToFront("B");
	e1.insertToFront("C");
	e1.insertToFront("D");
	LinkedList e2;
	e2.insertToFront("X");
	e2.insertToFront("Y");
	e2.insertToFront("Z");
	e1.swap(e2); // exchange contents of e1 and e2
	string s;
	assert(e1.size() == 3 && e1.get(0, s) && s == "Z");
	assert(e2.size() == 4 && e2.get(2, s) && s == "B");

	return 0;
}