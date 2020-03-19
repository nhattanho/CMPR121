#include "Project1.h"
#include <stddef.h>
#include <iostream>
using namespace std;
namespace Project1and2
{
	void headInsert(NodePtr& head, int theNumber)
	{
		NodePtr temp = new Node;
		temp->data = theNumber;
		temp->link = head;
		head = temp;
	}

	void reverser(NodePtr& head)
	{
		NodePtr current;
		NodePtr temp = NULL;
		while (head != NULL)
		{
			current = head;
			head = head->link;
			current->link = temp;
			temp = current;

		}
		head = temp;
	}

	void showList(NodePtr head)
	{
		while (head != NULL)
		{
			cout << head->data << " ";
			head = head->link;
		}
		cout << endl;
	}

	NodePtr mergeLists(NodePtr& list1, NodePtr& list2)
	{
		if (list1 == NULL)
			return list2;
		if (list2 == NULL)
			return list1;

		NodePtr head;

		// Create a head pointer to the list which has smaller first data node
		if (list1->data < list2->data)
		{
			head = list1;
			list1 = list1->link;
		}
		else
		{
			head = list2;
			list2 = list2->link;
		}
		NodePtr current = head;
		//loop until both list are not pointing to null
		while (list1 != NULL || list2 != NULL)
		{
			//if list1 is null, point the current pointer to the rest of list2
			if (list1 == NULL) {
				current->link = list2;
				list2 = NULL; //make sure both pointer variables are NULL when function call ends
				return head;
			}
			//if list2 is null, point the current pointer to the rest of list1 
			else if (list2 == NULL) {
				current->link = list1;
				list1 = NULL;
				return head;
			}
			//compare if list1 node data is smaller than list2 node data, list1 node will be
			//pointed by current pointer and reverse
			else if (list1->data < list2->data)
			{
				current->link = list1;
				current = current->link;
				list1 = list1->link;
			}
			else
			{
				current->link = list2;
				current = current->link;
				list2 = list2->link;
			}
		}
		return head;
	}
}