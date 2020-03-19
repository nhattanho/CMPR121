#include "input.h"
#include <cstdlib>
#include <cstddef>
#include <cstring>
#include <iostream>
using namespace std;
using namespace CMPR121;

class VectorDouble
{
private:
	int maxCount, count;
	double *list;

public:
	// Destructor
	~VectorDouble()
	{
		delete[] list;
	}

	//Constructor
	VectorDouble() : maxCount(50), count(0)
	{
		list = new double[50];
	}

	VectorDouble(int numberElements)
	{
		if (numberElements <= 0)
		{
			maxCount = 50;
			count = 0;
			list = new double[50];
		}
		else
		{
			maxCount = numberElements;
			count = 0;
			list = new double[maxCount];
		}
	}

	// copy constructor
	VectorDouble(const VectorDouble& object)
	{
		delete[] list;
		list = new double[object.maxCount];
		count = object.count;
		maxCount = object.maxCount;
		for (int c = 0; c < count; c++)
		{
			list[c] = object.list[c];
		}
	}

	// assignment operator =
	void operator =(const VectorDouble& object)
	{
		// Just update capacity and size for the destination when size of the source
		// greater(or equal) than the capacity of destination
		if (object.count >= maxCount)
		{
			delete[] list;
			count = object.count;
			maxCount = object.maxCount * 2; // depends on the programmer
			list = new double[maxCount];
			for (int c = 0; c < count; c++)
			{
				list[c] = object.list[c];
			}
		}
		else
		{
			for (int c = 0; c < object.count; c++)
				list[c] = object.list[c];
			count = object.count;
		}
	}

	// overload operator ==
	friend bool operator ==(const VectorDouble& object1, const VectorDouble& object2)
	{
		if (object1.count != object2.count)
			return false;
		for (int c = 0; c < object1.count; c++)
		{
			if (object1.list[c] == object2.list[c])
				return false;
		}
		return true;
	}

	// functionality of vector

	void push_back(const double newElement)
	{
		if (count < maxCount)
		{
			list[count] = newElement;
			count++;
		}
		else
		{
			maxCount *= 2;
			double* newList = new double[maxCount];
			for (int c = 0; c < count; c++)
			{
				newList[c] = list[c];
			}
			newList[count] = newElement;
			count++;
			delete[] list;
			list = newList;
		}
	}

	int capacity() const
	{
		return maxCount;
	}

	int size() const
	{
		return count;
	}

	void reserve(int newMaxCount)
	{
		if (newMaxCount > maxCount)
		{
			maxCount = newMaxCount;
			double* newList = new double[maxCount];
			for (int c = 0; c < count; c++)
			{
				newList[c] = list[c];
			}
			delete list;
			list = newList;
		}
	}

	void resize(int newCount)
	{
		if (newCount <= count)
			count = newCount;
		else if (newCount > count && newCount <= maxCount)
		{
			for (int c = count; c < newCount; c++)
			{
				list[c] = 0;
			}
			count = newCount;
		}
		else
		{
			maxCount = newCount * 2; // depends on programmer
			double* newList = new double[maxCount];
			for (int c = 0; c < count; c++)
			{
				newList[c] = list[c];
			}
			for (int c = count; c < newCount; c++)
			{
				newList[c] = 0;
			}
			count = newCount;
			delete[] list;
			list = newList;
		}
	}

	// Documentation: the position of value which was checked has to be in the range of vector.
	// Anyway, if the user still want to access with invalid position which is out of range,
	// default value is 0 will be returned.
	double valueat(int i)
	{
		if (i >= 0 && i < count)
			return list[i];
		else
			return 0;
	}
	// Documentation: This is handle for the case is that if the user want to change the value
	// of the position which is out of range.
	void changeValueAt(double newElement, int i)
	{
		// default change value at position 0 
		if (i < 0)
			i = 0;
		// default change value at position count-1
		if (i >= count)
			i = count - 1;
		if (i >= 0 && i < count)
			list[i] = newElement;
	}

