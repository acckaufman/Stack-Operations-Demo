//This program demonstrates a dynamic stack class template, using two different data types.
#include <iostream>
#include "DynamicStack.h"
using namespace std;

int main()
{
	//#######################################################
	//Part 1: Characters									#
	//#######################################################

	//Create a dynamic stack of the char data type.
	DynamicStack<char> charStack;

	//Push some values onto the stack.
	cout << "Character Stack:" << endl;
	cout << "Pushing 'a'." << endl;
	charStack.push('a');
	cout << "Pushing 'b'." << endl;
	charStack.push('b');
	cout << "Pushing 'c'." << endl << endl;
	charStack.push('c');

	//Display the values currently in the stack.
	charStack.displayStack();

	system("pause");

	char value;

	//Pop the values off the stack one by one, with an extra pop attempt to show what happens when the list is empty.

	for (int count = 0; count < 4; count++)
	{
		bool tempBool = false;		//To determine whether the pop operation was successful

		cout << endl << "Popping a value off the top of the stack." << endl;
		tempBool = charStack.pop(value);

		if (!tempBool)
			cout << "The last operation was not successful." << endl << endl;
		else
		{
			cout << "The value '" << value << "' was popped." << endl << endl;
			charStack.displayStack();
		}
		system("pause");
	}

	cout << endl << "##############################################################################" << endl << endl;

	//#######################################################
	//Part 2: Doubles										#
	//#######################################################

	//Create a dynamic stack of the double data type.
	DynamicStack<double> doubleStack;

	//Push some values onto the stack.
	cout << "Double Stack:" << endl;
	cout << "Pushing 4.62." << endl;
	doubleStack.push(4.62);
	cout << "Pushing 10.99." << endl;
	doubleStack.push(10.99);
	cout << "Pushing 8.75." << endl << endl;
	doubleStack.push(8.75);

	//Display the values currently in the stack.
	doubleStack.displayStack();

	system("pause");

	double number;

	//Pop the values off the stack one by one, with an extra pop attempt to show what happens when the list is empty.

	for (int count = 0; count < 4; count++)
	{
		bool tempBool = false;		//To determine whether the pop operation was successful

		cout << endl << "Popping a value off the top of the stack." << endl;
		tempBool = doubleStack.pop(number);

		if (!tempBool)
			cout << "The last operation was not successful." << endl << endl;
		else
		{
			cout << "The value " << number << " was popped." << endl << endl;
			doubleStack.displayStack();
		}
		system("pause");
	}

	return 0;
}