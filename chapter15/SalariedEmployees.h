#pragma once
#ifndef SALARIEDEMPLOYEES_H
#define SALARIEDEMPLOYEES_H
#include "Employees.h"

namespace employeesavitch
{
	class SalariedEmployees : public Employees
	{
	private:
		double salary;
	public:
		SalariedEmployees() : Employees(), salary(0.0) {}
		SalariedEmployees(string theName, string theSSN, double theWeeklySalary)
		{
			Employees(theName, theSSN);
		}
		double getSalary() const
		{
			return salary;
		}
		void setSalary(double newSalary)
		{
			salary = newSalary;
		}
		void printCheck()
		{
			setNetPay(salary);
			cout << "\n_____________________________________\n";
			cout << "Pay to the order of " << getName() << endl;
			cout << "The sum of " << getNetPay() << " Dollars\n";
			cout << "\n_____________________________________\n";
			cout << "Check Stub: NOT NEGOTIABLE\n";
			cout << "Employee Number: " << getSSN() << endl;
			cout << "Salaries Employee: " << getNetPay() << endl;
			cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n";
		}
	};
}

#endif