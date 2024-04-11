/*
 * Noelle Bishop
 * 04/07/24
 * Project Two for CS-210
 */

/* For the table output, I tried to get the dollar sign flush up against the right-aligned numbers, but I could not figure out how to achieve this.
 * Maybe if I converted each calculation to a string with a dollar sign before it, that could work, but the output solution I found works
 * well enough that the string conversion didn't seem necessary. Otherwise, my input validation works well except when the user enters
 * something like "$1.00" with an extra dollar sign in addition to the pre-placed one. It reads the number correctly from that, but the next output
 * looks strange. I couldn't figure out why the extra dollar sign wasn't throwing an exception like I set it up to. Also, closing the program at the end
 * takes two key presses instead of one, and I'm not sure why. I'd appreciate any advice you have for me- thanks!
 */

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Bank.h"

using namespace std;

// Program that asks the user for their initial investment, monthly deposit, interest rate, and years put into a bank, then outputs yearly totals based on this information.

Bank::Bank() {  // Default constructor
	openingAmount = 0.00;
	monthlyDeposit = 0.00;
	interestRate = 0.00;
	earnedInterest = 0.00;
	endBalance = 0.00;
	numYears = 0;
}

void Bank::PrintDataInputTitle() {  // Outputs the header for the initial section that input is gathered in.
	cout << "==============================================================" << endl;
	cout << "                          Data Input                          " << endl;
	cout << "==============================================================" << endl;
}

void Bank::GetDataInput() {  // Gathers user data from input and handles exceptions for input validation.
	// The below bools are used for separate try/throw/catch blocks so that each piece of input is validated separately.
	bool validOpeningAmount = false;
	bool validMonthlyDeposit = false;
	bool validInterestRate = false;
	bool validNumberOfYears = false;

	while (!validOpeningAmount) {
		try {
			GetOpeningAmount();

			validOpeningAmount = true;
		}
		catch (const runtime_error& excpt) {  // Catches input mismatches or input that's less than 0.
			cout << "Error: " << excpt.what() << endl;
		}
		catch (...) {  // To catch any unaccounted for errors.
			cout << "Error: Input is incorrect." << endl;
		}
	}

	while (!validMonthlyDeposit) {
		try {
			GetMonthlyDeposit();

			validMonthlyDeposit = true;
		}
		catch (const runtime_error& excpt) {
			cout << "Error: " << excpt.what() << endl;
		}
		catch (...) { 
			cout << "Error: Input is incorrect." << endl;
		}
	}

	while (!validInterestRate) {
		try {
			GetInterestRate();

			validInterestRate = true;
		}
		catch (const runtime_error& excpt) {
			cout << "Error: " << excpt.what() << endl;
		}
		catch (...) {
			cout << "Error: Input is incorrect." << endl;
		}
	}

	while (!validNumberOfYears) {
		try {
			GetNumberOfYears();

			validNumberOfYears = true;
		}
		catch (const runtime_error& excpt) {
			cout << "Error: " << excpt.what() << endl;
		}
		catch (...) { 
			cout << "Error: Input is incorrect." << endl;
		}
	}

	cout << endl;
	cout << "Press any key to continue. . ." << endl;

	cin.ignore();  // Clears the input so that cin.get() isn't immediately triggered.
	cin.get();  // Waits for a keyboard key press from the user.
}

void Bank::GetOpeningAmount() {  // Gets openingAmount from input and throws exceptions if input is invalid.
	cout << "Initial Investment Amount (ex: 1 or 1.00): $";
	cin >> openingAmount;

	if (openingAmount < 0) {
		cin.clear();
		cin.ignore();
		cout << endl;
		throw runtime_error("Initial investment can't be less than 0.");
	}
	else if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << endl;
		throw runtime_error("Input is not in XX.XX format.");
	}
}

