#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

template <class ItemType>
class List
{
private:
	int maxlenght;
	int currentLenght;
	ItemType* items;
	int current;
public:
	List() :maxlenght(0), currentLenght(0), current(0)
	{}
	List(int newMaxLenght);
	~List();
	int lenght() const;
	void add(ItemType newItem);
	bool full() const;
	bool empty() const;
	void erase();
	bool getItem(int index, ItemType& value) const;
	void next();
	void previous();
	ItemType getCurrent() const;
	void reset();
	friend ostream& operator <<<>(ostream& outs, const List<ItemType>& theList);
	ItemType findItem(ItemType item) const;
};
template <class ItemType>
List<ItemType>::List(int newMaxLenght)
{
	maxlenght = newMaxLenght;
	currentLenght = 0;
	items = new ItemType[newMaxLenght];
}

template <class ItemType>
List<ItemType>::~List()
{
	delete[] items;
}

template <class ItemType>
int List<ItemType>::lenght()const
{
	return currentLenght;
}

template <class ItemType>
void List<ItemType>::add(ItemType newItem)
{
	if (full())
		cout << "\nERROR-A2: adding to full list.\n";
	else
	{
		items[currentLenght] = newItem;
		currentLenght++;
	}
}

template <class ItemType>
bool List<ItemType>::full()const
{
	return (currentLenght == maxlenght);
}

template <class ItemType>
bool List<ItemType>::empty() const
{
	return (currentLenght == 0);
}

template <class ItemType>
void List<ItemType>::erase()
{
	currentLenght = 0;
	current = 0;
	if (!empty())
		delete[] items;
}

template <class ItemType>
bool List<ItemType>::getItem(int index, ItemType& value) const
{
	if (empty())
	{
		cout << "\nERROR-A3: List is empty.\n";
		return false;
	}

	if (index < 0 || index> maxlenght - 1)
	{
		cout << "\nERROR-A4: index, " << index << ", is out of the range.\n";
		return false;
	}
	value = items[index];
	return true;
}

template <class ItemType>
void List<ItemType>::next()
{
	if (current < currentLenght - 1)
		current++;
}

template <class ItemType>
void List<ItemType>::previous()
{
	if (currentLenght > 0)
		current--;
}

template <class ItemType>
ItemType List<ItemType>::getCurrent() const
{
	return items[current];
}

template <class ItemType>
ostream& operator <<<>(ostream& outs, const List<ItemType>& theList)
{
	if (!theList.empty())
	{
		outs << "\nList\n";
		outs << "=================\n";
		for (int c = 0; c < theList.lenght(); c++)
		{
			int value;
			theList.getItem(c, value);
			outs << "List[" << c << "] = " << value << "\n";
		}
		outs << "\n";
	}
	else
	{
		outs << "\nList is empty.\n\n";
	}
	return outs;
}

template <class ItemType>
void List<ItemType>::reset()
{
	current = 0;
}

template <class ItemType>
ItemType List<ItemType>::findItem(ItemType value) const
{
	for (int c = 0; c < lenght(); c++)
	{
		ItemType here;
		getItem(c, here);
		if (value == here)
			return c;
	}
	return -1;
}
#endif