/*
 * Noelle Bishop
 * 04/21/24
 * Project Three for CS-210
 */

// Program that lets the user check frequencies of grocery items listed in a file.

#include "ItemTracker.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <map>
#include <cctype>  // For capitalizing user input in PrintIndividualFrequency().

using namespace std;

ItemTracker::ItemTracker() {}

void ItemTracker::ReadFile() {  // Reads the groceries data into a map with each item as the key and its frequency as the incremented value (see the while() loop).
    ifstream inputFile;

    inputFile.open("groceries.txt");

    if (!inputFile.is_open()) {
        cout << "Unable to open input file." << endl;
        
        return;
    }

    string item;
    while (getline(inputFile, item)) {
        itemFrequencyMap[item]++;  // Using [], the value for each item's key is incremented by however many times each item is read.
    }

    inputFile.close();
    BackupFile();  // Successful completion of ReadFile() calls BackupFile(), instead of calling it from main() in Driver.cpp.
}

void ItemTracker::BackupFile() {  // Writes the map data into a .dat file to back it up.
    ofstream backupFile;

    backupFile.open("frequency.dat");

    if (!backupFile.is_open()) {
        cout << "Unable to write to output file." << endl;

        return;
    }

    for (auto& pair : itemFrequencyMap) {  // Enhanced for() loop used here and throughout for iterating through every key-value pair in the map.
        backupFile << pair.first << " " << pair.second << endl;
    }

    backupFile.close();
}

void ItemTracker::DisplayMenu() {  // Displays the menu, validates input for the user's menu choice, and calls functions based on the menu choice.
    int menuChoice = 0;

    while ((menuChoice < 1) || (menuChoice > 4)) {  // The menu choice must be valid to move on.
        cout << "-----------------------------------------------------" << endl;
        cout << "                    Corner Grocer" << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "1. Display frequency of a specific item" << endl;
        cout << "2. Display a list of all items and their frequencies" << endl;
        cout << "3. Display histogram of all items and their frequencies" << endl;
        cout << "4. Exit application" << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "Please enter your selection as a number 1 - 4: " << endl;

        try {
            cin >> menuChoice;

            if (menuChoice < 1) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                throw runtime_error("Selection cannot be less than 1.\n");
            }
            else if (menuChoice > 4) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                throw runtime_error("Selection cannot be greater than 4.\n");
            }
            else if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                throw runtime_error("Selection must be a number 1 - 4.\n");
            }
        }
        catch (const runtime_error& excpt) {
            cout << "\nError: " << excpt.what() << endl;
        }
    }

    if (menuChoice == 1) {
        PrintIndividualFrequency();
    }
    else if (menuChoice == 2) {
        PrintItemsAndFrequencies();
    }
    else if (menuChoice == 3) {
        PrintHistogram();
    }
    else if (menuChoice == 4) {
        return;  // Returns to main() in Driver.cpp for a graceful exit.
    }
}

void ItemTracker::PrintIndividualFrequency() {  // Displays the amount of times a grocery item appears in a file.
    string groceryItem;  // For reading the individual item from input and finding its frequency from the map.
    
    cout << "\n----------------------------------------------------------" << endl;
    cout << "What item are you looking for? Type it like this: Spinach" << endl;
    cout << "----------------------------------------------------------" << endl;
    cin >> groceryItem;

    if (!groceryItem.empty()) {
        groceryItem[0] = toupper(groceryItem[0]);  // This is so typing in "spinach" yields the same result as typing in "Spinach" would.
    }

    int frequency = itemFrequencyMap[groceryItem];
    cout << "\n" << groceryItem << " " << frequency << endl;

    cout << "\n" << "Press any key to continue. . ." << endl;  // Gives the user a moment to see the result before the menu is called again.
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clears the entire input string so cin.get() doesn't erroneously activate.
    cin.get();

    DisplayMenu();
}

void ItemTracker::PrintItemsAndFrequencies() {  // Displays a list of every item and its frequency from a file.
    cout << "\n----------------------------------------" << endl;
    cout << "Overall Frequency for Every Grocery Item" << endl;
    cout << "----------------------------------------" << endl;
    
    for (auto& pair : itemFrequencyMap) {
        cout << pair.first << " " << pair.second << endl;
    }

    cout << "----------------------------------------" << endl;

    cout << "\n" << "Press any key to continue. . ." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    DisplayMenu();
}

void ItemTracker::PrintHistogram() {  // Displays a histogram of every item and its frequency from a file.
    cout << "\n----------------------------------------------" << endl;
    cout << "Histogram for Every Grocery Item & Its Frequency" << endl;
    cout << "----------------------------------------------" << endl;

    for (auto& pair : itemFrequencyMap) {
        cout << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {  // Because the value of each pair is an int, it's easy to iterate through a frequency value to its end.
            cout << "*";
        }
        cout << endl;
    }

    cout << "----------------------------------------------" << endl;

    cout << "\n" << "Press any key to continue. . ." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    DisplayMenu();
}
