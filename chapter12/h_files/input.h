#pragma once
#ifndef INPUT_H
#define INPUT_H

#include <iostream>
using namespace std;
namespace CMPR121
{
	int inputDenominator(string prompt);
	int inputDenominator(string prompt, istream& ins);
	int inputInteger(string prompt, istream& ins);
	int inputInteger(string prompt);
	int inputInteger(string prompt, bool posNeg);
	int inputInteger(string prompt, int startRange, int endRange);
	double inputDouble(string prompt);
	double inputDouble(string prompt, istream& ins);
	double inputDouble(string prompt, bool posNeg);
	double inputDouble(string prompt, double startRange, double endRange);
	char getChar(string prompt);
	bool getBool(string prompt, int type);
	string getLine(string prompt);
}

#endif