#include "Employees.h"
#include "SalariedEmployees.h"
#include "Administrator.h"
#include <iostream>
using namespace std;

void PracticeProgram1();
/*
void PracticeProgram3();
void ProgrammingProject1();
void ProgrammingProject2();
void ProgrammingProject5();

*/

int main()
{
	while (true)
	{
		system("cls");
		cout << "\n\t\tChapter 15\n";
		cout << "\t===========================\n";
		cout << "\t 1: Practice Program1\n";
		cout << "\t 2: Practice Program2\n";
		cout << "\t 3: Practice Program3\n";
		cout << "\t 4: Programming Project1\n";
		cout << "\t 5: Programming Project2\n";
		cout << "\t 6: Programming Project3\n";
		cout << "\t 7: Programming Project4\n";
		cout << "\t 8: Programming Project5\n";
		cout << "\t 9: Programming Project7\n";
		cout << "\t10: Programming Project13\n";
		cout << "\t===========================\n";
		cout << "\t option: ";

		char option[80];
		cin.getline(option, 80, '\n');

		switch (atoi(option))
		{
		case 1: PracticeProgram1(); break;
			/*
		case 3: PracticeProgram3(); break;
		case 4: ProgrammingProject1(); break;
		case 5: ProgrammingProject2(); break;
		case 8: ProgrammingProject5(); break;
		*/
		default: return 0;
		}
		system("pause");
	}
	return 0;
}

void PracticeProgram1()
{
	using namespace employeesavitch;
	Employees test2;
	SalariedEmployees test1;
	Administrator test3;

	//test1.printCheck();
	test3.input();
	test3.print();
	test3.printCheck();
}