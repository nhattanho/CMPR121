// Nhat Ho
// CMPR121

#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;
#define ASCII_OF_LETTER 123 // a - z <=> 97 - 122

/**************************************************************************/
void setColors(WORD tColor, WORD bColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), tColor + (bColor * 16));
}
/**************************************************************************/

/**************************************************************************/
void displayMenu()
{
	setColors(13, 0);
	cout << "\n\t" << char(201) << string(30, char(205)) << char(187) << "\n\t" << char(186);
	setColors(15, 1);
	cout << "          CHAPTER 8           ";
	setColors(13, 0);
	cout << char(186) << "\n\t" << char(204) << string(30, char(205)) << char(185) << "\n\t" << char(186);
	setColors(15, 4);
	cout << "   1: Practice Proggram 1     ";
	setColors(13, 0);
	cout << char(186) << "\n\t" << char(186);
	setColors(15, 4);
	cout << "   2: Practice Proggram 2     ";
	setColors(13, 0);
	cout << char(186) << "\n\t" << char(186);
	setColors(15, 4);
	cout << "   3: Practice Proggram 4     ";
	setColors(13, 0);
	cout << char(186) << "\n\t" << char(186);
	setColors(15, 4);
	cout << "   4: Practice Proggram 5     ";
	setColors(13, 0);
	cout << char(186) << "\n\t" << char(186);
	setColors(15, 4);
	cout << "   5: Practice Proggram 7     ";
	setColors(13, 0);
	cout << char(186) << "\n\t" << char(186);
	setColors(15, 4);
	cout << "   6: Programming Project 1   ";
	setColors(13, 0);
	cout << char(186) << "\n\t" << char(186);
	setColors(15, 4);
	cout << "   7: Programming Project 4   ";
	setColors(13, 0);
	cout << char(186) << "\n\t" << char(186);
	setColors(15, 4);
	cout << "   8: Programming Project 14  ";
	setColors(13, 0);
	cout << char(186) << "\n\t" << char(186);
	setColors(15, 4);
	cout << "   9: Programming Project 15  ";
	setColors(13, 0);
	cout << char(186) << "\n\t" << char(186);
	setColors(15, 4);
	cout << "  10: Programming Project 18  ";
	setColors(13, 0);
	cout << char(186) << "\n\t" << char(200) << string(30, char(205)) << char(188) << "\n";
	setColors(15, 0);
	cout << " \t  Option: ";
}
/**************************************************************************/

/**************************************************************************/
void PracticeProgram1();

void PracticeProgram2();

bool firstlast2(vector <int> test);
int getInt(string prompt);
void PracticeProgram4();

bool swapFrontBack(vector<int>& test);
void PracticeProgram5();

string getString(string prompt);
string lowerCase(string name);
bool checkVowel(char c);
string changeName(string name);
void PracticeProgram7();

void lowerCaseForCstring(char array[]);
void removeMoreBlank(char line[], int length);
void removeMorePunct(char line[], int length);
void ProgrammingProject1();

char getChar(string prompt);
bool getBool(string prompt);
void ProgrammingProject4();

string getLine(string prompt);
vector<string> splitFuntion(string target, string delimiter);
void ProgrammingProject14();

string removeAnyExceptLetter(string line);
bool checkAnagram(string str1, string str2);
void ProgrammingProject15();

bool splitTime(string time, vector<int>& partOfTime, string& typeTime);
void getTime(string time, vector<int>& partOfTime, string& typeTime);
void changeToMilitary(vector<int>& time, string type, int realizeTime);
void ProgrammingProject18();

/**********************MAIN**************************/
int main()
{
	while (true)
	{
		system("cls");
		displayMenu();
		char option[80];
		setColors(14, 0);
		cin.getline(option, 80, '\n');
		setColors(15, 0);
		switch (atoi(option))
		{
		case 1: PracticeProgram1(); break;
		case 2: PracticeProgram2(); break;
		case 3: PracticeProgram4(); break;
		case 4: PracticeProgram5(); break;
		case 5: PracticeProgram7(); break;
		case 6: ProgrammingProject1(); break;
		case 7: ProgrammingProject4(); break;
		case 8: ProgrammingProject14(); break;
		case 9: ProgrammingProject15(); break;
		case 10: ProgrammingProject18(); break;
		default: return 0;
		}
		system("pause");
	}

	return 0;
}
/**************************************************************************/

