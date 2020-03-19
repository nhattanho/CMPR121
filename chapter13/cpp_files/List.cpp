#include "List.h"
#include <istream>
#include <ostream>
#include <string>
using namespace std;

namespace Project4and5
{
	List::List() : head(NULL), current(NULL), count(0) {}
	List::~List()
	{
		NodePtr temp;
		if (head != NULL)
		{
			temp = head;
			head = head->next;
			delete temp;
		}
	}

	/*---------------Implementation for project 4--------------*/
	int List::getSize() const
	{
		return count;
	}

	// Head insert, we don't do anything if the list is full
	void List::addItem(double newdata)
	{
		if (!full())
		{
			count++;
			NodePtr newItem = new Node;
			newItem->item = newdata;
			newItem->next = head;
			head = newItem;
			current = newItem;
		}
	}
	bool List::full() const
	{
		return (count == MAX_LIST_SIZE);
	}

	ostream& operator <<(ostream& outs, const List& object)
	{
		NodePtr temp = object.head;
		while (temp != NULL)
		{
			outs << temp->item << " ";
			temp = temp->next;
		}
		cout << endl;
		return outs;
	}
	/*---------------Implementation for project 5--------------*/
	double List::front()
	{
		if (head != NULL)
		{
			NodePtr temp = head;
			return temp->item;
		}
		// Documentation: if the list is NULL, default return NULL
		return NULL;
	}

	double List::back()
	{
		if (head != NULL)
		{
			NodePtr here = head;
			while (here->next != NULL)
			{
				here = here->next;
			}
			return here->item;
		}
		// Documentation: if the list is NULL, default return NULL
		return NULL;
	}

	NodePtr List::getBackPtr()
	{
		if (head != NULL)
		{
			NodePtr here = head;
			while (here->next != NULL)
			{
				here = here->next;
			}
			return here;
		}
		// Documentation: if the list is NULL, default return NULL
		return NULL;
	}

	double List::currentItem()
	{
		return (current != NULL ? current->item : NULL);
	}

	void List::advance()
	{
		if (current->next != NULL)
			current = current->next;
	}

	void List::reset()
	{
		if (head != NULL)
		{
			current = head;
		}
	}

	// Documentation: if the list is empty, we don't do anything
	void List::insert(double afterMe, double insertMe)
	{
		if (head != NULL)
		{
			if (!full())
			{
				NodePtr here = head;
				while (here->item != afterMe && here->next != NULL)
				{
					here = here->next;
				}
				if (here->item == afterMe)
				{
					NodePtr insert = new Node;
					insert->item = insertMe;
					insert->next = here->next;
					here->next = insert;
					current = insert;
					count++;
				}
			}
		}
	}

	int List::size()
	{
		return count;
	}

	double List::inputDouble(string prompt, istream& ins)
	{
		double input;
		do
		{
			cout << prompt;
			if (!(ins >> input))
			{
				cout << "ERROR-1B: Invalid input. Must be a double type.\n";
				ins.clear();
				ins.ignore(999, '\n');
			}
			else
				break;
		} while (true);
		return input;
	}

	// Add the new node at the end of the current list
	istream& operator >>(istream& ins, List& writeMe)
	{
		double newItem = writeMe.inputDouble("\nEnter the new Item for list: ", ins);
		NodePtr backPtr = writeMe.getBackPtr();
		NodePtr temp = new Node;
		temp->item = newItem;
		temp->next = NULL;
		backPtr->next = temp;
		writeMe.count++;
		return ins;
	}

	void List::showTest(string infor, List& object)
	{
		cout << infor << endl;
		cout << "test front: " << object.front() << endl;
		cout << "test back: " << object.back() << endl;
		cout << "test current: " << object.currentItem() << endl;
		cout << "size is " << object.size() << endl;
		cout << endl;
	}
}