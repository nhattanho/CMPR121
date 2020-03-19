#include "Queue.h"

Queue::Queue(): customerFront(NULL), customerBack(NULL), count(0), waitTime(0)
{}
Queue::~Queue()
{
	while (!empty())
	{
		CustomerPtr discard;
		discard = customerFront;
		customerFront = customerFront->next;
		if (customerFront == NULL)
			customerBack = NULL;
		delete discard;
	}
}
bool Queue::empty() const
{
	return (customerBack == NULL);
}
int Queue::simutlateArrival(long timeArive)
{
	if (empty())
	{
		customerFront = new Customer;
		customerFront->timeIn = timeArive;
		customerFront->next = NULL;
		customerBack = customerFront;
		count++;
		customerFront->countOut = count;
	}
	else
	{
		CustomerPtr temp = new Customer;
		temp->timeIn = timeArive;
		temp->next = NULL;
		customerBack->next = temp;
		customerBack = temp;
		count++;
		customerBack->countOut = count;
	}
	return count;
}
int Queue::helpNextCustomer(long timeHelp)
{
	if (!empty())
	{
		int count = customerFront->countOut;
		waitTime = timeHelp - customerFront->timeIn;
		CustomerPtr temp = new Customer;
		temp = customerFront;
		customerFront = customerFront->next;
		if (customerFront == NULL)
			customerBack = NULL;
		delete temp;
		return count;
	}
	return 0;//empty list of customer
}

long Queue::getWaitTime() const
{
	return waitTime;
}

int Queue::inputInteger(string prompt, int startRange, int endRange)
{
	int input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR-3A: Invalid input. Must be an integer type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (!(input >= startRange && input <= endRange))
			cout << "ERROR-3A: Invalid input. Must be from " << startRange << ".." << endRange << ".\n";
		else
			break;
	} while (true);
	return input;
}