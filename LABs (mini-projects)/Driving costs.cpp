#include <iostream>
#include <iomanip>  // For setprecision.
using namespace std;

// Program that calculates the cost of driving set amounts of miles given miles per gallon and cost per gallon.

int main() {
	double milesPerGallon;  // Variables of type double are declared for gathering floating-point input below.
	double dollarsPerGallon;

	cin >> milesPerGallon;
	cin >> dollarsPerGallon;

	cout << fixed << setprecision(2);  // These conditions persist, so they apply to subsequent calculations.
	cout << ((20 / milesPerGallon) * dollarsPerGallon) << " ";  // 20 equals the miles driven.
	cout << ((75 / milesPerGallon) * dollarsPerGallon) << " ";
	cout << ((500 / milesPerGallon) * dollarsPerGallon) << endl;

	return 0;
}
