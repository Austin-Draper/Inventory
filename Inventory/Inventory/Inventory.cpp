// Inventory.cpp : Defines the entry point for the console application.
//Austin Draper

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>

/************************************************************
* Stack to store operands of postfix expression            *
************************************************************/
class Stack
{
private:
	int *s;  //pointer to 1D dynamic array for storing stack elements
	int capacity,  //stack capacity
		t;  //index of the top element on stack
	void growStack(int newCapacity);  //increases the stack if it is full
									  //must be called from the push function if the stack is full

public:
	Stack(int capacity)
	{
		this->capacity = capacity;
		s = new int[capacity];
		t = -1;
	}
	Stack()
	{
		if (capacity == 0)
			return;
		delete[] s;
	}
	int size() const
	{
		return t + 1;
	}//return the number of elements in the stack
	bool isFull() const
	{
		if (t + 1 == capacity)
			return true;
		else
			return false;
	}
	bool isEmpty() const
	{
		if (t == -1)
			return true;
		else
			return false;
	}
	int top()
	{
		return s[t];
	}
	//returns the element at the top of the stack
	//without removing it from the stack

	void push(int x)
	{
		if (s == NULL)
		{
			s = new int[5];
		}
		else if (isFull())
		{
			growStack(capacity);
		}
		t++;
		s[t] = x;
	}
	void pop()
	{
		if (!isEmpty())
		{
			t--;
		}
		//else
		//cout << "Stack is Empty" << endl;
	}
};

void Stack::growStack(int newCapacity)
{
	int *newStack = new int[newCapacity + 5];
	for (int i = 0; i < capacity; i++)
	{
		newStack[i] = s[i];
	}
	delete[] s;
	s = newStack;
	capacity = newCapacity + 5;
}

using namespace std;
struct elements
{
	string name; //a short text description
	int ID; //part ID
	double price;  //Price of part
	int amount; //running count of product in stock
}*_array[100];



//using namespace std;
int main()
{
	Stack S;
	ifstream InData;
	ofstream OutData;
	int choice = 0;
	int count = 0;
	//int N = 50;
	//elements *array = new elements[N];

	int _ID;
	string _name;
	double _price;
	int _amount;
	// get info from file

	InData.open("textSave.txt");

	if (InData.fail())
	{
		cerr << "File not found, please try again." << endl;
		exit(1);//if it keeps failing, try putting txt file into Resource Files
	}
	while (!InData.eof())//can use while instead of for.
	{
		InData >> _ID >> _price >> _amount;
		getline(InData, _name);

		elements *v = new elements;
		v->ID = _ID;
		v->price = _price;
		v->amount = _amount;
		v->name = _name;

		_array[count] = v;


		count++;
	}
	InData.close();




	// user menu

	cout << "**********************************************************" << endl;

	cout << "Please select one of the following options : " << endl << endl;

	cout << "\t(1) Enter a new part." << endl;

	cout << "\t(2) Find a particular part." << endl;

	cout << "\t(3) Archive the information" << endl;//online example has this saving to dat file. check it out!

	cout << "\t(4) Quit this program." << endl << endl;

	while (choice != 4)
	{

		cin >> choice;


		cout << "**********************************************************" << endl;




		// function calls based on user input

		switch (choice) {

		case 1:
		{
			string hello;
			elements *v = new elements;
			cout << "Enter part ID: ";
			cin >> _ID;
			cout << "Enter price of part: ";
			cin >> _price;
			cout << "Enter quantity of parts: ";
			cin >> _amount;
			cout << "Enter short description of part: ";
			cin.ignore();
			getline(cin, hello);
			//cin >> _name;
			v->ID = _ID;
			v->price = _price;
			v->amount = _amount;
			v->name = hello;

			_array[count - 1] = v;
			count++;
			cout << "**********************************************************" << endl;

			break;
		}

		case 2:
		{
			int temp;
			double t_price;//temp price
			int t_amount;//temp amount
			string t_name;//temp description

			cout << "Enter a part ID number to search for: ";
			cin >> _ID;
			for (int j = 0; j < count; j++)
			{
				temp = _array[j]->ID;
				S.push(temp);

				if (S.top() == _ID)
				{
					cout << "Found the item!      ID: " << _array[j]->ID << "  ";
					t_price = _array[j]->price;
					cout << "Price: " << t_price << "  ";
					t_amount = _array[j]->amount;
					cout << "Quantity: " << t_amount << "  ";
					t_name = _array[j]->name;
					cout << "Description: " << t_name << endl << endl;
					break;
				}
				else if (j == count - 1)
				{
					cout << "Part ID does not exist" << endl << endl;
					break;
				}
				else
				{
					S.pop();
				}


			}
			cout << "**********************************************************" << endl;
			break;
		}

		case 3:
		{

			OutData.open("binarySave.dat");

			for (int l = 0; l < count - 1; l++)
			{
				OutData << _array[l]->ID << " " << _array[l]->price << " " << _array[l]->amount << " " << _array[l]->name << endl;
			}

			cout << "The information has been copied to binarySave.dat" << endl;
			OutData.close();
			cout << "**********************************************************" << endl;
			break;
		}
		case 4:
		{
			OutData.open("textSave.txt");
			for (int m = 0; m < count - 1; m++)
			{
				OutData << _array[m]->ID << " " << _array[m]->price << " " << _array[m]->amount << " " << _array[m]->name << endl;
			}
			OutData.close();
			exit(1);
		}
		}
	}


	system("PAUSE");
	return 0;
}