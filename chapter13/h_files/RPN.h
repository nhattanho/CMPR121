#pragma once
#ifndef RPN_H
#define RPN_H
namespace Project10
{
	struct Node
	{
		int data;
		Node* next;
	};
	typedef Node* NodePtr;

	class RPN
	{
	private:
		NodePtr top;
	public:
		RPN();
		~RPN();
		void push(int number);
		bool pop(int& result);
		bool empty() const;
	};
}
#endif
