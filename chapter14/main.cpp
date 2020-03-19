// Nhat Ho
// Dec 12 2018

#include <iostream>
#include <string>
using namespace std;

void PracticeProgram1();
void PracticeProgram5();
void ProgrammingProject1();
void ProgrammingProject4();
void ProgrammingProject5();

int main()
{
	while (true)
	{
		system("cls");
		cout << "\n\t\tChapter 14\n";
		cout << "\t===========================\n";
		cout << "\t 1: Practice Program1\n";
		cout << "\t 2: Practice Program5\n";
		cout << "\t 3: Programming Project1\n";
		cout << "\t 4: Programming Project4\n";
		cout << "\t 5: Programming Project5\n";
		cout << "\t===========================\n";
		cout << "\t option: ";

		char option[80];
		cin.getline(option, 80, '\n');

		switch (atoi(option))
		{
		case 1: PracticeProgram1(); break;
		case 2: PracticeProgram5(); break;
		case 3: ProgrammingProject1(); break;
		case 4: ProgrammingProject4(); break;
		case 5: ProgrammingProject5(); break;
		default: return 0;
		}
		system("pause");
	}
	return 0;
}
/*------------------------------Program 1------------------------------------------------*/
int inputInteger(string prompt)
{
	int input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR-1A: Invalid input. Must be an integer type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (input < 0)
		{
			cout << "ERROR-2A: Invalid input. Must be an positive number.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else
			break;
	} while (true);
	return input;
}
//recursive function
int fibonacci(int n) 
{
	//base or stop case
	if (n == 0 || n == 1) 
		return n;
	else 
		return (fibonacci(n - 1) + fibonacci(n - 2)); 
}
void PracticeProgram1()
{
	int n = inputInteger("\nEnter the positive number: ");
	cout << "\nThe fibonacci serie for " << n << " elements is.\n";
	for (int c = 0; c <= n; c++)
	{
		cout << fibonacci(c) << " ";
	}
	cout << endl;
	cin.ignore();
}

/*---------------------------------Program 2------------------------------------------*/
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
bool palidrome(const string input, int s, int e)
{
	if (s == e)
		return true;
	if (input[s] != input[e])
		return false;
	if (s < e + 1)
		return palidrome(input, s + 1, e - 1);
}
void PracticeProgram5()
{
	string input = getLine("\nenter the string: ");
	if (palidrome(input, 0, input.size() - 1))
		cout << "yes, it is palidrome.\n";
	else 
		cout << "no, it is not palidrome.\n";
}

/*---------------------------------Program 3------------------------------------------*/
int factorial(int n)
{
	if (n > 1)
		return n * factorial(n - 1);
	else
		return 1;
}
double calculateFormula(int x, int y)
{
	int numerator = factorial(x);
	int denominator = factorial(y) * factorial(x - y);
	return numerator / (denominator*1.0);
}
void ProgrammingProject1()
{
	cout << "This is test for formula C(n,r) = n!/[r! * (n-r)!] \n";
	cout << "The result of C(5,4) is " << calculateFormula(5, 4) << endl;
	cout << "The result of C(5,2) is " << calculateFormula(5, 2) << endl;
}

/*---------------------------------Program 4------------------------------------------*/
void swap(int &x, int &y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}
void Sort(int arr[], int n)
{
	// Stopping case 
	if (n == 1)
		return;

	for (int i = 0; i < n - 1; i++)
		if (arr[i] > arr[i + 1])
			swap(arr[i], arr[i + 1]);

	Sort(arr, n - 1);
}
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}
void ProgrammingProject4()
{
	int arr[] = { 77, 99, 120, 2, 89, 29, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	Sort(arr, n);
	cout << "Sorted array: \n";
	printArray(arr, n);
}

/*---------------------------------Program 5------------------------------------------*/
void TowerOfHanoi(int n, char Sour, char Aux, char Des)
{
	if (n == 1)
	{
		cout << "Move Disk " << n << " from " << Sour << " to " << Des << endl;
		return;
	}

	TowerOfHanoi(n - 1, Sour, Des, Aux);
	cout << "Move Disk " << n << " from " << Sour << " to " << Des << endl;
	TowerOfHanoi(n - 1, Aux, Sour, Des);
}
void ProgrammingProject5()
{
	int n = inputInteger("Enter no. of disks: ");
	//calling the TOH 
	TowerOfHanoi(n, 'A', 'B', 'C');
	cin.ignore();
}