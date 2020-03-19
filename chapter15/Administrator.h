#pragma once
#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "SalariedEmployees.h"
#include <string.h>
using namespace std;
namespace employeesavitch
{
	class Administrator : public SalariedEmployees
		//class Administrator : protected SalariedEmployees
	{
	private:
		string title;
		string responsibility;
		string supervisor;
	protected:
		double annualSalary;
	public:
		void setSuperVisor(string newSuperVisor)
		{
			supervisor = newSuperVisor;
		}
		void input()
		{
			string newName;
			cout << "Enter the name: ";
			cin >> newName;
			setName(newName);

			string newSSN;
			cout << "Enter the SSN: ";
			cin >> newSSN;
			setName(newSSN);

			double newAnnualSalary;
			cout << "Enter the annual Salary: ";
			cin >> newAnnualSalary;
			annualSalary = newAnnualSalary;

			setSalary(annualSalary / 12);

		}
		void print() const
		{
			cout << "\nName: " << getName() << endl;
			cout << "SSN: " << getSSN() << endl;
			cout << "Title: " << title << endl;
			cout << "responsibility: " << responsibility << endl;
			cout << "Supervisor: " << supervisor << endl;
			cout << "Annual Salary: " << annualSalary << endl;
		}
	};


}

#endif