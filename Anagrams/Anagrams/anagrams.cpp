#include <iostream>
#include <fstream>
#include <istream>
#include <cstring>
#include <string>
using namespace std;

const int MAXRESULTS = 20;    // Max matches that can be found
const int MAXDICTWORDS = 100; // Max words that can be read in

//
// Prototypes
//
int makeDictionary(istream& dictfile, string dict[]);

int shuffleChars(string word, const string dict[], int size,
    string results[]);

void revealOutcomes(const string results[], int size);

//
// Helper Functions
//
/*
    Helper for makeDictionary
    @param istream, string[], int
    @return number of elements added to string[]
*/
int makeHelper(istream& dictfile, string dict[], int size);

///*
//    Standard binary search
//    @param string word, const string[], int top, int bot
//    @returns index at which given word is located in dict[], otherwise returns -1 if not found
//*/
//int binarySearch(string word, const string dict[], int top, int bot);

int shuffleHelper(string word, string results[], int i, int j, const string dict[], int size);

int finder(string word, const string arr[], int size);

void bubbleswap(string& a, int i, int j, int n);

void bubblesort(string& a, int i);

void sort(string& a);

//
// Implementations
//
int finder(string word, const string arr[], int size) {
    // if value at arr equals word, return 0
    if (word == *arr)
        return 0;
    // if went through all values of arr and no answer found, return -1
    if (size == 0)
        return -1;

    // set x to number of values found
    int x = finder(word, arr + 1, size - 1);

    // if x is -1 (no value found) return -1, otherwise, add 1 to x
    if (x == -1)
        return -1;
    else {
        x++;
        return x;
    }
}

int makeDictionary(istream& dictfile, string dict[]) {
    // call to helper function with initial dict integrator of 0 (meaning we havent added anything yet to it)
    int x = makeHelper(dictfile, dict, 0);
    return x;
}

int makeHelper(istream& dictfile, string dict[], int i) {
    // if number of recursive calls equals MAXDICTWORDS (array can no longer hold more values) return 0;
    if (i == MAXDICTWORDS)
        return 0;
    // read line from txt file and read it into value of dict, if this fails (meaning no more in the file to read), return 0
    if (!(dictfile >> *dict))
        return 0;

    // recursively call function simplifying with adding size and dict to traverse to next element of dict[]
    // once all the base case is reached, add 1 to x each time the function was called
    int x = makeHelper(dictfile, dict + 1, i+1);
    x++;
    return x;
}

int shuffleChars(string word, const string dict[], int size, string results[]) {
    if (size > MAXDICTWORDS)
        return -1;
    int x = shuffleHelper(word, results, 0, 0, dict, size);
    return x;
}

int shuffleHelper(string word, string results[], int i, int j, const string dict[], int size) {
    if (j == MAXRESULTS)
        return 0;
    if (size == 0)
        return 0;
    if (dict[i] == "")
        return 0;
    string a = word;
    string b = dict[i];
    string temp = b;
    sort(a); sort(b);
    int x;
    if (a == b)
        x = shuffleHelper(word, results + 1, i + 1, j + 1, dict, size - 1);
    else {
        x = shuffleHelper(word, results, i + 1, j, dict, size - 1);
    }
    if (a == b && (finder(dict[i], results, MAXRESULTS)) == -1) { // && (finder(dict[i], results, MAXRESULTS) == -1)
        *results = temp;
        x++;
        return x;
    }
    else {
        return x;
    }
}

// sorting methods

void bubbleswap(string &a, int i, int j, int n) {

    if (j >= n)
        return;

    if (a[i] > a[j]) {
        char temp = a[j];
        a[j] = a[i];
        a[i] = temp;
    }

    bubbleswap(a, i + 1, j + 1, n);
}

void bubblesort(string &a, int i) {
    if (i == 0)
        return;

    bubbleswap(a, 0, 1, i);
    bubblesort(a, i - 1);
}

void sort(string &a) {

    int n = a.size();

    if (n <= 1)
        return;

    bubblesort(a, n);

}


int main()
{
    string results[MAXRESULTS];
    string dict[MAXDICTWORDS];
    ifstream dictfile;         // file containing the list of words
    int nwords;                // number of words read from dictionary
    string word;

    dictfile.open("words.txt");
    if (!dictfile) {
        cout << "File not found!" << endl;
        return (1);
    }
    nwords = makeDictionary(dictfile, dict);
    cout << nwords << endl;
    
    for (int i = 0; i < nwords; i++) {     //FOR TESTING PURPOSES
        cout << dict[i] << endl;
    }

    int tes = finder("tra", dict, MAXDICTWORDS);
    cout << tes << endl;

    int y = shuffleChars("Rat", dict, MAXDICTWORDS, results);
    cout << y << endl;
    cout << endl;

    for (int i = 0; i < y; i++) {     //FOR TESTING PURPOSES
        cout << results[i] << endl;
    }
    cout << finder("arT", dict, MAXDICTWORDS);

    /*cout << "Please enter a string for an anagram: ";
    cin >> word;

    int numMatches = shuffleChars(word, dict, nwords, results);
    if (!numMatches)
        cout << "No matches found" << endl;
    else
        revealOutcomes(results, numMatches);

    return 0;*/
    return 0;
}