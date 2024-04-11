#include <iostream>
#include <vector>
using namespace std;

// Program that takes a vector of integers from input, then uses bubble sorting to sort its elements from greatest to least.

void SortVector(vector<int>& myVec) {  // A pass by reference is used to refer to the original vector.
    int swapVal;  // A variable that stores a value temporary is integral for successful swapping.
    unsigned int i;
    unsigned int j;

    // These nested loops follow the bubble sort method.
    for (i = 0; i < myVec.size(); ++i) {
        // Inner loop goes to .size() - 1 because the last element will have nothing to the right to compare to.
        for (j = 0; j < myVec.size() - 1; ++j) {
            if (myVec.at(j) < myVec.at(j + 1)) {
                swapVal = myVec.at(j);  // Original value is temporarily stored.
                myVec.at(j) = myVec.at(j + 1);  // Greater value is copied to be on the left.
                myVec.at(j + 1) = swapVal;  // Original value is brought out of storage to be replaced on the right.
            }
        }
    }

    for (i = 0; i < myVec.size(); ++i) {  // This loop outputs the elements based on the assignment's specifications.
        cout << myVec.at(i) << ",";
    }

    cout << endl;

    // This is a void method, so there's no need for a return statement.
}

int main() {
    vector<int> myVec;
    int numVals;
    unsigned int i;

    cin >> numVals;
    myVec.resize(numVals);  // The first inputted int is used to establish the vector's size using .resize().

    for (i = 0; i < myVec.size(); ++i) {  // This loop populates the vector with the rest of the user's input.
        cin >> myVec.at(i);
    }

    SortVector(myVec);  // Function call with the vector as its parameter.

    return 0;
}
