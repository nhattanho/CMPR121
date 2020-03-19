#include <iostream>
#include <string>
using namespace std;

namespace ArrayFunctions
{
	template <class itemType>
	void sort(itemType array[], int size)
	{
		itemType temp;
		int check(0);
		for (int c = 1; c < size; c++)
		{
			temp = array[c];
			check = c - 1;

			while (array[check] > temp)
			{
				array[check + 1] = array[check];
				check = check - 1;
			}
			array[check + 1] = temp;
		}
	}

	template <class itemType>
	void display(itemType array[], int size)
	{
		for (int c = 0; c < size; c++)
		{
			cout << array[c] << " ";
		}
		cout << endl;
	}
}