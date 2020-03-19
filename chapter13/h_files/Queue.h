#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;
struct Customer
{
	long timeIn;
	int countOut;
	Customer* next;
	Customer()
	{
		timeIn = 0;
	}
};
typedef Customer* CustomerPtr;

class Queue
{
private:
	long waitTime;
	int count;
	CustomerPtr customerFront;
	CustomerPtr customerBack;
public:
	Queue();
	~Queue();
	bool empty() const;
	int simutlateArrival(long timeArive);
	int helpNextCustomer(long timeHelp);
	long getWaitTime() const;
	int inputInteger(string prompt, int startRange, int endRange);
};

#endif