/**********************PRACTICE PROGRAM 1*********************/
void PracticeProgram1()
{
	char input[81];
	cout << "Enter a C string contains a name, age, and title following this format <name age title>: ";
	cin.getline(input, 80);
	int firstspace = 0;
	int secondspace = 0;
	char name[80], age[5], title[80];
	int j = 0;
	for (int c = 0; c < strlen(input); c++)
	{
		if ((input[c] == ' ' && firstspace == 0))
		{
			firstspace = c;
			continue;
		}

		if ((input[c] == ' ' && firstspace != 0 && secondspace == 0))
			secondspace = c;
	}
	for (int c = 0; c < firstspace; c++)
	{
		name[c] = input[c];
		j = c + 1;
	}
	name[j] = '\0';
	j = 0;
	for (int c = firstspace + 1; c < secondspace; c++)
	{
		age[j] = input[c];
		j++;
	}
	age[j] = '\0';
	j = 0;
	for (int c = secondspace + 1; c < strlen(input); c++)
	{
		title[j] = input[c];
		j++;
	}
	title[j] = '\0';
	cout << "name is " << name << ", age is " << age << " and " << "title is " << title << "." << endl;

}
/**************************************************************************/

/*************************PRACTICE PROGRAM 2********************/
void PracticeProgram2()
{
	string input;
	cout << "Enter a string contains a name, age, and title following this format <name age title>:";
	getline(cin, input);
	if (input.length() > 0)
	{
		int firstspace = 0;
		int secondspace = 0;
		string name, age, title;
		for (int c = 0; c < input.length(); c++)
		{
			if ((input[c] == ' ' && firstspace == 0))
			{
				firstspace = c;
				continue;
			}

			if ((input[c] == ' ' && firstspace != 0 && secondspace == 0))
				secondspace = c;
		}
		// Get each of part
		name = input.substr(0, firstspace);
		age = input.substr(firstspace + 1, secondspace - firstspace - 1);
		title = input.substr(secondspace + 1, input.length() - secondspace - 1);
		// Display three parts
		cout << "name is " << name << endl;
		cout << "age is " << age << endl;
		cout << "title is " << title << endl;
	}
	else
		cout << "You donnot want to enter anything, bye!" << endl;
}
/**************************************************************************/

/*************************PRACTICE PROGRAM 4*******************/
bool firstlast2(vector <int> test)
{
	if (test.size() > 0)
	{
		if (test[0] == 2 || test[test.size() - 1] == 2)
			return true;
		else
			return false;
	}
	else
		return false;
}

int getInt(string prompt)
{
	while (true)
	{
		int number;
		cout << prompt;
		cin >> number;
		cin.ignore(999, '\n');
		if (!cin.fail()) return number;
		cin.clear();
		cin.ignore();
		cout << "Error: Non-numeric input. Try Again." << endl;
	}
}

void PracticeProgram4()
{
	vector <int> test;
	int quantity, number;
	quantity = getInt("How many number do you want in your vector? ");
	if (quantity > 0)
	{
		for (int i = 0; i < quantity; i++)
		{
			number = getInt("Please enter a number: ");
			test.push_back(number);
		}
		if (firstlast2(test))
			cout << "Yes, it has a 2 at first or end of vector.\n";
		else
		{
			cout << "The vector should not be empty!" << endl;
			cout << "If the vector is not empty, it does not has a 2 at first or end of vector.\n" << endl;
		}
		test.clear();
	}
	else
		cout << "You don't want to make a vector?, bye!" << endl;
}
/**************************************************************************/

/***********************PRACTICE PROGRAM 5************************/
bool swapFrontBack(vector<int>& test)
{
	if (test.size() > 0)
	{
		int temp;
		cout << "The first element before swapping " << test[0] << endl;
		cout << "The last element before swapping " << test[test.size() - 1] << endl;
		temp = test[0];
		test[0] = test[test.size() - 1];
		test[test.size() - 1] = temp;
		return true;
	}
	else
		return false;
}

