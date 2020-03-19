// Nhat Ho
// CMPR121

#include <iostream>
#include <iomanip>
#include <string>
#include <ostream>
#include <vector>
#include <istream>s
using namespace std;
enum type { addCal = 1, subCal, mulCal, divCal, negCal };
/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
namespace Program1
{
	struct student
	{
		double quiz1, quiz2;
		double midterm, final, average;
		char letterGrade;
	};
}
char getChar(string prompt);
bool getBool(string prompt);
int getInt(string prompt);
double getDouble(string prompt, int order, int type);
void display(Program1::student* ptr, int order);
void Program_Project1();
/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
namespace Program2
{
	class student
	{
	private:
		double quiz1, quiz2;
		double midterm, final, average;
		char letterGrade;
	public:
		student() : quiz1(0.0), quiz2(0.0), midterm(0.0), final(0.0), letterGrade('\0') {}
		student(double newQuiz1, double newQuiz2, double newMidterm, double newfinal, char newLetterGrade)
		{
			quiz1 = newQuiz1;
			quiz2 = newQuiz2;
			midterm = newMidterm;
			final = newfinal;
			letterGrade = newLetterGrade;
		}
		double getQuiz1() const
		{
			return quiz1;
		}

		void setQuiz1(double newScore)
		{
			quiz1 = newScore;
		}

		double getQuiz2() const
		{
			return quiz2;
		}

		void setQuiz2(double newScore)
		{
			quiz2 = newScore;
		}

		double getMidterm() const
		{
			return midterm;
		}

		void setMidterm(double newScore)
		{
			midterm = newScore;
		}

		double getFinal() const
		{
			return final;
		}

		void setFinal(double newScore)
		{
			final = newScore;
		}

		void calculateAverage()
		{
			average = final * 0.5 + midterm * 0.25 + (quiz1 + quiz2)*1.25;
		}

