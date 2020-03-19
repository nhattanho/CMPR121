// Nhat Ho
// 12/05/2018
// Homework Chapter 17

#include <iostream>
#include "Input.h"
#include <ctime>
#include "List.h"
#include "ArrayFunctions.h"
#include "ItemSet.h"
using namespace std;

const int ARRAY_MAX_SIZE = 100;

void PracticeProgram1();
void ProgrammingProject1();
void ProgrammingProject2();
void ProgrammingProject4();
void ProgrammingProject7();

int main()
{
	while (true)
	{
		system("cls");
		cout << "\n\t\tChapter 17\n";
		cout << "\t===========================\n";
		cout << "\t 1: Practice Program1\n";
		cout << "\t 2: Programming Project1\n";
		cout << "\t 3: Programming Project2\n";
		cout << "\t 4: Programming Project4\n";
		cout << "\t 5: Programming Project7\n";
		cout << "\t===========================\n";
		cout << "\t option: ";

		char option[80];
		cin.getline(option, 80, '\n');

		switch (atoi(option))
		{
		case 1: PracticeProgram1(); break;
		case 2: ProgrammingProject1(); break;
		case 3: ProgrammingProject2(); break;
		case 4: ProgrammingProject4(); break;
		case 5: ProgrammingProject7(); break;
		default: return 0;
		}
		system("pause");
	}
	return 0;
}

template <class itemType>
int findValued(const itemType array[ARRAY_MAX_SIZE], int size, itemType keyValue)
{
	for (int c = 0; c < size; c++)
		if (array[c] == keyValue)
			return c;
	return -1;
}
void PracticeProgram1()
{
	using namespace CMPR121;

	srand(time(0));
	double array[ARRAY_MAX_SIZE];
	int size = inputInteger("\nEnter the size of the array: ", 1, ARRAY_MAX_SIZE);

	for (int c = 0; c < size; c++)
		array[c] = (rand() % 100)*1.0;

	int result = findValued(array, size, 21.0);

	if (result == -1)
		cout << "\nThe array does not have value. " << 21.0 << ".\n";
	else
		cout << "\nThe value is located at index. " << result << ", of the array.\n";
	cin.ignore();
}
void ProgrammingProject1()
{
	List<int> testList(10);
	testList.add(4);
	testList.add(2);
	testList.add(24);
	cout << testList;

	for (int c = 0; c < testList.lenght(); c++)
		testList.next();

	cout << "\nThe current item is " << testList.getCurrent() << ".\n";

	for (int c = 2; c > 0; c--)
		testList.previous();
	cout << "\nThe current item is " << testList.getCurrent() << ".\n";

	testList.reset();
	cout << "\nThe current item is " << testList.getCurrent() << ".\n";

	testList.erase();
	cout << testList;

	cin.ignore();
}
void ProgrammingProject2()
{
	using namespace CMPR121;
	int inputInt = inputInteger("How many items? ");
	double tempDouble;
	List<double> testList(inputInt);

	for (int c = 0; c < inputInt; c++)
	{
		tempDouble = inputDouble("Add element for the list: ");
		testList.add(tempDouble);
	}

	tempDouble = inputDouble("What item do you want to find? ");
	cout << "The position of the element " << tempDouble << " is " << testList.findItem(tempDouble) << "\n";
	cin.ignore();
}

void ProgrammingProject4()
{
	using namespace ArrayFunctions;
	int const size = 5;
	int test[size] = {5, 6, 9, 3, 2};
	cout << "\nBefore sorting: ";
	display(test, size);

	sort(test, size);
	cout << "\nAfter sorting: ";
	display(test, size);
	cout << endl;

	double array1[size] = {8.5, 9.5, 7.5, 5.5, 6.5};
	cout << "\nBefore sorting: ";
	display(array1, size);

	sort(array1, size);
	cout << "\nThe array of doubles after sorting are: ";
	display(array1, size);

	cin.ignore();
}
void ProgrammingProject7()
{
	ItemSet <int>test1;
	test1.add(5);
	test1.add(6);
	test1.add(7);
	test1.remove(7);
	cout << "\nNumbers of items: " << test1.returnNumber();

	cout << "\nThe list of test1" << test1;

	ItemSet <double>test2;
	test2.add(5.5);
	test2.add(6.5);
	test2.add(7.5);
	test2.add(8.5);
	test2.remove(8.5);
	cout << "\nNumbers of items: " << test2.returnNumber();
	cout << "\nThe list of test2" << test2;
	cin.ignore();
}