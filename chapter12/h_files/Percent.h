#pragma once
#ifndef PERCENT_H
#define PERCENT_H

#include <istream>
#include <iostream>
using namespace std;

class Percent
{
private:
	int value;
public:
	Percent();
	Percent(int percentValue);
	friend bool operator ==(const Percent& first, const Percent& second);
	friend bool operator <(const Percent& first, const Percent& second);
	friend Percent operator +(const Percent& first, const Percent& second);
	friend Percent operator -(const Percent& first, const Percent& second);
	friend Percent operator *(const Percent& first, const int number);
	friend istream& operator >>(istream& ins, Percent& theObject);
	friend ostream& operator <<(ostream& outs, const Percent& aPercent);
};

#endif