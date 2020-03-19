#pragma once
#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include <string>
#include <iostream>
//#include <cstdlib.h>
using namespace std;
namespace employeesavitch
{
	class Employees
	{
	private:
		string name;
		string ssn;
		double netPay;
	public:
		~Employees();
		Employees();
		Employees(string theName, string theSSN);
		string getName() const;
		string getSSN() const;
		double getNetPay() const;
		void setName(string newName);
		void setSSN(string newSSN);
		void setNetPay(double newNetPay);
		void printCheck();
	};
}
#endif