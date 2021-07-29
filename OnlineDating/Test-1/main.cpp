//#include "OnlineDating.h"
//#include <iostream>
//#include <string>
//#include <cassert>
//
//using namespace std;
//
//void tests() {
//	OnlineDating x;
//	// empty list
//	assert(x.howManyMatches() == 0); // test for size of empty list
//	assert(x.noMatches()); // test if empty
//
//	//
//	// FILLING VALUES
//	//
//	// adding 7 values to list x
//	x.makeMatch("Derek", "Beans", "3");
//	x.makeMatch("Aue", "Cro", "4");
//	x.makeMatch("Aue", "Oij", "1");
//	x.makeMatch("Henrick", "Yro", "10");
//	x.makeMatch("Tresh", "Yro", "5");
//	x.makeMatch("Charles", "Cornell", "18");
//	x.makeMatch("Derek", "Beans", "5");
//
//	// adding 3 values to list y
//	OnlineDating y;
//	y.makeMatch("Boonanza", "Hoo", "5");
//	y.makeMatch("Aue", "Cro", "4");
//	y.makeMatch("Charles", "Cornell", "18");
//
//	// adding 2 values to list z
//	OnlineDating z;
//	z.makeMatch("Hoho", "Haha", "5");
//	z.makeMatch("OIJ", "oij", "10");
//
//	//
//	// TESTS WITH VALUES IN LIST
//	//
//	assert(mergeMatches(x, y, z)); // test to see if mergeMatches returns true with same name and same value in both OD lists
//
//	OnlineType temp; // variables to hold temp values
//	assert(x.howManyMatches() == 6); // test for 6 names (due to one duplicate name)
//	assert(!x.noMatches()); // test not empty
//	assert(!x.makeMatch("Tresh", "Yro", "6")); // test for same name
//	assert(x.makeMatch("", "", "1")); // test for empty strings
//
//	assert(!y.someoneAmongMatches("Random name", "Not in list")); // test name not in list
//	assert(y.someoneAmongMatches("Boonanza", "Hoo")); // test for someoneAmongMatches
//
//	assert(x.transformMatch("Derek", "Beans", "5")); // test if allows transform
//	x.lookAtMatches("Derek", "Beans", temp);
//	assert(temp == "5"); // test to see if transformMatch changed value and lookA5Matches works
//	assert(!x.transformMatch("Dek", "Boons", "6")); // test if not allows transform with invalid input name
//
//	assert(x.makeOrTransform("Derek", "Beans", "7")); // test for transform
//	assert(x.makeOrTransform("Ronsol", "Zeen", "101")); // test to see if added
//	assert(x.howManyMatches() == 8); // test for new additions
//
//	assert(y.blockPreviousMatch("Aue", "Cro")); // test see if removes name from list
//	assert(y.howManyMatches() == 2);
//	assert(!y.blockPreviousMatch("Not on list", "Name")); // test see for nothing to block
//
//	assert(mergeMatches(x, y, z)); // test see if returns true with Two Charles Cornells with same value
//	x.transformMatch("Charles", "Cornell", "50");
//	assert(!mergeMatches(x, y, z)); // test see if returns false with two Charles Cornells with different values
//	assert(mergeMatches(x, z, z)); // test for aliasing
//
//	// test confirm match to correctly take value from given index
//	string first, last;
//	x.confirmMatch(1, first, last, temp);
//	assert(first == "Derek" && last == "Beans" && temp == "7");
//
//	// test exchanging x and y lists
//	x.tradeMatches(y);
//	assert(x.howManyMatches() == 2);
//	assert(y.howManyMatches() == 8);
//
//	// test for authenticate matches with wildcard
//	authenticateMatches("*", "Yro", y, z);
//	assert(z.howManyMatches() == 2);
//	assert(z.someoneAmongMatches("Tresh", "Yro"));
//
//	//
//	//COPY CONSTRUCTION AND ASSIGNMENT OPERATION
//	//
//	// creating new lists for copy construction and assignment
//	OnlineDating old;
//	old.makeMatch("Here", "Now", "5");
//	old.makeMatch("Now", "Awesome", "124");
//
//	OnlineDating n;
//	n = old;
//
//	OnlineDating n2;
//	n2.makeMatch("Forever", "Away", "40");
//	old = n2;
//
//	// check for copy construction of n
//	assert(n.someoneAmongMatches("Now", "Awesome"));
//	assert(n.howManyMatches() == 2);
//
//	// check for assignment operation on old
//	assert(old.howManyMatches() == 1);
//}
//
//int main() {
//	tests();
//	cout << "Passed" << endl;
//	return 0;
//}