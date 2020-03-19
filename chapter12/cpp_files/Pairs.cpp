#include "Pairs.h"

#include <iostream>
using namespace std;

Pairs::~Pairs() {}
Pairs::Pairs()
{
	f = 0;
	s = 0;
}
Pairs::Pairs(int newFirst)
{
	f = newFirst;
	s = 0;
}
Pairs::Pairs(int newFirst, int newSecond)
{
	f = newFirst;
	s = newSecond;
}

Pairs operator +(const Pairs& first, const Pairs& second)
{
	Pairs temp;
	temp.f = first.f + second.f;
	temp.s = first.s + second.s;
	return temp;
}
Pairs operator -(const Pairs& first, const Pairs& second)
{
	Pairs temp;
	temp.f = first.f - second.f;
	temp.s = first.s - second.s;
	return temp;
}
Pairs operator *(const Pairs& first, int number)
{
	Pairs temp;
	temp.f = first.f * number;
	temp.s = first.s * number;
	return temp;
}
istream& operator >>(istream& ins, Pairs& second)
{
	char ch;
	ins >> ch; // discard initial '('
	ins >> second.f;
	ins >> ch; // discard initial ','
	ins >> second.s;
	ins >> ch; // discard initial ')'
	return ins;
}
ostream& operator <<(ostream& outs, const Pairs& second)
{
	outs << '(';
	outs << second.f;
	outs << ','; // might prefer "," to get an extra space
	outs << second.s;
	outs << ')';
	return outs;
}
