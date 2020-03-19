#include "StringSet.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

StringSet::StringSet(){}
StringSet::StringSet(const string newArray[])
{
	int size = sizeof(newArray);
	for (int c = 0; c < size; c++)
		vec.push_back(newArray[c]);
}
void StringSet::addEntry(string entry)
{
	vec.push_back(entry);
}
void StringSet::deleteEntry(string entry)
{
	if (vec.size() > 0)
	{
		for (int c = 0; c < vec.size(); c++)
		{
			if (vec[c] == entry)
			{
				vec.erase(vec.begin() + c);
				break;
			}
				
		}

	}
}
void StringSet::clearSet()
{
	vec.clear();
}
int StringSet::getLengthSet() const
{
	return vec.size();
}
void StringSet::outputSet()
{
	for (int c = 0; c < vec.size(); c++)
		cout << "vec[" << c << "] is: " << vec[c] << endl;
}
StringSet operator +(const StringSet& object1, const StringSet& object2)
{
	StringSet temp;
	temp.vec.insert(temp.vec.end(), object1.vec.begin(), object1.vec.end());
	temp.vec.insert(temp.vec.end(), object2.vec.begin(), object2.vec.end());
	return temp;
}
StringSet operator *(const StringSet& object1, const StringSet& object2)
{
	StringSet temp;
	for (int c = 0; c < object1.vec.size(); c++)
	{
		for (int i = 0; i < object2.vec.size();i++)
		{
			if (object1.vec[c] == object2.vec[i])
			{
				temp.vec.push_back(object1.vec[c]);
				break;
			}
		}
	}
	return temp;
}
