#include <string>

using namespace std;

// Returns the product of two non-negative integers, m and n,
// using only repeated addition.
int mTimesN(unsigned int m, unsigned int n);

// Returns the number of occurrences of digit in the decimal
// representation of num. digit is an int between 0 and 9
// inclusive.
//
int tallyTheDigits(int num, int digit);

// Returns the number of occurrences of digit in the decimal
// representation of num. digit is an int between 0 and 9
// inclusive.
string foursUp(string n);

// str contains a single pair of parentheses, return a new
// string made of only the parentheses and whatever those
// parentheses contain
string parentheticallySpeaking(string str);

// Return true if the total of any combination of elements in
// the array a equals the value of the target.
bool totalEclipseOfTheHeart(const int a[], int size, int target);

// returns true if the maze has a solution
bool seasonFinale(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec);

/*
* IMPLEMENTATIONS
*/

// Returns the product of two non-negative integers, m and n,
// using only repeated addition.
int mTimesN(unsigned int m, unsigned int n)
{
	if (n == 0 || m == 0) {
		return 0;
	}
	else {
		int x = m + mTimesN(m, n - 1);
		return x;
	}
}
// Returns the number of occurrences of digit in the decimal
// representation of num. digit is an int between 0 and 9
// inclusive.
//
// Pseudocode Example:
// tallyTheDigits(18838, 8) => 3
// tallyTheDigits (55555, 3) => 0
// tallyTheDigits (0, 0) => 0 or 1 (either if fine)
//
int tallyTheDigits(int num, int digit)
{
	// base cases
	if (num / 10 == 0 && num % 10 == digit)
		return 1;
	else if (num / 10 == 0)
		return 0;
	else {
		// if last digit is digit, then add 1
		if (num % 10 == digit)
			return 1 + tallyTheDigits(num / 10, digit);
		else
			return 0 + tallyTheDigits(num / 10, digit);
	}
}
// Returns a string where the same characters next each other in
// string n are separated by "44" (you can assume the input
// string will not have 4�s)
//
// Pseudocode Example:
// foursUp("goodbye") => "go44odbye"
// foursUp("yyuu") => "y44yu44u"
// foursUp("aaaa") => "a44a44a44a"
//
string foursUp(string n)
{
	// base case with only 1 character
	if (n.size() == 1)
		return n;
	string x;
	x = foursUp(n.substr(0, n.size() - 1));
	// if the last character and second to last match of current iteration of 'n' are the same, add 44 and then the rest of the string to x
	if (n.substr(n.size()-1, 1) == n.substr(n.size()-2, 1))
		x += "44" + n.substr(n.size()-1,1);
	else
		x += n.substr(n.size()-1);
	return x;
}
// str contains a single pair of parentheses, return a new
// string made of only the parentheses and whatever those
// parentheses contain
//
// Pseudocode Example:
// parentheticallySpeaking("abc(ghj)789") => "(ghj)"
// parentheticallySpeaking ("(x)7") => "(x)"
// parentheticallySpeaking ("4agh(y)") => "(y)"
// parentheticallySpeaking ("4agh()") => "()"
//
string parentheticallySpeaking(string str)
{
	if (str.size() == 0)
		return "";
	string x;
	// set x to the "rest" of the string
	x = parentheticallySpeaking(str.substr(0, str.size() - 1));
	// if x has '(', then keep adding values until ')' is found
	if (x.substr(0, 1) == "(") {
		if (x.substr(x.size() - 1, 1) == ")")
			return x;
		x += str.substr(str.size() - 1, 1);
	}
	// if '(' is found in str, then add that to x
	else if (str.substr(str.size() - 1, 1) == "(")
		x += str.substr(str.size() - 1, 1);
	
	return x;

}
// Return true if the total of any combination of elements in
// the array a equals the value of the target.
//
// Pseudocode Example:
// totalEclipseOfTheHeart([2, 4, 8], 3, 10) => true
// totalEclipseOfTheHeart ([2, 4, 8], 3, 6) => true
// totalEclipseOfTheHeart ([2, 4, 8], 3, 11) => false
// totalEclipseOfTheHeart ([2, 4, 8], 3, 0) => true
// totalEclipseOfTheHeart ([], 0, 0) => true
//
bool totalEclipseOfTheHeart(const int a[], int size, int
	target)
{
	// base cases
	if (target == 0)
		return true;
	if (size == 0)
		return false;

	// set pointer to point to start of array
	const int* arr = a;
	// recurse through every element using first element at a
	if (totalEclipseOfTheHeart(a, size - 1, target))
		return true;
	// if first element did not work, recurse using 'a+1'
	else if (totalEclipseOfTheHeart(a + 1, size - 1, target))
		return true;
	else {
		// recurse through every size and add the two values (start of 'a' and 'a' at size)
		return (*arr + *(arr + size) == target);
	}
	
}

bool seasonFinale(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec) {
	// if start location is equal to ending location
	if (sr == er && sc == ec)
		return true;

	// create variable see if maze is solvable (adjacent area is open)
	bool solved = false;

	// mark the current location as visited with '/'
	maze[sr] = maze[sr].substr(0, sc) + "/" + maze[sr].substr(sc + 1, nCols - sc);

	// check for all four sides of [sr][sc] to see if 
	// 1 - the area does not have '/' 
	// 2 - does not have '@' 
	// 3 - does not have 'X' 
	// 4 - maze is not solved yet
	if (maze[sr].substr(sc + 1, 1) != "/" && maze[sr].substr(sc + 1, 1) != "@" && maze[sr].substr(sc + 1, 1) != "X" && !solved)
		solved = seasonFinale(maze, nRows, nCols, sr, sc + 1, er, ec);
	if (maze[sr].substr(sc - 1, 1) != "/" && maze[sr].substr(sc - 1, 1) != "@" && maze[sr].substr(sc - 1, 1) != "X" && !solved)
		solved = seasonFinale(maze, nRows, nCols, sr, sc - 1, er, ec);
	if (maze[sr + 1].substr(sc, 1) != "/" && maze[sr + 1].substr(sc, 1) != "@" && maze[sr + 1].substr(sc, 1) != "X" && !solved)
		solved = seasonFinale(maze, nRows, nCols, sr + 1, sc, er, ec);
	if (maze[sr - 1].substr(sc, 1) != "/" && maze[sr - 1].substr(sc, 1) != "@" && maze[sr - 1].substr(sc, 1) != "X" && !solved)
		solved = seasonFinale(maze, nRows, nCols, sr - 1, sc, er, ec);
	return solved;
}

int main() {
	return 0;
}