	void output(ostream& outs)
	{
		outs << "These are information of this vector!" << endl;
		outs << "Capacity is: " << maxCount << endl;
		outs << "Size is: " << count << endl;
		if (count > 0) 
		{
			cout << "Element are: ";
			for (int c = 0; c < count; c++)
				cout << list[c] << " ";
		}
		cout << endl;
		cout << " =============================== " << endl;
	}
};
void Program_Project1();

class Rational
{
private:
	int numbers[2];
public:
	Rational()
	{
		numbers[0] = 0;// numerator
		numbers[1] = 1;// denominator
	}
	Rational(int wholeNumber)
	{
		numbers[0] = wholeNumber;
		numbers[1] = 1;
	}
	// Documentation: the denominator can not be 0, if the user make a mistake,
	// any value of denominator equal 0 should be treated as 1
	Rational(int newNumerator, int newDenominator)
	{
		numbers[0] = newNumerator;
		if (newDenominator == 0)
			newDenominator = 1;
		numbers[1] = newDenominator;
	}
	void setNumerator(int newNumerator)
	{
		numbers[0] = newNumerator;
	}
	int getNumerator() const
	{
		return numbers[0];
	}
	void setDenominator(int newDenominator)
	{
		if (newDenominator == 0)
			newDenominator = 1;
		numbers[1] = newDenominator;
	}
	int getDenominator() const
	{
		return numbers[1];
	}
	int greatestCommonDivisor(int numerator, int denominator)
	{
		while (denominator != 0)
		{
			int r = numerator % denominator;
			numerator = denominator;
			denominator = r; // remainder of division
		}
		return numerator;
	}
	void keepPositiveDenominator()
	{
		if (numbers[1] < 0)
		{
			numbers[0] *= -1;
			numbers[1] *= -1;
		}
	}
	void normalization()
	{
		if (numbers[0] != 0)
		{
			int gCD = greatestCommonDivisor(numbers[0], numbers[1]);
			numbers[0] /= gCD;
			numbers[1] /= gCD;
			this->keepPositiveDenominator();
		}
	}
	friend Rational operator +(const Rational& r1, const Rational& r2)
	{
		Rational tempAdd;
		tempAdd.numbers[0] = r1.numbers[0] * r2.numbers[1] + r1.numbers[1] * r2.numbers[0];
		tempAdd.numbers[1] = r1.numbers[1] * r2.numbers[1];
		return tempAdd;
	}
	friend Rational operator -(const Rational& r1, const Rational& r2)
	{
		Rational tempAdd;
		tempAdd.numbers[0] = r1.numbers[0] * r2.numbers[1] - r1.numbers[1] * r2.numbers[0];
		tempAdd.numbers[1] = r1.numbers[1] * r2.numbers[1];
		return tempAdd;
	}
	friend Rational operator *(const Rational& r1, const Rational& r2)
	{
		Rational tempAdd;
		tempAdd.numbers[0] = r1.numbers[0] * r2.numbers[0];
		tempAdd.numbers[1] = r1.numbers[1] * r2.numbers[1];
		return tempAdd;
	}
	friend Rational operator /(const Rational& r1, const Rational& r2)
	{
		Rational tempAdd;
		tempAdd.numbers[0] = r1.numbers[0] * r2.numbers[1];
		tempAdd.numbers[1] = r1.numbers[1] * r2.numbers[0];
		return tempAdd;
	}
	Rational operator -()
	{
		numbers[0] *= -1;
		return *this;
	}
	bool operator <(const Rational& r2)
	{
		this->keepPositiveDenominator();
		Rational temp;
		temp.numbers[0] = r2.numbers[0];
		temp.numbers[1] = r2.numbers[1];
		temp.keepPositiveDenominator();
		if (numbers[0] * temp.numbers[1] < numbers[1] * temp.numbers[0])
			return true;
		else
			return false;
	}
	bool operator <=(const Rational& r2)
	{
		this->keepPositiveDenominator();
		Rational temp;
		temp.numbers[0] = r2.numbers[0];
		temp.numbers[1] = r2.numbers[1];
		temp.keepPositiveDenominator();
		if (numbers[0] * temp.numbers[1] <= numbers[1] * temp.numbers[0])
			return true;
		else
			return false;
	}
	bool operator >=(const Rational& r2)
	{
		this->keepPositiveDenominator();
		Rational temp;
		temp.numbers[0] = r2.numbers[0];
		temp.numbers[1] = r2.numbers[1];
		temp.keepPositiveDenominator();
		if (numbers[0] * temp.numbers[1] >= numbers[1] * temp.numbers[0])
			return true;
		else
			return false;
	}
	bool operator ==(const Rational& r2)
	{
		if (this->operator<=(r2) && this->operator>=(r2))
			return true;
		else
			return false;
	}
	