void Bank::GetMonthlyDeposit() {  // Gets monthlyDeposit from input and throws exceptions if input is invalid.
	cout << "Monthly Deposit (ex: 50 or 50.00): $";
	cin >> monthlyDeposit;

	if (monthlyDeposit < 0) {
		cin.clear();
		cin.ignore();
		cout << endl;
		throw runtime_error("Monthly deposit can't be less than 0.");
	}
	else if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << endl;
		throw runtime_error("Input is not in XX.XX format.");
	}
}

void Bank::GetInterestRate() {  // Gets interestRate from input and throws exceptions if input is invalid.
	cout << "Annual Interest (ex: 5 or 12.5): %";
	cin >> interestRate;

	if (interestRate < 0) {
		cin.clear();
		cin.ignore();
		cout << endl;
		throw runtime_error("Annual interest can't be less than 0.");
	}
	else if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << endl;
		throw runtime_error("Input is not in XX.XX or XX format.");
	}
}

void Bank::GetNumberOfYears() {  // Gets numYears from input and throws exceptions if input is invalid.
	cout << "Number of years (ex: 7): ";
	cin >> numYears;

	if (numYears < 0) {
		cin.clear();
		cin.ignore();
		cout << endl;
		throw runtime_error("The number of years can't be less than 0.");
	}
	else if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << endl;
		throw runtime_error("Input is not a whole number.");
	}
}

void Bank::PrintTableWithoutMonthly() {  // Displays the header for the table for values without additional monthly deposits.
	cout << "==============================================================" << endl;
	cout << "   Balance and Interest Without Additional Monthly Deposits   " << endl;
	cout << "==============================================================" << endl;
	cout << " Year        Year End Balance     Year End Earned Interest    " << endl;
	cout << "--------------------------------------------------------------" << endl;
}

void Bank::CalculateWithoutMonthly() {  // Calculates user data without monthly deposits and populates the WithoutMonthly table.
	double totalBalance = openingAmount;
	
	cout << fixed << setprecision(2);

	for (int year = 1; year <= numYears; ++year) {
		earnedInterest = totalBalance * (interestRate / 100);
		endBalance = totalBalance + earnedInterest;

		// The below cout statements are split up for better readability.
		cout << setw(4) << year;
		cout << right << setw(14) << '$' << right << setw(8) << endBalance;
		cout << right << setw(18) << '$' << right << setw(6) << earnedInterest << endl;

		totalBalance = endBalance;
	}
	cout << "--------------------------------------------------------------" << endl;
}

void Bank::PrintTableWithMonthly() {  // Displays the header for the table for values with additional monthly deposits.
	cout << endl;  // Since this table comes second to the "Without Monthly" one, a newline precedes it for better readability.
	cout << "==============================================================" << endl;
	cout << "     Balance and Interest With Additional Monthly Deposits     " << endl;
	cout << "==============================================================" << endl;
	cout << " Year        Year End Balance     Year End Earned Interest     " << endl;
	cout << "--------------------------------------------------------------" << endl;
}

void Bank::CalculateWithMonthly() {  // Calculates user data with monthly deposits and populates the WithMonthly table.
	double totalBalance = openingAmount;

	cout << fixed << setprecision(2);

	for (int year = 1; year <= numYears; ++year) {
		double totalInterest = 0.00;

		for (int month = 1; month <= 12; ++month) {
			earnedInterest = ((totalBalance + monthlyDeposit) * (interestRate / 100)) / 12;

			totalBalance += monthlyDeposit + earnedInterest;
			totalInterest += earnedInterest;
		}
		
		cout << setw(4) << year;
		cout << right << setw(14) << '$' << right << setw(8) << totalBalance;
		cout << right << setw(18) << '$' << right << setw(6) << totalInterest << endl;
	}
	cout << "--------------------------------------------------------------" << endl;
	cout << endl;

	cout << "Press any key to close the program. . ." << endl;  // Since this is the last function called, it can also handle exiting the program gracefully.

	cin.ignore();
	cin.get();
}