void PracticeProgram5()
{
	vector <int> test;
	int quantity, number;
	quantity = getInt("How many number do you want in your vector? ");
	if (quantity > 0)
	{
		for (int i = 0; i < quantity; i++)
		{
			number = getInt("Please enter a number: ");
			test.push_back(number);
		}
		if (swapFrontBack(test))
		{
			cout << "The first element after swapping " << test[0] << endl;
			cout << "The last element after swapping " << test[test.size() - 1] << endl;
		}
		else
			cout << "The vector should not be empty, try again!" << endl;
	}
	else
		cout << "You don't want to make a vector?, bye!" << endl;
}
/**************************************************************************/

/*********************PRACTICE PROGRAM 7*********************/
string getString(string prompt)
{
	while (true)
	{
		string userAnswer;
		cout << prompt;
		cin >> userAnswer;
		cin.ignore(999, '\n');
		if (!cin.fail()) return userAnswer;
		cin.clear();
		cin.ignore();
		cout << "Input failed, try again" << endl;
	}
}

string lowerCase(string name)
{
	for (int i = 0; i < name.length(); i++)
	{
		if (!islower(name[i]))
			name[i] = tolower(name[i]);
	}
	return name;
}

bool checkVowel(char c)
{
	c = tolower(c);
	if (c == 'u' || c == 'e' || c == 'o' || c == 'a' || c == 'i')
		return true;
	else
		return false;
}

string changeName(string name)
{
	int len = name.length();
	string newName;
	if (checkVowel(name[0]))
		name = name + "way";
	else
	{
		newName = name.substr(1, len - 1);
		name = newName + name[0] + "ay";
	}
	name[0] = toupper(name[0]);
	return name;
}

void PracticeProgram7()
{
	string first, last, fullName;
	first = getString("Please enter the first name: ");
	first = lowerCase(first);
	first = changeName(first);
	last = getString("Please enter the last name: ");
	last = lowerCase(last);
	last = changeName(last);
	cout << "first: " << first << endl;
	cout << "last: " << last << endl;
	fullName = first + " " + last;
	cout << "Fullname is: " << fullName << endl;
}
/****************************END PROGRAM7***********************************/

/************************* **PROGRAMMING PROJECT 1*********************/
void lowerCaseForCstring(char array[])
{
	for (int i = 0; i < strlen(array); i++)
	{
		if (!islower(array[i]))
			array[i] = tolower(array[i]);
	}
}

void removeMoreBlank(char line[], int length)
{
	int i = 0, j = 0;
	while (length > 0)
	{
		// Check with the break line
		if (line[i] == '\n')
		{
			line[i] = ' ';
		}
		//  Blank characters are either the tab character ('\t') or the space character (' ')
		if (isblank(line[i]) && !isblank(line[i + 1]))
		{
			// Example a blank next to the comma ==> ignore
			if (ispunct(line[i + 1]) || line[i + 1] == '\n')
			{
				i++;
				length--;
				continue;
			}
			else
				line[i] = ' ';
		}
		// Two more blanks next to each other
		else if (isblank(line[i]) && isblank(line[i + 1]))
		{
			i++;
			length--;
			continue;
		}

		line[j] = line[i];
		j++;
		i++;
		length--;
	}
	line[j] = '\0';
}

// Concentrating to remove more commas next to each other
void removeMorePunct(char line[], int length)
{
	int j = 0;
	for (int i = 0; i < length; i++)
	{
		if (ispunct(line[i]) && ispunct(line[i + 1]))
		{
			continue;
		}
		line[j] = line[i];
		j++;
	}
	line[j] = '\0';
}

void ProgrammingProject1()
{
	//Can check with line[101] = "ho nhat    tan ,, is my \n name is ho nhat  tan.";
	char line[101];
	int length;
	while (true)
	{
		cout << "Please enter your sentence (upto 100 character and end with a period):" << endl;
		cin.getline(line, 101);
		length = strlen(line);
		if (length == 0)
		{
			cout << "Eror: The length of sentence is empty. Try again!";
			continue;
		}
		if (line[length - 1] != '.')
		{
			cout << "The end of sentences should be a period!" << endl;
			continue;
		}
		else
			break;
	}

	lowerCaseForCstring(line);
	line[0] = toupper(line[0]);
	removeMoreBlank(line, length);
	removeMorePunct(line, length);
	cout << line << endl;
}

/******************PROGRAMMING PROJECT 4******************/
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
		cin.ignore();
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

