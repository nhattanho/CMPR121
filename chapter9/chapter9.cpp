// Nhat Ho
//HomeWork Chapter 9
// 09/15/2018
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef char* charPtr;
typedef string* stringPtr;
typedef int* intPtr;

void reverseString(char input[]);
void Program_Project4();

char getChar(string prompt);
bool getBool(string prompt, int type);
string getLine(string prompt);
void display(stringPtr array, int size);
stringPtr addEntry(stringPtr dynamicArray, int &size, string newEntry);
stringPtr deleteEntry(stringPtr dynamicArray, int &size, string entryToDelete);
void Program_Project6();

int getInt(string prompt);
void Program_Project8();

int main()
{
	while (true)
	{
		system("cls");
		cout << "\n\t Chapter 9" << endl;
		cout << "==============================" << endl;
		cout << " 2: Programming Project4" << endl;
		cout << " 3: Programming Project6" << endl;
		cout << " 5: Programming Project8" << endl;
		cout << "==============================" << endl;
		cout << " option: ";
		char option[80];
		cin.getline(option, 80, '\n');
		cout << endl;
		switch (atoi(option))
		{
		case 2: Program_Project4(); break;
		case 3: Program_Project6(); break;
		case 5: Program_Project8(); break;
		default: exit(0);
		}
		cout << endl;
		system("pause");
		cin.clear();
	}

	return 0;
}
/*----------------------------Program_Project 4----------------------------*/
void reverseString(char input[])
{
	charPtr front, rear;
	char temp;
	front = input;
	rear = input + strlen(input) - 1;
	while (front < rear)
	{
		if (*front != *rear)
		{
			temp = *front;
			*front = *rear;
			*rear = temp;
		}
		front++;
		rear--;
	}
}

void Program_Project4()
{
	char input[101];
	cout << "Enter a C string which you want to reverse: ";
	cin.getline(input, 101);
	cout << "Before reversing: " << input << endl;
	reverseString(input);
	cout << "After reversing: " << input << endl;
}
/*--------------------------------------------------------------------------------------------*/

/*-------------------------------------Program_Project 6-----------------------------*/
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

bool getBool(string prompt, int type)
{
	while (true)
	{
		if (type == 1)
		{
			switch (getChar(prompt))
			{
			case 'A': case 'a': return true;
			case 'D': case 'd': return false;
			}
		}
		else if (type == 2)
		{
			switch (getChar(prompt))
			{
			case 'Y': case 'y': return true;
			case 'N': case 'n': return false;
			}
		}
		cout << "Wrong input, try again!" << endl;
	}
}

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
		cout << "Input failed, try again!" << endl;
	}
}

void display(stringPtr array, int size)
{
	if (size > 0)
	{
		cout << "List are:" << endl;
		for (int c = 0; c < size; c++)
		{
			cout << array[c] << endl;
		}
		cout << endl;
	}
}

stringPtr addEntry(stringPtr dynamicArray, int &size, string newEntry)
{
	stringPtr p = new string[size + 1];
	for (int c = 0; c < size; c++)
	{
		p[c] = dynamicArray[c];
	}
	p[size] = newEntry;
	size++;
	delete[] dynamicArray;
	return p;
}

stringPtr deleteEntry(stringPtr dynamicArray, int &size, string entryToDelete)
{
	if (size != 0)
	{
		stringPtr p = new string[size - 1];
		int positionToDelete = 0;
		for (int c = 0, count = 0; c < size; c++)
		{
			if (entryToDelete == dynamicArray[c])
			{
				// In case, the array has more strings equal entryToDelete 
				// ==> just delete the first string
				positionToDelete++;
				if (positionToDelete == 1)
					continue;
			}
			/*if count == size - 1, that means p is full, then, 
			+ if we met the entry ==> all data except entry have ben saved in
			p array
			+ if not, we have to return dynamicArray because p array
			doesn't have enough length to save all data*/
			if (count != size - 1)
				p[count++] = dynamicArray[c];
		}
		if (positionToDelete != 0)
		{
			delete[] dynamicArray;
			size = size - 1;
			return p;
		}
		delete[] p;
	}
	else
		cout << "Currently, your list is empty!" << endl;
	return dynamicArray;
}

void Program_Project6()
{
	string name;
	int size = 0;
	stringPtr ptr = new string[size];
	do
	{
		if (getBool("\nHi, do you want to add or delete member?(A or D) ", 1))
		{
			do
			{
				name = getLine("Please enter a member's name: ");
				ptr = addEntry(ptr, size, name);
			} while (getBool("Do you need to add more?(Y or N) ", 2));
			display(ptr, size);
		}
		else
		{
			do
			{
				name = getLine("Please enter a member's name: ");
				ptr = deleteEntry(ptr, size, name);
			} while (getBool("Do you need to delete more?(Y or N) ", 2));
			display(ptr, size);
		}

	} while (getBool("Do you want to continue?(Y or N) ", 2));
	delete[] ptr;
}
/*--------------------------------------------------------------------------------------------*/

/*------------------------------------Program_Project 8------------------------------*/
int getInt(string prompt)
{
	while (true)
	{
		int userAnswer;
		cout << prompt;
		cin >> userAnswer;
		cin.ignore(999, '\n');
		if (!cin.fail())
		{
			if (userAnswer > 100)
				cout << "Grade couldn't be greater than 100!" << endl;
			else if (userAnswer < 0 && userAnswer != -1)
				cout << "Grade couldn't be less than 0!" << endl;
			else
				return userAnswer;
		}
		else
		{
			cout << "Input failed, try again!" << endl;
			cin.clear();
			cin.ignore(999,'\n');
		}
	}
}
void Program_Project8()
{
	vector<int> grades;
	int grade = 0;
	intPtr array = new int[101]{};
	cout << "Enter grades from [0-100], and press -1 to exit!" << endl;
	while ((grade = getInt("Enter grade: ")) != -1)
	{
		grades.push_back(grade);
		//array[grade]++; //if the requirement don't need to use vector, stored grades directly into the dynamic arr
	}
	if (grades.size() == 0)
		cout << "You haven't had enter any grades!" << endl;
	else
	{
		for (int c = 0; c < grades.size(); c++)
		{
			array[grades[c]]++;
		}
		for (int c = 0; c < 101; c++)
		{
			if (array[c] != 0)
				cout << "Number of " << c << "'s: " << array[c] << endl;
		}
	}
	delete[] array;
}
