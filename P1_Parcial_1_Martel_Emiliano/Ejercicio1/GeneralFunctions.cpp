#include "GeneralFunctions.h"

bool GeneralFun::IntCheacker(string input) {
	for (char c : input) {
		if (!isdigit(c)) {
			return false;
		}
	}
	return true;
}

int GeneralFun::IntInputLoop(string question) {
	string input;
	bool inputValid = false;
	do
	{
		cout << question << endl;
		getline(cin, input);

		inputValid = IntCheacker(input);

		if (inputValid) {
			return stoi(input);
		}
		else {
			cout << "Invalid input, try again." << endl;
		}
	} while (!inputValid);
}