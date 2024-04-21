/*
 * Noelle Bishop
 * 04/21/24
 * Project Three for CS-210
 */

// For this program, Driver.cpp simply directs the program to ItemTracker.cpp with function calls.

#include "ItemTracker.h"

int main() {
	ItemTracker ItemTracker;

	ItemTracker.ReadFile();  // This will also call BackupFile() upon ReadFile()'s successful completion.
	ItemTracker.DisplayMenu();

	return 0;  // Menu choice 4 leads here, which gracefully closes the program.
}