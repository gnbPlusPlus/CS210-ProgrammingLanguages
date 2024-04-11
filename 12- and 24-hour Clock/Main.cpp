
 /* Although we haven't learned about classes in C++ yet, I looked ahead in zyBooks and browsed online resources to construct a Clock class here.
  * I did this because it seemed like it was suggested in the "Help with Project 1" announcement to implement a class for this assignment,
  * and I was worried I might get points taken off if I only used functions and pass by references to variables, instead. Either way, this project was
  * good practice, and I'm satisfied with what I managed to figure out. I left the comments relatively sparse so as not to state the obvious,
  * and I did not do input validation for getting user input in main() since it wasn't specified in the assignment guidelines to do so (and I struggled when I tried).
  * Lastly, I did not use the Sense tutor tool because I need to save money where I can. That being said, I used the Sense page in Module 3 to generally
  * guide my work along with the Chada Tech flowchart and requirements.
  */

#include "Clock.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Program that asks the user for the current time, gives the user 3 options to increment the time with, and displays the time in both 12- and 24-hour formats.

// Initializes the Clock class and gives more readable names to its variables for use throughout this file (e.g., h12 becomes hour12).
Clock::Clock(int h12, int h24, int m, int s, string aP) : hour12(h12), hour24(h24), min(m), sec(s), amPm(aP) {}

// Displays the menu of options for the user to choose from when getMenuChoice() is called.
void Clock::printMenu() {
	cout << "**************************" << endl;
	cout << "* 1 - Add One Hour       *" << endl;
	cout << "* 2 - Add One Minute     *" << endl;
	cout << "* 3 - Add One Second     *" << endl;
	cout << "* 4 - Exit Program       *" << endl;
	cout << "**************************" << endl;
}

// Displays the time in 12-hour format with AM or PM at the end (e.g., 10:29:03 AM).
void Clock::displayTime12() {  // setfill('0') is used to display times in XX:XX:XX format. For example, if a user enters 6:02:30, the function displays 06:02:30.
	cout << "**************************" << endl;
	cout << "*      12-Hour Clock     *" << endl;
	cout << "*       " << setw(2) << setfill('0') << hour12 << ":" << setw(2) << min << ":" << setw(2) << sec << " " << amPm << "      *" << endl;
	cout << "**************************" << endl;
	cout << endl;
}

// Displays the time in 24-hour format (e.g., 15:46:30).
void Clock::displayTime24() {
	cout << "**************************" << endl;
	cout << "*      24-Hour Clock     *" << endl;
	cout << "*         " << setw(2) << setfill('0') << hour24 << ":" << setw(2) << min << ":" << setw(2) << sec << "       *" << endl;
	cout << "**************************" << endl;
	cout << endl;
}

// Increments hour24 by 1 and adjusts hour12 to correctly display time in the 12-hour format.
void Clock::addHour() {
	hour24 = (hour24 + 1) % 24;  // The hour is incremented while the remainder of division by 24 ensures the time never goes above 23 hours (instead, it "restarts" at 00).

	// The following conditional branches update the 12-hour time to correctly iterate from 1-12 and AM/PM, using the 24-hour time as a guide.
	if (hour24 > 12) {
		hour12 = hour24 - 12;
	}
	else if (hour24 == 0) {
		hour12 = 12;
	}
	else {
		hour12 = hour24;
	}

	if (hour24 >= 12) {
		amPm = "PM";
	}
	else {
		amPm = "AM";
	}

	displayTime12();
	displayTime24();
}

// Increments min by 1 and assigns "AM" or "PM" to amPm in the event that addMinute() was called before addHour().
void Clock::addMinute() {
	min = (min + 1) % 60;  // min is incremented by 1, and it will "restart" as 00 when it reaches 60.

	if (hour24 >= 12) {
		amPm = "PM";
	}
	else {
		amPm = "AM";
	}

	displayTime12();
	displayTime24();
}

// Increments sec by 1 and assigns "AM" or "PM" to amPm in the event that addSecond() was called before addHour().
void Clock::addSecond() {
	sec = (sec + 1) % 60;  // sec is incremented by 1, and it will "restart" as 00 when it reaches 60.

	if (hour24 >= 12) {
		amPm = "PM";
	}
	else {
		amPm = "AM";
	}

	displayTime12();
	displayTime24();
}

// Uses a loop to continually call the correct function based on user input in response to printMenu() and exits the program given a sentinel value.
void Clock::getMenuChoice() {
	int menuChoice;

	cout << "Please enter your choice as 1, 2, 3, or 4." << endl;
	cin >> menuChoice;
	cout << endl;  // I've added newlines like this throughout the program to make text more readable.

	// The while loop enables continuous menu selections (until program is exited) and validates user input.
	while (menuChoice != 4) {
		if (menuChoice == 1) {
			addHour();
		}
		else if (menuChoice == 2) {
			addMinute();
		}
		else if (menuChoice == 3) {
			addSecond();
		}
		else {
			cout << "Invalid entry. Please enter 1, 2, 3, or 4." << endl;
			cout << endl;
		}

		printMenu();
		cout << "Please enter your choice as 1, 2, 3, or 4." << endl;
		cin >> menuChoice;
	}
}

// Gathers initial time from user input, then constructs a Clock class to continue the program by calling Clock's functions.
int main() {
	int userHour12, userHour24, userMin, userSec;
	char colon;  // Used to gather non-integer input.
	string amPm = "";  // amPm is initialized here as an empty string to pass it to the Clock constructor, and its value is updated in the addHour() function.

	cout << "Please enter the time in XX:XX:XX format." << endl;
	cin >> userHour12 >> colon >> userMin >> colon >> userSec;  // Input is read in order of the XX:XX:XX format.
	cout << endl;

	userHour24 = userHour12;  // The differentiation between hour variables, despite being the same value here, is useful for displaying each time format correctly.

	Clock Clock(userHour12, userHour24, userMin, userSec, amPm);

	Clock.printMenu();
	Clock.getMenuChoice();

	return 0;
}
