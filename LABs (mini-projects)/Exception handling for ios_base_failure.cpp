#include <string>
#include <iostream>
#include <stdexcept>
#include <limits>  // Allows cin.ignore() to ignore the rest of a line of input rather than just 1 character.

// Program that increments the ages of people who input their one-word first names and validates input otherwise.

using namespace std;

int main() {
    string inputName;
    int age;
    // Set exception mask for cin stream
    cin.exceptions(ios::failbit);

    cin >> inputName;
    while (inputName != "-1") {
        try {
            cin >> age;  // This is the variable in question, so it's the only one tested in the try block.
        }
        catch (ios_base::failure& excpt) {
            cin.clear();
            // I looked online for a way to ignore the rest of a line (not just 1 character) and found this.
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            age = -1;  // Set to -1 here so that it outputs as 0 when incremented below.
        }
        cout << inputName << " " << (age + 1) << endl;
        cin >> inputName;
    }

    return 0;
}