// Nhat Ho
// 10/31/2018

#include "input.h"
#include "Money.h"
#include "DigitalTime.h"
#include "Pairs.h"
#include "user.h"
#include "password.h"
#include "Greeting.h"
#include "Percent.h"
#include "Rational.h"
#include "StringSet.h"
#include <iostream>
#include <string>
using namespace std;
using namespace CMPR121;

void PracticeProgram1();
void PracticeProgram2();
void PracticeProgram3();
void PracticeProgram4();
void PracticeProgram5();
void Display12_5();
void Display12_6();
void Program_Project1();
void Program_Project2();
void Program_Project3();

int main()
{
	while (true)
	{
		system("cls");
		cout << "\n\tChapter 11" << endl;
		cout << "==============================" << endl;
		cout << " 1: Practice Program 1" << endl;
		cout << " 2: Practice Program 2" << endl;
		cout << " 3: Practice Program 3" << endl;
		cout << " 4: Practice Program 4" << endl;
		cout << " 5: Practice Program 5" << endl;
		cout << " 6: Display12_5" << endl;
		cout << " 7: Display12_6" << endl;
		cout << " 8 Programming Project1" << endl;
		cout << " 9: Programming Project2" << endl;
		cout << "10: Programming Project3" << endl;
		cout << "==============================" << endl;

		cout << " option: ";
		char option[80];
		cin.getline(option, 80, '\n');
		cout << endl;

		switch (atoi(option))
		{
		case 1: PracticeProgram1(); break;
		case 2: PracticeProgram2(); break;
		case 3: PracticeProgram3(); break;
		case 4: PracticeProgram4(); break;
		case 5: PracticeProgram5(); break;
		case 6: Display12_5(); break;
		case 7: Display12_6(); break;
		case 8: Program_Project1(); break;
		case 9: Program_Project2(); break;
		case 10: Program_Project3(); break;
		default: exit(0);
		}

		cout << endl;
		system("pause");
		cin.clear();
		cin.ignore(999, '\n');
	}
	return 0;
}

void PracticeProgram1()
{
	using namespace dtimesavitch; // did it for display 12_6
	DigitalTime clock, oldClock;
	cout << "Enter the time in 24-hour notation, ex:(hours:minutes): ";
	cin >> clock;

	oldClock = clock;
	clock.advance(15);
	if (clock == oldClock)
		cout << "Something is wrong.";
	cout << "You entered " << oldClock << endl;
	cout << "15 minutes later the time will be " << clock << "." << endl;

	clock.advance(2, 15);
	cout << "Continuning add 2 hours and 15 minutes after that, the time will be " << clock << "." << endl;

	DigitalTime current(5, 45), previous(4, 30);
	int hours, minutes;
	current.intervalSince(previous, hours, minutes);
	cout << "The time interval between " << previous << " and " << current << " is " << hours << " hours and " << minutes << " minutes.\n";
}

void PracticeProgram2() //did it for display 12_6
{
	using namespace dtimesavitch;
	DigitalTime clock, oldClock;
	cout << "Enter the time in 24-hour notation, ex:(hours:minutes): ";
	cin >> clock;

	oldClock = clock;
	clock.advance(15);
	if (clock == oldClock)
		cout << "Something is wrong.";
	cout << "You entered " << oldClock << endl;
	cout << "15 minutes later the time will be " << clock << "." << endl;

	clock.advance(2, 15);
	cout << "Continuning add 2 hours and 15 minutes after that, the time will be " << clock << "." << endl;

	DigitalTime current(5, 45), previous(4, 30);
	int hours, minutes;
	current.intervalSince(previous, hours, minutes);
	cout << "The time interval between " << previous << " and " << current << " is " << hours << " hours and " << minutes << " minutes.\n";

	DigitalTime newcurrent(420);
	cout << "The total minutes after setting 420 minutes: " << newcurrent.getTotalMinutes() << endl;
	cout << "The time for 420 minutes is: " << newcurrent << endl;

	newcurrent.setTotalMinutes(500);
	cout << "The hours after set 500 minutes is: " << newcurrent << endl;
}

