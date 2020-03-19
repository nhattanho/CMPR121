#include "RPN.h"
#include <string>
#include <iostream>
using namespace std;

namespace Project10
{
	RPN::RPN() :top(NULL) {}
	RPN::~RPN()
	{
		int next;
		while (!empty())
			pop(next);
	}
	void RPN::push(int number)
	{
		NodePtr temp = new Node;
		temp->data = number;
		temp->next = top;
		top = temp;
	}
	bool RPN::pop(int& result)
	{
		if (empty())
		{
			cout << "Error: popping an empty stack.\n";
			return false;
		}
		else
		{
			result = top->data;
			NodePtr temp;
			temp = top;
			top = top->next;
			delete temp;
			return true;
		}
	}
	bool RPN::empty() const
	{
		return (top == NULL);
	}
}