		double getAverage() const
		{
			return average;
		}
		void calculateLetterGrade()
		{
			if (average >= 90)
				letterGrade = 'A';
			else if (average >= 80 && average < 90)
				letterGrade = 'B';
			else if (average >= 70 && average < 80)
				letterGrade = 'C';
			else if (average >= 60 && average < 70)
				letterGrade = 'D';
			else
				letterGrade = 'F';
		}
		char getLetterGrade()
		{
			return letterGrade;
		}
	};
}
void display(Program2::student* ptr, int order);
void Program_Project2();
/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
class rational
{
private:
	int numerator, denominator;
public:
	rational() : numerator(0), denominator(0) {}
	rational(int newNumerator, int newdenominator) : numerator(newNumerator), denominator(newdenominator) {}
	void positiveDenominator()
	{
		if (denominator < 0)
		{
			denominator *= -1;
			numerator *= -1;
		}
	}
	int getInt7(string prompt, int type, istream& ins)
	{
		while (true)
		{
			int number;
			cout << prompt << ": ";
			ins >> number;
			ins.ignore(999, '\n');
			if (!ins.fail())
			{
				if (type == 1 && number == 0)
				{
					cout << "Denominator can not be zero, try again!" << endl;
					continue;
				}
				return number;
			}
			ins.clear();
			ins.ignore(999, '\n');
			cout << "Error: Non-numeric input. Try Again." << endl;
		}
	}
	rational add(rational* second)
	{
		rational temp;
		temp.numerator = numerator * second->denominator + denominator * second->numerator;
		temp.denominator = denominator * second->denominator;
		return temp;
	}
	rational sub(rational* second)
	{
		rational temp;
		temp.numerator = numerator * second->denominator - denominator * second->numerator;
		temp.denominator = denominator * second->denominator;
		return temp;
	}
	rational mul(rational* second)
	{
		rational temp;
		temp.numerator = numerator * second->numerator;
		temp.denominator = denominator * second->denominator;
		return temp;
	}
	rational div(rational* second)
	{
		rational temp;
		temp.numerator = numerator * second->denominator;
		temp.denominator = denominator * second->numerator;
		return temp;
	}
	rational neg()
	{
		rational temp;
		temp.numerator = numerator * -1;
		temp.denominator = denominator;
		return temp;
	}
	bool less(rational* second)
	{ 
		int tempNumerator = numerator;
		int tempDenominator = denominator;
		if (denominator < 0)
		{
			tempDenominator = denominator * -1;
			tempNumerator = numerator * -1;
		}
		second->positiveDenominator();
		if (tempNumerator * second->denominator < tempDenominator * second->numerator)
			return true;
		return false;
	}
	bool equal(rational* second)
	{
		if (numerator * second->denominator == denominator * second->numerator)
			return true;
		return false;
	}
	void input(istream& ins)
	{
		numerator = getInt7("Enter an integer nunber of numerator for rational ", 0, ins);
		denominator = getInt7("Enter an integer nunber of denominator for rational ", 1, ins);
	}
	void output(ostream& outs)
	{
		outs << numerator << "/" << denominator;
	}
};
void outputCalculation(rational* one, rational* two, rational* outputResult, type cal);
void outputLess(rational* one, rational* two, bool less);
void outputEqual(rational* one, rational* two, bool equal);
void Program_Project7();
/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
class Odometer {
private:
	double milesDriven;
	double fuelEfficiency;
public:
	Odometer() : milesDriven(0.0), fuelEfficiency(0.0) {}
	void reset()
	{
		milesDriven = 0;
		fuelEfficiency = 0;
	}
	void setFuelEfficiency(double extraFuel) //MPG
	{
		fuelEfficiency += extraFuel;
	}
	void setMilesDriven(double extraMiles)
	{
		milesDriven += extraMiles;
	}
	double getTotalMilesDriven() const
	{
		return milesDriven;
	}
	double getGallonsConsumed() const
	{
		return fuelEfficiency;
	}
	double getTripMpg(double miles, double fuel) const
	{
		if (miles == 0 || fuel == 0)
			return 0;
		return miles / fuel;
	}
	double getTotalMpg() const
	{
		if (milesDriven == 0 || fuelEfficiency == 0)
			return 0;
		return milesDriven / fuelEfficiency;
	}
};
double getDouble8(string prompt);
void Program_Project8();
/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
class Movie
{
private:
	string name, MPAARating;
	int number_1Terribles, number_2Bads, number_3Oks;
	int number_4Goods, number_5Greats;
public:
	Movie(string nameMovie, string ratingMPAA) : name(nameMovie), MPAARating(ratingMPAA)
	{
		number_1Terribles = 0;
		number_2Bads = 0;
		number_3Oks = 0;
		number_4Goods = 0;
		number_5Greats = 0;
	}
	void addRating(int type)
	{
		switch (type)
		{
		case 1:
			number_1Terribles++;
			break;
		case 2:
			number_2Bads++;
			break;
		case 3:
			number_3Oks++;
			break;
		case 4:
			number_4Goods++;
			break;
		case 5:
			number_5Greats++;
			break;
		}
	}
	void setName(string newName)
	{
		name = newName;
	}
	string getName() const
	{
		return name;
	}
	void setMPAARating(string newMPAARating)
	{
		MPAARating = newMPAARating;
	}
	string getMPAARating() const
	{
		return MPAARating;
	}
	double getAverage()
	{
		double average = (double)(number_1Terribles * 1.0 + number_2Bads * 2.0 + number_3Oks * 3.0
			+ number_4Goods * 4.0 + number_5Greats * 5.0);
		average /= (number_1Terribles + number_2Bads + number_3Oks + number_4Goods + number_5Greats);
		return average;
	}
};
string getLine(string prompt);
int getInt11(string prompt);
void display(vector <Movie> listMovie);
void Program_Project11();
/*------------------------------------------------------------------------MAIN-------------------------------------------------------------------*/
int main()
{
	while (true)
	{
		system("cls");
		cout << "\n\t\tNhat Ho ---- Chapter 10" << endl;
		cout << "=================================================================" << endl;
		cout << " 1: Programming Project1 using struct of one object" << endl;
		cout << " 2: Programming Project2 using class and dynamic array of objects" << endl;
		cout << " 3: Programming Project7 using class and dynamic array of objects" << endl;
		cout << " 4: Programming Project8 using class and dynamic array of objects" << endl;
		cout << " 5: Programming Project11 using class and vector" << endl;
		cout << "=================================================================" << endl;
		cout << " option: ";
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);
		char option[80];
		cin.getline(option, 80, '\n');
		cout << endl;
		switch (atoi(option))
		{
		case 1: Program_Project1(); break;
		case 2: Program_Project2(); break;
		case 3: Program_Project7(); break;
		case 4: Program_Project8(); break;
		case 5: Program_Project11(); break;
		default: exit(0);
		}
		cout << endl;
		system("pause");
		cin.clear();
	}
	return 0;
}

