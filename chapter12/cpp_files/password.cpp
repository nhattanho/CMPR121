#include "password.h"
#include "user.h"
#include <iostream>
#include <string>
using namespace std;

namespace
{
	bool isValid()
	{
		if (password.length() < 8)
			return false;

		for (int c = 0; c < password.length(); c++)
		{
			if (!checkLetter::isLetter(password[c]))
				return true;
		}
		return false;
	}
}

namespace Authenticate
{
	void inputPassword()
	{
		do
		{
			cout << "Enter your password (8 letters only " <<
				"and at least one nonletter): ";
			cin >> password;

		} while (!isValid());
	}
	string getPassword()
	{
		return password;
	}
}