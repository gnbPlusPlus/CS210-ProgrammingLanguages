#include <iostream>
#include <string>
using namespace std;

// Program that gets user input for different items' names, costs, and quantities, then outputs this information.

#include "ItemToPurchase.h"

int main() {
	// These variables are declared for reading values into input then passing them as function parameters.
	string name;
	int price;
	int quantity;

	ItemToPurchase item1;
	ItemToPurchase item2;

	cout << "Item 1" << endl;
	cout << "Enter the item name:" << endl;
	getline(cin, name);
	item1.SetName(name);

	cout << "Enter the item price:" << endl;
	cin >> price;
	item1.SetPrice(price);

	cout << "Enter the item quantity:" << endl;
	cin >> quantity;
	item1.SetQuantity(quantity);

	cin.ignore();
	cout << endl;  // Newline for better readability.

	cout << "Item 2" << endl;
	cout << "Enter the item name:" << endl;
	getline(cin, name);
	item2.SetName(name);

	cout << "Enter the item price:" << endl;
	cin >> price;
	item2.SetPrice(price);

	cout << "Enter the item quantity:" << endl;
	cin >> quantity;
	item2.SetQuantity(quantity);

	cout << endl;

	cout << "TOTAL COST" << endl;
	cout << item1.GetName() << " " << item1.GetQuantity() << " @ $" << item1.GetPrice() << " = $" << (item1.GetQuantity() * item1.GetPrice()) << endl;
	cout << item2.GetName() << " " << item2.GetQuantity() << " " << "@ $" << item2.GetPrice() << " = $" << (item2.GetQuantity() * item2.GetPrice()) << endl;
	cout << endl;
	cout << "Total: $" << (item1.GetQuantity() * item1.GetPrice()) + (item2.GetQuantity() * item2.GetPrice()) << endl;

	return 0;
}