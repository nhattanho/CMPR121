#include "Rational.h"
#include "input.h"
#include <istream>
using namespace std;
using namespace CMPR121;

Rational::Rational()
{
	numbers[0] = 0;// numerator
	numbers[1] = 1;// denominator
}
Rational::Rational(int wholeNumber)
{
	numbers[0] = wholeNumber;
	numbers[1] = 1;
}
// Documentation: the denominator can not be 0, if the user make a mistake,
// any value of denominator equal 0 should be treated as 1
Rational::Rational(int newNumerator, int newDenominator)
{
	numbers[0] = newNumerator;
	if (newDenominator == 0)
		newDenominator = 1;
	numbers[1] = newDenominator;
}
void Rational::setNumerator(int newNumerator)
{
	numbers[0] = newNumerator;
}
int Rational::getNumerator() const
{
	return numbers[0];
}
void Rational::setDenominator(int newDenominator)
{
	if (newDenominator == 0)
		newDenominator = 1;
	numbers[1] = newDenominator;
}
int Rational::getDenominator() const
{
	return numbers[1];
}
int Rational::greatestCommonDivisor(int numerator, int denominator)
{
	while (denominator != 0)
	{
		int r = numerator % denominator;
		numerator = denominator;
		denominator = r; // remainder of division
	}
	return numerator;
}
void Rational::keepPositiveDenominator()
{
	if (numbers[1] < 0)
	{
		numbers[0] *= -1;
		numbers[1] *= -1;
	}
}
void Rational::normalization()
{
	if (numbers[0] != 0)
	{
		int gCD = greatestCommonDivisor(numbers[0], numbers[1]);
		numbers[0] /= gCD;
		numbers[1] /= gCD;
		this->keepPositiveDenominator();
	}
}
Rational operator +(const Rational& r1, const Rational& r2)
{
	Rational tempAdd;
	tempAdd.numbers[0] = r1.numbers[0] * r2.numbers[1] + r1.numbers[1] * r2.numbers[0];
	tempAdd.numbers[1] = r1.numbers[1] * r2.numbers[1];
	return tempAdd;
}
Rational operator -(const Rational& r1, const Rational& r2)
{
	Rational tempAdd;
	tempAdd.numbers[0] = r1.numbers[0] * r2.numbers[1] - r1.numbers[1] * r2.numbers[0];
	tempAdd.numbers[1] = r1.numbers[1] * r2.numbers[1];
	return tempAdd;
}
Rational operator *(const Rational& r1, const Rational& r2)
{
	Rational tempAdd;
	tempAdd.numbers[0] = r1.numbers[0] * r2.numbers[0];
	tempAdd.numbers[1] = r1.numbers[1] * r2.numbers[1];
	return tempAdd;
}
Rational operator /(const Rational& r1, const Rational& r2)
{
	Rational tempAdd;
	tempAdd.numbers[0] = r1.numbers[0] * r2.numbers[1];
	tempAdd.numbers[1] = r1.numbers[1] * r2.numbers[0];
	return tempAdd;
}
Rational Rational::operator -()
{
	numbers[0] *= -1;
	return *this;
}
bool Rational::operator <(const Rational& r2)
{
	this->keepPositiveDenominator();
	Rational temp;
	temp.numbers[0] = r2.numbers[0];
	temp.numbers[1] = r2.numbers[1];
	temp.keepPositiveDenominator();
	if (numbers[0] * temp.numbers[1] < numbers[1] * temp.numbers[0])
		return true;
	else
		return false;
}
bool Rational::operator <=(const Rational& r2)
{
	this->keepPositiveDenominator();
	Rational temp;
	temp.numbers[0] = r2.numbers[0];
	temp.numbers[1] = r2.numbers[1];
	temp.keepPositiveDenominator();
	if (numbers[0] * temp.numbers[1] <= numbers[1] * temp.numbers[0])
		return true;
	else
		return false;
}
bool Rational::operator >=(const Rational& r2)
{
	this->keepPositiveDenominator();
	Rational temp;
	temp.numbers[0] = r2.numbers[0];
	temp.numbers[1] = r2.numbers[1];
	temp.keepPositiveDenominator();
	if (numbers[0] * temp.numbers[1] >= numbers[1] * temp.numbers[0])
		return true;
	else
		return false;
}
bool Rational::operator ==(const Rational& r2)
{
	if (this->operator<=(r2) && this->operator>=(r2))
		return true;
	else
		return false;
}

ostream& operator <<(ostream& outs, const Rational& object)
{
	outs << object.numbers[0] << "/" << object.numbers[1];
	return outs;
}
istream& operator >>(istream& ins, Rational& object)
{
	int numerator = inputInteger("Please enter the numerator: ", ins);
	int denominator = inputDenominator("Please enter the denominator: ", ins);
	object.numbers[0] = numerator;
	object.numbers[1] = denominator;
	return ins;
}

void checkZero(Rational object)
{
	if (object.getNumerator() == 0)
		cout << "0" << endl;
	else if (object.getDenominator() == 0)
		cout << "Reject" << endl;
	else
		cout << object << endl;
}