	friend ostream& operator <<(ostream& outs, const Rational& object)
	{
		outs << object.numbers[0] << "/" << object.numbers[1];
		return outs;
	}
	friend istream& operator >>(istream& ins, Rational& object)
	{
		int numerator = inputInteger("Please enter the numerator: ", ins);
		int denominator = CMPR121::getDenominator("Please enter the denominator: ", ins);
		object.numbers[0] = numerator;
		object.numbers[1] = denominator;
		return ins;
	}

};
void checkZero(Rational object)
{
	if (object.getNumerator() == 0)
		cout << "0" << endl;
	else if (object.getDenominator() == 0)
		cout << "Reject" << endl;
	else
		cout << object << endl;
}
void Program_Project2();

class Complex
{
private:
	double real, imaginary;
public:
	Complex(): real(0), imaginary(0){}
	Complex(double realPart): real(realPart), imaginary(0){}
	Complex(double realPart, double imaginaryPart): real(realPart), imaginary(imaginaryPart){}
	void setReal(double newReal)
	{
		real = newReal;
	}
	double getReal() const
	{
		return real;
	}
	void setImaginary(double newImaginary)
	{
		real = newImaginary;
	}
	double getImaginary() const
	{
		return imaginary;
	}
	friend Complex operator +(const Complex& c1, const Complex& c2)
	{
		Complex temp;
		temp.real = c1.real + c2.real;
		temp.imaginary = c1.imaginary + c2.imaginary;
		return temp;
	}
	friend Complex operator -(const Complex& c1, const Complex& c2)
	{
		Complex temp;
		temp.real = c1.real - c2.real;
		temp.imaginary = c1.imaginary - c2.imaginary;
		return temp;
	}
	friend Complex operator *(const Complex& c1, const Complex& c2)
	{
		Complex temp;
		temp.real = c1.real*c2.real - c1.imaginary*c2.imaginary;
		temp.imaginary = c1.real*c2.imaginary + c1.imaginary*c2.real;
		return temp;
	}
	bool operator ==(const Complex& c2)
	{
		if (real = c2.real && imaginary == c2.imaginary)
			return true;
		else
			return false;
	}
	friend ostream& operator <<(ostream& outs, const Complex& object)
	{
		outs << object.real << " + " << object.imaginary << "*i";
		return outs;
	}
	friend istream& operator >>(istream& ins, Complex& object)
	{
		double real = inputDouble("Please enter the real part: ", ins);
		double imaginary = inputDouble("Please enter the imaginary part: ", ins);
		object.real = real;
		object.imaginary = imaginary;
		return ins;
	}
};
void Program_Project3();

