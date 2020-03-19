#pragma once
#include "input.h"
#include <iostream>
#include <string>
using namespace std;
namespace CMPR121
{
	//return an input interger
	int inputDenominator(string prompt)
	{
		int input;
		do
		{
			cout << prompt;
			if (!(cin >> input))
			{
				cout << "ERROR-1A: Invalid input. Must be an integer type.\n";
				cin.clear();
				cin.ignore(999, '\n');
			}
			else if (input == 0)
				cout << "Denominator can not be zero, try again!" << endl;
			else
				break;
		} while (true);
		return input;
	}

	int inputDenominator(string prompt, istream& ins)
	{
		int input;
		do
		{
			cout << prompt;
			if (!(ins >> input))
			{
				cout << "ERROR-1A: Invalid input. Must be an integer type.\n";
				ins.clear();
				ins.ignore(999, '\n');
			}
			else if (input == 0)
				cout << "Denominator can not be zero, try again!" << endl;
			else
				break;
		} while (true);
		return input;
	}

	int inputInteger(string prompt, istream& ins)
	{
		int input;
		do
		{
			cout << prompt;
			if (!(ins >> input))
			{
				cout << "ERROR-1A: Invalid input. Must be an integer type.\n";
				ins.clear();
				ins.ignore(999, '\n');
			}
			else
				break;
		} while (true);
		return input;
	}

	int inputInteger(string prompt)
	{
		int input;
		do
		{
			cout << prompt;
			if (!(cin >> input))
			{
				cout << "ERROR-1A: Invalid input. Must be an integer type.\n";
				cin.clear();
				cin.ignore(999, '\n');
			}
			else
				break;
		} while (true);
		return input;
	}

	//return an integer where posNeg is positive (true) or negative (false)
	int inputInteger(string prompt, bool posNeg)
	{
		int input;
		do
		{
			cout << prompt;
			if (!(cin >> input))
			{
				cout << "ERROR-2A: Invalid input. Must be an integer type.\n";
				cin.clear();
				cin.ignore(999, '\n');
			}
			else if (posNeg && input < 0)
				cout << "ERROR-2A: Invalid input. Must be a positive number.\n";
			else if (!posNeg && input >= 0)
				cout << "ERROR-2A: Invalid input. Must be a negative number.\n";
			else
				break;
		} while (true);
		return input;
	}

	//return an input integer within range ,start and end
	int inputInteger(string prompt, int startRange, int endRange)
	{
		int input;
		do
		{
			cout << prompt;
			if (!(cin >> input))
			{
				cout << "ERROR-3A: Invalid input. Must be an integer type.\n";
				cin.clear();
				cin.ignore(999, '\n');
			}
			else if (!(input >= startRange && input <= endRange))
				cout << "ERROR-3A: Invalid input. Must be from " << startRange << ".." << endRange << ".\n";
			else
				break;
		} while (true);
		return input;
	}

	//return an input double
	double inputDouble(string prompt)
	{
		double input;
		do
		{
			cout << prompt;
			if (!(cin >> input))
			{
				cout << "ERROR-1B: Invalid input. Must be a double type.\n";
				cin.clear();
				cin.ignore(999, '\n');
			}
			else
				break;
		} while (true);
		return input;
	}

	double inputDouble(string prompt, istream& ins)
	{
		double input;
		do
		{
			cout << prompt;
			if (!(ins >> input))
			{
				cout << "ERROR-1B: Invalid input. Must be a double type.\n";
				ins.clear();
				ins.ignore(999, '\n');
			}
			else
				break;
		} while (true);
		return input;
	}

	//return a double where posNeg is positive (true) or negative (false)
	double inputDouble(string prompt, bool posNeg)
	{
		double input;
		do
		{
			cout << prompt;
			if (!(cin >> input))
			{
				cout << "ERROR-2B: Invalid input. Must be a double type.\n";
				cin.clear();
				cin.ignore(999, '\n');
			}
			else if (posNeg && input < 0.0)
				cout << "ERROR-2B: Invalid input. Must be a positive number.\n";
			else if (!posNeg && input >= 0.0)
				cout << "ERROR-2B: Invalid input. Must be a negative number.\n";
			else
				break;
		} while (true);
		return input;
	}

	//return an input double within range ,start and end
	double inputDouble(string prompt, double startRange, double endRange)
	{
		double input;
		do
		{
			cout << prompt;
			if (!(cin >> input))
			{
				cout << "ERROR-3A: Invalid input. Must be a double type.\n";
				cin.clear();
				cin.ignore(999, '\n');
			}
			else if (!(input >= startRange && input <= endRange))
				cout << "ERROR-3A: Invalid input. Must be from " << startRange << ".." << endRange << ".\n";
			else
				break;
		} while (true);
		return input;
	}
	char getChar(string prompt)
	{
		while (true)
		{
			char userAnswer;
			cout << prompt;
			cin >> userAnswer;
			cin.ignore(999, '\n');
			if (!cin.fail()) return userAnswer;
			cin.clear();
			cin.ignore();
			cout << "Input failed, try again" << endl;
		}
	}
	bool getBool(string prompt, int type)
	{
		while (true)
		{
			if (type == 1)
			{
				switch (getChar(prompt))
				{
				case 'A': case 'a': return true;
				case 'D': case 'd': return false;
				}
			}
			else if (type == 2)
			{
				switch (getChar(prompt))
				{
				case 'Y': case 'y': return true;
				case 'N': case 'n': return false;
				}
			}
			cout << "Wrong input, try again!" << endl;
		}
	}
	string getLine(string prompt)
	{
		while (true)
		{
			string userAnswer;
			cout << prompt;
			getline(cin, userAnswer);
			if (!cin.fail()) return userAnswer;
			cin.clear();
			cin.ignore(); // get rid of what killed it
			cout << "Input failed, try again!" << endl;
		}
	}
}