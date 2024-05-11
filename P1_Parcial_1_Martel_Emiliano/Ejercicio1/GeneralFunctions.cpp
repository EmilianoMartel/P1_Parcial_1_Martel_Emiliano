#include "GeneralFunctions.h"

bool intCheacker(string input) {
	for (char c : input) {
		if (!isdigit(c)) {
			return false;
		}
	}
	return true;
}

bool floatCheacker(string input) {
	istringstream isFloat(input);
	float f;
	if (isFloat >> f && isFloat.eof()) {
		return true;
	}
	else {
		return false;
	}
}

float floatInputLoop(string question) {
	string input;
	bool inputValid = false;
	do
	{
		cout << question << endl;
		getline(cin, input);

		inputValid = floatCheacker(input);

		if (inputValid) {
			return stoi(input);
		}
		else {
			cout << "Invalid input, try again." << endl;
		}
	} while (!inputValid);
	return 0.f;
}

int intInputLoop(string question) {
	string input;
	bool inputValid = false;
	do
	{
		cout << question << endl;
		getline(cin, input);

		inputValid = intCheacker(input);

		if (inputValid) {
			return stoi(input);
		}
		else {
			cout << "Invalid input, try again." << endl;
		}
	} while (!inputValid);
	return 0;
}

bool yesOrNoLoop(string question) {
	string input;
	bool inputValid = false;
	do
	{
		cout << question << endl;
		getline(cin, input);

		if (input == "Y" || input == "y" || input == "N" || input == "n") {
			inputValid = true;
		}
		else {
			cout << "Invalid input. Try again." << endl;
		}
	} while (!inputValid);

	if (input == "Y" || input == "y") {
		return true;
	}
	return false;
}