class StringVar
{
private:
	char* value;
	int maxLength;
public:
	~StringVar()
	{
		delete[] value;
	}
	StringVar() : maxLength(100)
	{
		value = new char[maxLength + 1];
		value[0] = '\0';
	}
	StringVar(int size) : maxLength(size)
	{
		value = new char[maxLength + 1];
		value[0] = '\0';
	}
	StringVar(const char a[]) : maxLength(strlen(a))
	{
		value = new char[maxLength + 1];
		strcpy(value, a);
	}
	StringVar(const StringVar& sObject) : maxLength(sObject.length())
	{
		value = new char[maxLength + 1];
		strcpy(value, sObject.value);
	}
	int length() const
	{
		return strlen(value);
	}
	void inputLine(istream& ins)
	{
		ins.getline(value, maxLength + 1);
	}
	StringVar copyPiece(int startIndex, int length)
	{
		int endIndex;
		if (startIndex >= maxLength)
			startIndex = maxLength - 1;
		else if (startIndex < 0)
			startIndex = 0;

		if (startIndex + length > maxLength)
			length = length - startIndex;

		endIndex = startIndex + length - 1;

		StringVar temp(length + 1);
		for (int c = 0; c < length; c++)
		{
			temp.value[c] = value[startIndex + c];
		}
		temp.value[length] = '\0';
		return temp;
	}
	// Documentation: the user should not enter the invalid range of the index
	// if they made a mistake, we have to handle in this function of the class
	char Onechar(int index)
	{
		if (index < 0)
			index = 0;
		else if (index > maxLength)
			index = maxLength - 1;
		return value[index - 1];
	}
	void setChar(int position, char newChar)
	{
		if (position >= 0 && position < maxLength)
			value[position] = newChar;
	}
	friend StringVar operator +(const StringVar& s1, const StringVar& s2)
	{
		StringVar addString;
		int addLength = s1.length() + s2.length();
		if (addLength > addString.maxLength)
		{
			delete[] addString.value;
			addString.maxLength += s1.maxLength + s2.maxLength; // depends on the programmer
			addString.value = new char[addString.maxLength + 1];
		}
		strcpy(addString.value, s1.value);
		strcat(addString.value, s2.value);
		return addString;
	}
	void operator=(const StringVar& rightSide)
	{
		int newLength = strlen(rightSide.value);
		if (newLength > maxLength)
		{
			delete[] value;
			maxLength = newLength;
			value = new char[maxLength + 1];
		}
		// can use strcpy(this->value, rightSide.value)
		for (int i = 0; i < newLength; i++)
			value[i] = rightSide.value[i];
		value[newLength] = '\0';
	}
	bool operator ==(const StringVar& s2)
	{
		if (strlen(value) != strlen(s2.value))
			return false;
		for (int c = 0; c < int(strlen(value)); c++)
		{
			if (value[c] != s2.value[c])
				return false;
		}
		return true;
	}
	friend istream& operator >>(istream& ins, StringVar& object)
	{
		char word;
		ins >> word;
		int length = object.length();
		if (length == object.maxLength - 1)
		{
			object.maxLength *= 2; // depends on programmer
			char* newValue = new char[object.maxLength];
			for (int c = 0; c < length; c++)
				newValue[c] = object.value[c];
			newValue[length++] = word;
			newValue[length] = '\0';
			delete[] object.value;
			object.value = newValue;
		}
		else
		{
			object.value[length] = word;
			object.value[length + 1] = '\0';
		}
		return ins;
	}
	friend ostream& operator <<(ostream& outs, StringVar& object)
	{
		outs << object.value << endl;
		return outs;
	}
};
void Program_Project4();

class Chapter9
{
private:
	int size;
	string* array;
public:
	~Chapter9()
	{
		delete[] array;
	}
	Chapter9() : size(100)
	{
		array = new string[size];
	}
	Chapter9(int newSize) : size(newSize)
	{
		array = new string[size];
	}
	Chapter9(const Chapter9& sObject) : size(sObject.size)
	{
		array = new string[size];
		for (int c = 0; c < size - 1; c++)
		{
			array[c] = sObject.array[c];
		}
	}
	void addEntry(string newEntry)
	{
		string* newArray = new string[size + 1];
		for (int c = 0; c < size; c++)
		{
			newArray[c] = array[c];
		}
		newArray[size] = newEntry;
		size++;
		delete[] array;
		array = newArray;
	}