void PracticeProgram3()
{
	Money first(46), second, third(20, 3);

	cout << "Enter amount of money do you want to object second, ex: $10.80: ";
	cin >> second;
	cout << "Checking the money of second object, it is: " << second << endl;

	double totalCents = first.getValue();
	cout << "\nThe total cents of first(46) is: " << totalCents << endl;

	cout << "\nStarting check equality between first(46) and third(20,3):\n";
	if (first == third)
		cout << "My code false for checking equality operator!\n";
	else
		cout << "They are not equality, code passed the checking!\n";

	second = -first;
	cout << "\nChecking for negative of first(46): " << second << endl;

	second = first + third;
	cout << "\nChecking add function between: first(46) + third(20,3), result is: " << second << endl;

	second = first - third;
	cout << "\nChecking sub function between: first(46) - third(20,3), result is: " << second << endl;

	Money checkPercent(100, 10);
	checkPercent = checkPercent.percent(10);
	cout << "\n10% of checkPercent(100,10) is: " << checkPercent << endl;

	cout << "\nThe value of first(46) is: " << first << " and " << "the value of third(20,3) is: " << third << endl;

	if (first > third)
		cout << "first > third, code passed the > operator!\n";
	else
		cout << "Code failed the > operator!\n";

	if (first >= third)
		cout << "first >= third, code passed the >= operator!\n";
	else
		cout << "Code failed the >= operator!\n";

	if (first < third)
		cout << "Code failed the < operator!\n";
	else
		cout << "first < third, code passed the < operator!\n";

	if (first <= third)
		cout << "Code failed the < operator!\n";
	else
		cout << "first <= third, code passed the <= operator!\n";
}

void PracticeProgram4()
{
	Pairs first, second(4), third(3, 4);
	cout << "Enter the first and second number for first pairs, ex:(4,2): ";
	cin >> first;
	cout << "The value of first pair you have just entered is: " << first << endl;

	cout << "\nSecond pair is " << second << " and third pair is: " << third << endl;
	first = second + third;
	cout << "\n" << second << " + " << third << " = " << first << endl;

	first = second - third;
	cout << "\n" << second << " - " << third << " = " << first << endl;

	first = second * 3;
	cout << "\n" << second << " * " << 3 << " = " << first << endl;
}

void PracticeProgram5()
{
	using namespace Authenticate;
	inputUserName();
	inputPassword();
	cout << "Your username is " << getUserName() << " and your password is: " << getPassword() << endl;
}

void Display12_5()
{
	{
		using namespace savitch2;
		greeting();

	}

	{
		using namespace savitch1;
		greeting();

	}

	bigGreeting();
}

void Display12_6()
{
	cout << "We finished the display12_6 by adding namespace ";
	cout << "dtimesavitch in DigitalTime.cpp and DigitalTime.h\n";
	using namespace dtimesavitch; // did it for display 12_6
	DigitalTime clock, oldClock;
	cout << "Enter the time in 24-hour notation, ex:(hours:minutes): ";
	cin >> clock;

	oldClock = clock;
	clock.advance(15);
	if (clock == oldClock)
		cout << "Something is wrong.";
	cout << "You entered " << oldClock << endl;
	cout << "15 minutes later the time will be " << clock << "." << endl;

	clock.advance(2, 15);
	cout << "Continuning add 2 hours and 15 minutes after that, the time will be " << clock << "." << endl;

	DigitalTime current(5, 45), previous(4, 30);
	int hours, minutes;
	current.intervalSince(previous, hours, minutes);
	cout << "The time interval between " << previous << " and " << current << " is " << hours << " hours and " << minutes << " minutes.\n";
}

