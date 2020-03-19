#pragma once
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <istream>
using namespace std;
const int MAX_LIST_SIZE = 50;

namespace Project4and5
{
	struct Node
	{
		double item;
		Node* next;
	};
	typedef Node* NodePtr;

	class List
	{
	private:
		NodePtr head;
		NodePtr current;
		int count;
	public:
		~List();
		List();

		//Project4's function
		int getSize() const;
		void addItem(double newdata);
		bool full() const;
		friend ostream& operator <<(ostream& outs, const List& object);

		//Project5's function
		double front();
		double back();
		NodePtr getBackPtr();
		double currentItem();
		void advance();
		void reset();
		void insert(double afterMe, double insertMe);
		int size();
		friend istream& operator >>(istream& ins, List& writeMe);
		void showTest(string infor, List& object);
		double inputDouble(string prompt, istream& ins);
	};
}

#endif