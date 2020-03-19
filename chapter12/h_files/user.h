#pragma once
#ifndef USER_H 
#define USER_H

#include <iostream>
using namespace std;

namespace
{
	string username;
	bool isValid();
}
namespace Authenticate
{
	void inputUserName();
	string getUserName();
}
namespace checkLetter
{
	bool isLetter(char c);
}
#endif