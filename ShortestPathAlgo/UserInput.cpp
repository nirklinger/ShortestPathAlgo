#include "UserInput.h"

void UserInput::getInputFromUser() {	
	cin >> n;
	cin >> s;
	cin >> t;	
}

void UserInput::printErrorMessage() {
	cout << "wrong input" << endl;
}

bool UserInput::isKeyboardDataValid() {
	if ((s < 1) || (t < 1) || (n < 1)) {
		printErrorMessage();
		return false;
	}
}

bool UserInput::isNumber(const string& s) {
	for (int i = 0; i < s.length(); ++i) {
		if ((isDigit(s[i]) == false)) {
			if ((i == 0) && (s[0] != '-'))
				return false;
			else if (i != 0) return false;
		}
	}
	return true;
}

bool UserInput::isDigit(const char& ch) {
	if ((ch >= '0') && (ch <= '9'))
		return true;
	else return false;
}