/*----------------------------------------------------------Program_Project 1---------------------------------------------------*/
char getChar(string prompt)
{
	while (true)
	{
		char userAnswer;
		cout << prompt;
		cin >> userAnswer;
		cin.ignore(999, '\n');
		if (!cin.fail()) return userAnswer;
		cin.clear();
		cin.ignore(999, '\n');
		cout << "Input failed, try again" << endl;
	}
}

bool getBool(string prompt)
{
	while (true)
	{
		switch (getChar(prompt))
		{
		case 'Y': case 'y': return true;
		case 'N': case 'n': return false;
		}
		cout << "please enter y or n" << endl;
	}
}

int getInt(string prompt)
{
	while (true)
	{
		int number;
		cout << prompt;
		cin >> number;
		cin.ignore(999, '\n');
		if (!cin.fail())
		{
			if (number < 0)
			{
				cout << "The number can not be negative!\n";
				continue;
			}
			return number;
		}
		cin.clear();
		cin.ignore(999, '\n');
		cout << "Error: Non-numeric input. Try Again." << endl;
	}
}

double getDouble(string prompt, int order, int type)
{
	while (true)
	{
		double number;
		cout << prompt << order << ": ";
		cin >> number;
		cin.ignore(999, '\n');
		if (!cin.fail())
		{
			switch (type)
			{
			case 1:
				if (number < 0 || number > 100)
				{
					cout << "The score has to be in [0-100], try again!\n";
					continue;
				}
				break;
			case 2:
				if (number < 0 || number > 10)
				{
					cout << "The score has to be in [0-10], try again!\n";
					continue;
				}
				break;
			}
			return number;
		}
		cin.clear();
		cin.ignore(999, '\n');
		cout << "Error: Non-numeric input. Try Again." << endl;
	}
}

void display(Program1::student* ptr, int order)
{
	cout << "Student Record\n";
	cout << "------------------------------------------------------------------------------\n";
	cout << "The quiz 1 score of the student " << order << " is: " << ptr->quiz1 << endl;
	cout << "The quiz 2 score of the student " << order << " is: " << ptr->quiz2 << endl;
	cout << "The midterm score of the student " << order << " is: " << ptr->midterm << endl;
	cout << "The final score score of the student " << order << " is: " << ptr->final << endl;
	cout << "The average score of the student " << order << " is: " << ptr->average << endl;
	cout << "The letter Grade of the student " << order << " is: " << ptr->letterGrade << "\n" << endl;
}

void Program_Project1()
{
	using namespace Program1;
	student *ptr;
	int number;
	do
	{
		number = getInt("Enter the number student for test: ");
		ptr = new student[number];

		for (int c = 0; c < number; c++)
		{
			// initialize all scores to be zero
			ptr->final = 0.0;
			ptr->midterm = 0.0;
			ptr->quiz1 = 0.0;
			ptr->quiz2 = 0.0;
			ptr->letterGrade = '\0';

			// read scores of the students
			ptr->quiz1 = getDouble("Enter the numeric score [0..10] of Quiz #1 for the student ", c + 1, 2);
			ptr->quiz2 = getDouble("Enter the numeric score [0..10] of Quiz #2 for the student ", c + 1, 2);
			ptr->midterm = getDouble("Enter the numeric score [0..100] of midterm for the student ", c + 1, 1);
			ptr->final = getDouble("Enter the numeric score [0..100] of final for the student ", c + 1, 1);

			// calculate the average 
			ptr->average = ptr->final * 0.5 + ptr->midterm * 0.25 + (ptr->quiz1 + ptr->quiz2)*1.25;

			if (ptr->average >= 90)
				ptr->letterGrade = 'A';
			else if (ptr->average >= 80 && ptr->average < 90)
				ptr->letterGrade = 'B';
			else if (ptr->average >= 70 && ptr->average < 80)
				ptr->letterGrade = 'C';
			else if (ptr->average >= 60 && ptr->average < 70)
				ptr->letterGrade = 'D';
			else
				ptr->letterGrade = 'F';
			display(ptr, c + 1);
			ptr++;
		}
	} while (getBool("Do you want to continue (y/n)?"));
	ptr = new student[number];
	delete[] ptr;
}

