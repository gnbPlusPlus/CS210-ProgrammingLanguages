/* 
 * Noelle Bishop
 * 04/21/24
 * Project Three for CS-210
 */

// The ItemTracker class establishes the map and functions used to keep track of grocery items and their frequencies.

#pragma once
#ifndef ITEMTRACKER_H
#define ITEMTRACKER_H

#include <string>
#include <map>

using namespace std;

class ItemTracker {
private:
	map<string, int> itemFrequencyMap;
public:
	ItemTracker();  // Default constructor

	void ReadFile();
	void BackupFile();

	void DisplayMenu();

	void PrintIndividualFrequency();
	void PrintItemsAndFrequencies();
	void PrintHistogram();
};

#endif
