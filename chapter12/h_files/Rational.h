#pragma once
#ifndef RATIONAL_H
#define RATIONAL_H

#include <istream>
#include <iostream>
using namespace std;

class Rational
{
private:
	int numbers[2];
public:
	Rational();
	Rational(int wholeNumber);
	Rational(int newNumerator, int newDenominator);
	void setNumerator(int newNumerator);
	int getNumerator() const;
	void setDenominator(int newDenominator);
	int getDenominator() const;
	int greatestCommonDivisor(int numerator, int denominator);
	void keepPositiveDenominator();
	void normalization();
	friend Rational operator +(const Rational& r1, const Rational& r2);
	friend Rational operator -(const Rational& r1, const Rational& r2);
	friend Rational operator *(const Rational& r1, const Rational& r2);
	friend Rational operator /(const Rational& r1, const Rational& r2);
	Rational operator -();
	bool operator <(const Rational& r2);
	bool operator <=(const Rational& r2);
	bool operator >=(const Rational& r2);
	bool operator ==(const Rational& r2);
	friend ostream& operator <<(ostream& outs, const Rational& object);
	friend istream& operator >>(istream& ins, Rational& object);
};
void checkZero(Rational object);
#endif
