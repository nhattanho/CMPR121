#pragma once
#ifndef PROJECT1_H
#define PROJECT1_H

#include <stddef.h>
namespace Project1and2
{
	struct Node
	{
		int data;
		Node *link;
	};
	typedef Node* NodePtr;

	void headInsert(NodePtr& head, int theNumber);
	void reverser(NodePtr& head);
	void showList(NodePtr head);
	NodePtr mergeLists(NodePtr& list1, NodePtr& list2);
}
#endif