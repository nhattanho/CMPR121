#include "DigitalTime.h"
#include <iostream>
#include <cctype>
#include <cstdlib>

using namespace std;

int digitToInt(char c)
{
	return(static_cast <int>(c) - static_cast<int>('0'));
}

void readMinute(istream& ins, int& theMinute)
{
	char c1, c2;
	ins >> c1 >> c2;

	if (!(isdigit(c1) && isdigit(c2)))
	{
		cout << "Error-1B: illegal input to readMinute\n";
		exit(1);
	}

	theMinute = (digitToInt(c1) * 10) + digitToInt(c2);

	if (theMinute < 0 || theMinute >59)
	{
		cout << "Error-2B: illegal input to readMinute\n";
		exit(1);
	}
}

void readHour(istream& ins, int& theHour)
{
	char c1, c2;
	ins >> c1 >> c2;
	if (!(isdigit(c1) && isdigit(c2) || c2 == ':'))
	{
		cout << "Error-1A: illegal input to readHour\n";
		exit(1);
	}
	if (isdigit(c1) && c2 == ':')
		theHour = digitToInt(c1);
	else
	{
		theHour = (digitToInt(c1) * 10) + digitToInt(c2);
		ins >> c2; //discard ':'
		if (c2 != ':')
		{
			cout << "Error-2A: illegal input to readHour\n";
			exit(1);
		}
	}
	if (theHour < 0 || theHour > 23)
	{
		cout << "Error-3A: illegal input to readHour\n";
		exit(1);
	}
}
namespace dtimesavitch //did it for display 12_6
{
	DigitalTime::~DigitalTime()
	{}

	DigitalTime::DigitalTime() : hour(0), minute(0), minutes(0)
	{}

	DigitalTime::DigitalTime(int newHour, int newMinute) : hour(newHour), minute(newMinute)
	{
		minutes = newHour * 60 + newMinute;
	}

	DigitalTime::DigitalTime(int theMinutes)
	{
		minutes = theMinutes;
		hour = theMinutes / 60;
		minute = theMinutes % 60;
	}

	int DigitalTime::getTotalMinutes() const
	{
		return minutes;
	}

	void DigitalTime::setTotalMinutes(int theMinutes)
	{
		minutes = theMinutes;
		hour = theMinutes / 60;
		minute = theMinutes % 60;
	}

	void DigitalTime::advance(int minutesAdded)
	{
		minutes = minutes + minutesAdded;

		int grossMinutes = minute + minutesAdded;
		minute = grossMinutes % 60;

		int hourAdjustment = grossMinutes / 60;
		hour = (hour + hourAdjustment) % 24;
	}

	void DigitalTime::advance(int hoursAdded, int minutesAdded)
	{
		minutes = minutes + hoursAdded * 60 + minutesAdded;

		hour = (hour + hoursAdded) % 24;
		advance(minutesAdded);
	}

	bool operator ==(const DigitalTime& time1, const DigitalTime& time2)
	{
		return (time1.hour == time2.hour && time1.minute == time2.minute);
	}

	istream& operator >>(istream& ins, DigitalTime& theObject)
	{
		readHour(ins, theObject.hour);
		readMinute(ins, theObject.minute);
		theObject.minutes = theObject.hour * 60 + theObject.minute;
		return ins;
	}

	ostream& operator <<(ostream& outs, const DigitalTime& theObject)
	{
		outs << theObject.hour << ':';
		if (theObject.minute < 10)
			outs << '0';
		outs << theObject.minute;
		return outs;
	}

	void DigitalTime::intervalSince(const DigitalTime& aPreviousTime, int& hoursInInterval, int& minutesInInterval) const
	{
		int totalCurrentMinutes = hour * 60 + minute;
		int totalPreviousMinutes = aPreviousTime.hour * 60 + aPreviousTime.minute;

		if (totalCurrentMinutes < totalPreviousMinutes)
			totalCurrentMinutes += 24 * 60;
		hoursInInterval = (totalCurrentMinutes - totalPreviousMinutes) / 60;
		minutesInInterval = (totalCurrentMinutes - totalPreviousMinutes) % 60;
	}
}