	void deleteEntry(string entryToDelete)
	{
		if (size != 0)
		{
			string* newArray = new string[size - 1];
			int positionToDelete = 0;
			for (int c = 0, count = 0; c < size; c++)
			{
				if (entryToDelete == array[c])
				{
					// In case, the array has more strings equal entryToDelete
					// ==> just delete the first string
					positionToDelete++;
					if (positionToDelete == 1)
						continue;
				}
				/*if count == size - 1, that means p is full, then,
				+ if we met the entry ==> all data except entry have ben saved in
				p array
				+ if not, we have to return dynamicArray because p array
				doesn't have enough length to save all data*/
				if (count != size - 1)
					newArray[count++] = array[c];
			}
			if (positionToDelete != 0)
			{
				delete[] array;
				size = size - 1;
				array = newArray;
			}
			delete[] newArray;
		}
	}
	void operator =(const Chapter9& object)
	{
		delete[] array;
		array = new string[size];
		for (int c = 0; c < size; c++)
		{
			array[c] = object.array[c];
		}
	}
	int currentsize() const
	{
		return size;
	}
	string getPosition(int position) const
	{
		if (position < 0)
			position = 0;
		if (position >= size)
			position = size - 1;
		return array[position];
	}
	void setPosition(int position, string line)
	{
		if (position < 0)
			position = 0;
		if (position >= size)
			position = size - 1;
		array[position] = line;
	}
};
void Program_Project11();

int main()
{
	while (true)
	{
		system("cls");
		cout << "\n\tChapter 11" << endl;
		cout << "==============================" << endl;
		cout << " 1: Programming Project1" << endl;
		cout << " 2: Programming Project2" << endl;
		cout << " 3: Programming Project3" << endl;
		cout << " 4: Programming Project4" << endl;
		cout << " 5: Programming Project11" << endl;
		cout << "==============================" << endl;
		cout << " option: ";
		char option[80];
		cin.getline(option, 80, '\n');
		cout << endl;
		switch (atoi(option))
		{
		case 1: Program_Project1(); break;
		case 2: Program_Project2(); break;
		case 3: Program_Project3(); break;
		case 4: Program_Project4(); break;
		case 5: Program_Project11(); break;
		default: exit(0);
		}
		cout << endl;
		system("pause");
		cin.clear();
	}

	return 0;
}

void Program_Project1()
{
	// Just testing for VectorDouble class
	VectorDouble v1;
	VectorDouble v2(2);
	VectorDouble v3(v2);// it is equal with: VectorDouble v3 = v2 => call copy constructor
	cout << "vector v1: v1" << endl;
	v1.output(cout);
	cout << "vector v2: v2(2)" << endl;
	v2.output(cout);
	cout << "vector v3: v3(v2)" << endl; 
	v3.output(cout);
	cout << endl;

	// Try to make v1 is different with v2, it is useful for testing overload operator ==
	v1.push_back(12);
	v1.push_back(13);
	cout << "v1 after push_back:" << endl;
	v1.output(cout);
	v2.push_back(10);
	v2.push_back(11);
	v2.push_back(9);
	cout << "v2 after push_back:" << endl;
	v2.output(cout);

	cout << "\nTesting for overload operator ==:" << endl;
	cout << "v1 and v2 are " << (v1 == v2 ? " the same. " : "not the same ") << endl;
	cout << "v2 and v3 are " << (v2 == v3 ? " the same. " : "not the same ") << endl;

	cout << "\nTesting for assignment operator: v1 = v2" << endl;
	v1 = v2; // call a assignment operator =
	v1.output(cout);

	cout << "\nTesting for v1.resize, size to 5" << endl;
	v1.resize(5);
	v1.output(cout);
	cout << "\nTesting for v1.resize, size to 2" << endl;
	v1.resize(2);
	v1.output(cout);

	cout << "\nTesting for v1.reserve to 10" << endl;
	v1.reserve(10);
	v1.output(cout);
	cout << "\nTesting for v1.reserve to 60" << endl;
	v1.reserve(60);
	v1.output(cout);

	cout << "\nTesting for get value at v1[1], v1[1] = ";
	cout << v1.valueat(1) << endl;

	cout << "\nTesting for change value v1[1] = 8, v[1] = ";
	v1.changeValueAt(8,1);
	cout << v1.valueat(1) << endl;
}

