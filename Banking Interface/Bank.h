#pragma once
#ifndef BANK_H
#define BANK_H

// Class that holds the variables and functions necessary for getting and manipulating user data related to investing money.

class Bank {
	private:  // Used for gathering and performing calculations on user input.
		double openingAmount, monthlyDeposit, interestRate, earnedInterest, endBalance;
		int numYears;
	public:
		Bank();  // Default constructor

		void PrintDataInputTitle();
		void PrintTableWithoutMonthly();
		void PrintTableWithMonthly();

		void GetDataInput();
		void GetOpeningAmount();
		void GetMonthlyDeposit();
		void GetInterestRate();
		void GetNumberOfYears();

		void CalculateWithoutMonthly();
		void CalculateWithMonthly();
};

#endif
