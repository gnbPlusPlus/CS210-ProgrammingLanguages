#pragma once  // This was included when I made a new header file, so I left it as is.
#ifndef CLOCK_H
#define CLOCK_H

#include <string>

class Clock {
private:
	int hour12, hour24, min, sec;  // Used for gathering initial time from input and updating it based on user choices in getMenuChoice().
	std::string amPm;  // Used for determining whether time in the 12-hour format is in the morning ("AM") or afternoon/evening/night ("PM").

public:
	Clock(int h12, int h24, int m, int s, std::string aP);  // aP is short for "AM or PM".

	void printMenu();
	void displayTime12();
	void displayTime24();
	void addHour();
	void addMinute();
	void addSecond();
	void getMenuChoice();
};

#endif
