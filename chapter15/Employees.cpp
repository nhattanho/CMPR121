#include "Employees.h"

namespace employeesavitch
{
	Employees::~Employees() {}
	Employees::Employees() :name("No name yet"), ssn("No number yet"), netPay(0.0) {}
	Employees::Employees(string theName, string theSSN) : name(theName), ssn(theSSN), netPay(0.0) {}
	string Employees::getName() const
	{
		return name;
	}
	string Employees::getSSN() const
	{
		return ssn;
	}
	double Employees::getNetPay() const
	{
		return netPay;
	}
	void Employees::setName(string newName)
	{
		name = newName;
	}
	void Employees::setSSN(string newSSN)
	{
		ssn = newSSN;
	}
	void Employees::setNetPay(double newNetPay)
	{
		netPay = newNetPay;
	}
	void Employees::printCheck()
	{
		cout << "ERROR: printcheck FUNCTION CALL FOR AN UNDEFINITE\n";
		cout << " Check for testing\n";
		exit(1);
	}
}