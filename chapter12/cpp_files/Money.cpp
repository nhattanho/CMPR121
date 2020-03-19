#include "Money.h"
#include <iostream>
using namespace std;
int digitToInt1(char c)
{
	return(static_cast <int>(c) - static_cast<int>('0'));
}
Money::~Money() {} // make class generally
Money::Money()
{
	allCents = 0;
}
Money::Money(long dollars)
{
	allCents = dollars * 100;
}
Money::Money(long dollars, int cents)
{
	allCents = dollars * 100 + cents;
}
double Money::getValue() const
{
	return allCents;
}
Money Money::percent(int percentFigure) const
{
	Money temp;
	temp.allCents = percentFigure * allCents / 100;
	return temp;
}
Money operator +(const Money& amount1, const Money& amount2)
{
	Money temp;
	temp.allCents = amount1.allCents + amount2.allCents;
	return temp;
}
Money operator -(const Money& amount1, const Money& amount2)
{
	Money temp;
	temp.allCents = amount1.allCents - amount2.allCents;
	return temp;
}
Money operator -(const Money& amount)
{
	Money temp;
	temp.allCents = -amount.allCents;
	return temp;
}
bool operator ==(const Money& amount1, const Money& amount2)
{
	if (amount1.allCents == amount2.allCents)
		return true;
	return false;
}
bool operator <(const Money& amount1, const Money& amount2)
{
	if (amount1.allCents < amount2.allCents)
		return true;
	return false;
}
bool operator <=(const Money& amount1, const Money& amount2)
{
	if (amount1.allCents <= amount2.allCents)
		return true;
	return false;
}
bool operator >(const Money& amount1, const Money& amount2)
{
	if (amount1.allCents > amount2.allCents)
		return true;
	return false;
}
bool operator >=(const Money& amount1, const Money& amount2)
{
	if (amount1.allCents >= amount2.allCents)
		return true;
	return false;
}
istream& operator >>(istream& ins, Money& amount)
{
	char oneChar, decimalPoint, digit1, digit2;
	long dollars;
	int cents;
	bool negative;
	ins >> oneChar;
	if (oneChar == '-')
	{
		negative = true;
		ins >> oneChar;
	}
	else
		negative = false;
	ins >> dollars >> decimalPoint >> digit1 >> digit2;

	if (oneChar != '$' || decimalPoint != '.' || !isdigit(digit1) || !isdigit(digit2))
	{
		cout << "Error illegal form for money input\n";
		exit(1);
	}
	cents = digitToInt1(digit1) * 10 + digitToInt1(digit2);

	amount.allCents = dollars * 100 + cents;
	if (negative)
		amount.allCents = -amount.allCents;
	return ins;
}
ostream& operator <<(ostream& outs, const Money& amount)
{
	long positiveCents, dollars, cents;
	positiveCents = labs(amount.allCents);
	dollars = positiveCents / 100;
	cents = positiveCents % 100;

	if (amount.allCents < 0)
		outs << "-$" << dollars << '.';
	else
		outs << "$" << dollars << '.';

	if (cents < 10)
		outs << '0';
	outs << cents;

	return outs;
}