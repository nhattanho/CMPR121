//Nhat Ho
//11/14/2018

#include "Project1.h"
#include "List.h"
#include "Queue.h"
#include "RPN.h"
#include <string>
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <istream> 
using namespace std;

void ProgrammingProject1();
void ProgrammingProject2();
void ProgrammingProject4();
void ProgrammingProject5();
void ProgrammingProject8();
void ProgrammingProject10();

int main()
{
	while (true)
	{
		system("cls");
		cout << "\n\t\tChapter 13\n";
		cout << "\t===========================\n";
		cout << "\t 1: Programming Project1\n";
		cout << "\t 2: Programming Project2\n";
		cout << "\t 3: Programming Project4\n";
		cout << "\t 4: Programming Project5\n";
		cout << "\t 5: Programming Project8\n";
		cout << "\t 6: Programming Project10\n";
		cout << "\t===========================\n";
		cout << "\t option: ";
		char option[80];
		cin.getline(option, 80, '\n');
		cout << endl;
		switch (atoi(option))
		{
		case 1: ProgrammingProject1(); break;
		case 2: ProgrammingProject2(); break;
		case 3: ProgrammingProject4(); break;
		case 4: ProgrammingProject5(); break;
		case 5: ProgrammingProject8(); break;
		case 6: ProgrammingProject10(); break;
		default: return 0;
		}
		system("pause");
	}
	return 0;
}

void ProgrammingProject1()
{
	using namespace Project1and2;
	NodePtr test = NULL;
	// Create a list of nodes 4 -> 3 -> 2 -> 1 -> 0
	for (int i = 1; i < 5; i++)
		headInsert(test, i);
	cout << "The list before conversing:\n";
	showList(test);

	cout << "The list after conversing:\n";
	reverser(test);
	showList(test);
}

void ProgrammingProject2()
{
	using namespace Project1and2;
	NodePtr list1 = NULL;
	headInsert(list1, 22);
	headInsert(list1, 19);
	headInsert(list1, 12);
	headInsert(list1, 8);
	NodePtr list2 = NULL;
	headInsert(list2, 26);
	headInsert(list2, 20);
	headInsert(list2, 15);
	NodePtr result = mergeLists(list1, list2);
	showList(result);
}

void ProgrammingProject4()
{
	using namespace Project4and5;
	List test;
	test.addItem(10);
	test.addItem(15);
	test.addItem(20);
	test.addItem(25);
	test.addItem(30);
	cout << "The maximum size of list is: " << MAX_LIST_SIZE << endl;
	cout << "The current size of list: " << test.getSize() << endl;
	cout << "The size is full: " << (test.full() == true ? "yes" : "no") << endl;
	cout << "The elements of list are:\n";
	cout << test;
}

void ProgrammingProject5()
{
	using namespace Project4and5;
	List test;
	test.showTest("This is the test for empty list!", test);
	test.addItem(10);
	test.addItem(15);
	test.addItem(20);
	cout << "The elements of list are:\n";
	cout << test;
	test.showTest("This is the test for above list!", test);
	
	test.insert(0, 4);
	cout << "The elements of list after insert (0, 4) are:\n";
	cout << test;

	test.insert(15, 16);
	cout << "The elements of list after insert (15, 16) are:\n";
	cout << test;

	test.insert(20, 25);
	cout << "The elements of list after insert (20, 25) are:\n";
	cout << test;
	test.showTest("This is the test for above list!", test);

	test.advance();
	cout << "Test current item after using advance function: " << test.currentItem() << endl;

	cin >> test;
	cout << "\nThe elements of list after using >> operator!\n";
	cout << test;
	test.showTest("This is the test for above list after using >> operator!", test);

	test.reset();
	test.showTest("This is the test for list after reseting!", test);
}

void ProgrammingProject8()
{
	long seconds;
	seconds = static_cast<long>(time(NULL));
	cout << "At the begining, seconds since 1/1/1970: " << seconds << endl;
	string prompt = "Enter '1' to simulate a customer's arrival,\n"
		"Enter '2' to help the next customer, or '3' to quit.\n";
	Queue test;
	while (true)
	{
		int option = test.inputInteger(prompt, 1, 3);
		if (option == 1)
		{
			seconds = static_cast<long>(time(NULL));
			int countArrive = test.simutlateArrival(seconds);
			cout << "Customer " << countArrive << " entered the queue at time " << seconds << endl;
		}
		else if (option == 2)
		{
			seconds = static_cast<long>(time(NULL));
			int countHelp = test.helpNextCustomer(seconds);
			if (countHelp != 0)
			{
				long waitTime = test.getWaitTime();
				cout << "Customer " << countHelp << " is being helped at time " << seconds << endl;
				cout << "Wait time = " << waitTime << endl;
			}
			//follow the requirement, if nobody is in the queue, output the empty line
			else
				cout << endl;
		}
		else
			break;
	}
}

void ProgrammingProject10()
{
	using namespace Project10;
	RPN test;
	int number1, number2;
	
	while (true)
	{
		char token[50];
		cin >> token;
		if (strcmp(token, "q") == 0)
			break;
		else if (strcmp(token, "/") == 0)
		{
			if (test.pop(number1) && test.pop(number2))
				test.push(number2 / number1);
			else
				break;
		}
		else if (strcmp(token, "*") == 0)
		{
			if (test.pop(number1) && test.pop(number2))
				test.push(number2 * number1);
			else
				break;
		}
		else if (strcmp(token, "-") == 0)
		{
			if (test.pop(number1) && test.pop(number2))
				test.push(number2 - number1);
			else
				break;
		}
		else if (strcmp(token, "+") == 0)
		{
			if (test.pop(number1) && test.pop(number2))
				test.push(number2 + number1);
			else
				break;
		}
		else
			test.push(atoi(token));
	}
	if (!test.empty())
	{
		test.pop(number1);
		cout << "The top of the stack is: " << number1 << endl;
	}
	else
		cout << "Error: Invalid input!\n";
}