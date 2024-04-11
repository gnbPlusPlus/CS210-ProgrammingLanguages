/*
 * Noelle Bishop
 * 04/07/24
 * Project Two for CS-210
 */

#include <iostream>
#include "Bank.h"

// The driver for Bank.cpp, using a Bank object.

int main() {  // Using a class and its functions allows main to guide the program through function calls with little to no extraneous code.
	Bank Bank;

	Bank.PrintDataInputTitle();
	Bank.GetDataInput();

	Bank.PrintTableWithoutMonthly();
	Bank.CalculateWithoutMonthly();

	Bank.PrintTableWithMonthly();
	Bank.CalculateWithMonthly();

	return 0;
}