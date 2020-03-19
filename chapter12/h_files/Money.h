#pragma once
#ifndef MONEY_H 
#define MONEY_H

#include <iostream>
using namespace std;
class Money
{
private:
	long allCents;
public:
	~Money();
	Money();
	Money(long dollars);
	Money(long dollars, int cents);
	double getValue() const;
	Money percent(int percentFigure) const;
	friend Money operator +(const Money& amount1, const Money& amount2);
	friend Money operator -(const Money& amount1, const Money& amount2);
	friend Money operator -(const Money& amount);
	friend bool operator ==(const Money& amount1, const Money& amount2);
	friend bool operator <(const Money& amount1, const Money& amount2);
	friend bool operator <=(const Money& amount1, const Money& amount2);
	friend bool operator >(const Money& amount1, const Money& amount2);
	friend bool operator >=(const Money& amount1, const Money& amount2);
	friend istream& operator >>(istream& ins, Money& amount);
	friend ostream& operator <<(ostream& outs, const Money& amount);
};
#endif