void Program_Project2()
{
	Rational* ptr = new Rational[2];
	Rational temp;
	// Create first rational by using insert operator >>
	cout << "Enter the first rational!" << endl;
	cin >> ptr[0];
	
	// Create second rational by calling set function
	cout << "\nEnter the second rational!" << endl;
	int numerator = inputInteger("Enter the numberator: ");
	int denominator = getDenominator("Enter the denominator: ");
	ptr[1].setNumerator(numerator);
	ptr[1].setDenominator(denominator);

	//Adding
	temp = ptr[0] + ptr[1];
	cout << ptr[0] << " + " << ptr[1] << " = " << temp << " --> ";
	temp.normalization();
	checkZero(temp);

	//Sub
	temp = ptr[0] - ptr[1];
	cout << ptr[0] << " - " << ptr[1] << " = " << temp << " --> ";
	temp.normalization();
	checkZero(temp);

	//Multi
	temp = ptr[0] * ptr[1];
	cout << ptr[0] << " * " << ptr[1] << " = " << temp << " --> ";
	temp.normalization();
	checkZero(temp);

	//Devide
	temp = ptr[0] / ptr[1];
	cout << ptr[0] << " / " << ptr[1] << " = " << temp << " --> ";
	temp.normalization();
	checkZero(temp);
	
	//Negative
	temp = ptr[0];
	cout << "-(" << temp << ")" << " = ";
	temp = -temp;
	cout << temp << " --> ";
	temp.normalization();
	checkZero(temp);

	// <
	cout << ptr[0] << " < " << ptr[1] << (ptr[0] < ptr[1] ? " true " : " false ") << endl;

	// <=
	cout << ptr[0] << " <= " << ptr[1] << (ptr[0] <= ptr[1] ? " true " : " false ") << endl;

	// >=
	cout << ptr[0] << " >= " << ptr[1] << (ptr[0] >= ptr[1] ? " true " : " false ") << endl;

	// ==
	cout << ptr[0] << " == " << ptr[1] << (ptr[0] == ptr[1] ? " true " : " false ") << endl;
	delete[] ptr;
}

void Program_Project3()
{
	Complex num1, num2;
	Complex temp;
	cout << "Enter the first complex number!" << endl;
	cin >> num1;
	cout << "\nEnter the second complex number!" << endl;
	cin >> num2;

	// Add
	temp = num1 + num2;
	cout << "(" << num1 << ")" << " + " << "(" << num2 << ")" << " = " << temp << endl;

	// Sub
	temp = num1 - num2;
	cout << "(" << num1 << ")" << " - " << "(" << num2 << ")" << " = " << temp << endl;

	// Multiple
	temp = num1 * num2;
	cout << "(" << num1 << ")" << " * " << "(" << num2 << ")" << " = " << temp << endl;

	// ==
	cout << "(" << num1 << ")" << " == " << "(" << num2 << ")" << (num1 == num2 ? " true " : " false ") << endl;
}

void Program_Project4()
{
	cout << "Test for constructor, assignment operator, output stream!" << endl;
	StringVar object1("my name is Nhat Ho!");
	StringVar object2;
	object2 = object1.copyPiece(11, 20);
	cout << object2;

	cout << "\nTest for + operator overloading" << endl;
	StringVar object3("This is home work for chapter 11.");
	StringVar object4 = object1 + object3;
	cout << object4;

	cout << "\nTest for == operator overloading" << endl;
	if (object4 == object1)
		cout << "My code is false!" << endl;
	else
		cout << "That's true" << endl;

	cout << "\nobject2 before reading:" << endl;
	cout << object2;
	cout << "Test for read one word, please enter a word: ";
	cin >> object2;
	cout << "object2 after reading:" << endl;
	cout << object2;
}

void Program_Project11()
{
	Chapter9 object1;
	object1.setPosition(0, "my name is ho nhat tan");
	object1.addEntry("c++ class");
	for (int c = 0; c < 2; c++)
		cout << object1.getPosition(c);
	Chapter9 object2;
	object2 = object1;
	for (int c = 0; c < 2; c++)
		cout << object2.getPosition(c);
}