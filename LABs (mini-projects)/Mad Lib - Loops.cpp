#include <iostream>
#include <string>
using namespace std;

// Program that reads a word and number from input then puts them in a sentence, Mad Libs-style.

int main() {
    // The variables are declared but not initialized with values.
    string word;
    int num;

    // The word and number are initially read from input here.
    cin >> word;
    cin >> num;

    while (word != "quit") {  // A while loop is ideal for looping until a sentinel value ("quit") occurs.
        cout << "Eating " << num << " " << word << " a day keeps you happy and healthy." << endl;

        // The word and number are updated from within the loop. This way, the loop detects when "quit" is entered.
        cin >> word;
        cin >> num;
    }

    return 0;
}
