#include "user.h"
#include <iostream>
#include <string>
using namespace std;

namespace
{
	bool isValid()
	{
		if (username.length() == 8)
		{
			for (int c = 0; c < username.length(); c++)
			{
				if (!checkLetter::isLetter(username[c]))
					return false;
			}
			return true;
		}
		return false;
	}
}

namespace Authenticate
{
	void inputUserName()
	{
		do
		{
			cout << "Enter your username (8 letters only): ";
			cin >> username;
		} while (!isValid());
	}

	string getUserName()
	{
		return username;
	}
}

namespace checkLetter
{
	bool isLetter(char c)
	{
		c = tolower(c);
		if (c < 'a' || c > 'z')
			return false;
		return true;
	}
}