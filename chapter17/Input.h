#include <iostream>
#include <string>
using namespace std;

namespace CMPR121
{
	//return an input interger
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
}