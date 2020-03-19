#pragma once
#ifndef DIGITALTIME_H 
#define DIGITALTIME_H

#include <iostream>
using namespace std;

namespace dtimesavitch // did it for display 12_6
{
	class DigitalTime
	{
	private:
		int hour;
		int minute;
		int minutes; //Practice Program 2
	public:
		~DigitalTime();
		DigitalTime();
		DigitalTime(int newHour, int newMinute);
		DigitalTime(int theMinutes); //Practice program2
		int getTotalMinutes() const; //Practice program2
		void setTotalMinutes(int theMinutes); //Practice program2
		void advance(int minutesAdded);
		void advance(int hoursAdded, int minutesAdded);
		friend bool operator ==(const DigitalTime& time1, const DigitalTime& time2);
		friend istream& operator >>(istream& ins, DigitalTime & theObject);
		friend ostream& operator <<(ostream& outs, const DigitalTime& theObject);
		void intervalSince(const DigitalTime& aPreviousTime, int& hoursInInterval, int& minutesInInterval) const;
	};
}
#endif