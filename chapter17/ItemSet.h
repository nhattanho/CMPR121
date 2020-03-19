#ifndef ITEMSET_H
#define ITEMSET_H

#include <vector>
using namespace std;

template <class ItemType>
class ItemSet
{
private:
	vector <ItemType> items;
public:
	ItemSet();
	~ItemSet();
	void add(ItemType newItem);
	void remove(ItemType itemToRemove);
	int returnNumber();
	bool inTheSet(ItemType item);
	friend ostream& operator <<<>(ostream& outs, ItemSet<ItemType>& theList);

};
template <class ItemType>
ItemSet<ItemType>::ItemSet()
{
	items.resize(0);
}

template <class ItemType>
ItemSet<ItemType>::~ItemSet(){}

template <class ItemType>
void ItemSet<ItemType>::add(ItemType newItem)
{
	for (int c = 0; c < items.size(); c++)
	{
		if (items[c] == newItem)
			break;
	}
	items.push_back(newItem);
}

template <class ItemType>
void ItemSet<ItemType>::remove(ItemType itemToRemove)
{
	for (int c = 0; c < items.size(); c++)
	{
		if (items[c] == itemToRemove)
			items.erase(items.begin() + c);
	}
}

template <class ItemType>
int ItemSet<ItemType>::returnNumber()
{
	return items.size();
}

template <class ItemType>
bool ItemSet<ItemType>::inTheSet(ItemType item)
{
	for (int c = 0; c < items.size(); c++)
	{
		if (items[c] == item)
			return true;
	}
	return false;
}

template <class ItemType>
ostream& operator <<<>(ostream& outs, ItemSet<ItemType>& theSet)
{
	if (!theSet.returnNumber() == 0)
	{
		outs << "\nSet:\n";
		outs << "=================\n";
		for (int c = 0; c < theSet.returnNumber(); c++)
			outs << "Set[" << c << "] = " << theSet.items[c] << "\n";
		outs << "\n";
	}
	else
		outs << "\nList is empty.\n\n";
	return outs;
}
#endif