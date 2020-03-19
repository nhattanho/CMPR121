#pragma once
#ifndef PAIRS_H 
#define PAIRS_H

#include <iostream>
using namespace std;
class Pairs
{
private:
	int f, s;
public:
	~Pairs();
	Pairs();
	Pairs(int newFirst);
	Pairs(int newFirst, int newSecond);
	friend Pairs operator +(const Pairs& firstPair, const Pairs& secondPair);
	friend Pairs operator -(const Pairs& firstPair, const Pairs& secondPair);
	friend Pairs operator *(const Pairs& pairObject, int number);
	friend istream& operator >>(istream& ins, Pairs& second);
	friend ostream& operator <<(ostream& outs, const Pairs& second);
};
#endif