/*------------------------------------------------------------Program_Project 2--------------------------------------------------------*/
void display(Program2::student* ptr, int order)
{
	cout << "Student Record\n";
	cout << "------------------------------------------------------------------------------\n";
	cout << "The quiz 1 score of the student " << order << " is: " << ptr->getQuiz1() << endl;
	cout << "The quiz 2 score of the student " << order << " is: " << ptr->getQuiz2() << endl;
	cout << "The midterm score of the student " << order << " is: " << ptr->getMidterm() << endl;
	cout << "The final score score of the student " << order << " is: " << ptr->getFinal() << endl;
	cout << "The average score of the student " << order << " is: " << ptr->getAverage() << endl;
	cout << "The letter Grade of the student " << order << " is: " << ptr->getLetterGrade() << "\n" << endl;
}

void Program_Project2()
{
	using namespace Program2;

	student *ptr;
	int number;
	double input;
	do
	{
		number = getInt("Enter the number student for test: ");
		ptr = new student[number];

		for (int c = 0; c < number; c++)
		{
			*ptr;
			input = getDouble("Enter the numeric score [0..10] of Quiz #1 for the student ", c + 1, 2);
			ptr->setQuiz1(input);
			input = getDouble("Enter the numeric score [0..10] of Quiz #2 for the student ", c + 1, 2);
			ptr->setQuiz2(input);
			input = getDouble("Enter the numeric score [0..100] of midterm for the student ", c + 1, 1);
			ptr->setMidterm(input);
			input = getDouble("Enter the numeric score [0..100] of final for the student ", c + 1, 1);
			ptr->setFinal(input);
			ptr->calculateAverage();
			ptr->calculateLetterGrade();
			display(ptr, c + 1);
			ptr++;
		}
	} while (getBool("Do you want to continue (y/n)?"));
	ptr = new student[number];
	delete[] ptr;
}

/*-------------------------------------------------------Program_Project 7----------------------------------------------------*/
void outputCalculation(rational* one, rational* two, rational* outputResult, type cal)
{
	if (cal == negCal)
	{
		cout << "-(";
		one->output(cout);
		cout << ") = ";
		outputResult->positiveDenominator();
		outputResult->output(cout);
	}
	else
	{
		one->output(cout);
		switch (cal)
		{
		case (addCal):
			cout << " + ";
			break;
		case (subCal):
			cout << " - ";
			break;
		case (mulCal):
			cout << " * ";
			break;
		case (divCal):
			cout << " / ";
			break;
		}
		two->output(cout);
		cout << " = ";
		outputResult->positiveDenominator();
		outputResult->output(cout);
	}
	cout << endl;
}

void outputLess(rational* one, rational* two, bool less)
{
	one->output(cout);
	cout << " < ";
	two->output(cout);
	cout << "? ";
	if (less == true)
		cout << "true" << endl;
	else
		cout << "false" << endl;
}

void outputEqual(rational* one, rational* two, bool equal)
{
	one->output(cout);
	cout << " == ";
	two->output(cout);
	cout << "? ";
	if (equal == true)
		cout << "true" << endl;
	else
		cout << "false" << endl;
}

void Program_Project7()
{
	rational *ptr = new rational[2];
	rational *outputResult = new rational;
	int numerator, denominator;
	for (int c = 0; c < 2; c++)
	{
		cout << "Rational number " << c + 1 << endl;
		cout << "----------------------------------------------------------------------\n";
		ptr[c].input(cin);
		cout << endl;
	}

	*outputResult = ptr->add(ptr + 1);
	outputCalculation(ptr, ptr + 1, outputResult, addCal);

	*outputResult = ptr->sub(ptr + 1);
	outputCalculation(ptr, ptr + 1, outputResult, subCal);

	*outputResult = ptr->mul(ptr + 1);
	outputCalculation(ptr, ptr + 1, outputResult, mulCal);

	*outputResult = ptr->div(ptr + 1);
	outputCalculation(ptr, ptr + 1, outputResult, divCal);

	*outputResult = ptr->neg();
	outputCalculation(ptr, ptr + 1, outputResult, negCal);

	bool lessResult = ptr->less(ptr + 1);
	outputLess(ptr, ptr + 1, lessResult);

	bool equalCheck = ptr->equal(ptr + 1);
	outputEqual(ptr, ptr + 1, equalCheck);

	delete[] ptr;
	delete outputResult;
}
/*--------------------------------------------------------Program_Project 8--------------------------------------------------*/
double getDouble8(string prompt)
{
	while (true)
	{
		double number;
		cout << prompt;
		cin >> number;
		cin.ignore(999, '\n');
		if (!cin.fail())
		{
			if (number < 0)
			{
				cout << "The number can not be less then zero, try again!\n";
				continue;
			}
			return number;
		}
		cin.clear();
		cin.ignore(999, '\n');
		cout << "Error: Non-numeric input. Try Again." << endl;
	}
}

