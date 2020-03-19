#pragma once
#ifndef STRINGSET_H
#define STRINGSET_H

#include <istream>
#include <string>
#include <vector>
using namespace std;

class StringSet
{
private:
	vector<string> vec;
public:
	StringSet();
	StringSet(const string newArray[]);
	void addEntry(string entry);
	void deleteEntry(string entry);
	void clearSet();
	int getLengthSet() const;
	void outputSet();
	friend StringSet operator +(const StringSet& array1, const StringSet& array2);
	friend StringSet operator *(const StringSet& array1, const StringSet& array2);
};

#endif
