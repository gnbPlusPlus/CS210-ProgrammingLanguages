#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Program that reads city temperature data in degrees Fahrenheit from a .txt file, then converts the temperatures to Celsius and writes them to a new .txt file.

int main() {
	ifstream fahrenheitFS;
	ofstream celsiusFS;

	// Each vector is sized to 6 because the original file features only 6 cities with their respective temperatures.
	vector<string> cityNames(6);
	vector<int> fahrenheitTemps(6);
	vector<int> celsiusTemps(6);
	unsigned int i;

	fahrenheitFS.open("FahrenheitTemperature.txt");

	if (!fahrenheitFS.is_open()) {  // Error handling per best practice.
		cout << "Cannot open FahrenheitTemperature.txt" << endl;

		return 1;
	}

	for (i = 0; i < 6; ++i) {  // The loop iterates while i < 6 because there are only 6 entries (cities with their temperatures) in the original file.
		fahrenheitFS >> cityNames.at(i) >> fahrenheitTemps.at(i);

		celsiusTemps.at(i) = (fahrenheitTemps.at(i) - 32) * 5.0 / 9.0;
	}
	
	fahrenheitFS.close();

	celsiusFS.open("CelsiusTemperature.txt");

	if (!celsiusFS.is_open()) {
		cout << "Cannot open CelsiusTemperature.txt" << endl;

		return 1;
	}

	for (i = 0; i < 6; ++i) {  // This is the point at which CelsiusTemperature is being written onto.
		celsiusFS << cityNames.at(i) << " " << celsiusTemps.at(i) << " C" << endl;  // A 'C' is added to each converted temperature for clarity.
	}

	celsiusFS.close();  // The file is closed and therefore saved.

	return 0;
}