void Program_Project8()
{
	int number;
	double milesDriven, gallonsUsed;
	Odometer* ptr;
	number = getInt("Enter the number of cars: ");
	ptr = new Odometer[number]();

	int option;
	for (int c = 0; c < number; c++)
	{
		do
		{
			cout << "\nSelect option for car #" << c + 1 << endl;
			option = getInt("(1) Enter Trip \n(2) Reset Odometer \n(3) Exit to get result\noption: ");
			switch (option)
			{
			case 1:
				milesDriven = getDouble8("Enter the positive number of miles driven: ");
				ptr[c].setMilesDriven(milesDriven);
				gallonsUsed = getDouble8("Enter the positive number of gallons used: ");
				ptr[c].setFuelEfficiency(gallonsUsed);
				cout << "This Trip Averaged " << ptr[c].getTripMpg(milesDriven, gallonsUsed) << " MPG.\n";
				break;
			case 2:
				ptr[c].reset();
				cout << "The odometer is reseted to zero!\n";
				break;
			default:
				option = 3;
				break;
			}
		} while (option != 3);
	}

	for (int c = 0; c < number; c++)
	{
		cout << "Information of car #" << c + 1 << endl;
		cout << "----------------------------------------------------------------------------------\n";
		cout << "Number of miles driven since last refuel: " << ptr[c].getTotalMilesDriven() << endl;
		cout << "Number of gallons used since last refuel: " << ptr[c].getGallonsConsumed() << endl;
		cout << "OverAll MPG: " << ptr[c].getTotalMpg() << endl;
		cout << endl;
	}
	delete[] ptr;
}

/*------------------------------------------------------------Program_Project 11---------------------------------------------------*/
string getLine(string prompt)
{
	while (true)
	{
		string userAnswer;
		cout << prompt;
		getline(cin, userAnswer);
		if (!cin.fail()) return userAnswer;
		cin.clear();
		cin.ignore();
		cout << "Input failed, try again" << endl;
	}
}

int getInt11(string prompt)
{
	while (true)
	{
		int number;
		cout << prompt;
		cin >> number;
		cin.ignore(999, '\n');
		if (!cin.fail())
		{
			if (number < 1 || number > 5)
			{
				cout << "The type of rating has to be in [1-5]!\n";
				continue;
			}
			return number;
		}
		cin.clear();
		cin.ignore(999, '\n');
		cout << "Error: Non-numeric input. Try Again." << endl;
	}
}

void display(vector <Movie> listMovie)
{
	if (listMovie.size() > 0)
	{
		for (int c = 0; c < listMovie.size(); c++)
		{
			cout << "\nMovie #" << c + 1 << endl;
			cout << "--------------------------------------------\n";
			cout << "Name: " << listMovie[c].getName() << endl;
			cout << "MPPA Rating: " << listMovie[c].getMPAARating() << endl;
			cout << "Average Rating: " << listMovie[c].getAverage() << endl;
		}
	}
	else
		cout << "You don't have enter any movies!\n";
}

void Program_Project11()
{
	vector <Movie> listMovie;
	string nameMovie, ratingMPPA;
	int typeRating, count = 0;
	do
	{
		nameMovie = getLine("\nEnter the name of the movie: ");
		ratingMPPA = getLine("\nEnter the MPAA Rating (G, PG, PG-13, R, etc...) of this movie: ");
		Movie movie(nameMovie, ratingMPPA);
		listMovie.push_back(movie);
		do
		{
			typeRating = getInt11("Movie rating(1 - Terrible, 2 - Bad, 3 - OK, 4 - Good, or 5 - Great)? ");
			listMovie[count].addRating(typeRating);

		} while (getBool("Continue rating this movie, (Y - yes or N - no)? "));
		count++;
	} while (getBool("Continue adding a new movie(Y - yes or N - no)? "));

	display(listMovie);
}
/*----------------------------------------------------------------------------------------------------------------------------------------------------*/