void ProgrammingProject4()
{
	string firstName, middleOrInitialName, lastName, outName;
	string input;
	int firstspace = 0;
	int secondspace = 0;
	cout << "Enter your full name following this format <fisrtname middle/initial lastname>" << endl;
	cout << "or <fisrtname lastname>" << endl;
	getline(cin, input);
	if (input.length() > 0)
	{
		for (int c = 0; c < input.length(); c++)
		{
			if ((input[c] == ' ' && firstspace == 0))
			{
				firstspace = c;
				continue;
			}

			if ((input[c] == ' ' && firstspace != 0 && secondspace == 0))
				secondspace = c;
		}

		// This case we have middile or initial name
		if (secondspace != 0)
		{
			// Get each of part
			firstName = input.substr(0, firstspace);
			middleOrInitialName = input.substr(firstspace + 1, secondspace - firstspace - 1);
			middleOrInitialName = middleOrInitialName[0];
			middleOrInitialName += '.';
			lastName = input.substr(secondspace + 1, input.length() - secondspace - 1);
			outName = lastName + ", " + firstName + " " + middleOrInitialName;
		}
		// We don't get middile or initial name
		else
		{
			firstName = input.substr(0, firstspace);
			lastName = input.substr(firstspace + 1, input.length() - firstspace - 1);
			outName = lastName + ", " + firstName;
		}
		cout << "Name is: " << outName << endl;
	}
	else
		cout << "You have to input your full name, try again!" << endl;
}
/**************************************************************************/

/**********************PROGRAMMING PROJECT 14********************/
string getLine(string prompt)
{
	while (true)
	{
		string userAnswer;
		cout << prompt;
		getline(cin, userAnswer);
		if (!cin.fail()) return userAnswer;
		cin.clear();
		cin.ignore(); // get rid of what killed it
		cout << "Input failed, try again" << endl;
	}
}

vector<string> splitFuntion(string target, string delimiter)
{
	vector<string> test;
	int i = 0;
	int pos = target.find(delimiter);
	while (pos != string::npos) {
		test.push_back(target.substr(i, pos - i));
		// Moving to the next apart of string
		i = ++pos;
		pos = target.find(delimiter, pos);
		if (pos == string::npos)
			test.push_back(target.substr(i, target.length() - i));
	}
	return test;
}

void ProgrammingProject14()
{
	vector<string> test;
	// Example: string: "ho-nhat-tan-is-my-name", delimiter: "-"
	// or "ho nhat tan is my name", delimiter: " "
	string target = getLine("Please enter your string with delimiter: ");
	string delimiter = getLine("Please enter your delimiter: ");
	test = splitFuntion(target, delimiter);

	// display the vector after spiliting
	for (int i = 0; i < test.size(); i++)
	{
		if (i != test.size() - 1)
		{
			cout << test[i] << ",";
		}
		else
			cout << " and " << test[i] << "." << endl;
	}
	test.clear();
}
/**************************************************************************/

/*******************PROGRAMMING PROJECT 15******************/
string removeAnyExceptLetter(string line)
{
	string lineAfterRemove;
	int length = line.length();
	for (int c = 0; c < length; c++)
	{
		if (isalpha(line[c]))
		{
			lineAfterRemove += line[c];
		}
	}
	return lineAfterRemove;
}

bool checkAnagram(string str1, string str2)
{
	int count[ASCII_OF_LETTER] = { 0 };
	int len1 = str1.length();
	int len2 = str2.length();
	if (len1 != len2)
	{
		return false;
	}

	// a - z <=> 97 - 122 => the number of each letter will be stored in count[]
	// from count[97] - count[122]
	for (int c = 0; c < len1; c++)
	{
		count[str1[c]]++; // increasing number of each letter
		count[str2[c]]--; // decreasing number of each letter
	}
	/*
	if two string are anagram, finally, the values of all elements in array count[]
	has to be 0
	*/
	for (int c = 97; c < ASCII_OF_LETTER; c++)
	{
		if (count[c] != 0) // two strings has at least one different letter.
			return false;
	}
	return true;
}

