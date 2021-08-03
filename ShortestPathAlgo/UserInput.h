#ifndef UserInputH
#define UserInputH

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class UserInput {
	//Data members
	int n, t, s, actualInts = 0;
	std::string inputFile, outputFile;
	void printErrorMessage();
public:
	const int& getN() { return n; }
	const int& getT() { return t; }
	const int& getS() { return s; }
	void getInputFromUser();
	bool isKeyboardDataValid();
	bool isNumber(const string& s);
	bool isDigit(const char& ch);
	bool isFileDataValid();
};

#endif