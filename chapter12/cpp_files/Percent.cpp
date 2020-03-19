#include "Percent.h"
#include <istream>
using namespace std;

Percent::Percent()
{
	value = 0;
}
Percent::Percent(int percentValue)
{
	value = percentValue;
}
bool operator ==(const Percent& first, const Percent& second)
{
	return first.value == second.value;
}
bool operator <(const Percent& first, const Percent& second)
{
	return first.value < second.value;
}
Percent operator +(const Percent& first, const Percent& second)
{
	Percent temp;
	temp.value = first.value + second.value;
	return temp;
}
Percent operator -(const Percent& first, const Percent& second)
{
	Percent temp;
	temp.value = first.value - second.value;
	return temp;
}
Percent operator *(const Percent& first, const int number)
{
	Percent temp;
	temp.value = first.value * number;
	return temp;
}
istream& operator >>(istream& ins, Percent& theObject)
{
	char percentSign;
	ins >> theObject.value;
	ins >> percentSign;
	return ins;
}

ostream& operator <<(ostream& outs, const Percent& aPercent)
{
	outs << aPercent.value << '%';
	return outs;
}