void ProgrammingProject15()
{
	string str1 = getLine("Please enter your first string: ");
	str1 = lowerCase(str1);
	str1 = removeAnyExceptLetter(str1);
	string str2 = getLine("Please enter your second string: ");
	str2 = lowerCase(str2);
	str2 = removeAnyExceptLetter(str2);

	cout << "first string: " << str1 << "." << endl;
	cout << "second string: " << str2 << "." << endl;

	if (checkAnagram(str1, str2))
		cout << "Two string are anagram." << endl;
	else
		cout << "Two string are not anagram" << endl;
}

/********************PROGRAMMING PROJECT 18*****************/
bool splitTime(string time, vector<int>& partOfTime, string& typeTime)
{
	if (time.length() != 11)
		return false;
	for (int c = 0; c < 8; c++)
	{
		if (c != 2 && c != 5 && !isdigit(time[c]))
			return false;
	}

	string hourTime, minuteTime, secondTime;
	int hours, minutes, seconds;

	hourTime = time.substr(0, 2);
	hours = stoi(hourTime);

	minuteTime = time.substr(3, 4);
	minutes = stoi(minuteTime);

	secondTime = time.substr(6, 7);
	seconds = stoi(secondTime);

	if (hours < 1 || hours > 12 || minutes < 0 || minutes >= 60 || seconds < 0 || seconds >= 60)
	{
		return false;
	}

	typeTime = time.substr(9, 10);
	typeTime = lowerCase(typeTime);
	if (typeTime != "am" && typeTime != "pm")
		return false;
	partOfTime.clear();
	partOfTime.push_back(hours);
	partOfTime.push_back(minutes);
	partOfTime.push_back(seconds);
	return true;
}

void getTime(string time, vector<int>& partOfTime, string& typeTime)
{
	time = getLine("Please enter the time: ");
	while (!splitTime(time, partOfTime, typeTime))
	{
		cout << "Your time is wrong format!, try again!" << endl;
		time = getLine("Please enter the time: ");
	}
}

void changeToMilitary(vector<int>& time, string type, int realizeTime)
{
	if (type == "pm" && time[0] != 12)
	{
		time[0] = time[0] + 12;
	}
	if (type == "am" && time[0] == 12)
	{
		if (realizeTime == 1)
			time[0] = 0;
		else
			time[0] = 24;
	}
}

void ProgrammingProject18()
{
	vector<int> partOfTime1(3), partOfTime2(3);
	string typeTime1, typeTime2;
	string time1, time2;
	int outTime[3];
	int decreaseHour = 0;
	cout << "The first and second time you input have to follow this format: <HH:MM:SS AM|PM> " << endl;
	cout << "-----------For first time------------" << endl;
	getTime(time1, partOfTime1, typeTime1);
	cout << "-----------For second time-----------" << endl;
	getTime(time2, partOfTime2, typeTime2);
	if (partOfTime1[0] != 12 || partOfTime2[0] != 12 || typeTime1 != "am" || typeTime2 != "am")
	{
		changeToMilitary(partOfTime1, typeTime1, 1); // fisrt time
		changeToMilitary(partOfTime2, typeTime2, 0); // second time
	}

	if (partOfTime2[2] < partOfTime1[2]) //second2 < second1
	{
		partOfTime2[2] += 60;
		partOfTime2[1]--;
	}
	outTime[2] = partOfTime2[2] - partOfTime1[2];

	if (partOfTime2[1] < partOfTime1[1]) // minute2 < minute1
	{
		partOfTime2[1] += 60;
		partOfTime2[0]--;
		//decreaseHour = -1;
	}
	outTime[1] = partOfTime2[1] - partOfTime1[1];

	if (partOfTime2[0] < partOfTime1[0]) // hour2 < hour1
	{
		partOfTime2[0] += 12;

		// hour2 < hour1 and am -> am, that means the time will pass to another day
		// for ex: 04:20:35 am --> 02:15:30 am
		if ((typeTime1 == "am" && typeTime2 == "am") || (typeTime1 == "pm" && typeTime2 == "am"))
			decreaseHour = -1;
	}
	outTime[0] = partOfTime2[0] - partOfTime1[0];
	if (outTime[0] < 0 || decreaseHour == -1)
	{
		outTime[0] += 12;
	}

	cout << "The time elapse is " << outTime[0] << " hours" << " and " << outTime[1] << " minutes and " << outTime[2] << " seconds." << endl;

	partOfTime1.clear();
	partOfTime2.clear();
}
/**************************************************************************/