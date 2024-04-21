/*
 * If it seems like I've overexplained topics here, that's because I probably have!
 * Pointers, "new", "delete", and all the syntax have been tough for me to wrap my mind around.
 * I've watched a lot of videos to build the conceptual understanding, but this was still a
 * tough practical exercise for me.
 * "Overexplaining" with my comments here has been helpful for me to document what I've figured out
 * and why it makes sense. They'll be useful as I reference this program throughout my coursework-
 * thanks for understanding!
 */

 // Program that uses a linked list to output a list of contacts' names and phone numbers.

#include <iostream>
#include <string>

using namespace std;

class ContactNode {
private:
    string contactName, contactPhoneNumber;  // contactPhoneNumber is a string so it can seamlessly read hyphens from input.
    ContactNode* nextNodePtr;

public:
    // Constructor for name and phone number, as requested.
    ContactNode(string name, string phoneNumber) {
        contactName = name;
        contactPhoneNumber = phoneNumber;
        nextNodePtr = nullptr;
    }

    // Accessors, abbreviated on one line each because of their single body statements.
    string GetName() { return contactName; }
    string GetPhoneNumber() { return contactPhoneNumber; }
    ContactNode* GetNext() { return nextNodePtr; }

    // InsertAfter() adds a node to the linked list after the node passed as a parameter.
    void InsertAfter(ContactNode* node) {
        node->nextNodePtr = nextNodePtr;
        nextNodePtr = node;
    }

    // PrintContactNode() displays the contacts' names and numbers, to be used in main() with a loop.
    void PrintContactNode() {
        cout << "Name: " << contactName << endl;
        cout << "Phone number: " << contactPhoneNumber << endl;
    }
};

int main() {
    ContactNode* head = nullptr;  // Used to differentiate between the head and subsequent nodes in the below loop.

    for (int i = 0; i < 3; ++i) {  // Since the numbers don't matter here, it's OK for i to start at 0.
        string name, phoneNumber;  // Initialized here since contactName and contactPhoneNumber are private class members.

        getline(cin, name);
        getline(cin, phoneNumber);

        ContactNode* person = new ContactNode(name, phoneNumber);

        if (head == nullptr) {  // If the head is null, then the list hasn't started yet, so it starts here.
            head = person;
        }
        else {
            ContactNode* currentNode = head;
            while (currentNode->GetNext() != nullptr) {
                currentNode = currentNode->GetNext();
            }
            currentNode->InsertAfter(person);
        }
    }

    ContactNode* currentNode = head;  // This is to "reset" to front of the list.

    for (int i = 1; currentNode != nullptr; ++i) {  // The numbers matter here, so i starts at 1 for Person 1.
        cout << "Person " << i << ": " << currentNode->GetName() << ", " << currentNode->GetPhoneNumber() << endl;
        currentNode = currentNode->GetNext();
    }

    cout << "\nCONTACT LIST" << endl;
    currentNode = head;  // Once again "resetting" so the list output starts at the beginning.

    while (currentNode != nullptr) {  // Here and in other loops used, nullptr indicates the end of the list.
        currentNode->PrintContactNode();
        cout << endl;
        currentNode = currentNode->GetNext();
    }

    currentNode = head;  // "Resetting" or restarting at the beginning of the list for deletion below.
    while (currentNode != nullptr) {
        ContactNode* tempPtr = currentNode;  // The current spot in the list is preserved is memory using the pointer "tempPtr".
        currentNode = currentNode->GetNext();  // The next node is "grabbed" before deleting its predecessor below.
        delete tempPtr;  // Since the "new" keyword was used, it's important to free memory using "delete".
    }

    return 0;
}