void Program_Project1()
{
	Percent object1, object2(25), object3(45);
	cout << "Enter the value percent for object1, (ex:10%): ";
	cin >> object1;
	cout << "The value of object1 you has just entered: " << object1 << endl;

	cout << "\nValue of object2 is " << object2 << " and value of object3 is " << object3 << endl;
	if (object2 == object3)
		cout << "Something wrong in the code\n";
	else
		cout << "Passed the equality operator check, object2 != object3\n";

	if (object2 < object3)
		cout << "Passed the < operator check, object2 < object3\n";
	else
		cout << "Something wrong in the code\n";

	object1 = object2 + object3;
	cout << "\nValue of object1 = object2 + object3 is: " << object1 << endl;

	object1 = object2 - object3;
	cout << "\nValue of object1 = object2 - object3 is: " << object1 << endl;

	object1 = object2 * 3;
	cout << "\nValue of object1 = object2 * 3 is: " << object1 << endl;
}

void Program_Project2()
{
	Rational* ptr = new Rational[2];
	Rational temp;
	// Create first rational by using insert operator >>
	cout << "Enter the first rational!" << endl;
	cin >> ptr[0];

	// Create second rational by calling set function
	cout << "\nEnter the second rational!" << endl;
	int numerator = inputInteger("Enter the numberator: ");
	int denominator = inputDenominator("Enter the denominator: ");
	ptr[1].setNumerator(numerator);
	ptr[1].setDenominator(denominator);

	//Adding
	temp = ptr[0] + ptr[1];
	cout << ptr[0] << " + " << ptr[1] << " = " << temp << " --> ";
	temp.normalization();
	checkZero(temp);

	//Sub
	temp = ptr[0] - ptr[1];
	cout << ptr[0] << " - " << ptr[1] << " = " << temp << " --> ";
	temp.normalization();
	checkZero(temp);

	//Multi
	temp = ptr[0] * ptr[1];
	cout << ptr[0] << " * " << ptr[1] << " = " << temp << " --> ";
	temp.normalization();
	checkZero(temp);

	//Devide
	temp = ptr[0] / ptr[1];
	cout << ptr[0] << " / " << ptr[1] << " = " << temp << " --> ";
	temp.normalization();
	checkZero(temp);

	//Negative
	temp = ptr[0];
	cout << "-(" << temp << ")" << " = ";
	temp = -temp;
	cout << temp << " --> ";
	temp.normalization();
	checkZero(temp);

	// <
	cout << ptr[0] << " < " << ptr[1] << (ptr[0] < ptr[1] ? " true " : " false ") << endl;

	// <=
	cout << ptr[0] << " <= " << ptr[1] << (ptr[0] <= ptr[1] ? " true " : " false ") << endl;

	// >=
	cout << ptr[0] << " >= " << ptr[1] << (ptr[0] >= ptr[1] ? " true " : " false ") << endl;

	// ==
	cout << ptr[0] << " == " << ptr[1] << (ptr[0] == ptr[1] ? " true " : " false ") << endl;
	delete[] ptr;
}

void Program_Project3()
{
	string test[4] = { "first string", "second string", "third string", "four string" };
	StringSet object1, object2(test);
	
	cout << "Testing for constructor, object2 after initilizing by an array!\n";
	object2.outputSet();

	cout << "\nCurrent size of object2 is: " << object2.getLengthSet() << endl;
	
	object2.addEntry("fifth string");
	object2.deleteEntry("second string");
	cout << "\nTesting for add \"fifth string\" and delete \"second string\" entry.";
	cout << "\nObject2 after adding and deleting!\n";
	object2.outputSet();

	string test1[4] = { "first for new array", "second for new array", "third for new array", "first string"};
	StringSet object3(test1);
	cout << "\nObject3 is:\n";
	object3.outputSet();

	object1 = object2 + object3;
	cout << "\nObject1 after using: object1 = object2 + object3\n";
	object1.outputSet();

	object1 = object2 * object3;
	cout << "\nObject1 after using: object1 = object2 * object3\n";
	object1.outputSet();

	object1.clearSet();
	cout << "\nObject1 after clear: \n";
	object1.outputSet();
}